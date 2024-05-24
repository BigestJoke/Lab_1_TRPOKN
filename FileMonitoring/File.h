#ifndef FILE_H
#define FILE_H
#include <QString>
#include <QFileInfo>
#include <QDateTime>

class File {
public:
    File(const QString &filePath);
    QString getFilePath() const;
    int getSize() const;
    QDateTime getLastModified() const;
    bool exists() const;

private:
    QFileInfo fileInfo; //обьект для хранения данных о файле
};

#endif
