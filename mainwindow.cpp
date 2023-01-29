#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), tcpClient(new TCPClient())
{
    ui->setupUi(this);
    tcpClient->connectToServer();


    settings = new QSettings("settings.ini", QSettings::IniFormat);
    settings->beginGroup( "displayScale" );
    if(settings->contains("temperature")){// проверяю есть ли сохраненные настройки шкал отображения
        this->ui->label->setText(settings->value( "temperature").toString());
    }else{
        settings->setValue( "temperature", 128 );
        this->ui->label->setText("333");
    }


//    connect(this->ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::ChangeScale);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete  tcpClient;
}

void MainWindow::SaveSettings(QString key, int index)
{
    settings->setValue(key, index);
}

void MainWindow::RecalculateValue()
{

}

void MainWindow::ChangeScale()
{

}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    SaveSettings("temperature", index);

}



