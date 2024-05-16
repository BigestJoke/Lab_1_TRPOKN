#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QFileInfo>

class File {
public:
    File(const QString &filePath);
    QString getFilePath() const;
    qint64 getSize() const;
    QDateTime getLastModified() const;
    bool exists() const;

private:
    QFileInfo fileInfo;
};

#endif
