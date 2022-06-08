#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glOrtho(0, 12, 0, 12, 0, 12);

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON); // 
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(0, 0);
    glVertex2i(2, 0);
    glVertex2i(2, 2);
    glVertex2i(0, 2);
    glVertex2i(0, 0);
    glEnd();

    // glBegin(GL_POLYGON); // 
    // glColor3f(0.0f, 0.0f, 0.0f);
    // glVertex2i(2, 0);
    // glVertex2i(4, 0);
    // glVertex2i(2, 2);
    // glVertex2i(2, 2);
    // glVertex2i(2, 0);
    // glEnd();


    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("JIDAN's HOUSE"); // name
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
