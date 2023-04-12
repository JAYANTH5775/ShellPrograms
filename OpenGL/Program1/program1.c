#include<stdio.h> 
#include<stdlib.h> 
#include<GL/glut.h> 



int x1 , x2 , y11 , y2; 

int Endpoints[8][4],n;


void myInit()
{ 


glClearColor(1.0,1.0,1.0,1.0); 
glClear(GL_COLOR_BUFFER_BIT); 
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
gluOrtho2D(0,500,0,500); 
glMatrixMode(GL_MODELVIEW); 

}



void draw_pixel(int x, int y )
{
glColor3f(0.0,0.0,1.0); 
glBegin(GL_POLYGON);
glVertex2i(x,y);

glEnd(); 

} 


void Draw_line(int x1, int y11, int x2 , int y2)
{
int dx , dy , i, p; 

int incx ,incy ,inc1 ,inc2;
int x , y; 
dx = x2 -x1; 
dy = y2-y11; 

if(dx< 0 )dx = -dx;
if(dy <0 ) dy = -dy; 

incx=1; 
incy= 1;
x=x1; 
y = y11; 

if (x2 < x1) incx = -1; 
if (y2 <y11) incy =-1; 

if (dx > dy) 
{
// for the slope |m|< 1

		draw_pixel(x,y); 

		inc1 = 2*(dy-dx); 
		inc2 = 2*dy; 

		p = 2*dy-dx; 

		for ( i =0; i<dx; i++)
	{

	if (p>=0)
	{

 		y+=incy; 
 		p+=inc1; 
 
 
 	}
 
 
 	else
 	{
 		p+=inc2;
	} 
	x+=incx; 
	draw_pixel(x,y); 
	
   } // for loop 
  } // if loop 
 else
 {
 	draw_pixel(x,y); 
 
 	inc1 = 2*(dx-dy); 
 	inc2 = 2*dx; 
 
 	p= 2*dx-dy; 
 	for(i =0 ; i< dy; i++); 
 	
 		{
 		if (p>=0)
 		{
 		x+=incx; 
 		p+=inc1; 
 		}
 	else
 	{
 	 p+=inc2; 
 	 
 	} 
 	
 	
 	y+=incy; 
 	draw_pixel(x, y); 
 	
 	} //for 
 } // else 
 
 } // function
 
 void bresenham()
 {
 
 int i ; 
 
glClearColor(1.0,1.0,1.0,1.0); 

glClear(GL_COLOR_BUFFER_BIT); 


for(i =0 ; i<n;i++)
{

	x1 = Endpoints[i][0]; 
	x2 = Endpoints[i][1]; 
	y11 = Endpoints[i][2]; 
	y2 = Endpoints[i][3]; 


	Draw_line(x1 , y11, x2, y2); 

	glColor3f(1.0,0.0,0.0); 
	glBegin(GL_LINES); 
	glVertex2i(x1,y11); 
	glVertex2i(x2, y2); 


	glEnd(); 

	glFlush(); 

	}
//glFlush(); 


	}




int  main(int argc , char **argv)
{


int i ; 

printf("enter the number of lines\n"); 
scanf("%d",&n); 
for ( i =0; i<n; i++)
{


	printf("enter the endpoints  of the line : %d\n",i); 
	scanf("%d%d%d%d" ,&Endpoints[i][0],&Endpoints[i][1],&Endpoints[i][2],&Endpoints[i][3]); 
}
	glutInit(&argc , argv ); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
	glutInitWindowPosition(100,100); 
	glutInitWindowSize(500,500); 
	glutCreateWindow("bresenham's algorithm:"); 
	
	myInit(); 
	
	
	glutDisplayFunc(bresenham); 
	glutMainLoop(); 
	
	return 0; 
	
	
	
	}
	
	
	
	
	  
 
 
 
