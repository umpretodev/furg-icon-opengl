#include <GL/glut.h>
#include <glm/glm.hpp>
#include "GeometryEntity.hpp"

using vec3 = glm::vec3;

void displayCallback(vec3 origin, GLfloat radius) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glutSwapBuffers();

    GeometryEntity::run(origin, radius);
}