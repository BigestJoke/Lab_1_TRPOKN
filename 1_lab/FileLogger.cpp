#include "FileLogger.h"

FileLogger::FileLogger(QObject *parent) : QObject(parent) {}

void FileLogger::logFileChange(const File &fileData) {
    qDebug() << "File changed:" << fileData.getFilePath() << "Size:" << fileData.getSize();
}

void FileLogger::logFileExistence(const File &fileData) {
    if (fileData.exists()) {
        qDebug() << "File exists:" << fileData.getFilePath() << "Size:" << fileData.getSize();
    } else {
        qDebug() << "File does not exist:" << fileData.getFilePath();
    }
}




