
#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glOrtho(-21, 21, -16, 16, -21, 21);
}

//Square Shape
void squareShape(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    glBegin(GL_QUADS);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glVertex2d(x3, y3);
    glVertex2d(x4, y4);
    glEnd();
}

//Triangle Shape
void triangleShape(double x1, double y1, double x2, double y2, double x3, double y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glVertex2d(x3, y3);
    glEnd();
}
//Line
void line(double x1, double y1, double x2, double y2)
{
    glBegin(GL_LINES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glEnd();
}
//Circle
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

//Display Function

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Shed
    glColor3f(1.0f, 0.0f, 0.0f);
    triangleShape(0.0, 4.5, 5.5, 0.0, -5.5, 0.0);

    //Body
    glColor3f(1.0f, 0.5f, 0.0f);
    squareShape(4.5, 0.0, 4.5, -6.0, -4.5, -6.0, -4.5, 0.0);

    //Door
    glColor3f(0.5f, 0.5f, 0.0f);
    squareShape(1.0, -2.0, 1.0, -6.0, -1.0, -6.0, -1.0, -2.0);

    //Left window
    glColor3f(0.5f, 0.5f, 0.5f);
    squareShape(-2.0, -2.8, -2.0, -4.8, -3.2, -4.8, -3.2, -2.8);
    //Grill
    glColor3f(0.0f, 0.0f, 0.0f);
    line(-2.3, -2.8, -2.3, -4.8);
    line(-2.6, -2.8, -2.6, -4.8);
    line(-2.9, -2.8, -2.9, -4.8);
    line(-2.0, -3.8, -3.2, -3.8);

    //Right window
    glColor3f(0.5f, 0.5f, 0.5f);
    squareShape(2.0, -2.8, 2.0, -4.8, 3.2, -4.8, 3.2, -2.8);
    //grill
    glColor3f(0.0f, 0.0f, 0.0f);
    line(2.3, -2.8, 2.3, -4.8);
    line(2.6, -2.8, 2.6, -4.8);
    line(2.9, -2.8, 2.9, -4.8);
    line(2.0, -3.8, 3.2, -3.8);

    //Pira
    glColor3f(0.5f, 0.5f, 0.7f);
    squareShape(5.0, -6.0, 5.0, -6.5, -5.0, -6.0, -5.0, -6.5);

    //sun
    glColor3f(1.0f, 0.0f, 0.0f);
    line(-18.8, 14.8, -15.2, 11.2);
    line(-15.2, 14.8, -18.8, 11.2);
    line(-19.5, 13.0, -14.5, 13.0);
    line(-17.0, 15.5, -17, 10.5);
    circle(-17, 11.3, 0.03);

    //Cloud
    glColor3f(0.5f, 0.5f, 0.5f);
    circle(-8, 9.3, 0.03);
    circle(-5.5, 9.3, 0.03);
    circle(-6.5, 10.8, 0.03);

    //Rain
    glColor3f(0.5f, 0.5f, 0.5f);
    line(-9.0, 9.0, -9, 8);
    line(-7.8, 9.0, -7.8, 8);
    line(-6.5, 9.0, -6.5, 8);
    line(-5.2, 9.0, -5.2, 8);
    line(-8.4, 8.5, -8.4, 6.5);
    line(-7.2, 8.5, -7.2, 6.5);
    line(-6, 8.5, -6, 6.5);
    line(-4.6, 8.5, -4.6, 6.5);



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
