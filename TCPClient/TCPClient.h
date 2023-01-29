#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>
#include <QByteArray>

class TCPClient:public QObject
{
        Q_OBJECT
public:
    TCPClient();
private slots:

private:
    QTcpSocket *socket;
    QByteArray Data;

    void SendToServer(QByteArray arr); // функция передачи данных серверу
    quint16 nextBlockSize = 0; // содержит объем отправляемого сообщения
public slots:
    void slotReadyRead();
    void connectToServer();
};

#endif // TCPCLIENT_H
