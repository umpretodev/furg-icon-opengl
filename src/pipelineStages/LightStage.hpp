#include "../entities/LightEntity.hpp"
#include <glm/glm.hpp>
#include <GL/glut.h>

using vec3 = glm::vec3;

class LightStage {
    public:
        static void run() {
            LightEntity::initLights();
            LightEntity::setupLighting();
        }
};