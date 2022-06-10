
#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glOrtho(0, 100, 0, 80, 0, 100);
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

    //Sky
    glColor3f(0.580f, 0.945f, 1.0f);
    squareShape(0, 80, 100, 80, 100, 60, 0, 60);

    //nature
    glColor3f(0.188, 0.592, 0.149);
    squareShape(0, 61, 75, 61, 75, 60, 0, 60);
    squareShape(0, 60, 5, 63, 10, 63, 15, 60);
    squareShape(20, 60, 25, 63, 30, 63, 35, 60);
    squareShape(40, 60, 45, 63, 50, 63, 55, 60);
    squareShape(65, 60, 70, 63, 75, 63, 80, 60);

    //river and land divider
    glColor3f(0.5f, 0.5f, 0.5f);
    squareShape(78, 60, 80, 60, 77, 55, 75, 55);
    squareShape(75, 55, 77, 55, 74, 50, 72, 50);
    squareShape(72, 50, 74, 50, 73, 48, 71, 48);
    squareShape(71, 48, 73, 48, 73, 46, 71, 46);
    squareShape(71, 46, 73, 46, 74, 44, 72, 44);
    squareShape(72, 44, 74, 44, 76, 42, 74, 42);
    squareShape(74, 42, 76, 42, 78, 40, 76, 40);
    squareShape(76, 40, 78, 40, 78, 38, 76, 38);
    squareShape(76, 38, 78, 38, 77, 36, 75, 36);
    squareShape(75, 36, 77, 36, 75, 34, 73, 34);
    squareShape(73, 34, 75, 34, 72, 30, 70, 30);
    squareShape(70, 30, 72, 30, 70, 28, 68, 28);
    squareShape(68, 28, 70, 28, 68, 26, 66, 26);
    squareShape(66, 26, 68, 26, 68, 23, 66, 23);
    squareShape(66, 23, 68, 23, 70, 20, 68, 20);
    squareShape(68, 20, 70, 20, 72, 18, 70, 18);
    squareShape(70, 18, 72, 18, 72, 16, 70, 16);
    squareShape(70, 16, 72, 16, 70, 13, 68, 13);
    squareShape(68, 13, 70, 13, 67, 10, 65, 10);
    squareShape(65, 10, 67, 10, 64, 8, 62, 8);
    squareShape(62, 8, 64, 8, 62, 6, 60, 6);
    squareShape(60, 6, 62, 6, 60, 3, 58, 3);
    squareShape(58, 3, 60, 3, 57, 0, 55, 0);

    //river water color
    glColor3f(0.741, 0.964, 1);
    squareShape(80, 60, 100, 60, 100, 50, 74, 50);
    squareShape(74, 50, 100, 50, 100, 48, 73, 48);
    squareShape(73, 48, 100, 48, 100, 46, 73, 46);
    squareShape(73, 46, 100, 46, 100, 44, 74, 44);
    squareShape(74, 44, 100, 44, 100, 42, 76, 42);
    squareShape(76, 42, 100, 42, 100, 40, 78, 40);
    squareShape(78, 40, 100, 40, 100, 38, 78, 38);
    squareShape(78, 38, 100, 38, 100, 36, 77, 36);
    squareShape(77, 36, 100, 36, 100, 34, 75, 34);
    squareShape(75, 34, 100, 34, 100, 30, 72, 30);
    squareShape(74, 32, 100, 32, 100, 28, 70, 28);
    squareShape(70, 28, 100, 28, 100, 26, 68, 26);
    squareShape(68, 26, 100, 26, 100, 23, 68, 23);
    squareShape(68, 23, 100, 23, 100, 20, 70, 20);
    squareShape(70, 20, 100, 20, 100, 18, 72, 18);
    squareShape(72, 18, 100, 18, 100, 16, 72, 16);
    squareShape(72, 16, 100, 16, 100, 13, 70, 13);
    squareShape(70, 13, 100, 13, 100, 10, 67, 10);
    squareShape(67, 10, 100, 10, 100, 8, 64, 8);
    squareShape(64, 8, 100, 8, 100, 6, 62, 6);
    squareShape(62, 6, 100, 6, 100, 3, 60, 3);
    squareShape(60, 3, 100, 3, 100, 0, 57, 0);


    //soli color
    glColor3f(0.513, 0.968, 0.470);
    squareShape(78, 60, 0, 60, 0, 50, 72, 50);
    squareShape(72, 50, 0, 50, 0, 48, 71, 48);
    squareShape(71, 48, 0, 48, 0, 46, 71, 46);
    squareShape(71, 46, 0, 46, 0, 44, 72, 44);
    squareShape(72, 44, 0, 44, 0, 42, 74, 42);
    squareShape(74, 42, 0, 42, 0, 40, 76, 40);
    squareShape(76, 40, 0, 40, 0, 38, 76, 38);
    squareShape(76, 38, 0, 38, 0, 36, 75, 36);
    squareShape(75, 36, 0, 36, 0, 34, 73, 34);
    squareShape(73, 34, 0, 34, 0, 30, 70, 30);
    squareShape(72, 32, 0, 32, 0, 28, 68, 28);
    squareShape(68, 28, 0, 28, 0, 26, 66, 26);
    squareShape(66, 26, 0, 26, 0, 23, 66, 23);
    squareShape(66, 23, 0, 23, 0, 20, 68, 20);
    squareShape(68, 20, 0, 20, 0, 18, 70, 18);
    squareShape(70, 18, 0, 18, 0, 16, 70, 16);
    squareShape(70, 16, 0, 16, 0, 13, 68, 13);
    squareShape(68, 13, 0, 13, 0, 10, 65, 10);
    squareShape(65, 10, 0, 10, 0, 8, 62, 8);
    squareShape(62, 8, 0, 8, 0, 6, 60, 6);
    squareShape(60, 6, 0, 6, 0, 3, 58, 3);
    squareShape(58, 3, 0, 3, 0, 0, 55, 0);






    glFlush();
}

int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 620);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("AAI's WINDOW");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
