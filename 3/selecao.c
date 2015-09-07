#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

GLfloat rl1,gl1,bl1,rl2,gl2,bl2,rl3,gl3,bl3,rl4,gl4,bl4;
GLfloat rf1,gf1,bf1,rf2,gf2,bf2,rf3,gf3,bf3,rf4,gf4,bf4;
bool b = false;
bool f = false;

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Preenchendo regiões");
  init();
  glutDisplayFunc(display); 
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}

void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
  rl1=rl2=rl3=rl4=0; gl1=gl2=gl3=gl4=0; bl1=bl2=bl3=bl4=0;
  rf1=rf2=rf3=rf4=1; gf1=gf2=gf3=gf4=1; bf1=bf2=bf3=bf4=0;
}

void display(void)
{
  int i;
  glClear(GL_COLOR_BUFFER_BIT);

  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rf1, gf1, bf1);
  glBegin(GL_POLYGON);
  glVertex2i(30,226);  glVertex2i(113,226);
  glVertex2i(113,143); glVertex2i(30,143);
  glEnd();
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rl1, gl1, bl1);
  glBegin(GL_POLYGON);
  glVertex2i(30,226);  glVertex2i(113,226);
  glVertex2i(113,143); glVertex2i(30,143);
  glEnd();

  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rf2, gf2, bf2);
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143);
  glEnd();
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rl2, gl2, bl2);
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143);
  glEnd();

  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rf3, gf3, bf3);
  glBegin(GL_POLYGON);
  glVertex2i(30,113); glVertex2i(113,113);
  glVertex2i(113,30); glVertex2i(30,30); 
  glEnd();
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rl3, gl3, bl3);
  glBegin(GL_POLYGON);
  glVertex2i(30,113); glVertex2i(113,113);
  glVertex2i(113,30); glVertex2i(30,30); 
  glEnd();

  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rf4, gf4, bf4);
  glBegin(GL_POLYGON);
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30);  glVertex2i(143,30);
  glEnd();
  glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rl4, gl4, bl4);
  glBegin(GL_POLYGON);
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30);  glVertex2i(143,30); 
  glEnd();

  glFlush();

  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key) 
  {
    case 'b':
      b = true;
      f = false;
      break;
    case 'f':
      b = false;
      f = true;
      break;
  }
}

void mouse(int button, int state, int x, int y)
{
  switch (button) 
  {
    case GLUT_LEFT_BUTTON:
	    if (state == GLUT_DOWN) 
      {
        if(b)
        {
          if(30 <= x && x <= 113)
          {
            if(143 <= y && y <= 226)
            {
              rl3=(GLfloat)rand()/(RAND_MAX+1.0);
              gl3=(GLfloat)rand()/(RAND_MAX+1.0);
              bl3=(GLfloat)rand()/(RAND_MAX+1.0);
            }
            else if(30 <= y && y <= 133)
            {
              rl1=(GLfloat)rand()/(RAND_MAX+1.0);
              gl1=(GLfloat)rand()/(RAND_MAX+1.0);
              bl1=(GLfloat)rand()/(RAND_MAX+1.0);
            }
            
          }
          else if(143 <= x && x <= 226)
          {
            if(143 <= y && y <= 226)
            {
              rl4=(GLfloat)rand()/(RAND_MAX+1.0);
              gl4=(GLfloat)rand()/(RAND_MAX+1.0);
              bl4=(GLfloat)rand()/(RAND_MAX+1.0);
            }
            else if(30 <= y && y <= 133)
            {
              rl2=(GLfloat)rand()/(RAND_MAX+1.0);
              gl2=(GLfloat)rand()/(RAND_MAX+1.0);
              bl2=(GLfloat)rand()/(RAND_MAX+1.0);
            }
          }
        }
        else if(f)
        {
          if(30 <= x && x <= 113)
          {
            if(143 <= y && y <= 226)
            {
              rf3=(GLfloat)rand()/(RAND_MAX+1.0);
              gf3=(GLfloat)rand()/(RAND_MAX+1.0);
              bf3=(GLfloat)rand()/(RAND_MAX+1.0);
            }
            else if(30 <= y && y <= 133)
            {
              rf1=(GLfloat)rand()/(RAND_MAX+1.0);
              gf1=(GLfloat)rand()/(RAND_MAX+1.0);
              bf1=(GLfloat)rand()/(RAND_MAX+1.0);
            }
            
          }
          else if(143 <= x && x <= 226)
          {
            if(143 <= y && y <= 226)
            {
              rf4=(GLfloat)rand()/(RAND_MAX+1.0);
              gf4=(GLfloat)rand()/(RAND_MAX+1.0);
              bf4=(GLfloat)rand()/(RAND_MAX+1.0);
            }
            else if(30 <= y && y <= 133)
            {
              rf2=(GLfloat)rand()/(RAND_MAX+1.0);
              gf2=(GLfloat)rand()/(RAND_MAX+1.0);
              bf2=(GLfloat)rand()/(RAND_MAX+1.0);
            }
          }
        }
        glutPostRedisplay();
      }
      break;
  }
}