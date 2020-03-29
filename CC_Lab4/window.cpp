#include "window.h"

Window::Window() {
    glWidget = new glView;
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(glWidget);
    setLayout(mainLayout);
}
