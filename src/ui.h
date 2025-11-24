#pragma once

#include <QtWidgets/QMainWindow>
#include <QDebug>

class Ui : public QMainWindow {
    Q_OBJECT 
public:
    explicit Ui(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())
        : QMainWindow(parent, flags) {

    }

    ~Ui() override {
        qDebug() << "ui destructed";
    };

    void SetUi() {

    }

};