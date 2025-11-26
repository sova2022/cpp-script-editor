#pragma once

#include <QFile>
#include <QFileDialog>

#include "ui.h"
#include "udp_file_server.h"

/**
 * @brief Основной контроллер логики редактора скриптов.
 *
 * Управляет интерфейсом, обработкой изменений текста,
 * загрузкой и сохранением файлов, а также взаимодействием
 * с UDP-сервером.
 */
class ScriptEditor : public QObject {
	Q_OBJECT
public:		
	explicit ScriptEditor(QObject* parent = nullptr);

	~ScriptEditor() override;

	void ConnectWidgetsSignals();

	/**
	 * @brief Инициализирует UDP-сервер.
	 */
	void InitSocket();

	/**
	 * @brief Показывает главное окно приложения.
	 */
	void Show();

public slots:

	/**
	 * @brief Сохраняет текущий скрипт в файл.
	 */
	void onSave();

	/**
	 * @brief Загружает скрипт из файла.
	 */
	void onLoad();

	/**
	 * @brief Вызывается при изменении текста в редакторе.
	 */
	void onScriptModified();

private slots:

	/**
	 * @brief Проверяет наличие несохранённых изменений.
	 * @return true — если пользователь подтвердил действие.
	 */
	bool onUnsavedChanges();


	/**
	 * @brief Вызывается при запросе файла через UDP.
	 */
	void onFileRequest();

private:
	Ui* ui_;
	UdpFileServer* server_;
	QString currentFile_;

	/**
	 * @brief Проверяет, был ли изменён текст скрипта.
	 * @return true, если текст изменён.
	 */
	bool IsScriptModified();
};