#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

#define RAND_FLOAT() ((float)rand() / RAND_MAX)

int init();
void display();
void desenhaCasa();
void transformObject();
void rotate2D(GLfloat rotangle);
void movimentaQuadrado();
void scale2D(GLfloat incx, GLfloat incy, GLfloat maxx, GLfloat minx);

GLfloat rfx, rfy, sx, sy, angle, tx, ty;
bool increasing;

int main(int argc, char **argv)
{

  srand(time(NULL));
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(200, 0); // posição da janela
  glutInitWindowSize(400, 300);   // largura e altura da janela
  glutCreateWindow("Animação");   // cria a janela

  init();                   // executa função de inicialização
  glutDisplayFunc(display); // função "display" como a função de
                            // callback de exibição

  glutMainLoop(); // mostre tudo e espere
  return 0;
}

int init(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0); // define a cor de fundo

  glMatrixMode(GL_PROJECTION); // carrega a matriz de projeção
  gluOrtho2D(0, 200, 0, 150);  // define projeção ortogonal 2D que
                               // mapeia objetos da coordenada do
                               // mundo para coordenadas da tela
  rfx = 100;
  rfy = 65;
  sx = sy = 1;
  angle = 0;
  tx = 0;
  increasing = true;

  return 0;
}

void desenhaCasa(void)
{
  glBegin(GL_POLYGON);
  glVertex2f(110, 50);
  glVertex2f(110, 70);
  glVertex2f(100, 80);
  glVertex2f(90, 70);
  glVertex2f(90, 50);
  glEnd();
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glMatrixMode(GL_MODELVIEW);

  glPushMatrix();
  glLoadIdentity();
  movimentaQuadrado();
  glBegin(GL_QUADS);
  glVertex2f(0, 20);
  glVertex2f(20, 20);
  glVertex2f(20, 0);
  glVertex2f(0, 0);
  glEnd();
  // glTranslatef(0, 1, 0);
  // movimentaQuadrado();
  glPopMatrix();

  glutPostRedisplay();
  glutSwapBuffers();
}
int speedx = 1;
int speedy = 1;
bool isLeft = false;

void movimentaQuadrado()
{

  srand(time(NULL));

  tx += speedx;
  ty += speedy;

  if (tx == 180 || tx == 0)
  {
    speedx *= -1;

    glClearColor(RAND_FLOAT(), RAND_FLOAT(), RAND_FLOAT(), 0.0); // define a cor de fundo
  }
  if (ty == 130 || ty == 0)
  {
    speedy *= -1;

    glClearColor(RAND_FLOAT(), RAND_FLOAT(), RAND_FLOAT(), 0.0); // define a cor de fundo
  }

  glTranslatef(tx, ty, 0);
}
