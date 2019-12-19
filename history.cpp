#include "history.hpp"

History::History(QObject *parent) : QObject(parent)
{
}

void History::append(const QString &url)
{
    if (m_index > 0) {
        while (m_history.size() > m_index + 1) {
            m_history.removeLast();
        }
    }

    if (m_history.size() > 1 && m_history[m_index] + 1 != url) {
        m_index++;
    } else {
        m_index++;
        m_history << url;
    }
}

void History::back()
{
    if (m_index > 0) {
        emit updated(m_history[--m_index]);
    }
}

void History::forward()
{
    if (m_index < m_history.size() - 1) {
        emit updated(m_history[++m_index]);
    }
}
