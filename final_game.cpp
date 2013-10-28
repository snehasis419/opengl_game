#include "stdafx.h"
#include <cmath>
#include <stdio.h>
#include <Windows.h>
#include <GL/GL.h>
#include <GL/GLAux.h>
#include <GL/glut.h>
float posX = 0.01, posY = -0.1, posZ = 0,angle=1,PI=3.14,x=0,y=0,posX1=0.01,posY1=-0.1,posZ1=0,posX2=0.01,posY2=-0.1,posZ2=0,t=0,speed_ball=0.001;
int ij;
void circ() {
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2d(0.9, 0.6);
    glVertex2d(0.8, 0.6);
	glVertex2d(0.8, 0);
	glVertex2d(0.9, 0);
	glEnd();
	
}

void rec(){
	glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
	glVertex2d(-0.9,0.6);
	glVertex2d(-0.9,0);
	glVertex2d(-0.8,0);
	glVertex2d(-0.8,0.6);
    glEnd();
}

void circ1() {
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 300; i++) {
        angle = 2 * PI * i / 300;
        x = cos(angle) / 20;
        y = sin(angle) / 20;
        glVertex2d(x, y);
    }
    glEnd();
}
void hello()
{
	glutPostRedisplay();
}


void display() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
	glTranslatef(posX2,posY2,posZ2);
	circ1();

    glPopMatrix();

    glutSwapBuffers();

	glPushMatrix();

    glTranslatef(posX, posY, posZ);
    if(posX2<=0.77 && t==0)
	{
	posX2+=speed_ball;
	}
	else if(posX2>0.77)
	{
		if(posY2>=posY+0.4 && posY2<=posY+0.6)
		{
			t=2;
			posX2-=speed_ball;
			posY2+=speed_ball;
		}
		else if(posY2>=posY+0.2 && posY2<posY+0.4)
		{
        posX2-=speed_ball;
		t=1;
		}
		else if(posY2>=posY && posY2<posY+0.2)
		{
			t=4;
			posX2-=speed_ball;
			posY2-=speed_ball;
		}
		else
		{
			t=0;
			posX2=0;
			posY2=0;
			posX1=0;
			posY1=0;
			posX=0;
			posY=0;
			//for(ij=0;ij<1000000;ij++);
			Sleep(1000);
		}
	}
	else if(t==2 && posX2>=-0.75 && posY2<=1.0)
	{
		posX2-=speed_ball;
		posY2+=speed_ball;
	}
	else if(t==2 && posX2>=-0.75 && posY2>1.0)
	{
		t=4;
		posX2-=speed_ball;
		posY2-=speed_ball;
	}
	else if(t==4 && posX2>=-0.75 && posY2>=-1.0)
	{
		posX2-=speed_ball;
		posY2-=speed_ball;
	}
	else if(t==4 && posX2>=-0.75 && posY2<-1.0)
	{
		t=2;
		posX2-=speed_ball;
		posY2+=speed_ball;
	}

	else if(t==1 && posX2>=-0.75)
	{
		posX2-=speed_ball;
	}
	else if(posX2<-0.75)
	{
		if(posY2>=posY1+0.4 && posY2<=posY1+0.6)
		{
			t=3;
			posX2+=speed_ball;
			posY2+=speed_ball;
		}
		else if(posY2>=posY1+0.2 && posY2<posY1+0.4)
		{
			t=0;
            posX2+=speed_ball;
		}
		else if(posY2>=posY1 && posY2<posY1+0.2)
		{
			t=5;
			posX2+=speed_ball;
			posY2-=speed_ball;
		}
		else
		{
			t=1;
			posX2=0;
			posY2=0;
			posX1=0;
			posY1=0;
			posX=0;
			posY=0;
			//for(ij=0;ij<1000000;ij++);
			Sleep(1000);
		}
	}
	else if(t==3 && posY2<=1.0 && posX2<=0.77)
	{
		posX2+=speed_ball;
		posY2+=speed_ball;
	}
	else if(t==3 && posY2>1.0 && posX2<=0.77)
	{
		t=5;
		posY2-=speed_ball;
		posX2+=speed_ball;
	}
	else if(t==5 && posY2>=-1.0 && posX2<=0.77)
	{
		posX2+=speed_ball;
		posY2-=speed_ball;
	}
	else if(t==5 && posY2<-1.0 && posX2<=0.77)
	{
		t=3;
		posX2+=speed_ball;
		posY2+=speed_ball;
    }
	circ();
	 glPopMatrix();

    glutSwapBuffers();
	glPushMatrix();
	glTranslatef(posX1,posY1,posZ1);
	rec();
    glPopMatrix();

    glutSwapBuffers();
	
}


float move_unit = 0.05f;
void keyboardown(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_F1:
        if(posY1<0.4)
		{posY1 += move_unit;}
       break;
   case GLUT_KEY_F2:
	   if(posY1>-1.0)
        posY1 -= move_unit;
       break;
    case GLUT_KEY_UP:
        if(posY<0.4)
		{posY += move_unit;}
        break;
    case GLUT_KEY_DOWN:
		if(posY>-1.0) 
		{posY -= move_unit;}
        break;
    default:
        break;
    }
glutPostRedisplay();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Example");
	glutDisplayFunc(display);
	glutSpecialFunc(keyboardown);
	glutIdleFunc(hello);
	glutMainLoop();
	
}