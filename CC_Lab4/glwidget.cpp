#include "glwidget.h"

void glView::initializeGL() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, 0, 1);
}

void glView::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void glView::paintGL() {
    qglClearColor(Qt::darkCyan);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_POLYGON);
    qglColor(Qt::red);
    glVertex2i(200, 200);
    qglColor(Qt::blue);
    glVertex2i(100, 300);
    qglColor(Qt::green);
    glVertex2i(400, 400);
    qglColor(Qt::red);
    glVertex2i(500, 100);
    qglColor(Qt::blue);
    glVertex2i(200, 400);
    qglColor(Qt::green);
    glVertex2i(500, 500);
    glEnd();
}
