//! [main program]
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//! [create, resize and show]
    QWidget window;
    window.resize(1920, 1080);
    window.show();
//! [create, resize]
    window.setWindowTitle(
        QApplication::translate("toplevel", "Infinity Keyboard"));

    window.setStyleSheet("background-image: url(/home/brian_chuk/Desktop/Projects/hackathons/InfinityKeyboard/gradientbg.jpg)"); //it works.

    return app.exec();
}
//! [main program]
