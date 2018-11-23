
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int width=1000,height=800;

void init()
{
  gluOrtho2D(0,width,height,0);
  glClearColor(0.0,0.0,0.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0f,1.0f,1.0f);
}

void draw_rect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
glColor3ub(rand(),rand(),rand()); // random colors
glBegin(GL_LINE_LOOP);
glVertex2i(x1,y1);
glVertex2i(x2,y2);
glVertex2i(x3,y3);
glVertex2i(x4,y4);
glEnd();
glFlush();
}

void draw_tri(int x1,int y1,int x2,int y2,int x3,int y3)
{
if(y2-y1>20 )
{

glColor3ub(rand(),rand(),rand());

glBegin(GL_TRIANGLES);
glVertex2i(x1,y1);
glVertex2i(x2,y2);
glVertex2i(x3,y3);
glEnd();

draw_rect((x1+x2)/2,(y1+y2)/2,(x1+x3)/2,(y1+y3)/2,(x1+x3)/2,y3,(x1+x2)/2,y2);
draw_tri(x1,y1,(x1+x2)/2,(y1+y2)/2,(x1+x3)/2,(y1+y3)/2);
draw_tri((x1+x2)/2,(y1+y2)/2,(x1+x2)/2,y2,x2,y2);
draw_tri((x1+x3)/2,(y1+y3)/2,(x1+x3)/2,y3,x3,y3);
glFlush();
  }
}

void display()
{
draw_tri(500,200,200,600,800,600);
}

void main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(width,height);
  glutCreateWindow("fractal");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
}

