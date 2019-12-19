#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QObject>
#include <QStringList>

class History;

class Window : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString location MEMBER m_location NOTIFY locationChanged)
    Q_PROPERTY(QString title MEMBER m_title NOTIFY titleChanged)

public:
    explicit Window(QObject *parent = nullptr);

    void setHistory(History *history);

signals:
    void locationChanged(const QString &location);
    void titleChanged(const QString &title);

public slots:
    void back();
    void forward();

    void alert(const QString &message);

private:
    History *m_history;
    QString m_location;
    QString m_title;
};

#endif // WINDOW_HPP
