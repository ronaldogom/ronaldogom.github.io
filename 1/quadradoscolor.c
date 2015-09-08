#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
void display(void);
void timer(int);
void keyboard(unsigned char key, int x, int y);
 
GLfloat h1=0,   s1=1, i1=1;
GLfloat h2=90,  s2=1, i2=1;
GLfloat h3=180, s3=1, i3=1;
GLfloat h4=270, s4=1, i4=1;
 
 
GLfloat r1=0, g1=0, b1=0;
GLfloat r2=0, g2=0, b2=0;
GLfloat r3=0, g3=0, b3=0;
GLfloat r4=0, g4=0, b4=0;
 
 
GLfloat rad(int h){
  return h*3.14/180;
}
 
void convert(GLfloat h, GLfloat s, GLfloat i, int pos){
 
    GLfloat r, g, b;
 
    if(pos==1)      {r=r1; g=g1; b=b1;}
    else if(pos==2) {r=r2; g=g2; b=b2;}
    else if(pos==3) {r=r3; g=g3; b=b3;}
    else if(pos==4) {r=r4; g=g4; b=b4;}
 
    if((h >= 0) && (h < 120))
    {    
        b = i*(1-s)/3;
        r = i*(1+((s*cos(rad(h))/(cos(rad(60)-rad(h))))));
        g = 3*i - (r+b); 
    } 
    else if((h >= 120) && (h < 240))
    {
        r = i*(1-s)/3;
        g = i*(1+((s*cos(rad(h-120)))/(cos(rad(60)-rad(h-120)))));
        b = 3*i - (r+g);
    }
    else if((h >= 240) && (h < 360))
    {
        g = i*(1-s)/3;
        b = i*(1+((s*cos(rad(h-240)))/(cos(rad(60)-rad(h-240)))));
        r = 3*i - (g+b);
    }
 
    if(pos==1)      {r1=r; g1=g; b1=b;}
    else if(pos==2) {r2=r; g2=g; b2=b;}
    else if(pos==3) {r3=r; g3=g; b3=b;}
    else if(pos==4) {r4=r; g4=g; b4=b;}
 
}
 
void timer(int value){
 
    h1 += 1;
    h2 += 1;
    h3 += 1;
    h4 += 1;
 
    if (h1 > 360) h1=0;
    if (h2 > 360) h2=0;
    if (h3 > 360) h3=0;
    if (h4 > 360) h4=0;
 
    convert(h1, s1, i1, 1);
    convert(h2, s2, i2, 2);
    convert(h3, s3, i3, 3);
    convert(h4, s4, i4, 4);
 
    glutPostRedisplay();
    glutTimerFunc(10, timer, 1);
}
 
 
void display(void){
    int i;
 
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f (r1, g1, b1);
    
    glVertex2f(0.1,0.1);
    glColor3f (r2, g2, b2);
    glVertex2f(0.9,0.1);
    glColor3f (r3, g3, b3);
    glVertex2f(0.9,0.9);
    glColor3f (r4, g4, b4);
    glVertex2f(0.1,0.9);
    
    glEnd();
 
 
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (256, 256); 
    glutInitWindowPosition (100, 100); 
    glutCreateWindow (argv[0]);
 
    glutTimerFunc(10, timer, 1);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    //glShadeModel (GL_FLAT);
    glOrtho (0, 1, 0, 1, -1 ,1);
    glutDisplayFunc(display);
    glutMainLoop();
 
    return 0;
}