#include <GL/glut.h>
#include <glm/glm.hpp>

using vec3 = glm::vec3;

class PhongLighting
{
public:
    static void setupLighting() {
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0); // Ativando a luz 0

        // Configurações da luz
        GLfloat lightPosition[] = {1.0f, 1.0f, 1.0f, 1.0f};
        GLfloat lightAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
        GLfloat lightDiffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
        GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};

        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

        // Configurações do material
        GLfloat materialAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
        GLfloat materialDiffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
        GLfloat materialSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
        GLfloat materialShininess = 50.0f;

        glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
        glMaterialf(GL_FRONT, GL_SHININESS, materialShininess);
    }

    static void enable() {
        glEnable(GL_LIGHTING);
    }

    static void disable() {
        glDisable(GL_LIGHTING);
    }
};
