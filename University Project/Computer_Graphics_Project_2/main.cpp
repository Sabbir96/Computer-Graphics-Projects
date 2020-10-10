#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>
#include <GL/gl.h>
#define PI 2*acos(0.0)

using namespace std;

void display();
void drawQuad(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
void drawQuadGradient(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
void drawLine(GLfloat, GLfloat, GLfloat, GLfloat);
void drawTriangle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
void drawCircle(GLfloat,GLfloat,GLfloat);
void drawQuadGradient3ub(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3,GLfloat r,GLfloat g,GLfloat b);

void pressKey(unsigned char, int, int );
bool day=true;
bool secondScene=true;
bool isCar=false;
bool isMan=false;
bool trafficGreen = true;
bool trafficRed = false;
//bool isCar1=false;

GLfloat sunPosition = 0.2f;
GLfloat sunSpeed = 0.0035f;
GLfloat moonPosition=0.0002f;
GLfloat moonSpeed=0.0044f;
GLfloat carPosition = 1.0f;
GLfloat carSpeed = 0.0095f;
GLfloat carPosition1 = -1.0f;
//GLfloat carSpeed = 0.0095f;
void pressKey(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'l':
        isCar=false;
        break;
    case 'x':
        isCar=true;
        break;
    case 'r':
        carSpeed=0.0;
        trafficRed=true;
        trafficGreen=false;

        break;
    case 'g':
        carSpeed=0.0075f;
        trafficRed=false;
        trafficGreen=true;

        break;
    case 'c':
        PostQuitMessage(0);
        break;
        glutPostRedisplay();
    }
}
void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        carSpeed += 0.01f;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        carSpeed -= 0.01f;
    }
    glutPostRedisplay();
}

void parkSky(bool day)
{
    if(day==true)
    {
        glLoadIdentity();
        glColor3f(0.5,1,1);
        drawQuadGradient3ub(3,23,1,0.3,-1,0.3,-1,1, 255,255,224);
    }
    else
    {

        glPushMatrix();

        glColor3ub(95,95,95);
        drawQuadGradient3ub(3,23,1,0.3,-1,0.3,-1,1,1,1,1);
        glPopMatrix();
    }
}

void parkroad(bool day)
{
    if(day==true)
    {
        glColor3f(0.128,0.128,0.128);
        drawQuad(-1,-0.3,1,-0.3, 1,0.1,-1, 0.1);//road
        glColor3ub(128,128,128);
        drawQuad(-1,-0.3, -1,-0.4, 1,-0.4, 1,-0.3);//roadside
        glColor3ub(128,128,128);
        drawQuad(-1,0.1, -1,0.2, 1,0.2, 1,0.1);//roadside
        glColor3f(1,1,1);
        drawQuad(-0.95,-0.08,-0.95,-0.12, -0.65,-0.12, -0.65,-0.08); //white1
        float x=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08);
        x+=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08);
        x+=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08);
        x+=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08); //white5
        glColor3ub(255,215,0);
        drawQuadGradient3ub(-1,0.35,-1,0.2, 1,0.2,1,0.6,50,205,50);

        //Fench
        glColor3ub(0,0,0);
        drawQuad(-1,0.36,1,0.6,   1,0.61,-1,0.35);
        drawQuad(-1,0.42,-1,0.41,1,0.67,1,0.66);
        drawLine(-0.9,0.43,-0.9,0.36);
        drawLine(-0.7,0.45,-0.7,0.39);
        drawLine(-0.5,0.47,-0.5,0.42);
        drawLine(-0.3,0.50,-0.3,0.44);
        drawLine(-0.09,0.53,-0.09,0.47);
        drawLine(0.4,0.59,0.4,0.53);
        drawLine(0.65,0.62,0.65,0.56);
        drawLine(0.9,0.65,0.9,0.59);

    }
    else
    {
        glPushMatrix();
        glColor3f(0.128,0.128,0.128);
        drawQuad(-1,-0.3,1,-0.3, 1,0.1,-1, 0.1);//road
        glColor3ub(255,255,0);
        drawQuad(-1,-0.3, -1,-0.4, 1,-0.4, 1,-0.3);//roadside
        glColor3ub(255,255,0);
        drawQuad(-1,0.1, -1,0.2, 1,0.2, 1,0.1);//roadside
        glColor3f(1,1,1);
        drawQuad(-0.95,-0.08,-0.95,-0.12, -0.65,-0.12, -0.65,-0.08); //white1
        float x=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08);
        x+=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08);
        x+=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08);
        x+=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08); //white5
        glPopMatrix();

        glPushMatrix();
        glEnable(GL_LIGHTING);
        GLfloat global_ambient[] = {1.2,1.2,0.9, 0.9};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

        glColor3ub(184,134,11);
        drawQuadGradient3ub(-1,0.35,-1,0.2, 1,0.2,1,0.6,184,134,11);
        glDisable(GL_LIGHTING);
        glPopMatrix();

    }
}
void zebraCrossing()
{
    glColor3f(1,1,1);
    float y=-0.05;
    drawQuad(0.20,0.1+y, 0.03,0.1+y, 0.03,0.11+y,0.20,0.11+y);
    y-=0.05;
    drawQuad(0.20,0.1+y, 0.03,0.1+y, 0.03,0.11+y,0.20,0.11+y);
    y-=0.05;
    drawQuad(0.20,0.1+y, 0.03,0.1+y, 0.03,0.11+y,0.20,0.11+y);
    y-=0.05;
    drawQuad(0.20,0.1+y, 0.03,0.1+y, 0.03,0.11+y,0.20,0.11+y);
    y-=0.05;
    drawQuad(0.20,0.1+y, 0.03,0.1+y, 0.03,0.11+y,0.20,0.11+y);
    y-=0.05;
    drawQuad(0.20,0.1+y, 0.03,0.1+y, 0.03,0.11+y,0.20,0.11+y);
    y-=0.05;
    drawQuad(0.20,0.1+y, 0.03,0.1+y, 0.03,0.11+y,0.20,0.11+y);
    y-=0.05;
    drawQuad(0.20,0.1+y, 0.03,0.1+y, 0.03,0.11+y,0.20,0.11+y);


}
void traffic()
{

    if(day==true)
    {
        glColor3f(0.211,0.211,0.211);
        drawQuad(0.15,0.1, 0.1,0.1, 0.1,0.15,0.15,0.15);
        drawQuad(0.13,0.15, 0.115,0.15, 0.115,0.3,0.13,0.3);
        glColor3f(0,0,0);
        drawQuad(0.18,0.3, 0.08,0.3, 0.08,0.45,0.18,0.45);
        if(trafficGreen == true)
        {
            glColor3f(0,1,0);
        }
        else
        {
            glColor3f(0.192,0.192,0.192);
        }
        //glColor3f(0.192,0.192,0.192);
        drawCircle(0.125, 0.41, 0.025);
        if(trafficRed == true)
        {
            glColor3f(1,0,0);
        }
        else
        {
            glColor3f(0.192,0.192,0.192);
        }
        drawCircle(0.125, 0.35, 0.025);

    }
    else
    {

        glColor3f(0.211,0.211,0.211);
        drawQuad(0.15,0.1, 0.1,0.1, 0.1,0.15,0.15,0.15);
        drawQuad(0.13,0.15, 0.115,0.15, 0.115,0.3,0.13,0.3);
        glColor3f(0,0,0);
        drawQuad(0.18,0.3, 0.08,0.3, 0.08,0.45,0.18,0.45);
        if(trafficGreen == true)
        {
            glColor3f(0,1,0);
        }
        else
        {
            glColor3f(0.192,0.192,0.192);
        }
        //glColor3f(0.192,0.192,0.192);
        drawCircle(0.125, 0.41, 0.025);
        if(trafficRed == true)
        {
            glColor3f(1,0,0);
        }
        else
        {
            glColor3f(0.192,0.192,0.192);
        }
        drawCircle(0.125, 0.35, 0.025);
    }
}

void drawQuadGradient3ub(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3,GLfloat r,GLfloat g,GLfloat b)
{
    glBegin(GL_QUADS);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glColor3ub(r,g,b);

    glVertex2f(x2,y2);

    glVertex2f(x3,y3);

    glEnd();
}

void drawRectangle(GLdouble x, GLdouble y, GLdouble w, GLdouble h)
{
    glBegin(GL_QUADS);

    glVertex2f(x, y);
    glVertex2f(x, y + h);
    glVertex2f(x - w, y + h);
    glVertex2f(x - w, y);

    glEnd();
}

void DayUpdate(int value)
{
    glutPostRedisplay();
    glutTimerFunc(4100, DayUpdate, 0);
    if(day==true)
    {
        day=false;
    }
    else
    {
        day=true;
    }
}

void SunUpdate(int value)
{
    if(day==true )
    {
        sunPosition=sunPosition-sunSpeed;
    }
    else
    {
        sunPosition=0.2f;
    }

    glutPostRedisplay();

    glutTimerFunc(1800/60, SunUpdate, 0);

}
void MoonUpdate(int value)
{
    if(day==false )
    {
        moonPosition=moonPosition-moonSpeed;
    }
    else
    {
        moonPosition=0.2f;
    }

    glutPostRedisplay();

    glutTimerFunc(2000/60, MoonUpdate, 0);

}
void CarUpdate (int value)
{

    if(carPosition < -1.71)
    {
        carPosition = 1.0f;
    }

    if(carPosition>1.31)
    {
        carPosition=-1.0;
    }
    if(isCar==true)
    {
        carPosition += carSpeed;
    }
    else
    {
        carPosition-=carSpeed;
    }

    glutPostRedisplay();


    glutTimerFunc(1000/60, CarUpdate, 0);
}


void drawCircle(GLfloat x,GLfloat y,GLfloat radius)
{
    int i;
    int lineAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    //glColor3ub(255, 0, 191);
    for(i = 0; i <= lineAmount; i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / lineAmount)),y + (radius* sin(i * twicePi / lineAmount)));

    }
    glEnd();
}



void drawQuad(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3)
{
    glBegin(GL_QUADS);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glVertex2f(x2,y2);

    glVertex2f(x3,y3);

    glEnd();
}
void drawQuadGradient(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3,GLfloat r,GLfloat g,GLfloat b)
{

    glBegin(GL_QUADS);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glColor3f(r,g,b);

    glVertex2f(x2,y2);

    glVertex2f(x3,y3);


    glEnd();
}


void drawLine(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1)
{
    glBegin(GL_LINES);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glEnd();
}


void drawTriangle(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
    glBegin(GL_TRIANGLES);

    glVertex2f(x0,y0);

    glVertex2f(x1,y1);

    glVertex2f(x2,y2);

    glEnd();
}
void parkGrass()
{
    glColor3ub(0,159,225);
    drawQuadGradient(-1,-0.4,1,-0.4,1,-1,-1,-1,1,1,1);//

    //drawQuad(-1,-0.4,1,-0.4,1,-1,-1,-1);

}

void tree1(bool day)
{

    if(day==true)
    {
        glPushMatrix();
        glScalef(0.7,0.7,0);
        glTranslatef(1.1,1.29,0);
        //tree1
        glColor3ub(97, 29, 30);
        drawQuad(-0.7,-0.5, -0.7,-0.7, -0.65,-0.7, -0.65,-0.5);  //tree wood
        drawQuad(-0.8,-0.35, -0.7,-0.5, -0.65,-0.5, -0.75,-0.3);
        drawQuad(-0.60,-0.3, -0.68,-0.45, -0.65,-0.5, -0.58,-0.35);

        glColor3ub( 34,139,34);  //tree leaf
        drawCircle(-0.77,-0.3,0.15);
        drawCircle(-0.59,-0.3,0.15);
        drawCircle(-0.67,-0.2,0.2);
        glPopMatrix();
    }
    else
    {

        glPushMatrix();
        glScalef(0.7,0.7,0);
        glTranslatef(1.1,1.29,0);
        //tree1
        glEnable(GL_LIGHTING);
        GLfloat global_ambient[] = {0.8,0.2,0.3, 0.1};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
        glColor3ub(97, 29, 30);
        drawQuad(-0.7,-0.5, -0.7,-0.7, -0.65,-0.7, -0.65,-0.5);  //tree wood
        drawQuad(-0.8,-0.35, -0.7,-0.5, -0.65,-0.5, -0.75,-0.3);
        drawQuad(-0.60,-0.3, -0.68,-0.45, -0.65,-0.5, -0.58,-0.35);
        glDisable(GL_LIGHTING);

        GLfloat global_ambient1[] = {0.42,1.22,0.59, 0.1};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);
        glEnable(GL_LIGHTING);
        glColor3ub(42, 122, 59);
        drawCircle(-0.77,-0.3,0.15);
        drawCircle(-0.59,-0.3,0.15);
        drawCircle(-0.67,-0.2,0.2);
        glDisable(GL_LIGHTING);
        glPopMatrix();
    }
}
void tree2(bool day)
{
    if(day==true)
    {
        glPushMatrix();
        glScalef(1,0.5,0);
        glTranslatef(0.25,1.6,0);
        //tree1
        glColor3ub(97, 29, 30);
        drawQuad(-0.7,-0.5, -0.7,-0.9, -0.65,-0.9, -0.65,-0.5);
        drawQuad(-0.8,-0.35, -0.7,-0.5, -0.65,-0.5, -0.75,-0.3);
        drawQuad(-0.60,-0.3, -0.68,-0.45, -0.65,-0.5, -0.58,-0.35);

        glColor3ub(34,139,34);
        drawCircle(-0.77,-0.3,0.15);
        drawCircle(-0.59,-0.3,0.15);
        drawCircle(-0.67,-0.2,0.2);
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
        glScalef(1,0.5,0);
        glTranslatef(0.25,1.6,0);
        glEnable(GL_LIGHTING);
        GLfloat global_ambient[] = {0.8,0.2,0.3, 0.1};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
        glColor3ub(97, 29, 30);
        drawQuad(-0.7,-0.5, -0.7,-0.9, -0.65,-0.9, -0.65,-0.5);
        drawQuad(-0.8,-0.35, -0.7,-0.5, -0.65,-0.5, -0.75,-0.3);
        drawQuad(-0.60,-0.3, -0.68,-0.45, -0.65,-0.5, -0.58,-0.35);
        glDisable(GL_LIGHTING);

        GLfloat global_ambient1[] = {0.42,1.22,0.59, 0.1};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);
        glEnable(GL_LIGHTING);
        glColor3ub(42, 122, 59);
        drawCircle(-0.77,-0.3,0.15);
        drawCircle(-0.59,-0.3,0.15);
        drawCircle(-0.67,-0.2,0.2);
        glDisable(GL_LIGHTING);
        glPopMatrix();
    }
}

void windows(GLfloat x,GLfloat y,GLfloat z,bool day)
{
    glPushMatrix();
    glScalef(0.8,0.8,0.0);
    glTranslatef(x,y,z);


    if(day==true)
    {
        glColor3ub(179, 230, 255);
    }
    else
    {
        glColor3ub(255, 191, 0);
    }
    drawQuad(0.10,0.6,0.0,0.6,0.0,0.45,0.10,0.45);
    glColor3ub(0, 0, 0);
    drawQuad(0.12,0.45,-0.02,0.45,-0.02,0.43,0.12,0.43);
    drawQuad(0.12,0.45+0.15,-0.02,0.45+0.15,-0.02,0.43+0.15,0.12,0.43+0.15);
    glPopMatrix();
}

void dayView()
{

    parkSky(day);

    glPushMatrix();
    glTranslatef(-1.4,sunPosition,0.0);
    glColor3ub(255,215,0);
    drawCircle(0.7,0.9,0.11);
    glPopMatrix();

    parkroad(day);
    traffic();
    zebraCrossing();
    parkGrass();
    tree1(day);
    tree2(day);


}


void nightView()
{

    parkSky(day);
    glPushMatrix();
    glTranslatef(0.004,moonPosition,0.4);
    glColor3ub(255,255,255);
    drawCircle(-0.7,0.9,0.11);
    glPopMatrix();
    parkGrass();
    parkroad(day);
    traffic();
    zebraCrossing();
    tree1(day);
    tree2(day);

    glEnable(GL_LIGHTING);
    GLfloat global_ambient2[] = {0.0,1.1,0.0, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient2);

    glDisable(GL_LIGHTING);

    glEnable(GL_LIGHTING);
    GLfloat global_ambient3[] = {0.0,1.9,0.0, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient3);


    glDisable(GL_LIGHTING);

}


void kurilRoad(bool day)
{
    if(day==true)
    {
        glColor3ub(119,136,153);
        drawQuad(-1,-0.4, 1,-0.4, 1,0.2, -1, 0.2);//road
        glColor3ub(128,128,128);
        drawQuad(-1,-0.3, -1,-0.4, 1,-0.4, 1,-0.3);//roadside
        glColor3ub(128,128,128);
        drawQuad(-1,0.1, -1,0.2, 1,0.2, 1,0.1);//roadside
        glColor3f(1,1,1);
        drawQuad(-0.95,-0.08,-0.95,-0.12, -0.65,-0.12, -0.65,-0.08); //white1
        float x=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08);
        x+=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08);
        x+=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08);
        x+=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08); //white5
    }

    else
    {
        glColor3ub(119,136,153);
        drawQuad(-1,-0.4, 1,-0.4, 1,0.2, -1, 0.2);//road
        glColor3ub(211,211,211);
        drawQuad(-1,-0.3, -1,-0.4, 1,-0.4, 1,-0.3);//roadside
        glColor3ub(211,211,211);
        drawQuad(-1,0.1, -1,0.2, 1,0.2, 1,0.1);//roadside

        glColor3f(1,1,1);
        drawQuad(-0.95,-0.08,-0.95,-0.12, -0.65,-0.12, -0.65,-0.08); //white1
        float x=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08);
        x+=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08);
        x+=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08);
        x+=0.4;
        drawQuad(-0.95+x,-0.08,-0.95+x,-0.12, -0.65+x,-0.12, -0.65+x,-0.08); //white5


    }
}

void car()
{
    glPushMatrix();
    glTranslatef(carPosition,0.1,0.0);
    glScalef(0.6,0.6,0);
    glScalef(1,1,1);
    glColor3ub(33,79,198);//car color
    drawRectangle(0.4, -0.2, 0.8, 0.4);
    drawQuad(0.65, -0.2,0.65, -0.05,0.4, 0.2,0.4, -0.2);
    glColor3ub(50,50,50);
    drawQuad(-0.01,-0.02,-0.01,0.15,-0.35,0.15,-0.35,-0.02);
    drawQuad(0.4,-0.02,0.3,0.15,0.03,0.15,0.03,-0.02);

    glColor3ub(0, 0, 0);
    drawCircle(0.35, -0.2, 0.125 );
    glColor3ub(240,240,240);
    drawCircle(0.35, -0.2, 0.1);

    // rear wheel
    glColor3ub(0,0,0);
    drawCircle(-0.25, -0.2, 0.125);
    glColor3ub(240,240,240);
    drawCircle(-0.25, -0.2, 0.1);
    glPopMatrix();
}
void car1()
{
    glPushMatrix();
    glTranslatef(carPosition,-0.1,0.0);
    glScalef(0.4,0.4,0);
    glScalef(-1,1,1);
    glColor3ub(33,79,198);//car color
    drawRectangle(0.4, -0.2, 0.8, 0.4);
    drawQuad(0.65, -0.2,0.65, -0.05,0.4, 0.2,0.4, -0.2);
    glColor3ub(50,50,50);
    drawQuad(-0.01,-0.02,-0.01,0.15,-0.35,0.15,-0.35,-0.02);
    drawQuad(0.4,-0.02,0.3,0.15,0.03,0.15,0.03,-0.02);

    glColor3ub(0, 0, 0);
    drawCircle(0.35, -0.2, 0.125 );
    glColor3ub(240,240,240);
    drawCircle(0.35, -0.2, 0.1);

    // rear wheel
    glColor3ub(0,0,0);
    drawCircle(-0.25, -0.2, 0.125);
    glColor3ub(240,240,240);
    drawCircle(-0.25, -0.2, 0.1);
    glPopMatrix();
}

void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(day == true && secondScene==true)
    {
        dayView();
    }
    else if(day==false && secondScene==true)
    {
        nightView();
    }
    if(isCar==true)
    {
        car();
    }
    else
    {
        car1();
    }
    glutSwapBuffers();
    glFlush();

}

int main(int argc,char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 700);
    glutInitWindowPosition(800/2 - 310,700/2 - 310);
    glutCreateWindow("Nikunja-2");
    glutDisplayFunc(display);
    glEnable(GL_BLEND);
    glutKeyboardFunc(pressKey);
    glutMouseFunc(handleMouse);
    glutTimerFunc(1000/60, SunUpdate, 0);
    glutTimerFunc(1000/60, MoonUpdate, 0);
    glutTimerFunc(4100,DayUpdate,0);
    glutTimerFunc(1000/60, CarUpdate, 0);

    glutMainLoop();
    return 0;

}
