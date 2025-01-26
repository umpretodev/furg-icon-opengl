#include <glm/glm.hpp>
#include "../entities/GeometryEntity.hpp"

class GeometryModelingStage {
    public:
        static void run(vec3 origin, GLfloat radius) {
            GeometryEntity::run(GLOBAL_ORIGIN, GLOBAL_RADIUS);
        }
};