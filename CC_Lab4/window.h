#ifndef WINDOW_H
#define WINDOW_H

#include "glwidget.h"

#include <QWidget>

class Window : public QWidget {
    Q_OBJECT

public:
    Window();
    glView *glWidget;
private:
    void keyPressEvent(QKeyEvent *e);
};

#endif
