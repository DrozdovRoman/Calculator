#include "ratesdata.h"

ratesdata::ratesdata() {
    NetworkManager = new QNetworkAccessManager(this); // Создаем объект класса QNetworkAcessManager
        connect(NetworkManager,& QNetworkAccessManager::finished,this,& ratesdata::slot_NetworkManager); // Соединяем сигнал окончания обработки запроса и слота обработки данных

    request.setUrl(QUrl("https://min-api.cryptocompare.com/data/pricemulti?fsyms=BTC,ETH,USDT,BNB,USDC,XRP,ADA,SOL,NEXO,NEAR,DOT,TRX&tsyms=RUB,USD,EUR&api_key=2be0fbd8ffeab0266c0030cc3bfbfe306ad3b533ba06df038bc0cce58eba8165"));
    // Преобразовываем запрос к API сервису к формату URL
    timer = new QTimer();
    A = QVector<double>(3);
    RateData = QVector<QVector<double>>(12);
    timer -> setInterval(10000); // Задаем интервал таймера
        connect(timer, &QTimer::timeout, this, & ratesdata::SendReq); // Соединяем сигнал окончания таймера и слот отправки запроса серверу
    timer -> start(1000);
}

ratesdata::~ratesdata() {
    timer -> stop();
    timer -> deleteLater();

    delete NetworkManager;
}

void ratesdata::SendReq() {
    NetworkManager -> get(request); // Отправляем запрос серверу
}

void ratesdata::slot_NetworkManager(QNetworkReply *rep) { // Преобразуем данные полученные от сервера, в двумерный массив
    rep -> waitForReadyRead(100);
    doc = QJsonDocument::fromJson(rep -> readAll(), &err);
    if (err.errorString() == "no error occurred") {
        temp = doc.object().value("BTC").toObject();
        A.replace(0,temp.value("USD").toDouble());
        A.replace(1,temp.value("EUR").toDouble());
        A.replace(2,temp.value("RUB").toDouble());
        RateData.replace(0,A);
        temp = doc.object().value("ETH").toObject();
        A.replace(0,temp.value("USD").toDouble());
        A.replace(1,temp.value("EUR").toDouble());
        A.replace(2,temp.value("RUB").toDouble());
        RateData.replace(1,A);
        temp = doc.object().value("USDT").toObject();
        A.replace(0,temp.value("USD").toDouble());
        A.replace(1,temp.value("EUR").toDouble());
        A.replace(2,temp.value("RUB").toDouble());
        RateData.replace(2,A);
        temp = doc.object().value("BNB").toObject();
        A.replace(0,temp.value("USD").toDouble());
        A.replace(1,temp.value("EUR").toDouble());
        A.replace(2,temp.value("RUB").toDouble());
        RateData.replace(3,A);
        temp = doc.object().value("USDC").toObject();
        A.replace(0,temp.value("USD").toDouble());
        A.replace(1,temp.value("EUR").toDouble());
        A.replace(2,temp.value("RUB").toDouble());
        RateData.replace(4,A);
        temp = doc.object().value("XRP").toObject();
        A.replace(0,temp.value("USD").toDouble());
        A.replace(1,temp.value("EUR").toDouble());
        A.replace(2,temp.value("RUB").toDouble());
        RateData.replace(5,A);
        temp = doc.object().value("ADA").toObject();
        A.replace(0,temp.value("USD").toDouble());
        A.replace(1,temp.value("EUR").toDouble());
        A.replace(2,temp.value("RUB").toDouble());
        RateData.replace(6,A);
        temp = doc.object().value("SOL").toObject();
        A.replace(0,temp.value("USD").toDouble());
        A.replace(1,temp.value("EUR").toDouble());
        A.replace(2,temp.value("RUB").toDouble());
        RateData.replace(7,A);
        temp = doc.object().value("NEXO").toObject();
        A.replace(0,temp.value("USD").toDouble());
        A.replace(1,temp.value("EUR").toDouble());
        A.replace(2,temp.value("RUB").toDouble());
        RateData.replace(8,A);
        temp = doc.object().value("NEAR").toObject();
        A.replace(0,temp.value("USD").toDouble());
        A.replace(1,temp.value("EUR").toDouble());
        A.replace(2,temp.value("RUB").toDouble());
        RateData.replace(9,A);
        temp = doc.object().value("DOT").toObject();
        A.replace(0,temp.value("USD").toDouble());
        A.replace(1,temp.value("EUR").toDouble());
        A.replace(2,temp.value("RUB").toDouble());
        RateData.replace(10,A);
        temp = doc.object().value("TRX").toObject();
        A.replace(0,temp.value("USD").toDouble());
        A.replace(1,temp.value("EUR").toDouble());
        A.replace(2,temp.value("RUB").toDouble());
        RateData.replace(11,A);

        emit signal(RateData);
    }
    rep -> deleteLater();
}
