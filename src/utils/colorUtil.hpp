#ifndef COLOR_UTILS_HPP
#define COLOR_UTILS_HPP

#include <GL/glut.h>

class ColorUtil {
    public:
        static void setBackground() { glColor3f(.0f, .0f, .0f); }
        static void setOrange() { glColor3f(0.93f, 0.66f, 0.33f); }
        static void setYellow() { glColor3f(0.93f, 0.8f, 0.33f); }
        static void setRed()    { glColor3f(0.93f, 0.39f, 0.33f); }
        static void setWhite()  { glColor3f(1.0f, 1.0f, 1.0f);    }
};

#endif