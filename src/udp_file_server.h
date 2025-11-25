#pragma once

#include <QNetworkDatagram>
#include <QUdpSocket>
#include <QHostAddress>

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

signals:
    void datagramRecived(const QNetworkDatagram datagram);

private:
    QUdpSocket* socket_;

    void readPendingDatagrams() {
        while (socket_->hasPendingDatagrams()) {
            QNetworkDatagram datagram = socket_->receiveDatagram();
            emit datagramRecived(datagram);
        }
    }
};