#include <GL/glut.h>
#include <glm/glm.hpp>
#include "../utils/colorUtil.hpp"

using vec3 = glm::vec3;

class FurgDrawer {
    private:
        void static drawNeutralComponent(vec3 origin, GLfloat radius) {
            glDisable(GL_LIGHTING);
                ColorUtil::setBackground();
                GLfloat RIGHT_SIDE  = origin.x + (radius * .7f);
                GLfloat LEFT_SIDE   = origin.x - (radius * .7f);
                GLfloat UP_SIDE     = origin.y + (radius * .7f);
                GLfloat BOTTOM_SIDE = origin.y - (radius * .7f);

                
                GLfloat L = radius * 0.1;
                GLfloat l = radius * 0.05;

                GLfloat RIGHT_INSIDE  = RIGHT_SIDE - 2*L;
                GLfloat LEFT_INSIDE   = LEFT_SIDE  +  2*L;
                GLfloat BOTTOM_INSIDE = BOTTOM_SIDE + 2*L;
                GLfloat UP_INSIDE = UP_SIDE + 0.2; 

                // External Component
                glBegin(GL_QUADS);
                    glVertex3d(LEFT_SIDE - L, BOTTOM_SIDE, 0);
                    glVertex3d(LEFT_SIDE, BOTTOM_SIDE, 0);
                    glVertex3d(LEFT_SIDE, UP_SIDE + .1, 0);
                    glVertex3d(LEFT_SIDE - L, UP_SIDE + .1, 0);
                glEnd();

                glBegin(GL_QUADS);
                    glVertex3d(RIGHT_SIDE + L, BOTTOM_SIDE, 0);
                    glVertex3d(RIGHT_SIDE, BOTTOM_SIDE, 0);
                    glVertex3d(RIGHT_SIDE, UP_SIDE + .1, 0);
                    glVertex3d(RIGHT_SIDE + L, UP_SIDE + .1, 0);
                glEnd();

                glBegin(GL_QUADS);
                    glVertex3d(LEFT_SIDE  - .1, BOTTOM_SIDE, 0);
                    glVertex3d(LEFT_SIDE  - .1, BOTTOM_SIDE - L, 0);
                    glVertex3d(RIGHT_SIDE + .1, BOTTOM_SIDE - L, 0);
                    glVertex3d(RIGHT_SIDE + .1, BOTTOM_SIDE, 0);
                glEnd();


                // Internal Component
                glBegin(GL_QUADS);
                    glVertex3d(LEFT_INSIDE + l, BOTTOM_INSIDE, 0);
                    glVertex3d(LEFT_INSIDE, BOTTOM_INSIDE, 0);
                    glVertex3d(LEFT_INSIDE, UP_INSIDE, 0);
                    glVertex3d(LEFT_INSIDE + l, UP_INSIDE, 0);
                glEnd();
                
                glBegin(GL_QUADS);
                    glVertex3d(RIGHT_INSIDE - l, BOTTOM_INSIDE, 0);
                    glVertex3d(RIGHT_INSIDE, BOTTOM_INSIDE, 0);
                    glVertex3d(RIGHT_INSIDE, UP_INSIDE, 0);
                    glVertex3d(RIGHT_INSIDE - l, UP_INSIDE, 0);
                glEnd();
                
                glBegin(GL_QUADS);
                    glVertex3d(LEFT_INSIDE, BOTTOM_INSIDE, 0);
                    glVertex3d(LEFT_INSIDE, BOTTOM_INSIDE + l, 0);
                    glVertex3d(RIGHT_INSIDE, BOTTOM_INSIDE + l, 0);
                    glVertex3d(RIGHT_INSIDE - l, BOTTOM_INSIDE, 0);
                glEnd();
            glEnable(GL_LIGHTING);
        }


        void static drawOrangeComponent(vec3 center, GLfloat radius) {
            ColorUtil::setOrange();

            glBegin(GL_POLYGON);
                int segmentsNumber = 200;

                for (int i = 0; i < segmentsNumber; i++) {
                    float theta = (2 * M_PI * float(i)) / float(segmentsNumber);
                    float x = radius * cos(theta);
                    float y = radius * sin(theta);

                    glVertex3f(x + center.x, center.y + y, center.z);
                }

            glEnd();
        }

        void static drawRedComponent(vec3 origin, GLfloat radius) {
            ColorUtil::setRed();

            GLfloat RIGHT_SIDE = origin.x + (radius * .7f);
            GLfloat LEFT_SIDE  = origin.x - (radius * .7f);
            GLfloat UP_SIDE = origin.y + (radius * .72f);
            GLfloat BOTTOM_SIDE = origin.y - (radius * .7f);

            GLfloat TIP = radius * 0.18; 
            GLfloat L = radius * .2f;

            glBegin(GL_QUADS);
                glVertex3d(LEFT_SIDE + L, BOTTOM_SIDE, 0);
                glVertex3d(LEFT_SIDE, BOTTOM_SIDE, 0);
                glVertex3d(LEFT_SIDE, UP_SIDE, 0);
                glVertex3d(LEFT_SIDE + L, UP_SIDE + TIP, 0);
            glEnd();

            glBegin(GL_QUADS);
                glVertex3d(RIGHT_SIDE - L, BOTTOM_SIDE, 0);
                glVertex3d(RIGHT_SIDE, BOTTOM_SIDE, 0);
                glVertex3d(RIGHT_SIDE, UP_SIDE, 0);
                glVertex3d(RIGHT_SIDE - L, UP_SIDE + TIP, 0);
            glEnd();

            glBegin(GL_QUADS);
                glVertex3d(LEFT_SIDE, BOTTOM_SIDE, 0);
                glVertex3d(LEFT_SIDE, BOTTOM_SIDE + L, 0);
                glVertex3d(RIGHT_SIDE, BOTTOM_SIDE + L, 0);
                glVertex3d(RIGHT_SIDE, BOTTOM_SIDE, 0);
            glEnd();
        }

        static void drawEllipse(vec3 p1, vec3 p2, float b) {
            ColorUtil::setYellow();

            float a = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)) / 2.0f; 
            float cx = (p1.x + p2.x) / 2.0f;
            float cy = (p1.y + p2.y) / 2.0f;

            float angle = atan2(p2.y - p1.y, p2.x - p1.x);

            glBegin(GL_POLYGON); 
                for (int i = 0; i < 360; i++) {
                    float theta = i * (M_PI / 180.0f);
                    float x = a * cos(theta);
                    float y = b * sin(theta);

                    float xr = x * cos(angle) - y * sin(angle);
                    float yr = x * sin(angle) + y * cos(angle);

                    glVertex2f(cx + xr, cy + yr);
                }
            glEnd();
        }

        static void drawYellowComponent(vec3 origin, GLfloat radius) {
            ColorUtil::setYellow();

            GLfloat RIGHT_SIDE = origin.x + (radius * .45f);
            GLfloat LEFT_SIDE = origin.x - (radius * .45f);
            GLfloat UP_SIDE = origin.y + (radius * 1.f);
            GLfloat BOTTOM_SIDE = origin.y - (radius * .45f);

            glBegin(GL_QUADS);
                glVertex3d(LEFT_SIDE, BOTTOM_SIDE, 0);
                glVertex3d(LEFT_SIDE, UP_SIDE, 0);
                glVertex3d(RIGHT_SIDE, UP_SIDE, 0);
                glVertex3d(RIGHT_SIDE, BOTTOM_SIDE, 0);
            glEnd();


            vec3 vertex1 = vec3(RIGHT_SIDE, UP_SIDE, 0);
            vec3 vertex2 = vec3(LEFT_SIDE, UP_SIDE, 0);
            GLfloat b = radius * .15;


            FurgDrawer::drawEllipse(vertex1, vertex2, b);
        }

    public:
        static void draw(vec3 origin, GLfloat radius) {
            drawOrangeComponent(origin, radius);
            drawYellowComponent(origin, radius);
            drawRedComponent(origin, radius);
            drawNeutralComponent(origin, radius);
        }

        static void eraseBackground(vec3 origin, GLfloat radius) {
            drawNeutralComponent(origin, radius);
        }
};