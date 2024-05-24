#ifndef FILEWATCHER_H
#define FILEWATCHER_H
#include <QObject>
#include <QTimer>
#include <QList>
#include "File.h"

class FileWatcher : public QObject {
    Q_OBJECT

signals:
    void fileChanged(const File &file);
    void fileExistenceChanged(const File &file);

public:
    FileWatcher(const QStringList &filePaths, int checkIntervalMs, QObject *parent = 0);
    ~FileWatcher();

private slots:
    void checkFiles();

private:
    QTimer timer;
    QList<File> watchedFiles;
    int checkIntervalMs;
};

#endif
