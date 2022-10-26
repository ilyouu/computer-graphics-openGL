#include <GL/gl.h>
#include <GL/glut.h>


int rotateX = 25, rotateY = -25, rotateZ = 0, left = 0;  // rotation amounts about axes, controlled by keyboard


/* Arrays for use with glDrawElements.  This is the data for a cube with 6 different
 * colors at the six vertices.  (Looks kind of strange without lighting.)
 */

float vertexCoords[24] = {  // Coordinates for the vertices of a cube.
           1,1,1,   1,1,-1,   1,-1,-1,   1,-1,1,
          -1,1,1,  -1,1,-1,  -1,-1,-1,  -1,-1,1  };
          
float vertexColors[24] = {  // An RGB color value for each vertex
           1,1,1,   1,0,0,   1,1,0,   0,1,0,
           0,0,1,   1,0,1,   0,0,0,   0,1,1  };
          
int elementArray[24] = {  // Vertex number for the six faces.
          0,1,2,3, 0,3,7,4, 0,4,5,1,
          6,2,1,5, 6,5,4,7, 6,7,3,2  };
          
          
/* We will draw edges for the first cube using this array with glDrawElements.
 * (It looks pretty bad without lighting if edges aren't drawn.
 */
  
int edgeElementArray[24] = {
        0,1,  1,5,  5,4,  4,0,    // edges of the top face
        7,3,  3,2,  2,6,  6,7,    // edges of the bottom face
        1,2,  0,3,  4,7,  5,6  
}; // edges connecting top face to bottom face

/* Arrays for use with glDrawArrays.  The coordinate array contains four sets of vertex
 * coordinates for each face.  The color array must have a color for each vertex.  Since
 * the color of each face is solid, there is a lot of redundancy in the color array.
 * There is also redundancy in the coordinate array, compared to using glDrawElements.
 * But note that it is impossible to use a single call to glDrawElements to draw a cube 
 * with six faces where each face has a different solid color, since with glDrawElements, 
 * the colors are associated with the vertices, not the faces.
 */

float cubeCoords[72] = {
       1,1,1,    -1,1,1,   -1,-1,1,   1,-1,1,      // face #1
       1,1,1,     1,-1,1,   1,-1,-1,  1,1,-1,      // face #2
       1,1,1,     1,1,-1,  -1,1,-1,  -1,1,1,       // face #3
       -1,-1,-1, -1,1,-1,   1,1,-1,   1,-1,-1,     // face #4
       -1,-1,-1, -1,-1,1,  -1,1,1,   -1,1,-1,      // face #5
       -1,-1,-1,  1,-1,-1,  1,-1,1,   -1,-1,1  };  // face #6

float cubeFaceColors[72] = {
        1,0,0,  1,0,0,  1,0,0,  1,0,0,      // face #1 is red
        0,1,0,  0,1,0,  0,1,0,  0,1,0,      // face #2 is green
        0,0,1,  0,0,1,  0,0,1,  0,0,1,      // face #3 is blue
        1,1,0,  1,1,0,  1,1,0,  1,1,0,      // face #4 is yellow
        0,1,1,  0,1,1,  0,1,1,  0,1,1,      // face #5 is cyan
        1,0,1,  1,0,1,  1,0,1,  1,0,1,   }; // face #6 is red


// ----------------------------------------------------------------------


void display() {
       // called when the display needs to be drawn
       
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();             // Set up modelview transform, first cube.
    glTranslatef(left, 0, 0);     // Move cube to left half of window.
    
    glRotatef(rotateZ,0,0,1);     // Apply rotations.
    glRotatef(rotateY,0,1,0);
    glRotatef(rotateX,1,0,0);
    
    glVertexPointer( 3, GL_FLOAT, 0, cubeCoords );  // Set data type and location, first cube.
    glColorPointer( 3, GL_FLOAT, 0, cubeFaceColors );

    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );

    glDrawArrays( GL_QUADS, 0, 24 ); // Draw the first cube!
    
    
    glutSwapBuffers();
}


void specialKeyFunction(int key, int x, int y) {
        // called when a special key is pressed 
    if ( key == GLUT_KEY_LEFT )
       rotateY -= 15;
    else if ( key == GLUT_KEY_RIGHT )
       rotateY += 15;
    else if ( key == GLUT_KEY_DOWN)
       rotateX += 15;
    else if ( key == GLUT_KEY_UP )
       rotateX -= 15;
    else if ( key == GLUT_KEY_PAGE_UP )
       rotateZ += 15;
    else if ( key == GLUT_KEY_PAGE_DOWN )
       rotateZ -= 15;
    else if ( key == GLUT_KEY_HOME )
       rotateX = rotateY = rotateZ = 0;
    glutPostRedisplay();
}

void keyPressed(unsigned char key, int x, int y) {
	if ( key == 'l' )
       left -= 1;
    else if ( key == 'L' )
       left -= 1;
    else if ( key == 'r' )
       left += 1;
    else if ( key == 'R' )
       left += 1;
    glutPostRedisplay();
}

void initGL() {
        // called by main() to do initialization for this program.
    glMatrixMode(GL_PROJECTION);
    glOrtho(-4, 4, -2, 2, -2, 2);   // simple orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1);    
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(110,110);
    glutCreateWindow("3D - Mo Hinh Mat Da Giac");
    initGL();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeyFunction);
    glutKeyboardFunc(keyPressed);  
    glutMainLoop();
    return 0;
}
