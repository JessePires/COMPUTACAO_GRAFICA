#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define PI 3.1415
#define CENTER 100
#define RADIUS 30

int init(void) {  // inicia os parâmetros de rendering
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}

void display(void) {  // função callback chamada para fazer o desenho
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POLYGON);
  glColor3f(0.0, 0.0, 0.0);

  for (int i = 0; i < 360; i++) {
    float theta = i * PI / 180;
    glVertex2f(CENTER + RADIUS * cos(theta), CENTER + RADIUS * sin(theta));
  }

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
