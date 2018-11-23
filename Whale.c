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
 beizerCurve(-200,100,-200,300,100,150,200,100);
 beizerCurve(200,100,210,160,250,190,270,200);
 beizerCurve(270,200,260,180,250,120,240,100);
 beizerCurve(-20,190,-10,240,-5,290,30,320);
 beizerCurve(30,320,27,310,24,250,16,205);
 beizerCurve(16,205,10,200,5,195,0,185);
 beizerCurve(-200,100,-200,-100,100,50,200,100);
 beizerCurve(200,100,210,40,250,10,270,0);
 beizerCurve(270,0,260,20,250,80,240,100);
 beizerCurve(-20,10,-10,-40,-5,-90,30,-120);
 beizerCurve(30,-120,27,-110,24,-50,16,-5);
 beizerCurve(16,-5,10,0,5,5,0,15);

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