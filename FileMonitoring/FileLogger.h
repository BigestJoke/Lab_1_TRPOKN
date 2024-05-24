#ifndef FILELOGGER_H
#define FILELOGGER_H
#include <QObject>
#include <QDebug>
#include "File.h"

class FileLogger : public QObject {
    Q_OBJECT

public slots:
    void onFileChanged(const File &fileData);
    void onFileExistence(const File &fileData);
};

#endif // FILELOGGER_H
