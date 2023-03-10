#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <TCPClient/TCPClient.h>
#include <QSettings>
#include <displayeddata.h>

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
    TCPClient *clientToEmmitator;
    QSettings *settings;

    DisplayedData* temperature;
    DisplayedData* pressure;
    DisplayedData* humidity;

    void closeEvent(QCloseEvent *event) override; // переопределяем  метод - перехватывает закрытие окна и сохраняет настройки единиц измерения
private slots:


    void SlotSetRawDataTemp(int var);
    void on_pushButton_clicked();
    void on_checkBox_stateChanged(int arg1);
};

#endif // MAINWINDOW_H
