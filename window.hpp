#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QObject>
#include <QStringList>

class Window : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString location MEMBER m_location NOTIFY locationChanged)
    Q_PROPERTY(QString title MEMBER m_title NOTIFY titleChanged)

public:
    explicit Window(QObject *parent = nullptr);

    void addToHistory(const QString &url);

    inline QString currentHistoryItem() { return m_history[m_historyIndex]; }

signals:
    void locationChanged(const QString &location);
    void titleChanged(const QString &title);
    void historyChanged();

public slots:
    void goBack();
    void goForward();

    void alert(const QString &message);

private:
    QString m_location;
    QString m_title;
    QStringList m_history;
    int m_historyIndex = -1;
};

#endif // WINDOW_HPP
