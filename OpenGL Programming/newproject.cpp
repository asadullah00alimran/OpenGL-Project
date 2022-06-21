#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>

static float cloud1 = -20, ty = 0;
static float shift = 0;

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

void cloud(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    int i = 0;
    float angle;
    GLfloat PI = 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (i = 0;i < 100;i++)
    {
        angle = 2 * PI * i / 100;
        glVertex2f(x + (cos(angle) * rx), y + (sin(angle) * ry));
    }
    glEnd();
}

void cloudMove()
{
    cloud1 += .03;
    if (cloud1 > 200) {
        cloud1 = -20;
    }
    glutPostRedisplay();
}
void movingCloud()
{
    glColor3f(1, 1, 1);
    cloudMove();
    glPushMatrix();
    glTranslatef(cloud1, -15, 0);
    cloud(3, 5, 5, 88);
    cloud(3, 5, 8, 91);
    cloud(3, 5, 12, 92);
    cloud(3, 5, 12, 87);
    cloud(3, 5, 7, 85);
    glPopMatrix();
}
void boatMove()
{
    shift += 0.01;
    shift = (shift > 200) ? 0 : shift;
    glutPostRedisplay();
}

//Display Function

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Sky
    glColor3f(0.580f, 0.945f, 1.0f);
    squareShape(0, 80, 100, 80, 100, 60, 0, 60);
    //sun
    glColor3f(1.0, 0.0, 0.0);
    circle(60, 60, 0.1);
    line(60, 64, 54, 70.5);
    line(60, 64, 54, 73);
    line(60, 64, 56, 74);
    line(60, 64, 58, 74);
    line(60, 64, 60, 75);
    line(60, 64, 62, 74);
    line(60, 64, 64, 73);
    line(60, 64, 66.5, 72);
    line(60, 64, 68, 70);
    line(60, 64, 68, 68);


    //nature
    glColor3f(0.188, 0.592, 0.149);
    squareShape(0, 61, 75, 61, 75, 60, 0, 60);
    squareShape(0, 60, 5, 63, 10, 63, 15, 60);
    squareShape(20, 60, 25, 63, 30, 63, 35, 60);
    squareShape(40, 60, 45, 63, 50, 63, 55, 60);
    squareShape(65, 60, 70, 63, 75, 63, 80, 60);

    // hill
    glColor3f(0.188, 0.592, 0.149);
    triangleShape(42, 60, 58, 60, 50, 74);
    triangleShape(46, 60, 62, 60, 54, 70);
    triangleShape(49, 60, 65, 60, 59, 66);
    triangleShape(58, 60, 75, 60, 70, 68);

    //Cloud Moving
    movingCloud();


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



    //tree
    glColor3f(0.380, 0.141, 0.149);
    squareShape(18, 39, 18, 42, 23, 42, 23, 39);
    squareShape(18, 42, 16, 45, 17.6, 46.5, 21, 42);
    squareShape(21, 42, 24, 46.5, 26, 46, 23, 42);
    glColor3f(0.188, 0.592, 0.149);
    circle(16, 43, 0.09);
    circle(26, 42, 0.09);
    circle(22, 47, 0.09);

    // Back side House
    //shed
    glColor3f(0.4, 0.3, 0.4);
    squareShape(9, 36, 14, 39, 17, 37, 16, 36);
    glColor3f(1, 0.0, 0.1);
    triangleShape(14, 39, 19, 39, 17, 37);
    triangleShape(9, 36, 14, 39, 14.5, 38.5);
    glColor3f(0, 0, 0);
    squareShape(11, 30, 17, 29, 18, 28, 9, 29);
    glColor3f(1, 0, 0);
    squareShape(11, 36, 17, 36, 17, 29, 11, 30);
    glColor3f(0, 0, 0);
    squareShape(10, 30, 17, 29, 18, 28, 9, 29);
    glColor3f(.1, .1, .8);
    squareShape(12.5, 34.5, 15, 34, 15, 31.5, 12.5, 32);
    //grill
    glColor3f(1.0, 1.0, 1.0);
    line(12.5, 33.25, 15, 32.75);
    line(13.25, 34.5, 13.25, 31.75);
    line(14.25, 34.25, 14.25, 31.50);





    // glBegin(GL_POLYGON);
    // glVertex2d(23, 45);
    // glVertex2d(25, 45);
    // glVertex2d(27, 42);
    // glVertex2d(28, 45);
    // glVertex2d(30, 45);
    // glVertex2d(28, 40);
    // glVertex2d(25, 40);
    // glVertex2d(23, 45);


    // front House
    //Front Side
    glColor3f(0.956, 0.933, 0.121);
    squareShape(25, 35, 38, 35, 38, 27, 25, 27);
    //down  part
    glColor3f(.5, .5, .5);
    squareShape(25, 27, 38, 27, 39, 26, 25, 26);
    squareShape(25, 27, 17, 29, 16, 28, 25, 26);

    //left side
    glColor3f(0.956, 0.933, 0.121);
    squareShape(17, 36.5, 17, 29, 25, 27, 25, 35);
    //piller
    glColor3f(0, 0, 0);
    line(25, 35, 25, 27);
    //r-piller
    glColor3f(0, 0, 0);
    line(38, 35, 38, 27);
    //Shed
    glColor3f(0.756, 0.023, 0.047);
    squareShape(20, 40, 35, 40, 41, 34, 26, 34);
    //Shed left
    triangleShape(15, 35, 20, 40, 21, 39);
    //Shed shadow
    glColor3f(0.380, 0.141, 0.149);
    triangleShape(17, 36.5, 21, 39, 25, 35);
    //window-big
    glColor3f(0, 0, 0);
    squareShape(19, 34, 23, 33, 23, 30, 19, 31);
    //window small-left
    squareShape(26.5, 31, 28.5, 31, 28.5, 28.5, 26.5, 28.5);
    //window small-right
    squareShape(35, 31, 37, 31, 37, 28.5, 35, 28.5);

    //Grill
    glColor3f(1, 1, 1);
    line(19, 32.5, 23, 31.5);
    line(20, 30.5, 20, 34);
    line(21, 30.5, 21, 33.5);
    line(22, 30, 22, 33.5);
    //door
    glColor3f(0, 0, 0);
    squareShape(30, 32, 33, 32, 33, 27, 30, 27);
    glColor3f(1, 1, 1);
    line(31.5, 32, 31.5, 27);




    glColor3f(0.3, 0.3, 1);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0, 18);
    glVertex2f(150, 18);
    glVertex2f(150, 0);

    glEnd();

    glPushMatrix();


    // we want to draw moving boat
    boatMove();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(45 + shift, 20);
    glVertex2f(5 + shift, 20);
    glVertex2f(15 + shift, 10);
    glVertex2f(35 + shift, 10);

    glEnd();



    glColor3f(0.160, 0.658, 0.203);
    glBegin(GL_POLYGON);
    glVertex2f(25 + shift, 30);
    glVertex2f(25 + shift, 25);
    glVertex2f(17.943 + shift, 25.019);

    glEnd();


    // fourth regular shape is octagon
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(25 + shift, 25.0);
    glVertex2f(25 + shift, 20);
    glVertex2f(23 + shift, 20);
    glVertex2f(23 + shift, 25);

    glEnd();

    glPopMatrix();




    glFlush();
}

int main(int argc, char** argv)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("AAI's WINDOW");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}