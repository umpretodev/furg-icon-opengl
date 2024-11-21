#include <GL/glut.h>
#include <glm/glm.hpp>
#include "LightEntity.hpp"

void setupCallBack() {
    glMatrixMode(GL_PROJECTION);
    LightEntity::initLights();
    LightEntity::setupLighting();
}