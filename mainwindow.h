#pragma once

#include <QMainWindow>

#include "dbconnector.h"

#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include "main.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//    QSqlDatabase loginDb( QString adress, QString username, QString password);
//    void setDb(QSqlDatabase db);

private slots:
    void on_actionAbout_triggered();

    void on_pushButton_clicked();

    void on_actionConnection_triggered();

private:
    Ui::MainWindow *ui;

    dbConnector *_dbConenctor;
//    QSqlDatabase db;

    QSqlQueryModel *pQueryModel;
};
