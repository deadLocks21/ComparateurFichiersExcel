#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "storage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_chooseRHFile_pressed();

    void on_pb_chooseProWebFile_pressed();

    void on_pb_launch_pressed();

private:
    Ui::MainWindow *ui;
    Storage storage;
};
#endif // MAINWINDOW_H
