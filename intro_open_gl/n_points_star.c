#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define PI 3.1415
#define CENTER_X 100
#define CENTER_Y 75
#define DOTS_QUANTITY 8

GLfloat degreesToRadians(GLfloat degrees) { return degrees * PI / 180; }

int init(void) {  // inicia os parâmetros de rendering
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void display(void) {  // função callback chamada para fazer o desenho
  int rInternal = 20;
  int rExternal = 50;
  int gap = 360 / DOTS_QUANTITY;
  int pointPositionExternal = 90 - gap + 1;
  int pointPositionIternal = (pointPositionExternal + 90) / 2 + 1;

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_LINE_LOOP);
  glColor3f(0.0, 0.0, 0.0);

  for (GLint i = 0; i < DOTS_QUANTITY; i++) {
    int xExternal =
        CENTER_X + 50 * cos(degreesToRadians(pointPositionExternal));
    int yExternal =
        CENTER_Y + 50 * sin(degreesToRadians(pointPositionExternal));

    int xInternal = CENTER_X + 20 * cos(degreesToRadians(pointPositionIternal));
    int yInternal = CENTER_Y + 20 * sin(degreesToRadians(pointPositionIternal));

    glVertex2i(xExternal, yExternal);

    glVertex2i(xInternal, yInternal);

    pointPositionIternal += gap;
    pointPositionExternal += gap;
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
