
#include <QCoreApplication>
#include "FileWatcher.h"
#include "FileLogger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList filePaths = {
        "C:/Users/Asus/Desktop/456.txt",
        "C:/Users/Asus/Desktop/123.txt",
    };
    int checkIntervalMs = 10000;
    FileLogger logger;

    // Проверка существования файлов перед созданием FileWatcher
    for (const QString &filePath : filePaths) {
        File fileData(filePath);
        if (fileData.exists()) {
            logger.onFileExistence(fileData);
        } else {
            logger.onFileExistence(fileData);
        }
    }

    // Создание и запуск FileWatcher
    FileWatcher watcher(filePaths, checkIntervalMs);

    // Подключение сигналов от FileWatcher к слотам FileLogger
    QObject::connect(&watcher, &FileWatcher::fileChanged, &logger, &FileLogger::onFileChanged);
    QObject::connect(&watcher, &FileWatcher::fileExistenceChanged, &logger, &FileLogger::onFileExistence);

    return a.exec();
}
