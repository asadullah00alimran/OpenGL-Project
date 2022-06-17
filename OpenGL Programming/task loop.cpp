#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>

void init()
{
    glClearColor(0.0f, 0.50f, 0.5f, 0.0f);
    glOrtho(-100, 100, -100, 100, -100, 100);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x1 = -100, y1 = 0, x2 = -90, y2 = 10;
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            glColor3f(1.0f, 0.0f, 1.0f);
            glRectf(x1, y1, x2, y2);
            x1 = x1 + 10;
            x2 = x2 + 10;
        }
        else             //original code
        {
            glColor3f(1.0f, 1.0f, 0.0f);
            glRectf(x1, y1, x2, y2);
            x1 = x1 + 10;
            x2 = x2 + 10;
        }
    }
    glFlush();
}
int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("DEMO");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
