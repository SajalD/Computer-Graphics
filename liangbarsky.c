#include<stdio.h>
#include<GL/glut.h>

void liang_barsky(int x1, int y1, int x2, int y2){
    int xmin=200, ymin=200, xmax=600, ymax=600;
    double t, t1=0, t2=1;
    double p[4], q[4];
    int dx=x2-x1, dy=y2-y1, i;
    
    p[0]= (double)-dx; 
    q[0]= (double)x1 - xmin;

    p[1]= (double)dx; 
    q[1]= (double)xmax - x1;

    p[2]= (double)-dy; 
    q[2]= (double)y1 - ymin;

    p[3]= (double)dy; 
    q[3]= (double)ymax - y1;
    
    for(i=0; i<4; i++){
        if( p[i] == 0 && q[i] < 0 ){
            printf("Line outside the window"); }

        else if( p[i] < 0 ){
            t = (q[i] / p[i]);
            if( t > t1 && t < t2)
            { t1 = t; } 
        }

        else if( p[i] > 0 ){
            t = (q[i] / p[i]);
            if( t > t1 && t < t2)
            { t2 = t; } 
        }
    }

    if( t1 < t2){
        x2 = x1 + (t2*dx) ;
        x1 = x1 + (t1*dx) ;
        y2 = y1 + (t2*dy) ;
        y1 = y1 + (t1*dy) ;
        
        
        
        glColor3f( 1.0, 0.0, 0.0 );
        glBegin(GL_LINES);
            glVertex2i( x1, y1 );
            glVertex2i( x2, y2 );
        glEnd();
        glFlush();
        }
    else{
        printf("Line is outside the window"); }
    }

void Init(void){
    glClearColor( 1.0, 1.0, 1.0, 1.0);
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0f, 800.0f, 0.0f, 800.0f);
    glColor3f( 0.0f, 0.0f, 0.0f);
    
    }



void clipping_window(void){
    glBegin(GL_LINES);
        glVertex2i( 200, 200 );
        glVertex2i( 200, 600 );        
        glVertex2i( 200, 600 );
        glVertex2i( 600, 600 );
        glVertex2i( 600, 600 );
        glVertex2i( 600, 200 );
        glVertex2i( 600, 200 );
        glVertex2i( 200, 200 );
        glVertex2i( 0, 400 );
        glVertex2i( 800, 400 );
        glVertex2i( 400, 0 );
        glVertex2i( 400, 800 );
    glEnd();
    liang_barsky(100,300,700,600);
    glFlush();
    }

int main( int argc, char **argv){
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(1920,1080);
    glutInitWindowPosition(0,0);
    glutCreateWindow("LIANG BARSKY");
    Init();
    glutDisplayFunc(clipping_window);
    glutMainLoop();
    return 0;
    }