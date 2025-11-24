#pragma once

#include <memory>

#include "ui.h"


class ScriptEditor : public QObject {
	Q_OBJECT
public:		
	explicit ScriptEditor(QObject* parent = nullptr)
	: QObject(parent) {
		ui_ = new Ui();
	}

	void Show() {
		ui_->show();
	}

	~ScriptEditor() override {
		ui_->~Ui();
	};

private:
	Ui* ui_;
};


