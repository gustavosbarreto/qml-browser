#ifndef HISTORY_HPP
#define HISTORY_HPP

#include <QObject>

#include <QObject>
#include <QStringList>

class History : public QObject
{
    Q_OBJECT

public:
    explicit History(QObject *parent = nullptr);

    void append(const QString &url);

signals:
    void updated(const QString &url);

public slots:
    void back();
    void forward();

private:
    QStringList m_history;
    int m_index = -1;
};

#endif // HISTORY_HPP
