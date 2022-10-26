#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>

using namespace std;
float xmin=-100;    
float ymin=-100;
float xmax=200;
float ymax=150;
float xdA,ydA,xdB,ydB; 


void initGL(void)
{
    glClearColor(1,1,1,0);
    gluOrtho2D(-300,300,-300,300);
}


void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_LINE_LOOP); 
   		glVertex2i(xmin,ymin);
   		glVertex2i(xmin,ymax);
   		glVertex2i(xmax,ymax);
   		glVertex2i(xmax,ymin);
   glEnd();
   
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_LINES);  
   		glVertex2i(xdA,ydA);
   		glVertex2i(xdB,ydB);
   glEnd();

   glFlush();
}

int code(float x,float y) 
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=2;
    if(x<xmin)c=1;
    return c;
}

void cohen_Line(float xA,float yA,float xB,float yB)
{
    int cA=code(xA,yA); 
    int cB=code(xB,yB); 
    float m=(yB-yA)/(xB-xA);
    
	while((cA|cB)>0)  
    {
    
    	if((cA & cB)!=0){exit(0);} 

    	float xi=xA;float yi=yA;  
    	int c=cA;  
    	if(c==0){c=cB;xi=xB;yi=yB;}  
    	
    	float x,y;
    	if((c & 8)){y=ymax;x=xi+ 1.0/m*(ymax-yi);}
    	else if((c & 4)){y=ymin;x=xi+1.0/m*(ymin-yi);}
      		 else if((c & 2)){x=xmax;y=yi+m*(xmax-xi);}
       			  else if((c & 1)){x=xmin;y=yi+m*(xmin-xi);}
    
    	if(c==cA){ xdA=x; ydA=y;  cA=code(xdA,ydA); }   
    	if(c==cB){ xdB=x; ydB=y;  cB=code(xdB,ydB); }  
	}

 display();
}

int main(int argc,char** argv)
{
    printf("Nhap toa do 2 diem A(xd1,yd1) va B(xd2,yd2): ");
    cin>>xdA>>ydA>>xdB>>ydB;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Lab2 - Cohen - Sutherland");
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}

