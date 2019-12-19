#include "windowapi.hpp"

#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QVariant>

#include "history.hpp"

WindowAPI::WindowAPI(QObject *parent) : QObject(parent)
{
}

void WindowAPI::setHistory(History *history)
{
    m_history = history;

    connect(history, &History::updated, [=](const QString &url) {
       m_location = url;
    });
}

void WindowAPI::back()
{
    m_history->back();
}

void WindowAPI::forward()
{
    m_history->back();
}

void WindowAPI::alert(const QString &message)
{
    QMessageBox::warning((QWidget *)parent(), "Warning", message);
}

QVariant WindowAPI::prompt(const QString &title, const QVariant &defaultValue)
{
    QVariant value = QInputDialog::getText((QWidget *)parent(), m_title, title, QLineEdit::Normal, defaultValue.toString());
    return value;
}

bool WindowAPI::confirm(const QString &message)
{
    return QMessageBox::question((QWidget *)parent(), m_title, message) == QMessageBox::Yes;
}
