#include <GL/glut.h>
#include <glm/glm.hpp>
#include "ColorEntity.hpp"
#include "LightEntity.hpp"

using vec3 = glm::vec3;

#ifndef GEOMETRYeNTITY_HPP
#define GEOMETRYeNTITY_HPP

class GeometryEntity {
private:
    void static renderNeutralComponent(vec3 origin, GLfloat radius, GLfloat deep = 0) {

        LightEntity::disable();

            ColorEntity::setBlack();

            // Configurations setup
            GLfloat RIGHT_SIDE = origin.x + (radius * .7f);
            GLfloat LEFT_SIDE = origin.x - (radius * .7f);
            GLfloat UP_SIDE = origin.y + (radius * .55f);
            GLfloat BOTTOM_SIDE = origin.y - (radius * .7f);
            GLfloat TIP = radius * 0.18f;

            GLfloat L = radius * 0.1;
            GLfloat l = radius * 0.05;

            GLfloat RIGHT_INSIDE = RIGHT_SIDE - 2 * L;
            GLfloat LEFT_INSIDE = LEFT_SIDE + 2 * L;
            GLfloat BOTTOM_INSIDE = BOTTOM_SIDE + 2 * L;
            GLfloat UP_INSIDE = UP_SIDE + 0.2;

            // EXTERNAL COMPONENT
            // Make polygon (left)
            glBegin(GL_QUADS);
            glVertex3d(LEFT_SIDE - L, BOTTOM_SIDE, deep);
            glVertex3d(LEFT_SIDE, BOTTOM_SIDE, deep);
            glVertex3d(LEFT_SIDE, UP_SIDE + TIP, deep);
            glVertex3d(LEFT_SIDE - L, UP_SIDE, deep);
            glEnd();

            // Make polygon (right)
            glBegin(GL_QUADS);
            glVertex3d(RIGHT_SIDE + L, BOTTOM_SIDE, deep);
            glVertex3d(RIGHT_SIDE, BOTTOM_SIDE, deep);
            glVertex3d(RIGHT_SIDE, UP_SIDE + TIP, deep);
            glVertex3d(RIGHT_SIDE + L, UP_SIDE, deep);
            glEnd();

            // Make polygon (bottom)
            glBegin(GL_QUADS);
            glVertex3d(LEFT_SIDE - .06, BOTTOM_SIDE, deep);
            glVertex3d(LEFT_SIDE - .06, BOTTOM_SIDE - L, deep);
            glVertex3d(RIGHT_SIDE + .06, BOTTOM_SIDE - L, deep);
            glVertex3d(RIGHT_SIDE + .06, BOTTOM_SIDE, deep);
            glEnd();

            // INTERNAL COMPONENT
            // Make polygon (left)
            glBegin(GL_QUADS);
            glVertex3d(LEFT_INSIDE + l, BOTTOM_INSIDE, deep);
            glVertex3d(LEFT_INSIDE, BOTTOM_INSIDE, deep);
            glVertex3d(LEFT_INSIDE, UP_INSIDE, deep);
            glVertex3d(LEFT_INSIDE + l, UP_INSIDE, deep);
            glEnd();

            // Make polygon (right)
            glBegin(GL_QUADS);
            glVertex3d(RIGHT_INSIDE - l, BOTTOM_INSIDE, deep);
            glVertex3d(RIGHT_INSIDE, BOTTOM_INSIDE, deep);
            glVertex3d(RIGHT_INSIDE, UP_INSIDE, deep);
            glVertex3d(RIGHT_INSIDE - l, UP_INSIDE, deep);
            glEnd();

            // Make Polygon (bottom)
            glBegin(GL_QUADS);
            glVertex3d(LEFT_INSIDE, BOTTOM_INSIDE, deep);
            glVertex3d(LEFT_INSIDE, BOTTOM_INSIDE + l, deep);
            glVertex3d(RIGHT_INSIDE, BOTTOM_INSIDE + l, deep);
            glVertex3d(RIGHT_INSIDE - l, BOTTOM_INSIDE, deep);
            glEnd();
        LightEntity::enable();
    }

    void static renderOrangeComponent(vec3 center, GLfloat radius, GLfloat deep = 0) {
        
        ColorEntity::setOrange();

        glBegin(GL_POLYGON);
        int segmentsNumber = 200;

        for (int i = 0; i < segmentsNumber; i++) {
            float theta = (2 * M_PI * float(i)) / float(segmentsNumber);
            float x = radius * cos(theta);
            float y = radius * sin(theta);

            glVertex3f(x + center.x, center.y + y, center.z + deep);
        }
        glEnd();

        // Render sides
        if (deep) {
            ColorEntity::setOrange();
            glBegin(GL_POLYGON_BIT);
            for (int i = 0; i < segmentsNumber + 100; i++) {
                float theta = (2 * M_PI * float(i)) / float(segmentsNumber);
                float x = radius * cos(theta);
                float y = radius * sin(theta);

                glVertex3f(x + center.x, center.y + y, center.z);
                glVertex3f(x + center.x, center.y + y, center.z + deep);
            }
            glEnd();
        }
    }

    void static renderRedComponent(vec3 origin, GLfloat radius, GLfloat deep = 0) {
        ColorEntity::setRed();

        GLfloat RIGHT_SIDE = origin.x + (radius * .7f);
        GLfloat LEFT_SIDE = origin.x - (radius * .7f);
        GLfloat UP_SIDE = origin.y + (radius * .72f);
        GLfloat BOTTOM_SIDE = origin.y - (radius * .7f);

        GLfloat TIP = radius * 0.18;
        GLfloat L = radius * .2f;

        glBegin(GL_QUADS);
            glVertex3d(LEFT_SIDE + L, BOTTOM_SIDE, deep);
            glVertex3d(LEFT_SIDE, BOTTOM_SIDE, deep);
            glVertex3d(LEFT_SIDE, UP_SIDE, deep);
            glVertex3d(LEFT_SIDE + L, UP_SIDE + TIP, deep);
        glEnd();

        glBegin(GL_QUADS);
        glVertex3d(RIGHT_SIDE - L, BOTTOM_SIDE, deep);
        glVertex3d(RIGHT_SIDE, BOTTOM_SIDE, deep);
        glVertex3d(RIGHT_SIDE, UP_SIDE, deep);
        glVertex3d(RIGHT_SIDE - L, UP_SIDE + TIP, deep);
        glEnd();

        glBegin(GL_QUADS);
        glVertex3d(LEFT_SIDE, BOTTOM_SIDE, deep);
        glVertex3d(LEFT_SIDE, BOTTOM_SIDE + L, deep);
        glVertex3d(RIGHT_SIDE, BOTTOM_SIDE + L, deep);
        glVertex3d(RIGHT_SIDE, BOTTOM_SIDE, deep);
        glEnd();
    }

    static void renderEllipse(vec3 p1, vec3 p2, float b, GLfloat deep = 0) {
        ColorEntity::setYellow();

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

            glVertex3f(cx + xr, cy + yr, deep);
        }
        glEnd();

        if (deep) {
            glBegin(GL_POLYGON);
            for (int i = 0; i < 720; i++) {
                float theta = i * (M_PI / 180.0f);
                float x = a * cos(theta);
                float y = b * sin(theta);

                float xr = x * cos(angle) - y * sin(angle);
                float yr = x * sin(angle) + y * cos(angle);

                glVertex3f(cx + xr, cy + yr, 0);
                glVertex3f(cx + xr, cy + yr, deep);
            }
            glEnd();
        }
    }

    static void renderYellowComponent(vec3 origin, GLfloat radius, GLfloat deep = 0) {
        ColorEntity::setYellow();

        GLfloat RIGHT_SIDE = origin.x + (radius * .45f);
        GLfloat LEFT_SIDE = origin.x - (radius * .45f);
        GLfloat UP_SIDE = origin.y + (radius * 1.f);
        GLfloat BOTTOM_SIDE = origin.y - (radius * .45f);

        glBegin(GL_QUADS);
            glVertex3d(LEFT_SIDE, BOTTOM_SIDE, deep);
            glVertex3d(LEFT_SIDE, UP_SIDE, deep);
            glVertex3d(RIGHT_SIDE, UP_SIDE, deep);
            glVertex3d(RIGHT_SIDE, BOTTOM_SIDE, deep);
        glEnd();

        vec3 vertex1 = vec3(RIGHT_SIDE, UP_SIDE, deep);
        vec3 vertex2 = vec3(LEFT_SIDE, UP_SIDE, deep);
        GLfloat b = radius * .15;

        renderEllipse(vertex1, vertex2, b);
        renderEllipse(vertex1, vertex2, b, -.2f);
    }

public:
    static void run(vec3 origin, GLfloat radius) {
        // RENDER FRONT SIDE
        renderOrangeComponent(origin, radius);
        renderYellowComponent(origin, radius);
        renderRedComponent(origin, radius);
        renderNeutralComponent(origin, radius);

        // Render BACK SIDE
        renderOrangeComponent(origin, radius, -.2f);
        renderYellowComponent(origin, radius, -.2f);
        renderRedComponent(origin, radius, -.2f);
        renderNeutralComponent(origin, radius, -.2f);
    }
};

#endif