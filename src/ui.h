#pragma once

#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QStatusBar>
#include <QVBoxLayout>

const QString NAME_PROGRAMM = "Script Editor";
const QString VERSION = "ver. 1.0.0";

/**
 * @brief Главное окно графического интерфейса Script Editor.
 *
 * Отвечает за создание и размещение элементов интерфейса:
 * редактора текста, кнопок загрузки/сохранения и строки состояния.
 */
class Ui : public QMainWindow {
    Q_OBJECT
public:
    explicit Ui(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

    ~Ui() override = default;

    const QPushButton* GetLoadBtn();
    const QPushButton* GetSaveBtn();
    QTextEdit* GetEditor();
    void SetCurrentStatusInStatusBar(const QString& msg);

private:
    QTextEdit* editor_ = nullptr;
    QPushButton* saveBtn_ = nullptr;
    QPushButton* loadBtn_ = nullptr;

    /**
     * @brief Инициализация виджетов и их размещение.
     */
    void SetUi();
};