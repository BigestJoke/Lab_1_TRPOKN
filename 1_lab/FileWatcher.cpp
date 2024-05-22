#include "FileWatcher.h"

FileWatcher::FileWatcher(const QStringList &filePaths, int checkIntervalMs, QObject *parent)
    : QObject(parent), checkIntervalMs(checkIntervalMs)
{
    for (const QString &filePath : filePaths) {
        watchedFiles.append(File(filePath));
    }
    connect(&timer, &QTimer::timeout, this, &FileWatcher::checkFiles);
    timer.start(checkIntervalMs);
}

void FileWatcher::checkFiles() {
    for (File &file : watchedFiles) {
        File newFileData(file.getFilePath());

        if (newFileData.exists() != file.exists()) {
            emit fileExistenceChanged(newFileData);
            file = newFileData;
        } else if (newFileData.exists() &&
                   (newFileData.getLastModified() != file.getLastModified() ||
                    newFileData.getSize() != file.getSize())) {
            emit fileChanged(newFileData);
            file = newFileData;
        }
    }
}
