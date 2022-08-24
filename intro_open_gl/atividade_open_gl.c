#include <GL/glut.h>
#include <stdio.h>

int init(void) {  // inicia os parâmetros de rendering
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void display(void) {  // função callback chamada para fazer o desenho
  glClear(GL_COLOR_BUFFER_BIT);

  // CHÃO
  glBegin(GL_LINES);
  glColor3f(0.0, 1.0, 0.0);
  glVertex2i(20, 20);
  glVertex2i(180, 20);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(0.58, 0.29, 0.0);

  // PAREDE ESQUERDA
  glVertex2i(60, 85);
  glVertex2i(60, 20);

  // PAREDE DIREITA
  glVertex2i(140, 85);
  glVertex2i(140, 20);

  // PISO
  glVertex2i(60, 20);
  glVertex2i(140, 20);
  glEnd();

  // JANELAS
  glPointSize(15.0);
  glBegin(GL_POINTS);
  glColor3f(0.0, 1.0, 1.0);
  glVertex2i(80, 50);
  glVertex2i(120, 50);
  glEnd();

  // TETO
  glBegin(GL_TRIANGLES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2i(100, 125);
  glVertex2i(60, 85);
  glVertex2i(140, 85);
  glEnd();

  // PORTA
  glBegin(GL_QUAD_STRIP);
  glColor3f(0.58, 0.29, 0.0);
  glVertex2i(90, 55);
  glVertex2i(110, 55);
  glVertex2i(90, 20);
  glVertex2i(110, 20);
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
