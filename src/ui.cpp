#include "ui.h"

 Ui::Ui(QWidget* parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags) {
    SetUi();
}

const QPushButton* Ui::GetLoadBtn() {
    return loadBtn_;
}

const QPushButton* Ui::GetSaveBtn() {
    return saveBtn_;
}

QTextEdit* Ui::GetEditor() {
    return editor_;
}

void Ui::SetCurrentStatusInStatusBar(const QString& msg) {
    statusBar()->showMessage(msg);
}

void Ui::SetUi() {
    setWindowTitle(QString("%1 %2").arg(NAME_PROGRAMM, VERSION));
    setMinimumSize(QSize{ 640, 480 });
    setWindowIcon(QIcon(":/images/img/icon.ico"));

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* rightPanel = new QVBoxLayout();

    editor_  = new QTextEdit(centralWidget);
    loadBtn_ = new QPushButton("Load", centralWidget);
    saveBtn_ = new QPushButton("Save", centralWidget);

    rightPanel->addWidget(loadBtn_);
    rightPanel->addWidget(saveBtn_);
    rightPanel->addStretch();

    QHBoxLayout* mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->addWidget(editor_, 1);
    mainLayout->addLayout(rightPanel);
    mainLayout->setStretch(0, 1);

    centralWidget->setLayout(mainLayout);

    SetCurrentStatusInStatusBar("Ready");
}