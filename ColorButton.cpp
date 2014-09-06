#include "ColorButton.h"

ColorButton::ColorButton(QWidget *parent) :
    QPushButton(parent),
    colorState(0)
{

}

void ColorButton::changeColor(int avail){
    if(avail == colorState) return;

    QColor color;

    // Deterimine color
    if(avail == 1) {
        color = QColor(Qt::red);
    } else if(avail == 2) {
        color = QColor(Qt::yellow);
    } else if(avail == 3){
        color = QColor(Qt::green);
    }

    colorState = avail;

    QPalette pal;
    pal = this->palette();
    pal.setColor(QPalette::Button, color);
    setAutoFillBackground(true);
    this->setPalette(pal);
    update();
}
