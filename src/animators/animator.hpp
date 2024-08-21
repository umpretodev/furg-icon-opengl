#include <GL/glut.h>
#include <glm/glm.hpp>

using vec3 = glm::vec3;
using MatrixGL = GLfloat[16];

class Animator {
    private:
        static void toMatrixGL(GLfloat matrix[4][4], GLfloat matrixGL[16]) {
            int indexGL = 0;

           for (int line = 0; line < 4; line++) {
                for (int column = 0; column < 4; column++) {
                    matrixGL[indexGL++] = matrix[column][line];
                }
           }
        }


    public:
        void myTranslate(vec3 translation) {
            GLfloat tx = translation.x;
            GLfloat ty = translation.y;
            GLfloat tz = translation.z;


            GLfloat t[4][4] = {
                { 1.0f,  0.0f, 0.0f,  tx  },
                { 0.0f,  1.0f, 0.0f,  ty  },
                { 0.0f,  0.0f, 1.f,   tz  },
                { 0.0f,  0.0f, 0.0f, 1.0f }
            };

            GLfloat matrixGL[16];
            toMatrixGL(t, matrixGL);
        }

        static void myRotate(GLfloat theta) {
            GLfloat c = cos(glm::radians(theta));
            GLfloat s = sin(glm::radians(theta));

            GLfloat rotZ[4][4] = {
                { c,    -s,   0.0f,  0.0f },
                { s,     c,   0.0f,  0.0f },
                { 0.0f, 0.0f, 1.0f,  0.0f },
                { 0.0f, 0.0f, 0.0f,  1.0f }
            };

            GLfloat matrixGL[16];
            toMatrixGL(rotZ, matrixGL);
            glMultMatrixf(matrixGL);
        }


        static void rotate(GLfloat theta = 45) {
            glRotatef(glm::radians(theta), 0.0f, 0.0f, 1.0f);
        }
    
};