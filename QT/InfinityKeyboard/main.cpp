//! [main program]
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//! [create, resize and show]
    QWidget window;
    window.resize(1920, 1080);
    window.show();
//! [create, resize and show]
    window.setWindowTitle(
        QApplication::translate("toplevel", "Infinity Keyboard"));
    return app.exec();
}
//! [main program]
