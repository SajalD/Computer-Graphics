//BATMAN SYMBOL USING BEZIER CURVE

#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

void beizerCurve(p,q,r,s,t,v,w,a)
{
 int cp[4][2]={{p,q},{r,s},{t,v},{w,a}};
 int c[4],k,n=3;
 float x,y,u,blend;
 c[0]=1;
 c[1]=3;
 c[2]=3;
 c[3]=1;
 glColor3f(0.0,0.0,0.0);
 glLineWidth(5.0);
 glBegin(GL_LINE_STRIP);
 for(u=0;u<1.0;u+=0.01)
 {
  x=0;y=0;
  for(k=0;k<4;k++)
  {
   blend=c[k]*pow(u,k)*pow(1-u,n-k);
   x+=cp[k][0]*blend;
   y+=cp[k][1]*blend;
  }
  glVertex2f(x,y);
 }
 glEnd();
 glFlush();
}
void display()
{ 
 glClear(GL_COLOR_BUFFER_BIT);
 beizerCurve(0,0,10,200,200,200,300,200);
 beizerCurve(300,200,280,250,350,400,400,400);
 beizerCurve(110,400,200,400,300,400,400,400);
 beizerCurve(110,400,110,310,50,310,15,310);
 beizerCurve(15,310,13,342,12,358,10,390);
 beizerCurve(10,390,8,370,7,360,5,340);
 beizerCurve(5,340,2,340,-2,340,-5,340);
 beizerCurve(0,0,-10,200,-200,200,-300,200);
 beizerCurve(-300,200,-280,250,-350,400,-400,400);
 beizerCurve(-110,400,-200,400,-300,400,-400,400);
 beizerCurve(-110,400,-110,310,-50,310,-15,310);
 beizerCurve(-15,310,-13,342,-12,358,-10,390);
 beizerCurve(-10,390,-8,370,-7,360,-5,340);
}
void myinit()
{
 glClearColor(1.0,1.0,1.0,1.0); 
 glColor3f(1.0,0.0,0.0);
 glPointSize(5.0);
 gluOrtho2D(-400.0,400.0,-200.0,500.0);
}
int main(int argc, char ** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(1920,1080);
 glutCreateWindow("Bezier Curve");
 glutDisplayFunc(display);
 myinit();
 glutMainLoop();
 return 0;
}
