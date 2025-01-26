#include <GL/glut.h>
#include <glm/glm.hpp>

#include "../globals/GLOBALS.hpp"

class PerspectiveEntity {
    public:
        static void setOrtogonalProjection() {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            glOrtho(
                GLOBAL_LEFT_PROJECTION, 
                GLOBAL_RIGHT_PROJECTION,
                GLOBAL_TOP_PROJECTION, 
                GLOBAL_BOTTOM_PROJECTION, 
                GLOBAL_NEARVAL_PROJECTION, 
                GLOBAL_FARVAL_PROJECTION
            );

            glMatrixMode(GL_MODELVIEW);
        }

        static void setPerspectiveProjection() {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            gluPerspective(
                45.0,
                .1,//(GLOBAL_RIGHT_PROJECTION - GLOBAL_LEFT_PROJECTION) / (GLOBAL_TOP_PROJECTION - GLOBAL_BOTTOM_PROJECTION),
                .1,//GLOBAL_NEARVAL_PROJECTION,
                1.//GLOBAL_FARVAL_PROJECTION
            );
            
            glMatrixMode(GL_MODELVIEW);
        }

};
