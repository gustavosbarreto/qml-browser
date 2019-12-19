#include "window.hpp"

#include <QDebug>
#include <QMessageBox>

Window::Window(QObject *parent) : QObject(parent)
{
}

void Window::addToHistory(const QString &url)
{
    if (m_historyIndex > 0) {
        while (m_history.size() > m_historyIndex + 1) {
            m_history.removeLast();
        }
    }

    m_history << url;
    m_historyIndex++;
}

void Window::back()
{
    if (m_historyIndex > 0) {
        m_location = m_history[--m_historyIndex];
        emit historyChanged();
    }
}

void Window::forward()
{
    if (m_historyIndex < m_history.size() - 1) {
        m_location = m_history[++m_historyIndex];
        emit historyChanged();
    }
}

void Window::alert(const QString &message)
{
    QMessageBox::warning((QWidget *)parent(), "Warning", message);
}
