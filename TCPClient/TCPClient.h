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
    void SendToServer(QString arr); // функция передачи данных серверу
private slots:

private:
    QTcpSocket *socket;
    QByteArray Data;

    quint16 nextBlockSize = 0; // содержит объем отправляемого сообщения
public slots:
    void slotReadyRead();
    void connectToServer();
signals:
    void SigRecivedMessage(int);
};

#endif // TCPCLIENT_H
