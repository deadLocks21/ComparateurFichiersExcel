#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QSettings>
#include <QString>
#include <QDebug>
#include <QTime>
#include <string>


using std::string;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    storage.setPB(ui->progressBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_chooseRHFile_pressed()
{
    QSettings settings(QSettings::UserScope, "Microsoft", "Windows");
    settings.beginGroup("CurrentVersion/Explorer/Shell Folders");

    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Choisir le fichier des RH"), settings.value("Personal").toString(), tr("Excel Files (*.csv)"));

    storage.setRhFilePath(fileName.toStdString());

    ui->lb_rhPath->setStyleSheet("QLabel { color : black; }");
    ui->lb_rhPath->setText(storage.getRhFilePath().data());
}

void MainWindow::on_pb_chooseProWebFile_pressed()
{
    QSettings settings(QSettings::UserScope, "Microsoft", "Windows");
    settings.beginGroup("CurrentVersion/Explorer/Shell Folders");

    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Choisir le fichier de proweb"), settings.value("Personal").toString(), tr("Excel Files (*.csv)"));

    storage.setProwebFilePath(fileName.toStdString());

    ui->lb_pwPath->setStyleSheet("QLabel { color : black; }");
    ui->lb_pwPath->setText(storage.getProwebFilePath().data());
}

void MainWindow::on_pb_launch_pressed()
{
    bool launch = true;

    // TODO Décomenter !!
    if (storage.getRhFilePath() == "" || storage.getProwebFilePath() == "")
        launch = false;

    if(launch) {

        // qDebug() << "Go go go !!";
        ui->pb_launch->setEnabled(false);
        ui->pb_chooseRHFile->setEnabled(false);
        ui->pb_chooseProWebFile->setEnabled(false);
        ui->progressBar->setEnabled(true);

        process();

        ui->pb_launch->setEnabled(true);
        ui->pb_chooseRHFile->setEnabled(true);
        ui->pb_chooseProWebFile->setEnabled(true);
        ui->progressBar->setEnabled(false);

    } else {
        if(storage.getRhFilePath() == "")
        {
            ui->lb_rhPath->setStyleSheet("QLabel { color : red; }");
            ui->lb_rhPath->setText("Saisir un fichier svp");
        }

        if(storage.getProwebFilePath() == "")
        {
            ui->lb_pwPath->setStyleSheet("QLabel { color : red; }");
            ui->lb_pwPath->setText("Saisir un fichier svp");
        }
    }
}

void MainWindow::process()
{
    // TODO Enlever
//    storage.setRhFilePath("D:/Users/deadLocks21/Desktop/ProgCSEFlo/Fichier RH.csv");
//    storage.setProwebFilePath("D:/Users/deadLocks21/Desktop/ProgCSEFlo/Fichier proWeb.csv");

    storage.getRHContent();
    storage.getProwebContent();
    storage.compare();
}
