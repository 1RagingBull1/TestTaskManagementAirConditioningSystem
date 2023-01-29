#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <TCPClient/TCPClient.h>
#include <QSettings>

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

    void SaveSettings(QString key, int index);
    void RecalculateValue(QLabel *label, );
private slots:
    void ChangeScale();

    void on_comboBox_2_currentIndexChanged(int index);
};

#endif // MAINWINDOW_H
