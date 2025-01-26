
#include <GL/glut.h>
#include <iostream>

#include "../globals/GLOBALS.hpp"

using vec3 = glm::vec3;
using namespace std;

class WindowStage {
    private:
        static void update(int value) {
            glutPostRedisplay();
            glutTimerFunc(16, update, 0);
        }

        static void display() {
            glClear(GL_COLOR_BUFFER_BIT);
            glPushMatrix();
            //glTranslatef(GLOBAL_ORIGIN.x, GLOBAL_ORIGIN.y, GLOBAL_ORIGIN.z);
            glutSwapBuffers();
        }

    public:
        static void run() {
            cout << "Running window_stage" << endl;
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
            glutInitWindowSize(1000, 1000);
            glutInitWindowPosition(100, 100);
            glutCreateWindow("Furg Icon");
            
            //glutDisplayFunc(display);
            //glutTimerFunc(16, update, 0);
            //glutMainLoop();
        }
};