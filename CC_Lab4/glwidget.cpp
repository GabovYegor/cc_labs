#include "glwidget.h"

#include <cmath>

void glView::initializeGL() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, 0, 1);
}

void glView::resizeGL(int w, int h) { glViewport(0, 0, w, h); }
int glView::factorial(const int n){ return n < 2 ? 1 : n * factorial(n - 1); }
float glView::binomial_coff(const float n, const float k){ return factorial(n) / (factorial(k) * factorial(n - k)); }

QPointF glView::calculateBeziersCurve(const double t) {
    QPointF tempPoint;
    for (size_t i = 0; i < mainPoints.size(); i++){
        tempPoint.setX(tempPoint.x() + binomial_coff(mainPoints.size() - 1, i) *
                       pow(t, i) * pow((1 - t), (mainPoints.size() - 1 - i)) * mainPoints[i].x());
        tempPoint.setY(tempPoint.y() + binomial_coff((mainPoints.size() - 1), i) *
                       pow(t, i) * pow((1 - t), (mainPoints.size() - 1 - i)) * mainPoints[i].y());
    }
    return tempPoint;
}

void glView::drawStraightLinesBetweenMainPoints() {
    qglColor(Qt::blue);
    glLineWidth(lineWidth);
    glBegin(GL_LINE_STRIP);
    for(const auto& it: mainPoints)
        glVertex2i(it.x(), it.y());
    glEnd();
}

void glView::drawMainPoints() {
    qglColor(Qt::red);
    glPointSize(pointSize);
    glBegin(GL_POINTS);
    for(const auto& it: mainPoints)
        glVertex2i(it.x(), it.y());
    glEnd();
}

void glView::drawBeziersCurve() {
    std::vector <QPointF> beziersPoints;
    for(double t = 0.0; t <= 1.0; t += 0.01)
        beziersPoints.emplace_back(calculateBeziersCurve(t));
    qglColor(QColor(0, 0, 0));
    glBegin(GL_LINE_STRIP);
    for(const auto& i : beziersPoints)
        glVertex2i(i.x(), i.y());
    glEnd();
}

void glView::paintGL() {
    qglClearColor(QColor(230, 200, 200));
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawStraightLinesBetweenMainPoints();
    drawMainPoints();
    drawBeziersCurve();
}

bool glView::checkPointsCollision(const QPointF& lhsPoint, const QPointF& rhsPoint) {
    if( lhsPoint.x() <= rhsPoint.x() + this->pointSize &&
        lhsPoint.x() >= rhsPoint.x() - this->pointSize &&
        lhsPoint.y() <= rhsPoint.y() + this->pointSize &&
        lhsPoint.y() >= rhsPoint.y() - this->pointSize)
        return true;
    return false;
}

void glView::mouseMoveEvent(QMouseEvent* event) {
    for(auto& it: mainPoints)
        if(checkPointsCollision(event->pos(), QPointF(it.x(), it.y()))) {
            it = event->pos();
            break;
        }
    repaint();
}

void glView::mousePressEvent(QMouseEvent* event) {
    if(event->button() == Qt::LeftButton) {
        mainPoints.push_back(QPointF(event->pos()));
        repaint();
    }
}
