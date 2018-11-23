#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
float xc;
float yc; 
float rx; 
float ry;

void Init (void)
{
    glClearColor(1.0,1.0,1.0,0.0); //Background Color
    glColor3f(0.0,0.0,0.0); //Black Color
    glPointSize(8.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500); //Coordinate System
}

void putpixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
void axes(void)
{ 
    glBegin(GL_LINES);
    glVertex2i(-500,0);
    glVertex2i(500,0);
    glVertex2i(0,500);
    glVertex2i(0,-500);
    glEnd();
}
void ellipse()
 {
   int x, y, p;
   x=0;
   y=ry;
   p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
   while((2*x*ry*ry)<(2*y*rx*rx))
   {
        putpixel(xc+x,yc-y);
        putpixel(xc-x,yc+y);
        putpixel(xc+x,yc+y);
        putpixel(xc-x,yc-y);
        if(p<0)
        {
        x=x+1;
        p=p+(2*ry*ry*x)+(ry*ry);
        }
        else
        {
     x=x+1;
     y=y-1;
     p=p+(2*ry*ry*x+ry*ry)-(2*rx*rx*y);
        }
   }
   p=((float)x+0.5)*((float)x+0.5)*ry*ry+(y-1)*(y-1)*rx*rx-rx*rx*ry*ry;
         while(y>=0)
   {
        putpixel(xc+x,yc-y);
        putpixel(xc-x,yc+y);
        putpixel(xc+x,yc+y);
        putpixel(xc-x,yc-y);
        if(p>0)
        {
     y=y-1;
     p=p-(2*rx*rx*y)+(rx*rx);
        }
        else
        {
     y=y-1;
     x=x+1;
     p=p+(2*ry*ry*x)-(2*rx*rx*y)-(rx*rx);
        }
   }
 }
void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(1.0);
    ellipse();
    axes();
    glFlush ();
}
int main (int argc, char** argv)
{
   printf("Please enter the coordinates of the centre of the ellipse");
   scanf("%f%f",&xc,&yc);
   printf("Enter the radius of the x-axis and y-axis");
   scanf("%f%f",&rx,&ry);
   glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
               glutInitWindowSize(1000,1000);
         glutInitWindowPosition(300,300);    
       glutCreateWindow("Ellipse");
       Init();
       glutDisplayFunc(myDisplay);
       glutMainLoop();
       return 0;
} 