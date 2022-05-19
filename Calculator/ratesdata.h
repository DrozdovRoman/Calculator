#ifndef RATESDATA_H
#define RATESDATA_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>
#include <QVector>
class ratesdata : public QObject {
  Q_OBJECT;

public:
    ratesdata();
    ~ratesdata();

    QTimer* timer;

    QJsonDocument doc;
    QJsonObject temp;
    QJsonParseError err;
    QNetworkRequest request;
    QVector <double> A;
    QVector <QVector <double>> RateData;

    QNetworkAccessManager* NetworkManager;
signals:
    void signal(QVector<QVector<double>>);
public slots:
    void SendReq();
    void slot_NetworkManager(QNetworkReply*);
//    void slot_savedata();

};


#endif // RATESDATA_H
