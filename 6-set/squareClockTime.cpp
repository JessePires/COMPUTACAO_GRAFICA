#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

#define RAND_FLOAT() ((float)rand() / RAND_MAX)
#define SECONDS_GAP 360 / 60
#define MINUTE_GAP SECONDS_GAP / 60
#define HOURS_GAP 360 / 12

int init();
void display();
void desenhaCasa();
void transformObject();
void rotate2D(GLfloat rotangle);
void movimentaQuadrado();
void scale2D(GLfloat incx, GLfloat incy, GLfloat maxx, GLfloat minx);

GLfloat rfx, rfy, sx, sy, angle, tx, ty;
bool increasing;
time_t rawtime;
struct tm *info;
float minuteArrowDegree = 0;
float hourArrowDegree = 0;

int main(int argc, char **argv)
{

  srand(time(NULL));
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(200, 0); // posição da janela
  glutInitWindowSize(500, 500);   // largura e altura da janela
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
  gluOrtho2D(0, 500, 0, 500);  // define projeção ortogonal 2D que
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

void drawCircle(double radius)
{
  glColor3f(0, 0, 0);
  glBegin(GL_LINE_LOOP); // Middle circle;
  double ori_x = 250;    // the origin or center of circle
  double ori_y = 250;
  for (int i = 0; i <= 360; i++)
  {
    double angle = 2 * M_PI * i / 360;
    double x = cos(angle) * radius;
    double y = sin(angle) * radius;
    glVertex2d(ori_x + x, ori_y + y);
  }
  glEnd();
}

void drawBars(double outerRadius, double innerRadius, int gap)
{

  glColor3f(0, 0, 0);
  glBegin(GL_LINES);  // Middle circle;
  double ori_x = 250; // the origin or center of circle
  double ori_y = 250;
  for (int i = 0; i <= 360; i += gap)
  {
    double angle = 2 * M_PI * i / 360;
    double x1 = cos(angle) * outerRadius;
    double y1 = sin(angle) * outerRadius;

    double x2 = cos(angle) * innerRadius;
    double y2 = sin(angle) * innerRadius;
    glVertex2d(ori_x + x1, ori_y + y1);
    glVertex2d(ori_x + x2, ori_y + y2);
  }
  glEnd();
}

void drawLine(GLfloat center, GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b)
{
  glColor3f(r, g, b);

  glBegin(GL_LINES);
  glVertex2d(center, center);
  glVertex2d(x, y);
  glEnd();
}

void handleSecondsArrow()
{
  glPushMatrix();
  glTranslatef(250, 250, 0);
  glRotatef(info->tm_sec * SECONDS_GAP * -1, 0, 0, 1);
  glTranslatef(-250, -250, 0);

  drawLine(250, 250, 430, 0, 1, 0); // segundos
  glPopMatrix();
}

void handleMinutesArrow()
{
  minuteArrowDegree = info->tm_min * SECONDS_GAP;
  float secondsPadding = info->tm_sec / 60.0 * 6.0;
  glPushMatrix();
  glTranslatef(250, 250, 0);
  glRotatef((minuteArrowDegree + secondsPadding) * -1, 0, 0, 1);
  glTranslatef(-250, -250, 0);

  drawLine(250, 250, 400, 1, 0, 0); // minutes
  glPopMatrix();
}

void handleHoursArrow()
{
  hourArrowDegree = info->tm_hour * HOURS_GAP;
  float minutesPadding = info->tm_min / 60.0 * 6.0;
  glPushMatrix();
  glTranslatef(250, 250, 0);
  glRotatef((hourArrowDegree + minutesPadding) * -1, 0, 0, 1);
  glTranslatef(-250, -250, 0);

  drawLine(250, 250, 380, 0, 0, 1); // hora
  glPopMatrix();
}

void display(void)
{
  time(&rawtime);
  info = localtime(&rawtime);

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glMatrixMode(GL_MODELVIEW);

  glLineWidth(2.0);
  drawCircle(240);
  drawBars(220, 190, SECONDS_GAP);
  drawBars(220, 160, HOURS_GAP);

  glLineWidth(4.0);
  handleHoursArrow();

  glLineWidth(3.0);
  handleMinutesArrow();

  glLineWidth(2.0);
  handleSecondsArrow();

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
