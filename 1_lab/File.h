#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QFileInfo>

class File {
public:

    File(const QString &filePath);  // Конструктор

    QString getFilePath() const;// Получение пути к файлу
    qint64 getSize() const; // Получение размера файла
    QDateTime getLastModified() const; // Получение времени последнего изменения файла
    bool exists() const;  // Проверка существования файла

private:
    QFileInfo fileInfo;
};

#endif
