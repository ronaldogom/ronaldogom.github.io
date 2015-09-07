#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void display(void);
void timer(int);
void keyboard(unsigned char key, int x, int y);
/* cores do quadrado */
GLfloat r=1.0, g=0.5, b=0.0;
int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow (argv[0]);
  // inicia um temporizador. após 33ms ativa a funcao timer

  glClearColor(1.0, 1.0, 1.0, 0.0); //Specify the red, green, blue, and alpha values used when the color buffers are cleared. The initial values are all 0. 
  glShadeModel(GL_SMOOTH); //select flat or smooth shading
  glOrtho(0, 1, 0, 1, -1 ,1); //This will remap the OpenGL coordinates into the equivalent pixel values
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  
  glColor3f (r, g, b);
  glBegin(GL_POLYGON);
  glVertex2f(0.1,0.1);
  glVertex2f(0.1,0.4);
  glVertex2f(0.4,0.4);
  glVertex2f(0.4,0.1);

  glEnd();

  glColor3f (0.0, 1.0, 0.0);

  glBegin(GL_POLYGON);
  glVertex2f(0.6,0.1);
  glVertex2f(0.6,0.4);
  glVertex2f(0.9,0.4);
  glVertex2f(0.9,0.1);

  glEnd();

  glColor3f (0.0, 0.0, 1.0);

  glBegin(GL_POLYGON);
  glVertex2f(0.1,0.6);
  glVertex2f(0.1,0.9);
  glVertex2f(0.4,0.9);
  glVertex2f(0.4,0.6);

  glEnd();

  glColor3f (1.0, 0.0, 0.0);

  glBegin(GL_POLYGON);
  glVertex2f(0.6,0.6);
  glVertex2f(0.6,0.9);
  glVertex2f(0.9,0.9);
  glVertex2f(0.9,0.6);

  glEnd();
  glFlush();
}