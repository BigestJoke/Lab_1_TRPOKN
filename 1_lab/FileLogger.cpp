#include "FileLogger.h"

void FileLogger::onFileChanged(const File &fileData) {
    qDebug() << "File changed:" << fileData.getFilePath() << "Size:" << fileData.getSize();
}

void FileLogger::onFileExistence(const File &fileData) {
    if (fileData.exists()) {
        qDebug() << "File exists:" << fileData.getFilePath() << "Size:" << fileData.getSize();
    } else {
        qDebug() << "File does not exist:" << fileData.getFilePath();
    }
}

