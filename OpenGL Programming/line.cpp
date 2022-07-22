#include<windows.h>
#include<GL/glut.h>

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, 20, 0, 20, 0, 20);

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2d(5, 5);
    glVertex2d(15, 15);

    glEnd();
    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Line");
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(10, 10);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}