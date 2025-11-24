#include <QtWidgets/QApplication>
#include <QDebug>

#include "script_editor.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ScriptEditor se;
    se.Show();

    return app.exec();
}