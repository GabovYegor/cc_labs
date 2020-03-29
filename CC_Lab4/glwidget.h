#ifndef GLVIEW_HPP
#define GLVIEW_HPP

#include <QGLWidget>
#include <QMouseEvent>

#include <vector>

struct glView : QGLWidget {
    Q_OBJECT
public:
    void initializeGL() override;
    void resizeGL(int w, int h)override;
    void paintGL()override;

private:
    std::vector <QPointF> mainPoints;
    void mousePressEvent(QMouseEvent* event) override;
    void drawMainPoints();
    void drawStraightLinesBetweenMainPoints();
    void BeziersCurve();
    int factorial(const int n);
    float binomial_coff(const float n, const float k);
    QPointF calculateBeziersPoint(const double t);
};

#endif // GLVIEW_HPP
