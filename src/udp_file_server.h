#pragma once

#include <QHostAddress>
#include <QNetworkDatagram>
#include <QByteArray>
#include <QUdpSocket>


const quint16 PORT = 7755;

class UdpFileServer : public QObject {
    Q_OBJECT
public:
    explicit UdpFileServer(QObject* parent = nullptr)
        : QObject(parent)
        , socket_(new QUdpSocket(this)) {
    }

    ~UdpFileServer() override = default;

    void InitSocket() {
        socket_->bind(QHostAddress::LocalHost, PORT);
        connect(socket_, &QUdpSocket::readyRead, this, &UdpFileServer::readPendingDatagrams);
    }

    void SendData(const QByteArray& data) {
        socket_->writeDatagram(data, lastSenderAddress_, lastSenderPort_);
    }

signals:
    void fileRequested();

private slots:
    void readPendingDatagrams() {
        while (socket_->hasPendingDatagrams()) {
            QNetworkDatagram datagram = socket_->receiveDatagram();
            HandleRequest(datagram);            
        }
    }

private:
    QUdpSocket* socket_;
    QHostAddress lastSenderAddress_;
    quint16 lastSenderPort_;


    void HandleRequest(const QNetworkDatagram& datagram) {
        if (datagram.data() == "REQ") {
            lastSenderAddress_ = datagram.senderAddress();
            lastSenderPort_ = datagram.senderPort();
            emit fileRequested();
        }
    }

    
};