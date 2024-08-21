#include <GL/glut.h>
#include <glm/glm.hpp>

using vec3 = glm::vec3;

vec3 lightPos = vec3(.0f, 0.5f, .0f);
vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

// Propriedades do Material
vec3 ambientColor = vec3(0.5f, 0.7f, 0.2f);
vec3 diffuseColor = vec3(1.0f, 0.0f, 0.0f);

class Light {
    public:
        static void initLights() {
                GLfloat ambientLight[4] = {0.6, 0.2, 0.2, 1.0};
                GLfloat diffuseLight[4] = {0.7, 0.7, 0.7, -0.2};
                GLfloat specularLight[4] = {1.0, 1.0, 1.0, 1.0};
                GLfloat lightPosition[4] = {0.0, -100.0, 250.0, 1.0};

                GLfloat materialSpecular[4] = {1.0, 1.0, 1.0, 1.0};
                GLint materialShininess = 95;

                // Set material properties
                glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
                glMateriali(GL_FRONT, GL_SHININESS, materialShininess);

                // Set transparent material properties
                GLfloat transparentMaterial[] = {0.0, 0.4, 0.8, 0.6}; // Transparent material color
                glMaterialfv(GL_FRONT, GL_DIFFUSE, transparentMaterial);

                // Set light properties
                glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
                glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
                glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

                // Enable lighting features
                glEnable(GL_COLOR_MATERIAL);
                glEnable(GL_LIGHTING);
                glEnable(GL_LIGHT0);
                glEnable(GL_MULTISAMPLE_ARB);
            }
};