#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glOrtho(0, 100, 0, 80, 0, 100);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    glVertex2d(10, 10);
    glVertex2d(40, 10);
    glEnd();


    glFlush();
}

int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowSize(700, 300);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("AAI's WINDOW");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;

}