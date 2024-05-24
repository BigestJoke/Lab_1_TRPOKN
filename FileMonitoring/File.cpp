#include "File.h"

File::File(const QString &filePath) : fileInfo(filePath) {}

QString File::getFilePath() const {
    return fileInfo.filePath();
}

int File::getSize() const {
    return fileInfo.size();
}

QDateTime File::getLastModified() const {
    return fileInfo.lastModified();
}

bool File::exists() const {
    return fileInfo.exists();
}
