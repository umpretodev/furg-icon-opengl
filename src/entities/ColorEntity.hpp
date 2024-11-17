#include <GL/glut.h>

class ColorEntity {
    public:
        static void setBlack() { glColor3f(.0f, .0f, .0f); }
        static void setOrange() { glColor3f( .93f, 0.66f, .33f); }
        static void setYellow() { glColor3f(1.f, .8f, .33f); }
        static void setRed() { glColor3f(.93f, .39f, .33f); }
        static void setWhite() { glColor3f(1.f, 1.f, 1.f); }
};