#define BLACK 0
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

GLfloat house[3][3]={{100.0,250.0,175.0},{100.0,100.0,300.0},{1.0,1.0,1.0}};
GLfloat rotatemat[3][3]={{0},{0},{0}};
GLfloat arbitrary_x=0;
GLfloat arbitrary_y=0;
float rotation_angle;

void rotate()
{
    GLfloat m,n;
    if(rotation_angle!=0)
    {
        m = arbitrary_x;
        n = arbitrary_y;
        glTranslatef(m,n,0);
        glRotatef(rotation_angle,0,0,1);
        glTranslatef(-m,-n,0);
    }
}

void drawhouse()
{
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(house[0][0],house[1][0]);
    glVertex2f(house[0][1],house[1][1]);
    glVertex2f(house[0][2],house[1][2]);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawhouse();
    rotate();
    drawhouse();
    glFlush();
}

void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,499.0,0.0,499.0);
}

int main(int argc, char** argv)
{
    int ch;
    printf("Enter your choice \n1: Rotation about origin \n2: Rotation about a Fixed point\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
            printf("Enter the rotation angle in degree:");
            scanf("%f", &rotation_angle);
           // rotation_angle = (3.14 * rotation_angle) / 180;
            break;

        case 2:
            printf("Enter the fixed points:");
            scanf("%f%f", &arbitrary_x,&arbitrary_y);
            printf("Enter rotation angle in degree:");
            scanf("%f", &rotation_angle);
            //rotation_angle = (3.14 * rotation_angle) / 180;
            break;
    }

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);

    glutCreateWindow("house rotation");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}

