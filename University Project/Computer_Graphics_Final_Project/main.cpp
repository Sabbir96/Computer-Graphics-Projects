#include <bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#define PI 2*acos(0.0)

using namespace std;


void display();
void drawQuad(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
void drawQuadGradient(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
void drawLine(GLfloat, GLfloat, GLfloat, GLfloat);
void drawTriangle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
void drawCircle(GLfloat,GLfloat,GLfloat);
void DayUpdate(int value);
void idle();
void SunUpdate();
void KeyPress(unsigned char, int, int );
void drawClouds();
void drawrownak();
void carLeft();
void carRight();
void CarUpdate (int value);
void drawQuadGradient3ub(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3,GLfloat r,GLfloat g,GLfloat b);
void grass2();
void grass3();
void grass4();
void grass5();
void grass8();
void tree1();
void tree2();
void tree3();
void lamp1();
void lamp2();
void lamp3();
void grass();
void grass1();
void parkSky();
void parkroad();
void parkGrass();
void dayParkView();
void nightParkView();
void CloudUpdate(int value);
void SnowUpdate(int value);
void Cloud2Update(int value);

bool day=true;
bool isCarRight=false;
bool secondScene=true;
bool thirdScene=false;

GLfloat sunPosition = 0.2f;
GLfloat sunSpeed = 0.0035f;
GLfloat moonPosition=0.2f;
GLfloat moonSpeed=0.0044f;
GLfloat carPosition = 1.0f;
GLfloat carSpeed = 0.0095f;
GLfloat snowPosition = 0.0f;
GLfloat snowSpeed = 0.009f;
GLfloat cloudPosition=0.0f;
GLfloat cloudSpeed=0.008f;
GLfloat cloud2Position=0.2f;
GLfloat cloud2Speed=0.008f;

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
        drawQuadGradient3ub(3,23,1,0.3,-1,0.3,-1,1,0,0,0);
        glPopMatrix();
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

void parkGrass()
{
    glColor3ub(25,77,0);
    drawQuadGradient3ub(-1,-0.4,1,-0.4,1,-1,-1,-1,0,204,34);//

}
void grass()
{
    glPushMatrix();
    float x=0.69;
    float y=-0.4;

    glTranslatef(-1.3,-0.4,0);
    glScalef(2.5,0.4,0);
    glBegin(GL_POLYGON);

    glColor3ub(255,255,0);
    glVertex2f(-0.245+x,-0.20+y);
    glVertex2f(-0.230+x,0+y);
    glVertex2f(-0.220+x,0.10+y);
    glVertex2f(-0.240+x,0+y);
    glVertex2f(-0.230+x,0.30+y);
    glVertex2f(-0.250+x,0.10+y);
    glVertex2f(-0.255+x,0.50+y);
    glColor3ub(255,140,0);
    glVertex2f(-0.260+x,0.10+y);
    glVertex2f(-0.280+x,0.30+y);
    glVertex2f(-0.270+x,0.0+y);
    glVertex2f(-0.290+x,0.10+y);
    glVertex2f(-0.280+x,0.0+y);
    glVertex2f(-0.265+x,-0.20+y);
    glEnd();
    glPopMatrix();
    glLoadIdentity();

}
void grass1()
{
    glPushMatrix();
    float x=1.05;
    float y=-0.4;

    glTranslatef(-1.3,-0.4,0);
    glScalef(2.5,0.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
    glVertex2f(-0.245+x,-0.20+y);
    glVertex2f(-0.230+x,0+y);
    glVertex2f(-0.220+x,0.10+y);
    glVertex2f(-0.240+x,0+y);
    glVertex2f(-0.230+x,0.30+y);
    glVertex2f(-0.250+x,0.10+y);
    glVertex2f(-0.255+x,0.50+y);
    glColor3ub(255,140,0);
    glVertex2f(-0.260+x,0.10+y);
    glVertex2f(-0.280+x,0.30+y);
    glVertex2f(-0.270+x,0.0+y);
    glVertex2f(-0.290+x,0.10+y);
    glVertex2f(-0.280+x,0.0+y);
    glVertex2f(-0.265+x,-0.20+y);
    glEnd();
    glPopMatrix();
    glLoadIdentity();

}
void grass2()
{
    glPushMatrix();
    float x=0.51;
    float y=-0.4;

    glTranslatef(-1.3,-0.4,0);
    glScalef(2.5,0.4,0);
    glBegin(GL_POLYGON);

    glColor3ub(255,215,0);
    glVertex2f(-0.245+x,-0.20+y);
    glVertex2f(-0.230+x,0+y);
    glVertex2f(-0.220+x,0.10+y);
    glVertex2f(-0.240+x,0+y);
    glVertex2f(-0.230+x,0.30+y);
    glVertex2f(-0.250+x,0.10+y);
    glVertex2f(-0.255+x,0.50+y);
    glColor3ub(255,140,0);
    glVertex2f(-0.260+x,0.10+y);
    glVertex2f(-0.280+x,0.30+y);
    glVertex2f(-0.270+x,0.0+y);
    glVertex2f(-0.290+x,0.10+y);
    glVertex2f(-0.280+x,0.0+y);
    glVertex2f(-0.265+x,-0.20+y);
    glEnd();
    glPopMatrix();
    glLoadIdentity();

}
void grass3()
{
    glPushMatrix();
    float x=0.96;
    float y=-1.1;

    glTranslatef(-1.3,-0.4,0);
    glScalef(2.5,0.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
    glVertex2f(-0.245+x,-0.20+y);
    glVertex2f(-0.230+x,0+y);
    glVertex2f(-0.220+x,0.10+y);
    glVertex2f(-0.240+x,0+y);
    glVertex2f(-0.230+x,0.30+y);
    glVertex2f(-0.250+x,0.10+y);
    glVertex2f(-0.255+x,0.50+y);
    glColor3ub(255,140,0);
    glVertex2f(-0.260+x,0.10+y);
    glVertex2f(-0.280+x,0.30+y);
    glVertex2f(-0.270+x,0.0+y);
    glVertex2f(-0.290+x,0.10+y);
    glVertex2f(-0.280+x,0.0+y);
    glVertex2f(-0.265+x,-0.20+y);
    glEnd();
    glPopMatrix();

    glLoadIdentity();

}


void grass4()
{
    glPushMatrix();
    float x=0.87;
    float y=-0.4;

    glTranslatef(-1.3,-0.4,0);
    glScalef(2.5,0.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
    glVertex2f(-0.245+x,-0.20+y);
    glVertex2f(-0.230+x,0+y);
    glVertex2f(-0.220+x,0.10+y);
    glVertex2f(-0.240+x,0+y);
    glVertex2f(-0.230+x,0.30+y);
    glVertex2f(-0.250+x,0.10+y);
    glVertex2f(-0.255+x,0.50+y);
    glColor3ub(255,140,0);
    glVertex2f(-0.260+x,0.10+y);
    glVertex2f(-0.280+x,0.30+y);
    glVertex2f(-0.270+x,0.0+y);
    glVertex2f(-0.290+x,0.10+y);
    glVertex2f(-0.280+x,0.0+y);
    glVertex2f(-0.265+x,-0.20+y);
    glEnd();
    glPopMatrix();
    glLoadIdentity();
}

void grass5()
{
    glPushMatrix();
    float x=0.78;
    float y=-1.1;

    glTranslatef(-1.3,-0.4,0);
    glScalef(2.5,0.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
    glVertex2f(-0.245+x,-0.20+y);
    glVertex2f(-0.230+x,0+y);
    glVertex2f(-0.220+x,0.10+y);
    glVertex2f(-0.240+x,0+y);
    glVertex2f(-0.230+x,0.30+y);
    glVertex2f(-0.250+x,0.10+y);
    glVertex2f(-0.255+x,0.50+y);
    glColor3ub(255,140,0);
    glVertex2f(-0.260+x,0.10+y);
    glVertex2f(-0.280+x,0.30+y);
    glVertex2f(-0.270+x,0.0+y);
    glVertex2f(-0.290+x,0.10+y);
    glVertex2f(-0.280+x,0.0+y);
    glVertex2f(-0.265+x,-0.20+y);
    glEnd();
    glPopMatrix();
    glLoadIdentity();
}
void grass8()
{
    glPushMatrix();
    float x=0.59;
    float y=-1.1;

    glTranslatef(-1.3,-0.4,0);
    glScalef(2.5,0.4,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,215,0);
    glVertex2f(-0.245+x,-0.20+y);
    glVertex2f(-0.230+x,0+y);
    glVertex2f(-0.220+x,0.10+y);
    glVertex2f(-0.240+x,0+y);
    glVertex2f(-0.230+x,0.30+y);
    glVertex2f(-0.250+x,0.10+y);
    glVertex2f(-0.255+x,0.50+y);
    glColor3ub(255,140,0);
    glVertex2f(-0.260+x,0.10+y);
    glVertex2f(-0.280+x,0.30+y);
    glVertex2f(-0.270+x,0.0+y);
    glVertex2f(-0.290+x,0.10+y);
    glVertex2f(-0.280+x,0.0+y);
    glVertex2f(-0.265+x,-0.20+y);
    glEnd();
    glPopMatrix();
    glLoadIdentity();
}
// small tree
void tree1(bool day)
{

    if(day==true)
    {
        glPushMatrix();
        glScalef(0.5,0.5,0);
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
        glScalef(0.5,0.5,0);
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

void tree3(bool day)
{
    if(day==true)
    {
        glPushMatrix();
        glScalef(1,0.5,0);
        glTranslatef(1.4,1.8,0);
        //tree1
        glColor3ub(97, 29, 30);
        drawQuad(-0.7,-0.5, -0.7,-0.9, -0.65,-0.9, -0.65,-0.5);
        drawQuad(-0.8,-0.35, -0.7,-0.5, -0.65,-0.5, -0.75,-0.3);
        drawQuad(-0.60,-0.3, -0.68,-0.45, -0.65,-0.5, -0.58,-0.35);

        glColor3ub(34, 139, 34);
        drawCircle(-0.77,-0.3,0.15);
        drawCircle(-0.59,-0.3,0.15);
        drawCircle(-0.67,-0.2,0.2);
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
        glScalef(1,0.5,0);
        glTranslatef(1.4,1.8,0);
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
        glColor3ub(34,139,34);
        drawCircle(-0.77,-0.3,0.15);
        drawCircle(-0.59,-0.3,0.15);
        drawCircle(-0.67,-0.2,0.2);
        glDisable(GL_LIGHTING);
        glPopMatrix();
    }
}
void parkroad(bool day)
{
    if(day==true)
    {
        glColor3f(0,0.3,0.3);
        drawQuad(-1,-0.3,1,-0.3, 1,0.1,-1, 0.1);//road
        glColor3ub(175,238,238);
        drawQuad(-1,-0.3, -1,-0.4, 1,-0.4, 1,-0.3);//roadside
        glColor3ub(175,238,238);
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
        glColor3f(0,0.3,0.3);
        drawQuad(-1,-0.3,1,-0.3, 1,0.1,-1, 0.1);//road
        glColor3ub(175,238,238);
        drawQuad(-1,-0.3, -1,-0.4, 1,-0.4, 1,-0.3);//roadside
        glColor3ub(175,238,238);
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

void lamp1(bool day)
{
    if(day==true)
    {
        glColor3f(0.1,0.4,0.3);
        drawQuad(-0.8,0.22, -0.75,0.22, -0.75,0.33,-0.8,0.33);
        drawQuad(-0.78,0.33, -0.76,0.33, -0.76,0.63,-0.78,0.63);
        drawLine(-0.83,0.63, -0.71,0.63);
        drawLine(-0.83,0.63, -0.83,0.56);
        drawLine(-0.71,0.63, -0.71,0.56);
        drawTriangle(-0.83,0.57,-0.85,0.55, -0.81,0.55);//trileft
        drawTriangle(-0.71,0.57,-0.73,0.55, -0.69,0.55);//triright
        glColor3ub(175,238,238);
        drawQuad(-0.85,0.55,-0.83,0.5,-0.81,0.55,-0.83,0.55);
        drawQuad(-0.73,0.55, -0.71,0.5,-0.69,0.55,-0.71,0.55);
    }
    else
    {

        glColor3f(0.1,0.4,0.3);
        drawQuad(-0.8,0.22, -0.75,0.22, -0.75,0.33,-0.8,0.33);
        drawQuad(-0.78,0.33, -0.76,0.33, -0.76,0.63,-0.78,0.63);
        drawLine(-0.83,0.63, -0.71,0.63);
        drawLine(-0.83,0.63, -0.83,0.56);
        drawLine(-0.71,0.63, -0.71,0.56);
        drawTriangle(-0.83,0.57,-0.85,0.55, -0.81,0.55);//trileft
        drawTriangle(-0.71,0.57,-0.73,0.55, -0.69,0.55);//triright
        glColor3ub(255,255,0);
        drawQuad(-0.85,0.55,-0.83,0.5,-0.81,0.55,-0.83,0.55);
        drawQuad(-0.73,0.55, -0.71,0.5,-0.69,0.55,-0.71,0.55);
    }
}
void lamp2(bool day)
{
    if(day==true)
    {
        float x=0.65;
        glColor3f(0.1,0.4,0.3);
        drawQuad(-0.8+x,0.22, -0.75+x,0.22, -0.75+x,0.33,-0.8+x,0.33);
        drawQuad(-0.78+x,0.33, -0.76+x,0.33, -0.76+x,0.63,-0.78+x,0.63);
        drawLine(-0.83+x,0.63, -0.71+x,0.63);
        drawLine(-0.83+x,0.63, -0.83+x,0.56);
        drawLine(-0.71+x,0.63, -0.71+x,0.56);
        drawTriangle(-0.83+x,0.57,-0.85+x,0.55, -0.81+x,0.55);//trileft
        drawTriangle(-0.71+x,0.57,-0.73+x,0.55, -0.69+x,0.55);//triright
        glColor3ub(175,238,238);
        drawQuad(-0.85+x,0.55,-0.83+x,0.5,-0.81+x,0.55,-0.83+x,0.55);
        drawQuad(-0.73+x,0.55, -0.71+x,0.5,-0.69+x,0.55,-0.71+x,0.55);
    }
    else
    {
        float x=0.65;
        glColor3f(0.1,0.4,0.3);
        drawQuad(-0.8+x,0.22, -0.75+x,0.22, -0.75+x,0.33,-0.8+x,0.33);
        drawQuad(-0.78+x,0.33, -0.76+x,0.33, -0.76+x,0.63,-0.78+x,0.63);
        drawLine(-0.83+x,0.63, -0.71+x,0.63);
        drawLine(-0.83+x,0.63, -0.83+x,0.56);
        drawLine(-0.71+x,0.63, -0.71+x,0.56);
        drawTriangle(-0.83+x,0.57,-0.85+x,0.55, -0.81+x,0.55);//trileft
        drawTriangle(-0.71+x,0.57,-0.73+x,0.55, -0.69+x,0.55);//triright
        glColor3ub(255,255,0);
        drawQuad(-0.85+x,0.55,-0.83+x,0.5,-0.81+x,0.55,-0.83+x,0.55);
        drawQuad(-0.73+x,0.55, -0.71+x,0.5,-0.69+x,0.55,-0.71+x,0.55);

    }

}
void lamp3(bool day)
{
    if(day==true)
    {
        float x=1.3;
        glColor3f(0.1,0.4,0.3);
        drawQuad(-0.8+x,0.22, -0.75+x,0.22, -0.75+x,0.33,-0.8+x,0.33);
        drawQuad(-0.78+x,0.33, -0.76+x,0.33, -0.76+x,0.63,-0.78+x,0.63);
        drawLine(-0.83+x,0.63, -0.71+x,0.63);
        drawLine(-0.83+x,0.63, -0.83+x,0.56);
        drawLine(-0.71+x,0.63, -0.71+x,0.56);
        drawTriangle(-0.83+x,0.57,-0.85+x,0.55, -0.81+x,0.55);//trileft
        drawTriangle(-0.71+x,0.57,-0.73+x,0.55, -0.69+x,0.55);//triright
        glColor3ub(175,238,238);
        drawQuad(-0.85+x,0.55,-0.83+x,0.5,-0.81+x,0.55,-0.83+x,0.55);
        drawQuad(-0.73+x,0.55, -0.71+x,0.5,-0.69+x,0.55,-0.71+x,0.55);
    }
    else
    {
        float x=1.3;
        glColor3f(0.1,0.4,0.3);
        drawQuad(-0.8+x,0.22, -0.75+x,0.22, -0.75+x,0.33,-0.8+x,0.33);
        drawQuad(-0.78+x,0.33, -0.76+x,0.33, -0.76+x,0.63,-0.78+x,0.63);
        drawLine(-0.83+x,0.63, -0.71+x,0.63);
        drawLine(-0.83+x,0.63, -0.83+x,0.56);
        drawLine(-0.71+x,0.63, -0.71+x,0.56);
        drawTriangle(-0.83+x,0.57,-0.85+x,0.55, -0.81+x,0.55);//trileft
        drawTriangle(-0.71+x,0.57,-0.73+x,0.55, -0.69+x,0.55);//triright
        glColor3ub(255,255,0);
        drawQuad(-0.85+x,0.55,-0.83+x,0.5,-0.81+x,0.55,-0.83+x,0.55);
        drawQuad(-0.73+x,0.55, -0.71+x,0.5,-0.69+x,0.55,-0.71+x,0.55);

    }
}

void KeyPress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        isCarRight=false;
        break;
    case 'd':
        isCarRight=true;
        break;
    case 's':
        carSpeed=0.0;
        break;
    case 'w':
        carSpeed=0.0075f;
        break;
        glutPostRedisplay();
    }
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
void CarUpdate (int value)
{

    if(carPosition < -1.71)
    {
        carPosition = 1.0f;
    }

    if(carPosition>1.31)
    {
        carPosition=-0.3;
    }
    if(isCarRight==true)
        carPosition += carSpeed;
    else
        carPosition-=carSpeed;


    glutPostRedisplay();


    glutTimerFunc(1000/60, CarUpdate, 0);
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

    glutTimerFunc(1000/60, SunUpdate, 0);

}
void idle()
{
    glutPostRedisplay();
}



void drawCircle(GLfloat x,GLfloat y,GLfloat radius)
{
    int i;
    int lineAmount = 100;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);

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

void carLeft()
{
    glPushMatrix();
    glTranslatef(carPosition,-0.1,0.0);
    glScalef(0.3,0.3,0);
    glScalef(-1,1,1);
    glColor3ub(220,20,60);
    drawRectangle(0.4, -0.2, 0.8, 0.4);
    // front bum111per
    drawQuad(0.65, -0.2,0.65, -0.05,0.4, 0.2,0.4, -0.2);
    drawQuad(-0.4,-0.2,-0.4,0.2,-0.48,0.22,-0.48,-0.2);//rear spoiler
    drawQuad(0.1, 0.2,0.15, 0.23,-0.15, 0.23,-0.2, 0.2);//top hood



    glColor3ub(50,50,50);
    // rear window
    drawQuad(-0.01,-0.02,-0.01,0.15,-0.35,0.15,-0.35,-0.02);
    // front window
    drawQuad(0.4,-0.02,0.3,0.15,0.03,0.15,0.03,-0.02);

    // front wheel
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
void carRight()
{
    glPushMatrix();
    glTranslatef(carPosition,0.05,0.0);
    glScalef(0.3,0.3,0);

    glColor3ub(220,20,60);
    drawRectangle(0.4, -0.2, 0.8, 0.4);
    // front bumper
    drawQuad(0.65, -0.2,0.65, -0.05,0.4, 0.2,0.4, -0.2);
    drawQuad(-0.4,-0.2,-0.4,0.2,-0.48,0.22,-0.48,-0.2);//rear spoiler
    drawQuad(0.2, 0.2,0.15, 0.23,-0.15, 0.23,-0.2, 0.2);//top hood



    glColor3ub(50,50,50);
    // rear window
    drawQuad(-0.01,-0.02,-0.01,0.15,-0.35,0.15,-0.35,-0.02);
    // front window
    drawQuad(0.4,-0.02,0.3,0.15,0.03,0.15,0.03,-0.02);

    // front wheel
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
void dayParkView()
{
    parkSky(day);
    glPushMatrix();
    glTranslatef(-1.4,sunPosition,0.0);
    glColor3ub(255,215,0);
    drawCircle(0.7,0.9,0.11);
    glPopMatrix();

    parkroad(day);
    parkGrass();
    grass();
    grass1();
    grass2();
    grass3();
    grass4();
    grass5();
    grass8();
    lamp1(day);
    lamp2(day);
    lamp3(day);
    tree1(day);
    tree2(day);
    tree3(day);


}


void nightParkView()
{

    parkSky(day);

    parkroad(day);

    glEnable(GL_LIGHTING);
    GLfloat global_ambient2[] = {0.0,1.1,0.0, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient2);
    parkGrass();
    glDisable(GL_LIGHTING);




    glEnable(GL_LIGHTING);
    GLfloat global_ambient3[] = {0.0,1.9,0.0, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient3);
    grass();
    grass1();
    grass2();
    grass3();
    grass4();
    grass5();
    grass8();

    glDisable(GL_LIGHTING);


    lamp1(day);
    glPushMatrix();
    glTranslatef(-0.89,0.2,0.0);
    glScalef(0.3,1.5,0.1);
    glColor4ub(230, 230, 0,100);
    drawTriangle(0.2,0.2,0.0,0.0,0.4,0.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.77,0.2,0.0);
    glScalef(0.3,1.5,0.1);
    glColor4ub(230, 230, 0,100);
    drawTriangle(0.2,0.2,0.0,0.0,0.4,0.0);
    glPopMatrix();

    lamp2(day);
    glPushMatrix();
    glTranslatef(-0.24,0.2,0.0);
    glScalef(0.3,1.5,0.1);
    glColor4ub(230, 230, 0,100);
    drawTriangle(0.2,0.2,0.0,0.0,0.4,0.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.12,0.2,0.0);
    glScalef(0.3,1.5,0.1);
    glColor4ub(230, 230, 0,100);
    drawTriangle(0.2,0.2,0.0,0.0,0.4,0.0);
    glPopMatrix();




    lamp3(day);
    glPushMatrix();
    glTranslatef(0.41,0.2,0.0);
    glScalef(0.3,1.5,0.1);
    glColor4ub(230, 230, 0,100);
    drawTriangle(0.2,0.2,0.0,0.0,0.4,0.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.53,0.2,0.0);
    glScalef(0.3,1.5,0.1);
    glColor4ub(230, 230, 0,100);
    drawTriangle(0.2,0.2,0.0,0.0,0.4,0.0);
    glPopMatrix();
    tree1(day);
    tree2(day);
    tree3(day);
}


void rownakRoad(bool day)
{
    if(day==true)
    {
        glColor3ub(119,136,153);
        drawQuad(-1,-0.4, 1,-0.4, 1,0.2, -1, 0.2);//road
        glColor3ub(245,245,220);
        drawQuad(-1,-0.3, -1,-0.4, 1,-0.4, 1,-0.3);//roadside
        glColor3ub(245,245,220);
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
void rownakSky(bool day)
{
    if(day==true)
    {

        glColor3f(0.5,1,1);
        drawQuadGradient3ub( -1,1, -1,0.1, 1,0.1, 1,1,255,255,224);
    }
    else
    {
        glColor3ub(95,95,95);
        drawQuadGradient3ub( -1,1, -1,0.1, 1,0.1, 1,1,0,0,0);

    }
}

void window(GLfloat x,GLfloat y,GLfloat z,bool day)
{
    glPushMatrix();
    glScalef(0.8,0.8,0.0);
    glTranslatef(x,y,z);


    if(day==true)
    {
        glColor3ub(245,255,250);
    }
    else
    {
        glColor3ub(247, 255, 204);
    }
    drawQuad(0.10,0.6,0.0,0.6,0.0,0.52,0.10,0.52);

    glPopMatrix();
}
void rownakCloud()
{
    glPushMatrix();
    glTranslatef(cloudPosition,0.0, 0.0f);
    //cloud 1
    glColor3ub(242, 242, 242);
    drawCircle(-0.8,0.8, 0.1);
    glColor3ub(255,255,255);
    drawCircle(-0.7,0.85,0.1);
    glColor3ub(242, 242, 242);
    drawCircle(-0.7,0.75,0.1);
    drawCircle(-0.6,0.8,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud2Position,0.0,0.0f);
    glTranslatef(0.8,0,0);
    glColor3ub(242, 242, 242);
    drawCircle(-0.8,0.8, 0.1);
    glColor3ub(255,255,255);
    drawCircle(-0.7,0.85,0.1);
    glColor3ub(242, 242, 242);
    drawCircle(-0.7,0.75,0.1);
    drawCircle(-0.6,0.8,0.1);
    glPopMatrix();

}
void CloudUpdate(int value)
{
    if(cloudPosition<-1.5)
    {
        cloudPosition=2.0f;
    }
    if(cloudPosition>2.0)
    {
        cloudPosition=-1.5;
    }
    cloudPosition -= cloudSpeed;
    glutPostRedisplay();
    glutTimerFunc(25, CloudUpdate, 0);
}
void Cloud2Update(int value)
{
    if(cloud2Position<-1.5)
    {
        cloud2Position=2.0f;
    }
    if(cloud2Position>2.0)
    {
        cloud2Position=  -1.5;
    }
    cloud2Position += cloud2Speed;
    glutPostRedisplay();
    glutTimerFunc(25, Cloud2Update, 0);
}





void rownak(bool day)
{
    if(day==true)
    {



        glPushMatrix();
        glTranslated(-0.01,0.1,0);

        glColor3ub(233,150,122);
        drawQuadGradient(-0.7,0.1,-0.3,0.1,-0.3,0.37,-0.7,0.37,.9,0.3,0.1);
        glColor3ub(245,255,250);

        drawQuad(-0.275,0.4,-0.73,0.4,-0.73,0.36,-0.275,0.36);
        glColor3ub(220,220,220);
        drawTriangle(-0.275,0.4,-0.73,0.4,-0.5,0.51);

        window(-0.8,-0.2,0,true);
        window(-0.8,-0.38,0,true);
        window(-0.55,-0.38,0,true);
        window(-0.55,-0.2,0,true);


        glTranslated(1.0,0,0);
        glColor3ub(233,150,122);
        drawQuadGradient(-0.7,0.1,-0.3,0.1,-0.3,0.37,-0.7,0.37,.9,0.3,0.1);  //building
        glColor3ub(245,255,250);
        drawQuad(-0.275,0.4,-0.73,0.4,-0.73,0.36,-0.275,0.36);
        glColor3ub(220,220,220);
        drawTriangle(-0.275,0.4,-0.73,0.4,-0.5,0.51);

        window(-0.8,-0.2,0,true);
        window(-0.8,-0.38,0,true);
        window(-0.55,-0.38,0,true);
        window(-0.55,-0.2,0,true);


        glColor3ub(160,82,45);
        drawQuad(-0.7,0.25,-1.3,0.25,-1.3,0.18,-0.7,0.18);

        drawQuad(-0.7,0.33,-1.3,0.33,-1.3,0.30,-0.7,0.30);
        glColor3ub(128,212,255);


        drawQuad(-0.76,0.55,-1.24,0.55,-1.24,0.33,-0.76,0.33);// tomb

        glColor3ub(244,164,96);
        drawQuad(-1.24,0.61,-0.76,0.61,-0.66,0.52,-1.34,0.52);
        glPopMatrix();



        glPushMatrix();
        glScalef(0.9,0.9,0);
        glTranslatef(0.99,0.16,0);

        glColor3ub(0,0,205);
        drawQuad(-1.08,0.49,-1.06,0.49,-1.06,0.36,-1.08,0.36);// I

        drawQuad(-1.17,0.49,-1.15,0.49,-1.19,0.36,-1.21,0.36);      //A
        drawQuad(-1.17,0.49,-1.15,0.49,-1.11,0.36,-1.13,0.36);
        drawQuad(-1.18,0.41,-1.14,0.41,-1.14,0.39,-1.18,0.39);

        drawQuad(-1.03,0.49,-1.01,0.49,-1.01,0.36,-1.03,0.36);//  U
        drawQuad(-0.949,0.49,-0.93,0.49,-0.93,0.36,-0.949,0.36);
        drawQuad(-1.02,0.38,-0.93,0.38,-0.93,0.36,-1.02,0.36);


        drawQuad(-0.9,0.49,-0.88,0.49,-0.88,0.36,-0.9,0.36);  //B
        drawQuad(-0.82,0.49,-0.80,0.49,-0.80,0.36,-0.82,0.36);
        drawQuad(-0.9, 0.36,-0.80,0.36,-0.80,0.38,-0.9,0.38);
        drawQuad(-0.9, 0.415,-0.80,0.415,-0.80,0.435,-0.9,0.435);
        drawQuad(-0.9, 0.47,-0.80,0.47,-0.80,0.49,-0.9,0.49);

        glColor3ub(128,212,255);

        drawTriangle(-1.03,0.36,-1.01,0.36,-1.03,0.38);
        drawTriangle(-0.93,0.36,-0.95,0.36,-0.93,0.38);
        drawTriangle(-0.80,0.49,-0.82,0.49,-0.80,0.47);
        drawTriangle(-0.80,0.36,-0.80,0.38,-0.82,0.36);
        drawTriangle(-0.80,0.445,-0.80,0.405,-0.812,0.425);
        glColor3ub(128,128,128);

        glTranslated(-1.233,-0.04,0);
        drawQuad(-0.6,0.1,-0.61,0.1,-0.61,0.5,-0.6,0.5);



        drawQuad(-0.45,0.1,-0.46,0.1,-0.46,0.5,-0.45,0.5);// red flag bar
        drawQuad(-0.75, 0.1,-0.76,0.1,-0.76,0.5,-0.75,0.5);

        glColor3ub(0,0,255);
        drawQuad(-0.45,0.49,-0.45,0.42,-0.55,0.37,-0.55,0.44);

        glColor3ub(255,0,0);
        drawQuad(-0.6,0.49,-0.6,0.42,-0.7,0.37,-0.7,0.44);// red flag

        glColor3ub(0,128,0);

        drawQuad(-0.75,0.49,-0.75,0.42,-0.85,0.37,-0.85,0.44);

        glPopMatrix();

    }
    else
    {

        glPushMatrix();
        glEnable(GL_LIGHTING);
        GLfloat global_ambient[] = {1.9, 0.4, 0.1, 0.8};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

        glTranslated(-0.01,0.1,0);
        glColor3ub(153,51,0);
        drawQuadGradient(-0.7,0.1,-0.3,0.1,-0.3,0.37,-0.7,0.37,.9,0.3,0.1);
        glColor3ub(245,255,250);

        drawQuad(-0.275,0.4,-0.73,0.4,-0.73,0.36,-0.275,0.36);
        glColor3ub(220,220,220);
        drawTriangle(-0.275,0.4,-0.73,0.4,-0.5,0.51);

        glTranslated(1.0,0,0);
        glColor3ub(153,51,0);
        drawQuadGradient(-0.7,0.1,-0.3,0.1,-0.3,0.37,-0.7,0.37,.9,0.3,0.1);
        glColor3ub(245,255,250);
        drawQuad(-0.275,0.4,-0.73,0.4,-0.73,0.36,-0.275,0.36);
        glColor3ub(220,220,220);
        drawTriangle(-0.275,0.4,-0.73,0.4,-0.5,0.51);



        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHTING);


        window(-0.8,-0.2,0,false);
        window(-0.8,-0.38,0,false);
        window(-0.55,-0.38,0,false);
        window(-0.55,-0.2,0,false);

        glTranslated(1.0,0,0);

        window(-3.05,-0.2,0,false);
        window(-3.05,-0.38,0,false);
        window(-3.30,-0.38,0,false);
        window(-3.30,-0.2,0,false);



        glPopMatrix();
        glPushMatrix();


        glTranslated(0.99,0.1,0);
        glColor3ub(105,105,105);
        drawQuad(-0.7,0.25,-1.3,0.25,-1.3,0.18,-0.7,0.18);

        drawQuad(-0.7,0.33,-1.3,0.33,-1.3,0.30,-0.7,0.30);

        drawQuad(-0.76,0.55,-1.24,0.55,-1.24,0.33,-0.76,0.33);
        glColor3ub(128,42,0);
        drawQuad(-1.24,0.61,-0.76,0.61,-0.66,0.52,-1.34,0.52);
        glPopMatrix();



        glPushMatrix();


        glScalef(0.9,0.9,0);
        glTranslatef(0.99,0.16,0);

        glColor3ub(255,255,240);
        drawQuad(-1.08,0.49,-1.06,0.49,-1.06,0.36,-1.08,0.36);// I

        drawQuad(-1.17,0.49,-1.15,0.49,-1.19,0.36,-1.21,0.36);      //A
        drawQuad(-1.17,0.49,-1.15,0.49,-1.11,0.36,-1.13,0.36);
        drawQuad(-1.18,0.41,-1.14,0.41,-1.14,0.39,-1.18,0.39);

        drawQuad(-1.03,0.49,-1.01,0.49,-1.01,0.36,-1.03,0.36);//  U
        drawQuad(-0.949,0.49,-0.93,0.49,-0.93,0.36,-0.949,0.36);
        drawQuad(-1.02,0.38,-0.93,0.38,-0.93,0.36,-1.02,0.36);


        drawQuad(-0.9,0.49,-0.88,0.49,-0.88,0.36,-0.9,0.36);  //B
        drawQuad(-0.82,0.49,-0.80,0.49,-0.80,0.36,-0.82,0.36);
        drawQuad(-0.9, 0.36,-0.80,0.36,-0.80,0.38,-0.9,0.38);
        drawQuad(-0.9, 0.415,-0.80,0.415,-0.80,0.435,-0.9,0.435);
        drawQuad(-0.9, 0.47,-0.80,0.47,-0.80,0.49,-0.9,0.49);

        glColor3ub(105,105,105);

        drawTriangle(-1.03,0.36,-1.01,0.36,-1.03,0.38);
        drawTriangle(-0.93,0.36,-0.95,0.36,-0.93,0.38);
        drawTriangle(-0.80,0.49,-0.82,0.49,-0.80,0.47);
        drawTriangle(-0.80,0.36,-0.80,0.38,-0.82,0.36);
        drawTriangle(-0.80,0.445,-0.80,0.405,-0.812,0.425);

        glColor3ub(128,128,128);

        glTranslated(-1.233,-0.04,0);
        drawQuad(-0.6,0.1,-0.61,0.1,-0.61,0.5,-0.6,0.5);



        drawQuad(-0.45,0.1,-0.46,0.1,-0.46,0.5,-0.45,0.5);// red flag bar
        drawQuad(-0.75, 0.1,-0.76,0.1,-0.76,0.5,-0.75,0.5);

        glColor3ub(105,105,105);
        drawQuad(-0.45,0.49,-0.45,0.42,-0.55,0.37,-0.55,0.44);

        glColor3ub(105,105,105);
        drawQuad(-0.6,0.49,-0.6,0.42,-0.7,0.37,-0.7,0.44);// red flag

        glColor3ub(105,105,105);

        drawQuad(-0.75,0.49,-0.75,0.42,-0.85,0.37,-0.85,0.44);


        glPopMatrix();


    }


}
void SnowUpdate(int value)
{

    if(snowPosition < -1.5)
    {
        snowPosition = 2.0f;
    }

    if(snowPosition>2.0)
    {
        snowPosition=-1.5;
    }
    snowPosition -= snowSpeed;
    glutPostRedisplay();
    glutTimerFunc(25, SnowUpdate, 0);
}
void rownakRail()
{

    glColor3ub(163, 194, 194);
    drawQuad(-1,-0.4, -1,-0.75, 1,-0.75, 1,-0.4);



    if(day==false)
    {
        glEnable(GL_LIGHTING);//Enable Light Effect
        GLfloat global_ambient4[] = {153/100, 0, 0, 0.1};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient4);
        glColor3ub(153,0,0);
        drawQuad(-1,-0.4, -1,-0.45, 1,-0.45, 1,-0.4);
        drawQuad(-1,-0.70, -1,-0.75, 1,-0.75, 1,-0.70);
        drawQuad(-0.8,-0.4, -0.8,-0.75, -0.75,-0.75, -0.75,-0.4);//rail line
        drawQuad(-0.6,-0.4, -0.6,-0.75, -0.55,-0.75, -0.55,-0.4);
        drawQuad(-0.4,-0.4, -0.4,-0.75, -0.35,-0.75, -0.35,-0.4);
        drawQuad(-0.2,-0.4, -0.2,-0.75, -0.15,-0.75, -0.15,-0.4);
        drawQuad(0,-0.4, 0,-0.75, 0.05,-0.75, 0.05,-0.4);
        drawQuad(0.2,-0.4, 0.2,-0.75, 0.25,-0.75, 0.25,-0.4);
        drawQuad(0.4,-0.4, 0.4,-0.75, 0.45,-0.75, 0.45,-0.4);
        drawQuad(0.6,-0.4, 0.6,-0.75, 0.65,-0.75, 0.65,-0.4);
        drawQuad(0.8,-0.4, 0.8,-0.75, 0.85,-0.75, 0.85,-0.4);
        glDisable(GL_LIGHTING);

    }

    else
    {
        glColor3ub(153,0,0);
        drawQuad(-1,-0.4, -1,-0.45, 1,-0.45, 1,-0.4);
        drawQuad(-1,-0.70, -1,-0.75, 1,-0.75, 1,-0.70);
        drawQuad(-0.8,-0.4, -0.8,-0.75, -0.75,-0.75, -0.75,-0.4);//rail line
        drawQuad(-0.6,-0.4, -0.6,-0.75, -0.55,-0.75, -0.55,-0.4);
        drawQuad(-0.4,-0.4, -0.4,-0.75, -0.35,-0.75, -0.35,-0.4);
        drawQuad(-0.2,-0.4, -0.2,-0.75, -0.15,-0.75, -0.15,-0.4);
        drawQuad(0,-0.4, 0,-0.75, 0.05,-0.75, 0.05,-0.4);
        drawQuad(0.2,-0.4, 0.2,-0.75, 0.25,-0.75, 0.25,-0.4);
        drawQuad(0.4,-0.4, 0.4,-0.75, 0.45,-0.75, 0.45,-0.4);
        drawQuad(0.6,-0.4, 0.6,-0.75, 0.65,-0.75, 0.65,-0.4);
        drawQuad(0.8,-0.4, 0.8,-0.75, 0.85,-0.75, 0.85,-0.4);
    }


    glPushMatrix();
    glTranslatef(snowPosition,0.0, 0.0f);

    glPopMatrix();
}
void rownakJungle()
{
    glColor3ub(17, 198, 87);
    drawQuadGradient3ub(-1,-0.75, -1,-1, 1,-1, 1,-0.75,89,204,0);
    //tree1
    glPushMatrix();
    glScalef(0.6,0.55,0);
    glTranslatef(-0.7,-0.6,0);
    glColor3ub(97, 29, 30);
    drawQuad(-0.7,-0.5, -0.7,-0.9, -0.65,-0.9, -0.65,-0.5);
    drawQuad(-0.8,-0.35, -0.7,-0.5, -0.65,-0.5, -0.75,-0.3);
    drawQuad(-0.60,-0.3, -0.68,-0.45, -0.65,-0.5, -0.58,-0.35);

    glColor3ub(64,128,0); //leaf

    drawTriangle(-0.7,0, -0.95,-0.45, -0.4,-0.45);
    drawTriangle(-0.7,0.1, -0.95,-0.35, -0.4,-0.35);
    drawTriangle(-0.7,0.15, -0.95,-0.25, -0.4,-0.25);

    glColor3ub(10, 105, 54);
    drawTriangle(-0.85,-0.6, -0.7,-0.9, -0.7,-0.8);

    glPopMatrix();


    //tree3
    glPushMatrix();
    glScalef(0.52,0.5,0);
    glTranslatef(0.2,-0.8,0);

    glColor3ub(60, 29, 30);
    drawQuad(-0.7,-0.5, -0.7,-0.9, -0.65,-0.9, -0.65,-0.5);
    drawQuad(-0.8,-0.35, -0.7,-0.5, -0.65,-0.5, -0.75,-0.3);
    drawQuad(-0.60,-0.3, -0.68,-0.45, -0.65,-0.5, -0.58,-0.35);

    glColor3ub(42, 122, 59); //leaf

    drawTriangle(-0.7,0, -0.95,-0.45, -0.4,-0.45);
    drawTriangle(-0.7,0.1, -0.95,-0.35, -0.4,-0.35);
    drawTriangle(-0.7,0.15, -0.95,-0.25, -0.4,-0.25);

    glColor3ub(10, 105, 54);
    drawTriangle(-0.85,-0.6, -0.7,-0.9, -0.7,-0.8);

    glPopMatrix();


    //tree2
    glPushMatrix();
    glScalef(0.68,0.6,0);
    glTranslatef(-0.1,-0.65,0);

    glColor3ub(97, 29, 30);
    drawQuad(-0.7,-0.5, -0.7,-0.9, -0.65,-0.9, -0.65,-0.5);
    drawQuad(-0.8,-0.35, -0.7,-0.5, -0.65,-0.5, -0.75,-0.3);
    drawQuad(-0.60,-0.3, -0.68,-0.45, -0.65,-0.5, -0.58,-0.35);

    glColor3ub(115,230,0);

    drawTriangle(-0.7,0, -0.95,-0.45, -0.4,-0.45);
    drawTriangle(-0.7,0.1, -0.95,-0.35, -0.4,-0.35);
    drawTriangle(-0.7,0.15, -0.95,-0.25, -0.4,-0.25);

    glPopMatrix();


    //tree5(middle)
    glPushMatrix();
    glScalef(0.6,0.65,0);
    glTranslatef(1.3,-0.5,0);

    glColor3ub(97, 29, 30);
    drawQuad(-0.7,-0.5, -0.7,-0.9, -0.65,-0.9, -0.65,-0.5);
    drawQuad(-0.8,-0.35, -0.7,-0.5, -0.65,-0.5, -0.75,-0.3);
    drawQuad(-0.60,-0.3, -0.68,-0.45, -0.65,-0.5, -0.58,-0.35);

    glColor3ub(115,230,0); //leaf

    drawTriangle(-0.7,0, -0.95,-0.45, -0.4,-0.45);
    drawTriangle(-0.7,0.1, -0.95,-0.35, -0.4,-0.35);
    drawTriangle(-0.7,0.15, -0.95,-0.25, -0.4,-0.25);

    glColor3ub(10, 105, 54);
    drawTriangle(-0.85,-0.6, -0.7,-0.9, -0.7,-0.8);

    glPopMatrix();

    //tree4
    glPushMatrix();
    glScalef(0.7,0.7,0);
    glTranslatef(0.8,-0.4,0);

    glColor3ub(97, 29, 30);
    drawQuad(-0.7,-0.5, -0.7,-0.9, -0.65,-0.9, -0.65,-0.5);
    drawQuad(-0.8,-0.35, -0.7,-0.5, -0.65,-0.5, -0.75,-0.3);
    drawQuad(-0.60,-0.3, -0.68,-0.45, -0.65,-0.5, -0.58,-0.35);


    glColor3ub(42, 122, 59); //leaf

    drawTriangle(-0.7,0, -0.95,-0.45, -0.4,-0.45);
    drawTriangle(-0.7,0.1, -0.95,-0.35, -0.4,-0.35);
    drawTriangle(-0.7,0.15, -0.95,-0.25, -0.4,-0.25);


    glColor3ub(10, 105, 54);
    drawTriangle(-0.85,-0.6, -0.7,-0.9, -0.7,-0.8);

    glPopMatrix();


    //tree6(middle 2)
    glPushMatrix();
    glScalef(0.7,0.7,0);
    glTranslatef(1.5,-0.4,0);

    glColor3ub(97, 29, 30);
    drawQuad(-0.7,-0.5, -0.7,-0.9, -0.65,-0.9, -0.65,-0.5);
    drawQuad(-0.8,-0.35, -0.7,-0.5, -0.65,-0.5, -0.75,-0.3);
    drawQuad(-0.60,-0.3, -0.68,-0.45, -0.65,-0.5, -0.58,-0.35);

    glColor3ub(42, 122, 59); //leaf

    drawTriangle(-0.7,0, -0.95,-0.45, -0.4,-0.45);
    drawTriangle(-0.7,0.1, -0.95,-0.35, -0.4,-0.35);
    drawTriangle(-0.7,0.15, -0.95,-0.25, -0.4,-0.25);

    glColor3ub(10, 105, 54);
    drawTriangle(-0.85,-0.6, -0.7,-0.9, -0.7,-0.8);

    glPopMatrix();

    //tree7
    glPushMatrix();
    glScalef(0.6,0.6,0);
    glTranslatef(2,-0.6,0);

    glColor3ub(97, 29, 30);
    drawQuad(-0.7,-0.5, -0.7,-0.9, -0.65,-0.9, -0.65,-0.5);
    drawQuad(-0.8,-0.35, -0.7,-0.5, -0.65,-0.5, -0.75,-0.3);
    drawQuad(-0.60,-0.3, -0.68,-0.45, -0.65,-0.5, -0.58,-0.35);

    glColor3ub(115,230,0);//leaf

    drawTriangle(-0.7,0, -0.95,-0.45, -0.4,-0.45);
    drawTriangle(-0.7,0.1, -0.95,-0.35, -0.4,-0.35);
    drawTriangle(-0.7,0.15, -0.95,-0.25, -0.4,-0.25);

    glColor3ub(10, 105, 54);
    drawTriangle(-0.85,-0.6, -0.7,-0.9, -0.7,-0.8);

    glPopMatrix();

}
void rownakCar()
{

}
void snow()
{
    glPushMatrix();
    glTranslatef(-snowPosition,snowPosition, 0.0f);
    glColor3ub(255,255,255);
    drawCircle(0,0,0.025);
    drawCircle(-0.6,0.7,0.025);
    drawCircle(-0,0.9,0.025);
    drawCircle(-0.86,0.7,0.025);
    drawCircle(-0.65,0.87,0.025);
    drawCircle(-0.57,0.34,0.025);
    drawCircle(0,0,0.025);
    drawCircle(0.54,0.52,0.025);
    drawCircle(0.67,0.67,0.025);
    drawCircle(0.82,0.35,0.025);
    drawCircle(0.38,0.2,0.025);
    drawCircle(0.9,0.6,0.025);
    drawCircle(0.2,0.5,0.025);
    drawCircle(-0.32,0.5,0.025);
    drawCircle(-0.65,0.25,0.025);
    drawCircle(-0.7,0.3,0.025);

    glTranslatef(snowPosition,snowPosition, 0.0f);
    glColor3ub(255,255,255);
    glTranslatef(-0.2,1,0);
    drawCircle(0,0,0.025);
    drawCircle(-0.6,0.7,0.025);
    drawCircle(-0,0.9,0.025);
    drawCircle(-0.86,0.7,0.025);
    drawCircle(-0.65,0.87,0.025);
    drawCircle(-0.57,0.34,0.025);
    drawCircle(0,0,0.025);
    drawCircle(0.54,0.52,0.025);
    drawCircle(0.67,0.67,0.025);
    drawCircle(0.82,0.35,0.025);
    drawCircle(0.38,0.2,0.025);
    drawCircle(0.9,0.6,0.025);
    drawCircle(0.2,0.5,0.025);
    drawCircle(-0.32,0.5,0.025);
    drawCircle(-0.65,0.25,0.025);
    drawCircle(-0.7,0.3,0.025);


    glTranslatef(0.0f,snowPosition, 0.0f);
    glColor3ub(255,255,255);
    glTranslatef(0.2,0,0);
    drawCircle(0,0,0.025);
    drawCircle(-0.6,0.7,0.025);
    drawCircle(-0,0.9,0.025);
    drawCircle(-0.86,0.7,0.025);
    drawCircle(-0.65,0.87,0.025);
    drawCircle(-0.57,0.34,0.025);
    drawCircle(0,0,0.025);
    drawCircle(0.54,0.52,0.025);
    drawCircle(0.67,0.67,0.025);
    drawCircle(0.82,0.35,0.025);
    drawCircle(0.38,0.2,0.025);
    drawCircle(0.9,0.6,0.025);
    drawCircle(0.2,0.5,0.025);
    drawCircle(-0.32,0.5,0.025);
    drawCircle(-0.65,0.25,0.025);
    drawCircle(-0.7,0.3,0.025);
    glPopMatrix();
}
void rownakScenery()
{
    rownakSky(day);
    rownakCloud();
    rownakRoad(day);
    rownak(day);
    rownakRail();
    rownakJungle();
    if(carPosition<-0.8)
    {
        carPosition=-0.8;
    }

}

void nightrownakScenery()
{


    rownakSky(day);

    glEnable(GL_LIGHTING);
    GLfloat global_ambient1[] = {0.8, 0.8, 0.8, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient1);
    rownakCloud();
    glDisable(GL_LIGHTING);
    rownakRoad(day);
    glEnable(GL_LIGHTING);
    GLfloat global_ambient2[] = {1.8, 1.8, 1.8, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient2);
    rownak(day);
    glDisable(GL_LIGHTING);


    rownakRail();



    glEnable(GL_LIGHTING);
    GLfloat global_ambient3[] = {0.0,0.5,0.0, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient3);
    rownakJungle();
    glDisable(GL_LIGHTING);

    snow();
    if(carPosition<-0.8)
    {
        carPosition=-0.8;
    }



}
void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    if(secondScene==true && carPosition<-1.1)
    {

        carPosition=1.0;
        thirdScene=true;
        secondScene=false;
    }
    else if(secondScene==true && carPosition>1.1)
    {
        carPosition=1.1;

        secondScene=true;
    }


    if(day == true && secondScene==true)
    {
        dayParkView();

    }
    else if(day==false && secondScene==true)
    {
        nightParkView();

    }


    if(secondScene==true && carPosition<-1.1)
    {
        carPosition=1.0;
        secondScene=false;
        thirdScene=true;
    }
    else if(thirdScene==true && carPosition>1.1)
    {
        carPosition=-1.0;
        secondScene=true;
        thirdScene=false;
    }


    if(day == true && thirdScene==true)
    {
        rownakScenery();

    }
    else if(day==false && thirdScene==true)
    {
        nightrownakScenery();
    }
    if(isCarRight==false)
    {
        carLeft();
        if(thirdScene==true)
        {
            snow();
        }
    }
    else
    {
        carRight();
        if(thirdScene==true)
        {
            snow();
        }
    }
    glutSwapBuffers();
    glFlush();

}

int main(int argc,char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(755, 715);
    glutInitWindowPosition(1520/2 - 310,760/2 - 310);
    glutCreateWindow("Day&Night City View");
    glutDisplayFunc(display);

    glEnable(GL_BLEND);
    glutIdleFunc(idle);
    glutKeyboardFunc(KeyPress);
    glutTimerFunc(1000/60, SunUpdate, 0);
    glutTimerFunc(4100,DayUpdate,0);
    glutTimerFunc(1000/60, CarUpdate, 0);
    glutTimerFunc(30, SnowUpdate, 0);
    glutTimerFunc(25,CloudUpdate,0);
    glutTimerFunc(25,Cloud2Update,0);

    glutMainLoop();
    return 0;

}

