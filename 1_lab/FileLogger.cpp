#include "FileLogger.h"

void FileLogger::onFileChanged(const File &file) {
    qDebug() << "File changed:" << file.getFilePath() << "Size:" << file.getSize();
}

void FileLogger::onFileExistence(const File &fileData) {
    if (fileData.exists()) {
        qDebug() << "File exists:" << fileData.getFilePath() << "Size:" << fileData.getSize();
    } else {
        qDebug() << "File does not exist:" << fileData.getFilePath();
    }
}

