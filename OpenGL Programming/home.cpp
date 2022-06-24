#include<GL/glut.h>
#include<windows.h>

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, 10, 0, 10, 0, 10);

    glMatrixMode(GL_PROJECTION);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0);

    glBegin(GL_QUADS);
    glVertex2i(6, 5);

}

void main()
{

}