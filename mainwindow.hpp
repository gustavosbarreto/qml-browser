#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QLineEdit;

class WindowAPI;
class History;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadAddress();

private:
    void injectAPI();

private:
    Ui::MainWindow *ui;

    QLineEdit *m_addressLineEdit;
    WindowAPI *m_window;
    History *m_history;
};
#endif // MAINWINDOW_HPP
