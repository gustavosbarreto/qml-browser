#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "window.hpp"
#include "history.hpp"

#include <QLineEdit>
#include <QQmlEngine>
#include <QQmlContext>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->quickWidget->setClearColor(Qt::white);

    m_addressLineEdit = new QLineEdit(this);
    ui->toolBar->insertWidget(ui->actionGo, m_addressLineEdit);

    connect(m_addressLineEdit, &QLineEdit::returnPressed, this, &MainWindow::loadAddress);
    connect(ui->actionGo, &QAction::triggered, this, &MainWindow::loadAddress);

    m_history = new History(this);

    connect(m_history, &History::updated, this, [=](const QString &url) {
        ui->quickWidget->setSource(QUrl(url));
        m_addressLineEdit->setText(url);
    });

    connect(ui->actionBack, &QAction::triggered, m_history, &History::back);
    connect(ui->actionForward, &QAction::triggered, m_history, &History::forward);
    connect(ui->actionRefresh, &QAction::triggered, this, [=]() {
        const QUrl &url = ui->quickWidget->source();
        ui->quickWidget->engine()->clearComponentCache();
        ui->quickWidget->setSource(QUrl());
        ui->quickWidget->setSource(url);
    });

    m_window = new Window(this);
    m_window->setHistory(m_history);

    connect(m_window, &Window::locationChanged, this, [=](const QString &location) {
        m_addressLineEdit->setText(location);

        // Wait for QML signal handlers in progress
        QTimer::singleShot(0, [=]() {
            loadAddress();
        });
    });

    injectCodes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadAddress()
{
    ui->quickWidget->engine()->clearComponentCache();
    ui->quickWidget->setSource(QUrl(m_addressLineEdit->text()));
    m_history->append(ui->quickWidget->source().toString());
}

void MainWindow::injectCodes()
{
    QQmlContext *context = ui->quickWidget->engine()->rootContext();

    context->setContextProperty("window", m_window);
}
