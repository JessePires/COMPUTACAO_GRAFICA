#include <GL/glut.h>

void init(void) {
    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(0, 200, 0, 150);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glVertex2i(150, 100); //tr
        glVertex2i(150, 50);  //br
        glVertex2i(70, 50);   //bl
        glVertex2i(70, 100);  //tl
    glEnd();

  
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(400, 300);

    glutCreateWindow("Exemplo de programa OpenGL");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}