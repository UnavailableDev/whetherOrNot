#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

void MainWindow::setDb(QSqlDatabase _db){
    this->db = _db;
}

QSqlDatabase MainWindow::loginDb( QString adress, QString username, QString password){
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(adress);
    db.setUserName(username);
    db.setPassword(password);
    db.setDatabaseName("thecrapbox");
    return db;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::warning(this, "Oops..", "Task Failed succesfully ;)");
}


void MainWindow::on_pushButton_clicked()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("Joshy2me!teen44");
    db.setDatabaseName("thecrapbox");

    if(db.open()){
        QMessageBox::information(this, "Connection", "GREAT SUCCES!");
        pQueryModel = new QSqlQueryModel();
        pQueryModel->setQuery("SELECT * FROM opleiding;");
        ui->tableView->setModel(pQueryModel);
    } else {
        QMessageBox::warning(this, "No connection", "Failed to connect");
    }
}

void MainWindow::on_actionConnection_triggered()
{
    _dbConenctor = new dbConnector(this);
    _dbConenctor->show();
}

