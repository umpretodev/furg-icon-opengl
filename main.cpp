#include <GL/glut.h>
#include <glm/glm.hpp>
#include "src/drawers/furgDrawer.hpp"

using vec3 = glm::vec3;

#define ORIGIN vec3(.0f, .0f, 0.0f)
#define RADIUS 0.6

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    FurgDrawer::draw(ORIGIN, RADIUS);

    glutSwapBuffers();
}

void init() {
    glClearColor(.0f, .0f, .0f, .0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Furg Icon");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}