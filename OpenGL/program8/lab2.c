#include<stdio.h>
#include<GL/glut.h>
int n;
typedef GLfloat point2[2];
point2 v[3]={{-2,-1},{2,-1},{0,1}};
void drawtext(float x,float y,float z,char *s)
{
int i;
glColor3f(1.0,1.0,1.0);
glRasterPos3f(x,y,z);
for(i=0;s[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
}
void triangle(GLfloat *a,GLfloat *b,GLfloat *c)
{
glVertex2fv(a);
glVertex2fv(b);
glVertex2fv(c);
}
void divide_triangle(GLfloat *a,GLfloat *b,GLfloat *c,int m)
{

point2 v0,v1,v2;
int j;
if(m>0)
{
for(j=0;j<2;j++)v0[j]=(a[j]+b[j])/2;
for(j=0;j<2;j++)v1[j]=(a[j]+c[j])/2;
for(j=0;j<2;j++)v2[j]=(b[j]+c[j])/2;
divide_triangle(a,v0,v1,m-1);
divide_triangle(c,v1,v2,m-1);
divide_triangle(b,v2,v0,m-1);
}
else(triangle(a,b,c));
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_TRIANGLES);
divide_triangle(v[0],v[1],v[2],n);

glEnd();
drawtext(-1.0,-1.0,-1.0,"1BIS0CS129 PRATHVISHREE");
glFlush();
}
void myinit()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-2.0,2.0,-2.0,2.0);
glMatrixMode(GL_MODELVIEW);
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(1.0,0.0,0.0);
}
int main(int argc,char**argv)
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
return 0;
myinit();
glutMainLoop();
return 0;
}
