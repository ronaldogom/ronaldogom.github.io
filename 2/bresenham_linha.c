#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Desenhando uma linha");
  init();
  glutDisplayFunc(display); 
  glutMainLoop();
  return 0;
}

void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
}

void display(void)
{
	int x1 = 40;
	int x2 = 200;
	int y1 = 200;
	int y2 = 10;
	int Delta_x = abs(x2-x1);
	int Delta_y = abs(y2-y1);

	int y = y1;
	int x = x1;

	int new_e = 2*Delta_y - Delta_x;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.5, 0.0);
	glBegin(GL_POINTS);

	for(int i=1; i <= Delta_x; i++)
	{
		glVertex2i(x,y);
		while(new_e >= 0)
		{
			y = y -1;
			new_e = new_e - 2*Delta_x;
		}

		x = x + 1;
		new_e = new_e + 2*Delta_y;
	}
	  
	glEnd();
	glFlush();
}