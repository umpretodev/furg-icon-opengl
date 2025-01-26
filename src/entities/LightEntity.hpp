#include <glm/glm.hpp>
#include <GL/glut.h>
#include <iostream>

#ifndef LIGHTENTITY_HPP
#define LIGHTENTITY_HPP

class LightEntity {
    public: 
        static void disable() { glDisable(GL_LIGHTING); }
        static void enable() { glEnable(GL_LIGHTING); }

        static void initLights() {
            printf("Init lights\n");
            // GLfloat ambientLight[4] = {0.6, 0.2, 0.2, 1.0};
            // GLfloat diffuseLight[4] = {0.7, 0.7, 0.7, -0.2};
            // GLfloat specularLight[4] = {1.0, 1.0, 1.0, 1.0};
            // GLfloat lightPosition[4] = {0.0, -100.0, 250.0, 1.0};

            GLfloat materialSpecular[4] = {1.0, 1.0, 1.0, 1.0};
            GLint materialShininess = 95;

            // Set material properties
            glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
            glMateriali(GL_FRONT, GL_SHININESS, materialShininess);

            // Set transparent material properties
            GLfloat transparentMaterial[] = {0.0, 0.4, 0.8, 0.6}; // Transparent material color
            glMaterialfv(GL_FRONT, GL_DIFFUSE, transparentMaterial);

            // Set light properties
            // glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
            // glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
            // glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

            // Enable lighting features
            glEnable(GL_COLOR_MATERIAL);
            glEnable(GL_LIGHTING);
            glEnable(GL_LIGHT0);
            glEnable(GL_MULTISAMPLE_ARB);
        }

        static void setupLighting() {
            glEnable(GL_LIGHTING);
            glEnable(GL_LIGHT0);

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
};

#endif 