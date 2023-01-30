#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), clientToEmmitator(new TCPClient())
{
    ui->setupUi(this);

    clientToEmmitator->connectToServer();

    temperature = new TempertureData(ui->comboBox_2, ui->label_4, this);
    pressure = new PressureData(ui->comboBox_3, ui->label_6, this);
    humidity = new HumidityData(ui->comboBox_4, ui->label_5, this);



    settings = new QSettings("settings.ini", QSettings::IniFormat);
    settings->beginGroup( "displayScale" );
    if(settings->contains("temperature")){// проверяю есть ли сохраненные настройки шкал отображения
        this->ui->comboBox_2->setCurrentIndex(settings->value("temperature").toInt());
        this->ui->comboBox_3->setCurrentIndex(settings->value("pressure").toInt());
    }




}

MainWindow::~MainWindow()
{
    delete ui;
    delete  clientToEmmitator;
}



void MainWindow::closeEvent(QCloseEvent *event){
    settings->setValue("temperature", ui->comboBox_2->currentIndex());
    settings->setValue("pressure", ui->comboBox_3->currentIndex());
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
//    QByteArray arr = (QByteArray)"test";
    clientToEmmitator->SendToServer("first");
}
