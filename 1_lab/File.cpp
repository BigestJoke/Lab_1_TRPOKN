#include "file.h"

File::File(const QString &filePath)
    : m_filePath(filePath), m_qfile(filePath){}

bool File::exists() const
{
    return m_qfile.exists();
}

qint64 File::size() const
{
    return m_qfile.size();
}

QString File::path() const
{
    return m_filePath;
}

void File::printFileInfo () const
{
    qDebug() << "File path:" << m_filePath;
    if (m_qfile.exists()) {
        qDebug() << "File exists: Yes";
        qDebug() << "File size:" << m_qfile.size() << "bytes";
    } else {
        qDebug() << "File is not exists";
    }
}
