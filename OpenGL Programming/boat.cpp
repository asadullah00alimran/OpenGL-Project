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
