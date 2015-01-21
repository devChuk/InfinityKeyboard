//! [main program]
#include <QtWidgets>
#include <QLabel>

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
//! [create background]
    window.setStyleSheet("background-image: url(/home/brian_chuk/Desktop/Projects/hackathons/InfinityKeyboard/gradientbg.jpg)"); //eh. it works...
//! [fancy title]
    QLabel* durr = new QLabel("swag");
    QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(durr);
        window.setLayout(layout);

    return app.exec();
}
//! [main program]
