#include <stdio.h>
#include <GL/glut.h>

class wcPt2c {
    public: GLfloat x, y;
};

wcPt2c object[4];

void translatePolygon(wcPt2c *verts, GLint nVerts, GLfloat tx, GLfloat ty) {
    for (GLint i = 0; i < nVerts; i++) {
        verts[i].x = verts[i].x + tx;
        verts[i].y = verts[i].y + ty;
    }
}

int init (void) { // inicia os parâmetros de rendering
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
}

void display (void) { // função callback chamada para fazer o desenho 
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5.0);
    
    glBegin(GL_LINE_LOOP);
    
    for (GLint i = 0; i < 4; i++) {
        glVertex2i(object[i].x, object[i].y);
    }
    
    glEnd();

    glBegin(GL_LINE_LOOP);
    translatePolygon(object, 4, 5, 6);

    for (GLint i = 0; i < 4; i++) {
        glVertex2i(object[i].x, object[i].y);
    }
    glEnd();

    glFlush();
}

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(400, 300);

    glutCreateWindow("Exemplo de programa openGL");

    init();

    glutDisplayFunc(display);
    glutMainLoop();
}