#include <GL/glut.h>
void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
	glOrtho(-320,320,-240,240,-1,1);	
}

void draw2point(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
		glVertex2i(x + xc, y + yc);
		glVertex2i(xc - x, yc + y);
	glEnd();
}
void curve(int xc, int yc, int p, int bound)	
{	 
   	int x,y,d ; 
	int p2,p4;
	p2 = 2*p;
	p4 = 2*p2;
	x=0; y=0;
    d = 1-p;
	
	
	while ((x < p) and (y <= bound))
    	{
			draw2point(xc, yc, x,y);
			if (d>=0)
			{
				y++;
				d = d - p2;
			}
			x++;
			d = d + 2*x +1;
			if (d=1)
				d = 1 - p4;
			else
				d = 1 - p2;
		}
	while (y < bound)
		{
			draw2point(xc, yc, x, y);
			if (d<0)
			{
				x ++;
				d = d + 4*x;
			}	
			y++;
			d = d - p4;
        }
}

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glViewport(0,0,640,480);
	curve(0, 0, 4, 200); 
	glFlush();

}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	int mode=GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("CURVE");
	initGL();
	glutDisplayFunc(mydisplay);    
	glutMainLoop();
}

