#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

class wcPt2c {
 public:
  GLfloat x, y;
};

wcPt2c object[4];

GLfloat degreesToRadians(GLfloat degrees) { return degrees * (M_PI / 180.0); }

void rotatePolygon(wcPt2c* verts, GLint nVerts, GLdouble theta) {
  for (GLint i = 0; i < nVerts; i++) {
    verts[i].x = verts[i].x * cos(degreesToRadians(theta)) -
                 verts[i].y * sin(degreesToRadians(theta));

    verts[i].y = verts[i].x * sin(degreesToRadians(theta)) +
                 verts[i].y * cos(degreesToRadians(theta));
  }
}

int init(void) {  // inicia os parâmetros de rendering
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 200.0, 0.0, 150.0);

  object[0].x = 70;
  object[0].y = 70;

  object[1].x = 70;
  object[1].y = 90;

  object[2].x = 90;
  object[2].y = 90;

  object[3].x = 90;
  object[3].y = 70;

  return 0;
}

void display(void) {  // função callback chamada para fazer o desenho
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0, 0.0, 0.0);
  glPointSize(5.0);

  glBegin(GL_LINE_LOOP);

  for (GLint i = 0; i < 4; i++) {
    glVertex2i(object[i].x, object[i].y);
  }

  glEnd();

  glBegin(GL_LINE_LOOP);
  rotatePolygon(object, 4, -20);

  for (GLint i = 0; i < 4; i++) {
    glVertex2i(object[i].x, object[i].y);
  }

  glEnd();

  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(200, 0);
  glutInitWindowSize(700, 500);

  glutCreateWindow("Exemplo de programa openGL");

  init();

  glutDisplayFunc(display);
  glutMainLoop();
}