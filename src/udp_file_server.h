#pragma once

#include <QHostAddress>
#include <QNetworkDatagram>
#include <QByteArray>
#include <QUdpSocket>

const quint16 PORT = 7755;

/**
 * @brief UDP-сервер для отправки скрипта по запросу клиента.
 *
 * Прослушивает входящие datagram-запросы и отправляет текущий 
 * сохраненный или загруженный текст скрипта обратно инициатору.
 */
class UdpFileServer : public QObject {
    Q_OBJECT
public:
    explicit UdpFileServer(QObject* parent = nullptr);

    ~UdpFileServer() override = default;

    /**
     * @brief Инициализирует UDP-сокет и начинает прослушку порта.
     */
    void InitSocket();

    /**
     * @brief Отправляет данные последнему подключившемуся клиенту.
     * @param data Байтовые данные для отправки.
     */
    void SendData(const QByteArray& data);

signals:
    void fileRequested();

private slots:
    void readPendingDatagrams();

private:
    QUdpSocket* socket_;
    QHostAddress lastSenderAddress_;
    quint16 lastSenderPort_;

    /**
     * @brief Обрабатывает одну входящую датаграмму.
     * @param datagram Входящая датаграмма от клиента.
     */
    void HandleRequest(const QNetworkDatagram& datagram);
};