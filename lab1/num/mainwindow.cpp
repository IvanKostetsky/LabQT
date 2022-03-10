#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QHBoxLayout"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   QWidget* wdg = new QWidget();
     this->setWindowTitle("Изменяемое число");
     this->setFixedSize(280, 300);


     lan1 = new QLineEdit("0");
     lan2 = new QLineEdit();
     lan3 = new QLineEdit();

     lab = new QLabel();
     lab->setFixedSize(150, 50);

     lan1->setFixedSize(150,30);
     lan1->setReadOnly(true);
     lan2->setFixedSize(258,30);
     lan3->setFixedSize(258,30);


     btnPlus = new QPushButton(" + ");
     btnMinus = new QPushButton(" - ");

     bar = new QProgressBar;



     btnPlus->setFixedSize(30,30);
     btnMinus->setFixedSize(30,30);
   QHBoxLayout *lay2 = new QHBoxLayout;
     lay2->addWidget(btnPlus);
     lay2->addWidget(lan1);
     lay2->addWidget(btnMinus);
   QGridLayout* glayout1 = new QGridLayout();
     glayout1->addItem(lay2,1,1, 1, 2);
     glayout1->addWidget(lan2, 2, 1, 1, 2);
     glayout1->addWidget(lan3, 3, 1, 1, 2);
     glayout1->addWidget(bar, 4, 1, 1, 2);

   QObject::connect(btnMinus,SIGNAL(clicked()),this, SLOT(Izmbut()));
   QObject::connect(btnPlus,SIGNAL(clicked()),this, SLOT(Izmbut()));

    btnMinus->setCheckable(true);
    btnPlus->setCheckable(true);

    wdg->setLayout(glayout1);
    this->setCentralWidget(wdg);
}

MainWindow::~MainWindow()
{

}

void MainWindow::Izmbut()
{
    int num = lan1->text().toInt();
    int numMin = lan2->text().toInt();
    int numMax = lan3->text().toInt();
    int plus = 1;

    bar->setRange(numMin, numMax);


    if(btnMinus->isChecked())
    {

        if(num == numMin)
        {
            lab->setText(" Дальнейшее уменьшение \n            не возможно!");
            lab->show();
        }
        else  if (num != numMin)
        {
            lan1->setText(QString::number(num - plus));
        }
        bar->setValue(lan1->text().toInt());
        btnMinus->setChecked(false);
    }

    if(btnPlus->isChecked())
    {

        if(num == numMax)
        {
            lab->setText(" Дальнейшее увеличение \n            не возможно!");
            lab->show();
        }
        else
        {
            lan1->setText(QString::number(num + plus));
        }

        bar->setValue(lan1->text().toInt());
        btnPlus->setChecked(false);
    }
}
