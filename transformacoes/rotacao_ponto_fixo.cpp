#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

class wcPt2c {
 public:
  GLfloat x, y;
};

wcPt2c objectCoordinates[4];

GLfloat degreesToRadians(GLfloat degrees) { return degrees * (M_PI / 180.0); }

void rotatePolygon(wcPt2c* verts, GLint nVerts, GLdouble theta,
                   GLdouble x_rotate, GLdouble y_rotate) {
  for (GLint i = 0; i < nVerts; i++) {
    verts[i].x = x_rotate +
                 (verts[i].x - x_rotate) * cos(degreesToRadians(theta)) -
                 (verts[i].y - y_rotate) * sin(degreesToRadians(theta));

    verts[i].y = y_rotate +
                 (verts[i].x - x_rotate) * sin(degreesToRadians(theta)) +
                 (verts[i].y - y_rotate) * cos(degreesToRadians(theta));
  }
}

int init(void) {  // inicia os parâmetros de rendering
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 200.0, 0.0, 150.0);

  objectCoordinates[0].x = 70;
  objectCoordinates[0].y = 70;

  objectCoordinates[1].x = 70;
  objectCoordinates[1].y = 90;

  objectCoordinates[2].x = 90;
  objectCoordinates[2].y = 90;

  objectCoordinates[3].x = 90;
  objectCoordinates[3].y = 70;

  return 0;
}

void display(void) {  // função callback chamada para fazer o desenho
  GLdouble x_rotate = 70;
  GLdouble y_rotate = 70;

  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0, 0.0, 0.0);
  glPointSize(5.0);

  glBegin(GL_LINE_LOOP);

  for (GLint i = 0; i < 4; i++) {
    glVertex2i(objectCoordinates[i].x, objectCoordinates[i].y);
  }

  glEnd();

  glBegin(GL_LINE_LOOP);
  rotatePolygon(objectCoordinates, 4, 180, x_rotate, y_rotate);

  for (GLint i = 0; i < 4; i++) {
    glVertex2i(objectCoordinates[i].x, objectCoordinates[i].y);
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
