/* -*- c++ -*- */

// Compila: g++ -c -std=c++17 main.cpp -lglut -lGLU -lGL
// Linka:   g++ -o a.out main.o -lglut -lGLU -lGL
// ...o usa make

#include <GL/glut.h>

void dibujar(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 0.0, 0.0);
    glVertex3f(0.0, 0.6, 0.0);
    glVertex3f(0.8, 0.4, 0.0);
    glVertex3f(0.4, 0.4, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hola mundo 3D");
    glutDisplayFunc(dibujar);
    glutMainLoop();
    return 0;
}
