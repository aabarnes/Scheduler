#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QPushButton>

class ColorButton : public QPushButton
{
    Q_OBJECT

public:
    explicit ColorButton(QWidget *parent = 0);

    int getColorState() { return colorState;}

public slots:
    void changeColor(int avail);

private:
    int colorState;

    // Unimplemented
    ColorButton(const ColorButton&);
};

#endif // COLORBUTTON_H
