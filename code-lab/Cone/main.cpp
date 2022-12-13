#include <GL\glut.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble base=1;
GLdouble height=1.5;
GLint slices = 50;
GLint stacks = 50;


void displayCone(void)
{

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,0,-5);
    glColor3f(0, 0, 1); 
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0);
    glScalef(1.0,1.0,1.0);

    glutSolidCone(base,height,slices,stacks);
     
    glFlush();        
}

void reshapeCone(int x, int y)
{
    if (y == 0 || x == 0) return;  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
     
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
 
    glViewport(0,0,x,y);  
}

void idleCone(void)
{
    yRotated += 0.01;
    displayCone();
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(1000,500);
    glutCreateWindow("Cone");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    xRotated = yRotated = zRotated = 10.0;
    xRotated=70;
    yRotated=150;
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(displayCone);
    glutReshapeFunc(reshapeCone);
    glutIdleFunc(idleCone);
    glutMainLoop();
    return 0;
}
