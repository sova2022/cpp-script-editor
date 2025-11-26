#include <QtWidgets/QApplication>

#include "script_editor.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ScriptEditor se;
    se.ConnectWidgetsSignals();
    se.InitSocket();
    se.Show();

    return app.exec();
}