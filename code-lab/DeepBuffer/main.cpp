#include <GL/glut.h>
#include <windows.h>

GLfloat color[6][3] = {{1,1,1},{1,1,0},{1,0,0},{0,0,0},
						{0,1,1},{0,0,1}};
struct Point3D{
	float x,y,z;
	Point3D(float x, float y, float z){
		this->x = x; this->y = y; this->z = z;
	}
	Point3D(){
		x=0;y=0;z=0;
	}
};
Point3D p0(0,0,0), p1(0,0,1) ,p2(1,0,1), p3(1,0,0);
Point3D p4(0,1,0), p5(0,1,1) ,p6(1,1,1), p7(1,1,0);

float angle=0;
//hien thi chu
void drawText(float xPos, float yPos, float zPos, char str[]){
	glRasterPos3f(xPos,yPos,zPos);
	void * font = GLUT_BITMAP_9_BY_15;
	for(int i=0; i<strlen(str); i++){
		glutBitmapCharacter(font, str[i]);
	}
}
//ve mat phang
void drawSquare(Point3D a, Point3D b, Point3D c, Point3D d, GLfloat color[3]){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
	glLineWidth(2);
	glColor3fv(color);
	glBegin(GL_POLYGON);
		glVertex3f(a.x, a.y, a.z);
		glVertex3f(b.x, b.y, b.z);
		glVertex3f(c.x, c.y, c.z);
		glVertex3f(d.x, d.y, d.z);
	glEnd();
}
//hien thi cac diem tren truc
void drawVertexsName(){
	glColor3f(1,1,1);
	drawText(p0.x,p0.y,p0.z,"0");
	drawText(p1.x,p1.y,p1.z,"1");
	drawText(p2.x,p2.y,p2.z,"2");
	drawText(p3.x,p3.y,p3.z,"3");
	
	drawText(p4.x,p4.y,p4.z,"4");
	drawText(p5.x,p5.y,p5.z,"5");
	drawText(p6.x,p6.y,p6.z,"6");
	drawText(p7.x,p7.y,p7.z,"7");	
}
// truc toa do
void drawAxis(){
	glLineWidth(5);
	glBegin(GL_LINES);
		glColor3f(1,1,0);
		glVertex3f(0,0,0);
		glVertex3f(2,0,0);
		
		glColor3f(0,1,1);
		glVertex3f(0,0,0);
		glVertex3f(0,2,0);
		
		glColor3f(1,0,1);
		glVertex3f(0,0,0);
		glVertex3f(0,0,2);
	glEnd();
	glColor3f(1,1,1);
	drawText(1.9,0,0, "X");
	drawText(0,1.7,0, "Y");
	drawText(0,0.03,1.5, "Z");
}
void mydisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.7,0.5,0.3,0,0,0,0,1,0);
	glRotatef(angle,0,1,0);
	drawVertexsName();
	drawAxis();
	drawSquare(p0,p1,p2,p3,color[0]);
	drawSquare(p7,p3,p0,p4,color[1]);

	glFlush();
}
void mySpecialFunc(int key, int XBUTTON1, int y){
	if(key == GLUT_KEY_LEFT){
		angle = angle + 5;
	}else if(key == GLUT_KEY_RIGHT){
		angle = angle - 5;
	}
	glutPostRedisplay();
}
void init(){
	glClearColor(0, 0, 0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -1.5, 1.5, -10, 10.0);
}
int main(int argc, char * argv[]){
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (650,650);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Deep-buffer");
    glutDisplayFunc(mydisplay);
    glutSpecialFunc(mySpecialFunc);
    init();
    glutMainLoop();
}
