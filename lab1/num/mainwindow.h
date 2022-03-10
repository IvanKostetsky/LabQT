#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QProgressBar>
#include <QLineEdit>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *btnPlus;
    QPushButton *btnMinus;
    QProgressBar *bar;
    QLineEdit *lan1;
    QLineEdit *lan2;
    QLineEdit *lan3;
    QLabel *lab;

private slots:
    void Izmbut();
};
#endif // MAINWINDOW_H
