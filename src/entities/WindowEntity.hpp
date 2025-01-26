#include <GL/glut.h>
#include <glm/glm.hpp>
#include "LightEntity.hpp"
#include <iostream>

using vec3 = glm::vec3;
using namespace std;

#define ORIGIN vec3(.0f, .0f, 0.0f)
#define RADIUS 0.6

GLfloat THETA = 45.f;
GLfloat FREQ  = 0.01f; 
GLfloat TX    = 2.f;
GLfloat LIMIT = .5f;

class WindowEntity {
    private:
        // Graphic pipeline init lights
        static void handleSetup() {
            printf("Entre aqui\n");
            glMatrixMode(GL_PROJECTION);
            LightEntity::initLights();
            LightEntity::setupLighting();
        }

        // Graphic pipeline run update
        static void update(int value) {
            glutPostRedisplay();
            glutTimerFunc(16, update, 0);
        }

        static void display() {
            glClear(GL_COLOR_BUFFER_BIT);

            LightEntity::initLights();
            LightEntity::setupLighting();

            glPushMatrix();

            glTranslatef(ORIGIN.x, ORIGIN.y, ORIGIN.z);

            //Animator::rotate(THETA);
            //GeometryEntity::run(ORIGIN, RADIUS);

            glutSwapBuffers();
        }

    public:
        void static run(int argc, char **argv) {
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
            glutInitWindowSize(1000, 1000);
            glutInitWindowPosition(100, 100);
            glutCreateWindow("Furg Icon");


            //handleSetup();
            glMatrixMode(GL_PROJECTION);
            LightEntity::initLights();
            LightEntity::setupLighting();

            glutDisplayFunc(display);

            glutTimerFunc(16, update, 0);
            glutMainLoop();
        }
};