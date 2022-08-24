#include <GL/glut.h>
#include <stdio.h>

int init(void) {  // inicia os parâmetros de rendering
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void display(void) {  // função callback chamada para fazer o desenho
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(5.0);
  glBegin(GL_POINTS);
  glVertex2i(180, 15);
  glVertex2i(20, 145);
  glVertex2i(15, 180);
  glVertex2i(145, 20);
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
