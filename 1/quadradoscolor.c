#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void display(void);
void timer(int);
void keyboard(unsigned char key, int x, int y);

/* cores do quadrado HSI */
GLfloat h=0, s=1, i=1;
GLfloat r=0, g=0, b=0;

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow (argv[0]);
  // inicia um temporizador. após 33ms ativa a funcao timer
  glutTimerFunc(10, timer, 1);
  glClearColor(1.0, 1.0, 1.0, 0.0);
  //glShadeModel (GL_FLAT);
  glOrtho (0, 1, 0, 1, -1 ,1);
  glutDisplayFunc(display);
  glutMainLoop();
  
  return 0;
}

GLfloat rad (int h)
{
  return h*3.14/180;
}

void timer(int value)
{

  h = h + 0.5;
  
  if (h > 360) h = 0;

  if((h >= 0) && (h < 120))
  {    
    b = i*(1-s)/3;
    r = i/3*(1+((s*cosf(rad(h))/(cosf(rad(60)-rad(h))))));
    g = 3*i - (r+b);
  } 
  else if((h >= 120) && (h < 240))
  {
    r = i*(1-s)/3;
    g = i*(1+((s*cosf(rad(h-120)))/(cosf(rad(60)-rad(h-120)))));
    b = 3*i - (r+g);
  }
  else if((h >= 240) && (h < 360))
  {
    g = i*(1-s)/3;
    b = i*(1+((s*cosf(rad(h-240)))/(cosf(rad(60)-rad(h-240)))));
    r = 3*i - (g+b);
  }

  printf("%0.2f\n", h);

  printf("r = %0.2f, g = %0.2f, b = %0.2f\n", r, g, b);

  //if(r>1) r=1;
  //if(g>1) g=1;
  //if(b>1) b=1;

  glutPostRedisplay();
  glutTimerFunc(10, timer, 1);
  
}

void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (r, g, b);
  glBegin(GL_POLYGON);
  glVertex2f(0.25,0.25);
  glVertex2f(0.75,0.25);
  glVertex2f(0.75,0.75);
  glVertex2f(0.25,0.75);

  glEnd();
  glFlush();
}