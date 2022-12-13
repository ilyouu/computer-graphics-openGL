#include <vector>
#include <gl\glut.h>

typedef std::vector<float> floatvec;

float posX = 4.12f;
float posY = -4.87f;
float posZ = -3.84f;
float angleX = 343.25f;
float angleY = -45.00f;

float fMin = 0.5;
float fMax = 100.0;
float alpha = 60.0;

// Ve hinh chu nhat 3d
void DrawQuad(floatvec c) {
    glBegin(GL_QUADS);
    glVertex3f(-c[0], -c[1], -c[2]);
    glVertex3f(-c[3], -c[4], -c[5]);
    glVertex3f(-c[6], -c[7], -c[8]);
    glVertex3f(-c[9], -c[10], -c[11]);
    glEnd();
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();
    glRotatef(angleY, 2.0f, 0.0f, 0.0f);
    glRotatef(angleX, 0.0f, 1.0f, 1.0f);
    glRotatef(180.0, 0.0f, 0.0f, 1.0f);
    glTranslatef(posX, posY, posZ);

    // Ve o
    glColor3f(0, 1, 1); 
    std::vector<float> g1; 
        g1.push_back(0);
        g1.push_back(0);
        g1.push_back(0);
        g1.push_back(5);
        g1.push_back(0);
        g1.push_back(0);
        g1.push_back(5);
        g1.push_back(0);
        g1.push_back(5);
        g1.push_back(0);
        g1.push_back(0);
        g1.push_back(5);
    DrawQuad(g1);
    glColor3f(1, 1, 0);
    std::vector<float> g2; 
        g2.push_back(0);
        g2.push_back(3);
        g2.push_back(0);
        g2.push_back(5);
        g2.push_back(3);
        g2.push_back(0);
        g2.push_back(5);
        g2.push_back(3);
        g2.push_back(5);
        g2.push_back(0);
        g2.push_back(3);
        g2.push_back(5);
    DrawQuad(g2);

    glPopMatrix();
    glutSwapBuffers();
}

void Reshape(int width, int height) {
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(alpha, (GLfloat)width / (GLfloat)height, fMin, fMax);
    glMatrixMode(GL_MODELVIEW);
}

int main(int iArgc, char** cppArgv) {
    glutInit(&iArgc, cppArgv);
    glEnable(GL_DEPTH_TEST);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (650,650);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Deep-sorting");
    glutDisplayFunc(Display);
    glutIdleFunc(Display);
    glutReshapeFunc(Reshape);
    glutMainLoop();
    return 0;
}

