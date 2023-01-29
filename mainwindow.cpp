#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), tcpClient(new TCPClient())
{
    ui->setupUi(this);

//    temperature = new DisplayedData("temperature",ui->comboBox_2, ui->label_4,this);
//    connect(temperature, &DisplayedData::sigSaveSettings, this, &MainWindow::SlotSaveSettings);
//    temperature->SlotRefreshData(5);


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

void MainWindow::SlotSaveSettings(QString key, int index)
{
    settings->setValue(key, index);
}



