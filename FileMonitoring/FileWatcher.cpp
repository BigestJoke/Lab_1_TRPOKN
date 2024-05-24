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
    // Итерация по списку отслеживаемых файлов
    for (File &file : watchedFiles) {
        // Создание нового объекта File на основе пути текущего файла
        File newFile(file.getFilePath());
        if (newFile.exists() != file.exists()) {
            // Если существование файла изменилось, отправляем сигнал об изменении существования файла
            emit fileExistenceChanged(newFile);
            // Обновляем текущий файл на новый
            file = newFile;
        }
        // Проверка изменений в файле
        else if (newFile.exists() &&
                 (newFile.getLastModified() != file.getLastModified() || newFile.getSize() != file.getSize())) {
            // Если файл существует и изменился, отправляем сигнал об изменении файла
            emit fileChanged(newFile);
            file = newFile;
        }
    }
}

FileWatcher::~FileWatcher() {
    timer.stop();
}
