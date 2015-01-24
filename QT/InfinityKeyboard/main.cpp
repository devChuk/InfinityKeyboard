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
//!
    QString labelText = "<P><b><i><FONT COLOR='#ff0000' FONT SIZE = 4>";
    labelText.append("The Infinity Keyboard");
    labelText.append("</i></b></P></br>");
    QLabel* label = new QLabel();
    label->setText(labelText);
    //QLabel* durr = new QLabel("The Infinity Keyboard");
    QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(label);
        window.setLayout(layout);

    return app.exec();
}
//! [main program]
