#include "script_editor.h"

ScriptEditor::ScriptEditor(QObject* parent)
	: QObject(parent)
	, ui_(new Ui()) 
	, server_(new UdpFileServer(this)) {

	server_->InitSocket();
}

ScriptEditor::~ScriptEditor() {
	ui_->~Ui();
};

void ScriptEditor::ConnectWidgetsSignals() {
	connect(ui_->GetSaveBtn(), &QPushButton::clicked, this, &ScriptEditor::onSave);
	connect(ui_->GetLoadBtn(), &QPushButton::clicked, this, &ScriptEditor::onLoad);
	connect(server_, &UdpFileServer::datagramRecived, this, &ScriptEditor::onDatagramRecieved);
}

void ScriptEditor::Show() {
	ui_->show();
}

void ScriptEditor::onSave() {
	if (currentFile_.isEmpty()) {
		QString fn = QFileDialog::getSaveFileName(
			ui_,
			"Save script",
			"./scripts",
			"Script files (*.qs)"
		);

		if (fn.isEmpty()) {
			return;
		}

		currentFile_ = fn;
	}

	QFile f(currentFile_);
	if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) {
		QMessageBox::warning(ui_, "Error", "Cannot save file");
		return;
	}

	QTextStream out(&f);
	out << ui_->GetEditor()->toPlainText();

	ui_->GetEditor()->document()->setModified(false);
	ui_->SetCurrentStatusInStatusBar("File has been saved");
}

void ScriptEditor::onLoad() {
	if (IsScriptModified()) {
		if (!onUnsavedChanges()) {
			return;
		}
	}

	QString fn = QFileDialog::getOpenFileName(ui_, "Load script", "./scripts", "Script files (*.qs)");
	if (fn.isEmpty()) {
		return;
	}

	QFile f(fn);
	if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QMessageBox::warning(ui_, "Error", "Cannot open file");
		return;
	}

	ui_->GetEditor()->setPlainText(f.readAll());
	ui_->SetCurrentStatusInStatusBar("File has been loaded");

	currentFile_ = fn;
}

bool ScriptEditor::onUnsavedChanges() {
	auto ret = QMessageBox::warning(
		ui_,
		"Unsaved Changes",
		"The current file has unsaved changes. Do you want to save before loading a new file?",
		QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
	);

	switch (ret) {
	case QMessageBox::Cancel:
		return false;

	case QMessageBox::Yes:
		onSave();
		return true;

	case QMessageBox::No:
		return true;
	}

	return true;
}

void ScriptEditor::onDatagramRecieved(const QNetworkDatagram datagram) {
	qDebug() << "Received UDP datagram:";
	qDebug() << "  From:" << datagram.senderAddress().toString() << ":" << datagram.senderPort();
	qDebug() << "  Data:" << datagram.data();
}

bool ScriptEditor::IsScriptModified() {
	return ui_->GetEditor()->document()->isModified();
}