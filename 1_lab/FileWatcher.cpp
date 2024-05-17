#include "FileWatcher.h"
#include <QDateTime>
#include <QDebug>

FileWatcher::FileWatcher(const QStringList &filePaths, int checkIntervalMs, QObject *parent): QObject(parent), checkIntervalMs(checkIntervalMs)
{
    for (const QString &filePath : filePaths) {
        watchedFiles.append(File(filePath));


        File &fileData = watchedFiles.last();
        if (fileData.exists()) {
            qDebug() << "File exists:" << fileData.getFilePath() << " Size:" << fileData.getSize();
        } else {
            qDebug() << "File does not exist:" << fileData.getFilePath();
        }
    }
    connect(&timer, &QTimer::timeout, this, &FileWatcher::onFileChanged);
    timer.start(checkIntervalMs);
}

void FileWatcher::onFileChanged() {
    for (File &fileData : watchedFiles) {
        File newFileData(fileData.getFilePath());

        if (newFileData.exists() != fileData.exists()) {
            logger.logFileExistence(newFileData);
            fileData = newFileData; // Update the existing FileData object
        } else if (newFileData.exists() && (newFileData.getLastModified() != fileData.getLastModified() ||
                                            newFileData.getSize() != fileData.getSize())) {
            logger.logFileChange(newFileData);
            fileData = newFileData; // Update the existing FileData object
        }
    }
}

//add file to watch
void FileWatcher::addFile(const QString &filePath) {
    watchedFiles.append(File(filePath));
}
//remove file to watch
void FileWatcher::removeFile(const QString &filePath) {
    for (int i = 0; i < watchedFiles.size(); ++i) {
        if (watchedFiles[i].getFilePath() == filePath) {
            watchedFiles.removeAt(i);
            break;
        }
    }
}
