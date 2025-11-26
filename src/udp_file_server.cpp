#include "udp_file_server.h"

UdpFileServer::UdpFileServer(QObject* parent)
    : QObject(parent)
    , socket_(new QUdpSocket(this)) {
}

void UdpFileServer::InitSocket() {
    socket_->bind(QHostAddress::Any, PORT);
    connect(socket_, &QUdpSocket::readyRead, this, &UdpFileServer::readPendingDatagrams);
}

void UdpFileServer::SendData(const QByteArray & data) {
    socket_->writeDatagram(data, lastSenderAddress_, lastSenderPort_);
}

void UdpFileServer::readPendingDatagrams() {
    while (socket_->hasPendingDatagrams()) {
        QNetworkDatagram datagram = socket_->receiveDatagram();
        HandleRequest(datagram);
    }
}

void UdpFileServer::HandleRequest(const QNetworkDatagram & datagram) {
    if (datagram.data() == "REQ") {
        lastSenderAddress_ = datagram.senderAddress();
        lastSenderPort_ = datagram.senderPort();
        emit fileRequested();
    }
}