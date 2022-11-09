#include <GL/gl.h>
#include <GL/glut.h>

int rotateX = 25, rotateY = -25, rotateZ = 0, left = 0, top = 0, top2 = 0; 

float vertexCoords[24] = { 
    1, 1, 1, 1, 1, -1, 1, -1, -1, 1, -1, 1,
    -1, 1, 1, -1, 1, -1, -1, -1, -1, -1, -1, 1
};

float vertexColors[24] = { 
    1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0,
    0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1
};

int elementArray[24] = { 
    0, 1, 2, 3, 0, 3, 7, 4, 0, 4, 5, 1,
    6, 2, 1, 5, 6, 5, 4, 7, 6, 7, 3, 2
};

int edgeElementArray[24] = {
    0, 1, 1, 5, 5, 4, 4, 0,  
    7, 3, 3, 2, 2, 6, 6, 7, 
    1, 2, 0, 3, 4, 7, 5, 6   
};

float cubeCoords[72] = {
    1, 1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1,     
    1, 1, 1, 1, -1, 1, 1, -1, -1, 1, 1, -1,     
    1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1, 1,     
    -1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1,
    -1, -1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1, 
    -1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1, 1  
}; 
float cubeFaceColors[72] = {
	0,0,1,  0,0,1,  0,0,1,  0,0,1,   
    0.5,0.5,0.5,  0.5,0.5,0.5,  0.5,0.5,0.5,  0.5,0.5,0.5,    
    0,1,0,  0,1,0,  0,1,0,  0,1,0,     
    0,1,1,  0,1,1,  0,1,1,  0,1,1, 
    1,1,0,  1,1,0,  1,1,0,  1,1,0,       
    1,0,0,  1,0,0,  1,0,0,  1,0,0,      
};

float cubeFaceColors2[72] = {
	0,0,1,  0,0,1,  0,0,1,  0,0,1,   
    0.5,0.5,0.5,  0.5,0.5,0.5,  0.5,0.5,0.5,  0.5,0.5,0.5,    
	1,0,0,  1,0,0,  1,0,0,  1,0,0,   
    0,1,1,  0,1,1,  0,1,1,  0,1,1, 
    1,1,0,  1,1,0,  1,1,0,  1,1,0,       
    0,1,0,  0,1,0,  0,1,0,  0,1,0,
};

// ----------------------------------------------------------------------

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();         
    glTranslatef(left, top, 0); 

    glRotatef(rotateZ, 0, 0, 1); 
    glRotatef(rotateY, 0, 1, 0);
    glRotatef(rotateX, 1, 0, 0);

    glVertexPointer(3, GL_FLOAT, 0, cubeCoords); 
    glColorPointer(3, GL_FLOAT, 0, cubeFaceColors);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glDrawArrays(GL_QUADS, 0, 24); 

    // doi xung
//    glLoadIdentity();            
//    glTranslatef(left, top2, 0);      
//    
//    glRotatef(rotateZ, 0, 0, 1); 
//    glRotatef(rotateY, 0, 1, 0);
//    glRotatef(rotateX, 1, 0, 0);
//
//    glVertexPointer(3, GL_FLOAT, 0, cubeCoords); 
//    glColorPointer(3, GL_FLOAT, 0, cubeFaceColors2);
//
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnableClientState(GL_COLOR_ARRAY);
//    
//    glDrawArrays(GL_QUADS, 0, 24);
    
    glutSwapBuffers();
}

void specialKeyFunction(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)
        rotateY -= 15;
    else if (key == GLUT_KEY_RIGHT)
        rotateY += 15;
    else if (key == GLUT_KEY_DOWN)
        rotateX += 15;
    else if (key == GLUT_KEY_UP)
        rotateX -= 15;
    else if (key == GLUT_KEY_PAGE_UP)
        rotateZ += 15;
    else if (key == GLUT_KEY_PAGE_DOWN)
        rotateZ -= 15;
    else if (key == GLUT_KEY_HOME)
        rotateX = rotateY = rotateZ = 0;
    glutPostRedisplay();
}

void keyPressed(unsigned char key, int x, int y)
{
    if (key == 'l' || key == 'L')
        left -= 1;
    else if (key == 'r' || key == 'R')
        left += 1;

        
    else if (key == 't' || key == 'T')
        top += 1;
    else if (key == 'b' || key == 'B')
        top -= 1;
        
    glutPostRedisplay();
    
}

void initGL()
{
    glMatrixMode(GL_PROJECTION);
    glOrtho(-4, 4, -2, 2, -2, 2);
//    glOrtho(-6, 6, -2, 4, -2, 2);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(110, 110);
    glutCreateWindow("3D - Lab3B");
    initGL();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeyFunction);
    glutKeyboardFunc(keyPressed);
    glutMainLoop();
    return 0;
}
