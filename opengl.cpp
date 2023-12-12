#include <GL/glut.h>
#include <cmath>
#include <ctime>
#include <iostream>

// Global variables
int windowWidth = 800;
int windowHeight = 600;
float sunX = 0.0f;
float sunY = 0.0f;
float timeOfDay = 0.0f;

void drawSun() {
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow sun
    glTranslatef(sunX, sunY, 0.0f);
    glutSolidSphere(30, 30, 30); // Sun's size
    glTranslatef(-sunX, -sunY, 0.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Update the sun's position
    sunX = 200 * cos(timeOfDay);
    sunY = 200 * sin(timeOfDay);

    // Set the sky color based on time of day
    GLfloat skyColorR = 0.0;
    GLfloat skyColorG = 0.5 + 0.5 * sin(timeOfDay);
    GLfloat skyColorB = 0.5 + 0.5 * sin(timeOfDay);

    glClearColor(skyColorR, skyColorG, skyColorB, 1.0);

    drawSun();

    glutSwapBuffers();
}

void update(int value) {
    timeOfDay += 0.01; // Simulate the passage of time
    if (timeOfDay >= 2 * 3.14159265) {
        timeOfDay = 0.0;
    }

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, update, 0);
}

void reshape(int w, int h) {
    windowWidth = w;
    windowHeight = h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Sunrise and Sunset");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000 / 60, update, 0);

    glutMainLoop();

    return 0;
}
