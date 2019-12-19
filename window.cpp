#include "window.hpp"

#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QVariant>

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

QVariant Window::prompt(const QString &title, const QVariant &defaultValue)
{
    QVariant value = QInputDialog::getText((QWidget *)parent(), m_title, title, QLineEdit::Normal, defaultValue.toString());
    return value;
}
