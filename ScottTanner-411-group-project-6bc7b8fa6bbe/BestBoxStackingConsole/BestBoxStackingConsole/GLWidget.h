#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <gl/GLU.h>

class GLWidget : public QGLWidget
{
	Q_OBJECT
public:
	explicit GLWidget(QWidget *parent = 0);
	void initializeGL();
	void paintGL();
	void resize(int w, int h);
	void drawCube(float size = 1);
private:
	float angle = 45.0;
};

#endif // !GLWIDGET_H