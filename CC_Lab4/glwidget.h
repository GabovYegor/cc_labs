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
    GLfloat pointSize = 20;
    GLfloat lineWidth = 10;

    std::vector <QPointF> mainPoints;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    bool checkPointsCollision(const QPointF& p1, const QPointF& p2);
    void drawMainPoints();
    void drawStraightLinesBetweenMainPoints();
    void drawBeziersCurve();
    int factorial(const int n);
    float binomial_coff(const float n, const float k);
    QPointF calculateBeziersCurve(const double t);
};

#endif // GLVIEW_HPP
