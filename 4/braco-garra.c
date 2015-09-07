 #include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, m_fing = 0, i_fing = 0, p_fing = 0;

void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void){
  glClear (GL_COLOR_BUFFER_BIT);
  glPushMatrix();

  /* origem posicionada no ombro */
  glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
  /* origem posicionada no centro do braco */ 
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube (1.0);
  glPopMatrix();
   
  /* origem posicionada no cotovelo */
  glTranslatef (1.0, 0.0, 0.0);
  glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
  // origem posicionada no centro do antebraço
  glTranslatef (1.0, 0.0, 0.0);
  glPushMatrix();
  glScalef (2.0, 0.4, 1.0);
  glutWireCube (1.0);
  glPopMatrix();
  

  // dedo indicador
  glPushMatrix();
  glTranslatef (1.0, 0.20, 0.4);
  glRotatef ((GLfloat) i_fing, 0.0 , 0.0, 1.0);
  glTranslatef (0.25, 0.0, 0.0);
  glScalef(0.5 , 0.1, 0.25);
  glutWireCube(1.0);
  glPopMatrix();

  // dedo do meio
  glPushMatrix();
  glTranslatef (1.0, 0.20, -0.4);
  glRotatef ((GLfloat) m_fing, 0.0 , 0.0, 1.0);
  glTranslatef (0.25, 0.0, 0.0);
  glScalef(0.5 , 0.1, 0.25);
  glutWireCube(1.0);
  glPopMatrix();


  // dedo poelgar
  glPushMatrix();
  glTranslatef (1.0, -0.20, 0.0);
  glRotatef ((GLfloat) p_fing, 0.0 , 0.0, 1.0);
  glTranslatef (0.25, -0.0, 0.0);
  glScalef(0.5 , 0.1, 0.25);
  glutWireCube(1.0);
  glPopMatrix();

  /* origem volta para o sistema de coordenadas original */
  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -5.0);
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 's':
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'S':
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 'e':
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;
  case 'E':
    elbow = (elbow - 5) % 360;
    glutPostRedisplay();
    break;
  case 'i':
    i_fing = (i_fing - 5) % 360;
    glutPostRedisplay();
    break;
  case 'I':
    i_fing = (i_fing + 5) % 360;
    glutPostRedisplay();
    break;
  case 'p':
    p_fing = (p_fing - 5) % 360;
    glutPostRedisplay();
    break;
  case 'P':
    p_fing = (p_fing + 5) % 360;
    glutPostRedisplay();
    break;
  case 'm':
    m_fing = (m_fing - 5) % 360;
    glutPostRedisplay();
    break;
  case 'M':
    m_fing = (m_fing + 5) % 360;
    glutPostRedisplay();
    break;

  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}