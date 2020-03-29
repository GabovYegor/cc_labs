#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtGui>
#include <QHBoxLayout>

#include "glwidget.h"

class Window : public QWidget {
    Q_OBJECT

public:
    Window();
    glView *glWidget;
};

#endif
