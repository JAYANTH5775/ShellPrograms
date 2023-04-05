#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
int n;
void display()
{
GLfloat vertices[3][3]={{0.0,0.0,0.0},{25.0,50.0,0.0},{50.0,0.0,0.0}};
GLfloat p[3]={7.5,5.0,0.0};
int j,k;
int rand();
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
for(k=0;k<n;k++)
{
j=rand()%3;
p[0]=(p[0]+vertices[j][0])/2;
p[1]=(p[1]+vertices[j][1])/2;
glVertex3fv(p);
}
glEnd();
glFlush();
}
void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(1.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,60.0,0.0,60.0);
//glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
printf("no of division?:");
scanf("%d",&n);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutCreateWindow("2D gasket");
glutDisplayFunc(display);
myinit();
glutMainLoop();
}
