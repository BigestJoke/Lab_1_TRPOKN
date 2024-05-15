#ifndef FILE_H
#define FILE_H
#include <QString>
#include <QFile>
#include <QDebug>

class File
{
public:
    File(const QString &filePath);

    bool exists() const;
    qint64 size() const;
    QString path() const;

    void printFileInfo() const;

private:
    QString m_filePath;
    QFile m_qfile;
};

#endif
