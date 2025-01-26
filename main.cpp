#include "src/GraphicPipeline.hpp"
#include <GL/glut.h>

#include "src/entities/LightEntity.hpp"

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    // Pipeline Orchestration
    GraphicPipeline::handleGeometryModelingStage1();
    GraphicPipeline::handleTransformationStage2();
    
    GraphicPipeline::handleLightStage3();
    //LightEntity::initLights();

    GraphicPipeline::handleProjectionStage4();
    glutSwapBuffers();
}

void update(int value) {
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Furg Icon");

    GraphicPipeline::handleSetup();

    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutMainLoop();

    return 0;
}