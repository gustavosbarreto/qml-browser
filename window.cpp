#include "window.hpp"

#include <QDebug>
#include <QMessageBox>

#include "history.hpp"

Window::Window(QObject *parent) : QObject(parent)
{
}

void Window::setHistory(History *history)
{
    m_history = history;

    connect(history, &History::updated, [=](const QString &url) {
       m_location = url;
    });
}

void Window::back()
{
    m_history->back();
}

void Window::forward()
{
    m_history->back();
}

void Window::alert(const QString &message)
{
    QMessageBox::warning((QWidget *)parent(), "Warning", message);
}
