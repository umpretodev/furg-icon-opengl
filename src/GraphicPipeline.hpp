#include <GL/glut.h>
#include <glm/glm.hpp>

#include "pipelineStages/WindowStage.hpp"
#include "pipelineStages/GeometryModelingStage.hpp"
#include "pipelineStages/LightStage.hpp"
#include "pipelineStages/TransformationStage.hpp"
#include "pipelineStages/ProjectionStage.hpp"

#include "globals/GLOBALS.hpp"

#include "entities/LightEntity.hpp"

#include <iostream>


using vec3 = glm::vec3;
using namespace std;

class GraphicPipeline {
    public:
        static void handleSetup() {
            ColorEntity::setBlack();
            //glMatrixMode(GL_PROJECTION);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();

            gluLookAt(
                0.0, 0.0, 5.0, // Eye position
                0.0, 0.0, 0.0, // Look-at position
                0.0, 1.0, 0.0  // Up direction
            );

            glLoadIdentity();
            glEnable(GL_DEPTH_TEST);
        }

        static void handleGeometryModelingStage1() {
            GeometryModelingStage::run(GLOBAL_ORIGIN, GLOBAL_RADIUS);
        }

        static void handleTransformationStage2() {
            TransformationStage::run();
        }

        static void handleLightStage3() {
            LightStage::run();
        }

        static void handleProjectionStage4() {
            ProjectionStage::handleOrtogonalProjection();
            //ProjectionStage::handlePerspectiveProjection();
        }
};