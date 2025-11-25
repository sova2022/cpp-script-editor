#pragma once

#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QStatusBar>
#include <QVBoxLayout>

const QString NAME_PROGRAMM = "Script Editor";
const QString VERSION = "ver. 1.0.0";

class Ui : public QMainWindow {
    Q_OBJECT 
public:
    explicit Ui(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    ~Ui() override = default;

    const QPushButton* GetLoadBtn();
    const QPushButton* GetSaveBtn();
    const QTextEdit* GetEditor();    

private:
    QTextEdit* editor_    = nullptr;
    QPushButton* saveBtn_ = nullptr;
    QPushButton* loadBtn_ = nullptr;

    void SetUi();
};