#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void display(void);
void circle(int, int);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Desenhando uma circunferência");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (-128, 128, -128, 128, -1 ,1);
  glutDisplayFunc(display); 
  glutMainLoop();
  return 0;
}

void display(void)
{
  int x = 0;
  int y = 50;
  int d = 1 - 50;

  glClear(GL_COLOR_BUFFER_BIT);
  
  circle(x, y);

  while(y > x)
  {
    printf("testeWhile, d = %d, \n x = %d y = %d\n", d, x, y);
    if(d < 0)
    {
      d += 2*x + 3;
    }
    else
    {
      d += 2*(x-y) + 5;
      y--;
    }
    x++;
    circle(x,y);
  }
  glFlush();
}

void circle (int x, int y)
{
  printf("testeGL\n");
  
  glColor3f (0.0, 0.0, 1);
  glBegin(GL_POINTS);

  glVertex2i( x,  y);
  glVertex2i( y,  x);
  glVertex2i(-y,  x);
  glVertex2i( x, -y);
  glVertex2i(-x, -y);
  glVertex2i(-y, -x);
  glVertex2i( y, -x);
  glVertex2i(-x,  y);
  glEnd();
}




































