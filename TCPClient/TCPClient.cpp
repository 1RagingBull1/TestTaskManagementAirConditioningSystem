#include "TCPClient.h"

TCPClient::TCPClient()
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &TCPClient::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &QTcpSocket::deleteLater);
}

void TCPClient::SendToServer(QString arr)
{
    Data.clear();

    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_15);
    out<< quint16(0); // записываем в первые два байта 0, чтобы зарезервировать место в кадре посылки
    out<<arr; // отслыаемая  прописывается через датастрим в битовый массив Data, для исключения искажений и реализоации независимости от платформы

    out.device()->seek(0); // переходим на 0ую позицию в посылке, чтобы перезаписать размер посылки. Эти два байта зарезервирвовали выше
    out<< quint16(Data.size() - sizeof(quint16));

    socket->write(Data); //полученный массив отсылается через сокет
}

void TCPClient::slotReadyRead()
{
    QDataStream in (socket);
    in.setVersion(QDataStream::Qt_5_9);
//    if (in.status() == QDataStream::Ok) {
//        while(1){
//            if (nextBlockSize == 0) { // определяем известно ли нам сколько должно прийти байт. Это содержится в начале посылки первые 2 байта
//                if (socket->bytesAvailable() < 2) { //здесь контролируем что пришло миниум 2 байта, если нет то ждем когда придут первые 2 байта, чтобы узнать размер посылки
//                    break;
//                }
//                in>>nextBlockSize; // если пришли 2 байта, то записываем размер послыки в переменную
//            }
//            if(socket->bytesAvailable() < nextBlockSize){// сравниваем сколько пришло и сколько нужно байт
//                break;
//            }


//        }
//    }
    nextBlockSize = 0;
    int var;
    QString str;
    in>> str;
    var = str.toInt();
    emit SigRecivedMessage(var);
}

void TCPClient::connectToServer()
{
      socket->connectToHost("127.0.0.1", 2323); // создаем сокет который содержит адрес и порт сервера
}
