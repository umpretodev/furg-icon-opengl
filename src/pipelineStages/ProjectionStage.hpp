#include "../entities/PerspectiveEntity.hpp"

class ProjectionStage {
    public:
        static void handleOrtogonalProjection() {
            PerspectiveEntity::setOrtogonalProjection();
        }


        static void handlePerspectiveProjection() {
            PerspectiveEntity::setPerspectiveProjection();
        }
};