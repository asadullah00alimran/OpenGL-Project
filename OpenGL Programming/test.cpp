
#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glOrtho(-8, 8, -5, 5, -8, 8);
}

// double x1, y1, x2, y2, x3, y3, x4, y4;
// void squareShape(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
// {
//     glBegin(GL_QUADS);
//     glVertex2d(x1, y1);
//     glVertex2d(x2, y2);
//     glVertex2d(x3, y3);
//     glVertex2d(x4, y4);
//     glEnd();
// }
void line(double x1, double y1, double x2, double y2)
{
    glBegin(GL_LINES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glEnd();
}
void circle(double x, double y, double r)
{
    int i;
    glBegin(GL_TRIANGLE_FAN);
    for (i = 0;i < 360;i++)
    {
        x = x + cos((i * 3.14) / 180) * r;
        y = y + sin((i * 3.14) / 180) * r;
        glVertex2d(x, y);
    }
    glEnd();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    // squareShape(2.0, 2.0, 2.0, -2.0, -2.0, -2.0, -2.0, 2.0);
    // line(2, 2, 2, -2);
    // line(2, 2, 2, -2);
    // line(2, -2, -2, -2);
    // line(-2, -2, -2, 2);
    // line(-2, 2, 2, 2);
    //start
    line(0, 2.3, 0, -2.3);
    line(-2.3, 0, 2.3, 0);
    line(-1.8, 1.8, 1.8, -1.8);
    line(1.8, 1.8, -1.8, -1.8);


    glColor3f(1.0f, .0f, 0.0f);
    circle(0.0, -1.7, 0.03);





    glFlush();
}

int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("AAI's WINDOW");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
