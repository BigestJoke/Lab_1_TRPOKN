#include "FileWatcher.h"

FileWatcher::FileWatcher(const QStringList &filePaths, int checkIntervalMs, QObject *parent): QObject(parent), checkIntervalMs(checkIntervalMs)
{
    for (const QString &filePath : filePaths) {
        watchedFiles.append(File(filePath));
    }
    connect(&timer, &QTimer::timeout, this, &FileWatcher::checkFiles);
    timer.start(checkIntervalMs);
}

void FileWatcher::checkFiles() {
    for (File &file : watchedFiles) {
        File newFile(file.getFilePath());

        if (newFile.exists() != file.exists()) {
            emit fileExistenceChanged(newFile);
            file = newFile;
        } else if (newFile.exists() &&
                   (newFile.getLastModified() != file.getLastModified() ||
                    newFile.getSize() != file.getSize())) {
            emit fileChanged(newFile);
            file = newFile;
        }
    }
}
