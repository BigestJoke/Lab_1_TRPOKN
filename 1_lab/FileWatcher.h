#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QTimer>
#include <QList>
#include "File.h"
#include "FileLogger.h"

class FileWatcher : public QObject {
    Q_OBJECT

public:
    explicit FileWatcher(const QStringList &filePaths, int checkIntervalMs, QObject *parent = nullptr);
    void addFile(const QString &filePath);
    void removeFile(const QString &filePath);

private slots:
    void onFileChanged();

private:
    QTimer timer;
    QList<File> watchedFiles;
    FileLogger logger;
    int checkIntervalMs;
};

#endif // FILEWATCHER_H
