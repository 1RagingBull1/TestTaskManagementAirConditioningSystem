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
    TCPClient *tcpClient;
    QSettings *settings;

    DisplayedData* temperature;
    DisplayedData* pressure;
    DisplayedData* humidity;

private slots:
    void SlotSaveSettings(QString key, int index);

};

#endif // MAINWINDOW_H
