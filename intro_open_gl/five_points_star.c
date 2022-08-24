#include <GL/glut.h>
#include <stdio.h>

int init(void) {  // inicia os parâmetros de rendering
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void display(void) {  // função callback chamada para fazer o desenho
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLE_STRIP);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2i(100, 140);
  glVertex2i(80, 100);
  glVertex2i(120, 100);

  glVertex2i(30, 100);
  glVertex2i(65, 60);

  glVertex2i(170, 100);
  glVertex2i(135, 60);

  glVertex2i(65, 60);
  glVertex2i(30, 10);
  glVertex2i(100, 35);

  glVertex2i(90, 45);
  glVertex2i(170, 10);
  glVertex2i(135, 60);

  glEnd();

  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(200, 0);
  glutInitWindowSize(400, 300);

  glutCreateWindow("Exemplo de programa openGL");

  init();

  glutDisplayFunc(display);
  glutMainLoop();
}
