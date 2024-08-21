#include <GL/glut.h>
#include <glm/glm.hpp>
#include "src/drawers/furgDrawer.hpp"
#include "src/animators/animator.hpp"
#include "src/lights/light.hpp"

#include <iostream>

using vec3 = glm::vec3;

#define ORIGIN vec3(.0f, .0f, 0.0f)
#define RADIUS 0.6

GLfloat THETA = 45.f;
GLfloat FREQ  = 0.01f; 
GLfloat TX    = 2.f;
GLfloat LIMIT = .5f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glTranslatef(ORIGIN.x, ORIGIN.y, ORIGIN.z); 

    Animator::rotate(THETA);
    FurgDrawer::draw(ORIGIN, RADIUS);

    glutSwapBuffers();
}



void update(int value) {
    // if (TX <= LIMIT) TX += FREQ;
    // if (TX >= LIMIT) TX -= FREQ;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    ColorUtil::setBackground();
    glMatrixMode(GL_PROJECTION);

    Light::initLights();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 5.0,  // Eye position
              0.0, 0.0, 0.0,  // Look-at position
              0.0, 1.0, 0.0); // Up direction

    glLoadIdentity();
    
    //gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Furg Icon");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutMainLoop();

    return 0;
}