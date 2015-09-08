#include <GL/glut.h>
#include <stdlib.h>

GLubyte tux[] = 
{
 0x0, 0x0, 0x0, 0x0,   
 0x0, 0x0, 0x0, 0x0,   
 0x0, 0x0, 0xf, 0xff, 
 0x0, 0x0, 0xa, 0x1,   
 0x0, 0x0, 0xa, 0x1,   
 0x0, 0x0, 0xa, 0x1,   
 0x0, 0x0, 0xa, 0xf, 
 0x0, 0x0, 0xa, 0x0,   
 0x0, 0x0, 0xa, 0x1,   
 0x0, 0x0, 0xa, 0x1,   
 0x0, 0x0, 0xa, 0x1,   
 0x0, 0x0, 0xa, 0x1,   
 0x0, 0x0, 0xa, 0x1,   
 0x0, 0x0, 0xf, 0xff, 
 0x0, 0x0, 0x0, 0x0,
   
 0x0, 0x0, 0x0, 0x0, 
 0xe, 0x2, 0x0, 0x0, 
 0xa, 0x2, 0x0, 0x0, 
 0xa, 0x4, 0x0, 0x0, 
 0xa, 0x4, 0x0, 0x0, 
 0xa, 0x8, 0x0, 0x0, 
 0xa, 0x8, 0x0, 0x0, 
 0xb, 0xff,0x0, 0x0, 
 0xa, 0x1, 0x0, 0x0, 
 0xa, 0x1, 0x0, 0x0, 
 0xa, 0x1, 0x0, 0x0, 
 0xa, 0x1, 0x0, 0x0, 
 0xa, 0x1, 0x0, 0x0, 
 0xa, 0x1, 0x0, 0x0,
 0xf, 0xff,0x0, 0x0,
 0x0, 0x0, 0x0, 0x0, 
 0x0, 0x0, 0x0, 0x0
 
};

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (300, 300); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Padrão de preenchimento");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (-300, 300, -300, 300, -1 ,1);
}

void display(void)
{
  int i;  

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (0,0,1);
  glBegin(GL_POLYGON);
  glVertex2i(-200,0);  
  glVertex2i(-110,200);
  glVertex2i(110,200); 
  glVertex2i(200,0);
  glVertex2i(110,-200);
  glVertex2i(-110,-200);
  glEnd();

  glEnable(GL_POLYGON_STIPPLE);
  //glColor3f(1.0, 0.0, 1.0);
  glPolygonStipple(tux);


  glFlush();
  glutSwapBuffers();
}