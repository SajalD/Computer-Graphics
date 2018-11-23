#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int a[7][2],i=0,c,d,e=0;
int width=500, height=500;

void OnMouseClick(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
     a[i][0]=x;
     a[i][1]=y;
     c=x;
     d=y;
     i++;
     e++;
     show();

  }
  if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
  {
      create();

      i=0;
  }
}

void create()
{
    float t,xt,yt;
    void createbeizer(int, int);

    if(e==4)
    {
     for (t = 0.0; t < 1.0; t += 0.0005)
        {
            xt = (pow(1-t,3)*a[0][0])+(3*t*pow(1-t,2)*a[1][0])+(3*t*t*pow(1-t,1)*a[2][0])+(pow(t,3)*a[3][0]);
            yt = (pow(1-t,3)*a[0][1])+(3*t*pow(1-t,2)*a[1][1])+(3*t*t*pow(1-t,1)*a[2][1])+(pow(t,3)*a[3][1]);
            createbeizer(xt, yt);
        }
        for(i=0;i<2;i++)
        {
            a[i][0]=0;
            a[i][1]=0;
        }
        e=0;
}

}

void createbeizer(int b, int f)
{
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor4f(1,1,1,1);
    glVertex2f(b,500-f);
    glEnd();
    glFlush();
}

void show()
{
    glPointSize(3);
    glBegin(GL_POINTS);
    glColor4f(1,1,1,1);
    glVertex2f(c,500-d);
    glEnd();
    glFlush();
}

void beizercurve()
{
    glClearColor(0,0.3,0.7,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(width,height);
  glutCreateWindow("Beizer Curve");
  glutMouseFunc(OnMouseClick);
  gluOrtho2D(0,width,0,height);
  glutDisplayFunc(beizercurve);
  glutMainLoop();
}
