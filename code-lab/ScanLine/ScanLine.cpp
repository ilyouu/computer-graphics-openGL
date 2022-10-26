
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float x1,x2,x3,x4,y1,y2,y3,y4;
void draw_pixel(int x,int y)
{
    glColor3f(0.0, 1.0, 1.0);
    glPointSize(50.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void edgedetect(float x1,float y1,float x2,float y2,int *le,int *re)
{
    float temp,x,mx;
    int i;

    if(y1>y2)
    {
        temp=x1,x1=x2,x2=temp;
        temp=y1,y1=y2,y2=temp;
    }

    if(y1==y2)
        mx=x2-x1;
    else
        mx=(x2-x1)/(y2-y1);

    x=x1;

    for(i=(int)y1;i<=(int)y2;i++)
    {
        if(x<(float)le[i]) le[i]=(int)x;
        if(x>(float)re[i]) re[i]=(int)x;
        x+=mx;
    }
}

void scanfill(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
    int le[500],re[500],i,j;

    for(i=0;i<500;i++)
        le[i]=500,re[i]=0;

    edgedetect(x1,y1,x2,y2,le,re);
    edgedetect(x2,y2,x3,y3,le,re);
    edgedetect(x3,y3,x4,y4,le,re);
    edgedetect(x4,y4,x1,y1,le,re);

    for(j=0;j<500;j++)
    {
        if(le[j]<=re[j])
            for(i=le[j];i<re[j];i++)
                draw_pixel(i,j);
    }
}


void display()
{
    x1=250;y1=100;x2=300;y2=200;x3=200;
    y3=200;x4=250;y4=300;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    	glVertex2f(x1,y1);
    	glVertex2f(x2,y2);
    	glVertex2f(x3,y3);
    	glVertex2f(x4,y4);
    glEnd();

    scanfill(x1,y1,x2,y2,x3,y3,x4,y4);

    glFlush();
}


void init()
{
    glClearColor(1,1,1,0);
    gluOrtho2D(0.0, 500.0, 0.0, 400.0);
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);

    glutCreateWindow("ScanLine_PhanVanBang");
    glutDisplayFunc(display);

    init();
    glutMainLoop();
}


