
#include "File.h"
#include "qdatetime.h"

File::File(const QString &filePath) : fileInfo(filePath) {}

QString File::getFilePath() const { return fileInfo.filePath(); }
qint64 File::getSize() const { return fileInfo.size(); }
QDateTime File::getLastModified() const { return fileInfo.lastModified(); } // Add this line
bool File::exists() const { return fileInfo.exists(); }
