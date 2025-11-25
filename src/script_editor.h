#pragma once

#include <QFile>
#include <QFileDialog>

#include "ui.h"
#include "udp_file_server.h"

class ScriptEditor : public QObject {
	Q_OBJECT
public:		
	explicit ScriptEditor(QObject* parent = nullptr);

	~ScriptEditor() override;

	void ConnectWidgetsSignals();
	void Show();

public slots:
	void onSave();
	void onLoad();

private slots:
	bool onUnsavedChanges();
	void onFileRequest();

private:
	Ui* ui_;
	UdpFileServer* server_;
	QString currentFile_;

	bool IsScriptModified();
};