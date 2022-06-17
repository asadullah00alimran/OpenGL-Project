#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static GLfloat spin = 0.0;

void spinDisplay_left(void)
{
    spin = spin + 1;
    if (spin > 360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);


    glRectf(-25.0, -25.0, 25.0, 25.0);

    glPopMatrix();

    spinDisplay_left();


    glFlush();
}



void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}


int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
