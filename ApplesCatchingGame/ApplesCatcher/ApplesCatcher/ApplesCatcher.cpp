#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>


float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;

float cloudspeed = 0.03;
bool cloudMoveRight = true;
float cloudX = -6.0;

float marSpeed = 0.03;
bool moveRight = true;
bool layapple = true;
bool gameOver = false;
bool begin = true;

float marX = -0.55;
float marY = 0.0;
float marWidth = 1.10;
float marHeight = 0.66;

float dimX = marX + 0.55;
float dimWidth = 0.36;
float dimY = marY;
float dimHeight = 0.42;
float dimSpeed = 0.02;
float dps = 0.03;

float sunY = 1.0;
bool sunMoveup = true;

float basketX = -0.35;
float basketWidth = 0.70;
float basketY = -3.00;
float basketHeight = 0.70;

int count = 0;



void circle(float radius){

	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++)
	{
		float pi = 3.1416;
		float A = (i * 2 * pi) / 50;
		float r = radius;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x, y);
	}
	glEnd();

}

void cloudOne(){

	glPushMatrix();
	glTranslatef(cloudX, 2.2, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	circle(0.35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cloudX - 0.5, 2.2, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	circle(0.45);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cloudX - 1.0, 2.2, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	circle(0.35);
	glPopMatrix();

}

void cloudTwo(){

	glPushMatrix();
	glTranslatef(cloudX - 3.0, 2.2, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	circle(0.35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cloudX - 3.5, 2.2, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	circle(0.45);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(cloudX - 4.0, 2.2, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	circle(0.35);
	glPopMatrix();

}

void sun(){

	//sun smiley face
	glPushMatrix();
	glTranslatef(2.8, sunY + 0.2, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	circle(0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.2, sunY + 0.2, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	circle(0.05);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.8, sunY + 0.2, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	circle(0.07);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.2, sunY + 0.2, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	circle(0.07);
	glPopMatrix();
	glPushMatrix();
	glLineWidth(6);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(2.8, sunY - 0.2);
	glVertex2f(2.95, sunY - 0.3);
	glVertex2f(2.95, sunY - 0.3);
	glVertex2f(3.15, sunY - 0.3);
	glVertex2f(3.15, sunY - 0.3);
	glVertex2f(3.3, sunY - 0.2);
	glEnd();

	//sun rays
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(3.9, sunY, 0.0);
	glVertex3f(3.0, sunY + 0.3, 0.0);
	glVertex3f(3.0, sunY - 0.3, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(3.3, sunY, 0.0);
	glVertex3f(3.0, sunY + 0.3, 0.0);
	glVertex3f(3.65, sunY + 0.70, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(2.7, sunY, 0.0);
	glVertex3f(3.0, sunY + 0.3, 0.0);
	glVertex3f(2.3, sunY + 0.70, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(3.0, sunY - 0.3, 0.0);
	glVertex3f(3.3, sunY, 0.0);
	glVertex3f(3.65, sunY - 0.70, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(3.0, sunY - 0.3, 0.0);
	glVertex3f(2.7, sunY, 0.0);
	glVertex3f(2.35, sunY - 0.70, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(3.0, sunY - 0.9, 0.0);
	glVertex3f(3.3, sunY, 0.0);
	glVertex3f(2.7, sunY, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(3.0, sunY + 0.9, 0.0);
	glVertex3f(3.3, sunY, 0.0);
	glVertex3f(2.7, sunY, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(2.1, sunY, 0.0);
	glVertex3f(3.0, sunY + 0.3, 0.0);
	glVertex3f(3.0, sunY - 0.3, 0.0);
	glEnd();
	glPopMatrix();

	//sun base
	glPushMatrix();
	glTranslatef(3.0, sunY, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	circle(0.50);
	glPopMatrix();

}


void apple(float ex, float ey) {

	glColor3f(0.8, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(dimX + dps * 3, dimY - dps * 2.18);
	glVertex2f(dimX + dps * 3.5, dimY - dps * 2.62);
	glVertex2f(dimX + dps * 2.5, dimY - dps * 5.25);
	glVertex2f(dimX + dps * 2, dimY - dps * 10.5);
	glVertex2f(dimX + dps * 0.75, dimY - dps * 8.1);
	glVertex2f(dimX + dps * 0.5, dimY - dps * 5);
	glVertex2f(dimX + dps * 1, dimY - dps * 3.5);
	glVertex2f(dimX + dps * 1.5, dimY - dps * 2.62);
	glEnd(); 

	glColor3f(0.8, 0.35, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dimX + dps * 8, dimY + dps * 0.38);
	glVertex2f(dimX + dps * 7.5, dimY - dps * 1.75);
	glVertex2f(dimX + dps * 6.7, dimY - dps * 2.91);
	glVertex2f(dimX + dps * 6.3, dimY - dps * 2.91);
	glVertex2f(dimX + dps * 6.4, dimY - dps * 1.75);
	glVertex2f(dimX + dps * 7, dimY + dps * 0.38);
	glEnd(); 

	glColor3f(0.0, 0.35, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dimX + dps * 2, dimY + dps * 1.29);
	glVertex2f(dimX + dps * 3.5, dimY + dps * 0.58);
	glVertex2f(dimX + dps * 4, dimY + dps * 0);
	glVertex2f(dimX + dps * 5.2, dimY - dps * 0.6);
	glVertex2f(dimX + dps * 7, dimY - dps * 0.5);
	glVertex2f(dimX + dps * 6, dimY + dps * 0.38);
	glVertex2f(dimX + dps * 5.2, dimY + dps * 1.29);
	glVertex2f(dimX + dps * 4, dimY + dps * 1.35);
	glEnd();

	glColor3f(0.85, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(dimX + dps * 3.5, dimY - dps * 0.875);
	glVertex2f(dimX + dps * 2.5, dimY - dps * 1.75);
	glVertex2f(dimX + dps * 1.25, dimY - dps * 2.18);
	glVertex2f(dimX + dps * 0.5, dimY - dps * 2.91);
	glVertex2f(dimX + dps * 0, dimY - dps * 5.25);
	glVertex2f(dimX + dps * 0, dimY - dps * 7);
	glVertex2f(dimX + dps * 0.5, dimY - dps * 8.75);
	glVertex2f(dimX + dps * 1.25, dimY - dps * 11.62);
	glVertex2f(dimX + dps * 2.5, dimY - dps * 12.83);
	glVertex2f(dimX + dps * 3.5, dimY - dps * 13.41);
	glVertex2f(dimX + dps * 4.5, dimY - dps * 14);
	glVertex2f(dimX + dps * 7.5, dimY - dps * 14);
	glVertex2f(dimX + dps * 9, dimY - dps * 13.41);
	glVertex2f(dimX + dps * 10, dimY - dps * 12.83);
	glVertex2f(dimX + dps * 10.5, dimY - dps * 11.62);
	glVertex2f(dimX + dps * 11.5, dimY - dps * 9.92);
	glVertex2f(dimX + dps * 12, dimY - dps * 8.1);
	glVertex2f(dimX + dps * 12, dimY - dps * 5.83);
	glVertex2f(dimX + dps * 11.5, dimY - dps * 3.5);
	glVertex2f(dimX + dps * 10.5, dimY - dps * 2.18);
	glVertex2f(dimX + dps * 9.5, dimY - dps * 1.75);
	glVertex2f(dimX + dps * 8.5, dimY - dps * 0.875);
	glEnd();
	glFlush();

}

void basket(){

	glPushMatrix();
	glColor3f(0.94, 0.5, 0.3);
	glBegin(GL_QUADS);
	glVertex3f(basketX - 0.10, basketY + basketHeight, 0.0);
	glVertex3f(basketX, basketY, 0.0);
	glColor3f(0.7, 0.2, 0.0);
	glVertex3f(basketX + basketWidth, basketY, 0.0);
	glVertex3f(basketX + basketWidth + 0.10, basketY + basketHeight, 0.0);
	glEnd();
	glPopMatrix();
	glFlush();

}


void fenceBoard(float x, int var){

	if (var == 0) {
		glColor3f(1, 1, 1);
		glRectd(x - 0.05, -1.99, x + 0.05, -1.50);
		glBegin(GL_TRIANGLES);
		glVertex3f(x - 0.05, -1.50, 0.0);
		glVertex3f(x + 0.05, -1.50, 0.0);
		glVertex3f(x, -1.45, 0.0);
		glEnd();

	}
	else if (var == 1) {
		glColor3f(0.96, 0.96, 0.96);
		glRectd(x - 0.05, -1.99, x + 0.05, -1.50);
		glBegin(GL_TRIANGLES);
		glVertex3f(x - 0.05, -1.50, 0.0);
		glVertex3f(x + 0.05, -1.50, 0.0);
		glVertex3f(x, -1.45, 0.0);
		glEnd();
	}
	else if (var == 3) {
		glColor3f(0.87, 0.87, 0.87);
		glRectd(x - 0.05, -1.99, x + 0.05, -1.40);
		glPointSize(12.0);
		glEnable(GL_POINT_SMOOTH);
		glBegin(GL_POINTS);
		glVertex2f(x, -1.35);
		glEnd();
		glDisable(GL_POINT_SMOOTH);
	}

}

void fence(){

	glColor3f(0.83, 0.83, 0.83);
	glRectf(-4.2, -1.65, -4.1, -1.6);
	glRectf(-4.2, -1.85, -4.1, -1.8);
	glRectf(-4.9, -1.75, -4.8, -1.7);


	int j = 0;
	for (float i = 5; i <= 7; i = i + 0.1) {
		fenceBoard(i, j % 2);
		j++;
	}
	for (float i = -4.0; i <= 1.75; i = i + 0.1) {
		fenceBoard(i, j % 2);
		j++;
	}
	for (float i = -7.0; i <= -5.0; i = i + 0.1) {
		fenceBoard(i, j % 2);
		j++;
	}
	fenceBoard(-4.9, 3);
	fenceBoard(-4.1, 3);

	glColor3f(0.96, 0.96, 0.96);
	glRectd(-4.5 - 0.05, -1.99, -4.5 + 0.05, -1.40);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-4.8 - 0.05, -1.99);
	glVertex2f(-4.8 + 0.05, -1.99);
	glVertex2f(-4.8 + 0.05, -1.45);
	glVertex2f(-4.8 - 0.05, -1.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-4.2 - 0.05, -1.99);
	glVertex2f(-4.2 + 0.05, -1.99);
	glVertex2f(-4.2 + 0.05, -1.5);
	glVertex2f(-4.2 - 0.05, -1.45);
	glEnd();

	glColor3f(0.96, 0.96, 0.96);
	glBegin(GL_POLYGON);
	glVertex2f(-4.7 - 0.05, -1.99);
	glVertex2f(-4.7 + 0.05, -1.99);
	glVertex2f(-4.7 + 0.05, -1.425);
	glVertex2f(-4.7 - 0.05, -1.45);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-4.3 - 0.05, -1.99);
	glVertex2f(-4.3 + 0.05, -1.99);
	glVertex2f(-4.3 + 0.05, -1.45);
	glVertex2f(-4.3 - 0.05, -1.425);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-4.6 - 0.05, -1.99);
	glVertex2f(-4.6 + 0.05, -1.99);
	glVertex2f(-4.6 + 0.05, -1.4);
	glVertex2f(-4.6 - 0.05, -1.425);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-4.4 - 0.05, -1.99);
	glVertex2f(-4.4 + 0.05, -1.99);
	glVertex2f(-4.4 + 0.05, -1.425);
	glVertex2f(-4.4 - 0.05, -1.4);
	glEnd();

}


void mainTree(){

	glColor3f(1, 0, 0);
	glPointSize(20.0);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glVertex2f(-3.25, 1.5);
	glVertex2f(-2.8, 1.3);
	glVertex2f(-2.7, 0.8);
	glVertex2f(-3.1, 0.0);
	glVertex2f(-2.25, 0.4);
	glVertex2f(-2.4, 2.0);
	glVertex2f(-1.75, 1.5);
	glVertex2f(-1.5, 1.0);
	glVertex2f(-2.15, 1.1);
	glVertex2f(-1.8, 0.0);
	glVertex2f(-1.2, 0.4);
	glVertex2f(-0.6, -0.125);
	glVertex2f(-0.3, 0.25);
	glVertex2f(0.2, 0.1);
	glVertex2f(-3.5, 0.8);
	glVertex2f(0.1, 0.625);
	glVertex2f(-0.75, 0.90);
	glVertex2f(-1.0, 1.375);
	glVertex2f(-0.25, 1.15);
	glVertex2f(0.75, 1.3);
	glVertex2f(-0.4, 1.6);
	glVertex2f(-0.8, 2.0);
	glVertex2f(-1.6, 2.1);
	glEnd();
	glDisable(GL_POINT_SMOOTH);

	//1
	glColor3f(0.0, 0.8, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.25, 1.75, 0.0);
	glVertex3f(-1.8, 0.7, 0.0);
	glVertex3f(-1.3, 2.1, 0.0);
	glEnd();

	//2
	glColor3f(0.0, 0.68, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.60, 0.2, 0.0);
	glVertex3f(-1.8, 0.7, 0.0);
	glVertex3f(-1.3, 2.1, 0.0);
	glEnd();
	//3
	glColor3f(0.0, 0.68, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.25, 1.75, 0.0);
	glVertex3f(-1.8, 0.7, 0.0);
	glVertex3f(-2.75, 1.18, 0.0);
	glEnd();
	//4
	glColor3f(0.0, 0.7, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.3, 0.3, 0.0);
	glVertex3f(-0.60, 0.2, 0.0);
	glVertex3f(-2.75, 1.18, 0.0);
	glEnd();
	//5
	glColor3f(0.0, 0.9, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.3, 0.3, 0.0);
	glVertex3f(-3.40, 0.4, 0.0);
	glVertex3f(-2.75, 1.18, 0.0);
	glEnd();
	//6
	glColor3f(0.0, 0.85, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-3.40, 0.4, 0.0);
	glVertex3f(-2.25, 1.75, 0.0);
	glVertex3f(-3.60, 1.2, 0.0);
	glEnd();
	//7
	glColor3f(0.0, 0.6, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-3.60, 1.2, 0.0);
	glVertex3f(-1.3, 2.1, 0.0);
	glVertex3f(-3.0, 2.0, 0.0);
	glEnd();
	//8
	glColor3f(0.0, 0.6, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-3.60, 1.2, 0.0);
	glVertex3f(-3.40, 0.4, 0.0);
	glVertex3f(-3.85, 0.85, 0.0);
	glEnd();
	//9
	glColor3f(0.0, 0.8, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-3.60, 1.2, 0.0);
	glVertex3f(-3.4, 2.125, 0.0);
	glVertex3f(-3.0, 2.0, 0.0);
	glEnd();
	//10
	glColor3f(0.0, 0.9, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-3.60, 1.2, 0.0);
	glVertex3f(-3.85, 0.85, 0.0);
	glVertex3f(-3.4, 1.95, 0.0);
	glEnd();
	//11
	glColor3f(0.0, 0.75, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.3, 0.3, 0.0);
	glVertex3f(-3.40, 0.4, 0.0);
	glVertex3f(-2.70, -0.4, 0.0);
	glEnd();
	//12
	glColor3f(0.0, 0.8, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-3.5, -0.2, 0.0);
	glVertex3f(-3.40, 0.4, 0.0);
	glVertex3f(-2.70, -0.4, 0.0);
	glEnd();
	//13
	glColor3f(0.0, 0.95, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.3, 0.3, 0.0);
	glVertex3f(-1.60, -0.11, 0.0);
	glVertex3f(-2.70, -0.4, 0.0);
	glEnd();
	//14
	glColor3f(0.0, 0.85, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.3, 0.3, 0.0);
	glVertex3f(-1.60, -0.11, 0.0);
	glVertex3f(-0.60, 0.2, 0.0);
	glEnd();
	//15
	glColor3f(0.0, 0.65, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.75, -0.35, 0.0);
	glVertex3f(-1.60, -0.11, 0.0);
	glVertex3f(-0.60, 0.2, 0.0);
	glEnd();
	//16
	glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.75, -0.35, 0.0);
	glVertex3f(0.2, -0.25, 0.0);
	glVertex3f(-0.60, 0.2, 0.0);
	glEnd();
	//17
	glColor3f(0.0, 0.4, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.6, 0.6, 0.0);
	glVertex3f(0.2, -0.25, 0.0);
	glVertex3f(-0.60, 0.2, 0.0);
	glEnd();
	//18
	glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.6, 0.6, 0.0);
	glVertex3f(0.2, -0.25, 0.0);
	glVertex3f(0.80, 0.1, 0.0);
	glEnd();
	//19
	glColor3f(0.0, 0.6, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.6, 0.6, 0.0);
	glVertex3f(-0.2, 1.2, 0.0);
	glVertex3f(-0.60, 0.2, 0.0);
	glEnd();
	//20
	glColor3f(0.0, 0.7, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1, 1.1, 0.0);
	glVertex3f(-0.2, 1.2, 0.0);
	glVertex3f(-0.60, 0.2, 0.0);
	glEnd();
	//21
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1, 1.1, 0.0);
	glVertex3f(-0.2, 1.2, 0.0);
	glVertex3f(-1.3, 2.1, 0.0);
	glEnd();
	//22
	glColor3f(0.0, 0.8, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, 2.2, 0.0);
	glVertex3f(-0.2, 1.2, 0.0);
	glVertex3f(-1.3, 2.1, 0.0);
	glEnd();
	//23
	glColor3f(0.0, 0.6, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, 2.2, 0.0);
	glVertex3f(-0.2, 1.2, 0.0);
	glVertex3f(0.1, 1.9, 0.0);
	glEnd();
	//24
	glColor3f(0.0, 0.7, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.65, 1.7, 0.0);
	glVertex3f(-0.2, 1.2, 0.0);
	glVertex3f(0.1, 1.9, 0.0);
	glEnd();
	//25
	glColor3f(0.0, 0.64, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.65, 1.7, 0.0);
	glVertex3f(-0.2, 1.2, 0.0);
	glVertex3f(0.6, 0.6, 0.0);
	glEnd();
	//26
	glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.65, 1.7, 0.0);
	glVertex3f(1, 1.375, 0.0);
	glVertex3f(0.6, 0.6, 0.0);
	glEnd();
	//27
	glColor3f(0.0, 0.5, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, 2.2, 0.0);
	glVertex3f(0.15, 2.3, 0.0);
	glVertex3f(0.1, 1.9, 0.0);
	glEnd();
	//28
	glColor3f(0.0, 0.67, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, 2.2, 0.0);
	glVertex3f(-1.0, 2.5, 0.0);
	glVertex3f(-2.15, 1.9, 0.0);
	glEnd();
	//29
	glColor3f(0.0, 0.57, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.4, 2.3, 0.0);
	glVertex3f(-1.35, 2.3, 0.0);
	glVertex3f(-2.15, 1.9, 0.0);
	glEnd();
	//30
	glColor3f(0.0, 0.4, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.15, 1.9, 0.0);
	glVertex3f(-3.0, 2.0, 0.0);
	glVertex3f(-2.45, 2.4, 0.0);
	glEnd();

	//trunk
	glColor3f(0.6, 0.2, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.2, -2.0, 0.0);
	glVertex3f(-1.25, -2.0, 0.0);
	glVertex3f(-0.8, -1.85, 0.0);
	glEnd();

	glColor3f(0.7, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.2, -1.6, 0.0);
	glVertex3f(-1.25, -2.0, 0.0);
	glVertex3f(-0.8, -1.85, 0.0);
	glEnd();

	glColor3f(0.6, 0.2, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.2, -1.6, 0.0);
	glVertex3f(-1.25, -2.0, 0.0);
	glVertex3f(-1.5, -1.68, 0.0);
	glEnd();

	glColor3f(0.7, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.6, -2, 0.0);
	glVertex3f(-1.25, -2.0, 0.0);
	glVertex3f(-1.5, -1.68, 0.0);
	glEnd();

	glColor3f(0.6, 0.2, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.6, -2, 0.0);
	glVertex3f(-1.8, -1.6, 0.0);
	glVertex3f(-1.5, -1.68, 0.0);
	glEnd();

	glColor3f(0.7, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.6, -2, 0.0);
	glVertex3f(-1.8, -1.6, 0.0);
	glVertex3f(-2, -2, 0.0);
	glEnd();

	glColor3f(0.6, 0.2, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.3, -1.8, 0.0);
	glVertex3f(-1.8, -1.6, 0.0);
	glVertex3f(-2, -2, 0.0);
	glEnd();

	glColor3f(0.7, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.3, -1.8, 0.0);
	glVertex3f(-3.2, -2.0, 0.0);
	glVertex3f(-2, -2, 0.0);
	glEnd();

	glColor3f(0.7, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.5, -1.25, 0.0);
	glVertex3f(-1.5, -1.68, 0.0);
	glVertex3f(-1.2, -1.6, 0.0);
	glEnd();

	glColor3f(0.5, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.5, -1.25, 0.0);
	glVertex3f(-1.5, -1.68, 0.0);
	glVertex3f(-1.8, -1.6, 0.0);
	glEnd();

	glColor3f(0.7, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.5, -1.25, 0.0);
	glVertex3f(-1.7, -1.35, 0.0);
	glVertex3f(-1.8, -1.6, 0.0);
	glEnd();

	glColor3f(0.6, 0.2, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.3, -0.875, 0.0);
	glVertex3f(-1.5, -1.25, 0.0);
	glVertex3f(-1.2, -1.6, 0.0);
	glEnd();

	glColor3f(0.6, 0.2, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.7, -1.35, 0.0);
	glVertex3f(-1.5, -1.25, 0.0);
	glVertex3f(-1.8, -0.6, 0.0);
	glEnd();

	glColor3f(0.5, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.5, -1.25, 0.0);
	glVertex3f(-1.8, -0.6, 0.0);
	glVertex3f(-1.6, -0.5, 0.0);
	glEnd();

	glColor3f(0.7, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.5, -1.25, 0.0);
	glVertex3f(-1.3, -0.875, 0.0);
	glVertex3f(-1.6, -0.5, 0.0);
	glEnd();

	glColor3f(0.5, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.2, -0.45, 0.0);
	glVertex3f(-1.3, -0.875, 0.0);
	glVertex3f(-1.6, -0.5, 0.0);
	glEnd();

	glColor3f(0.6, 0.2, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-2.7, -0.4, 0.0);
	glVertex3f(-1.9, -0.2, 0.0);
	glVertex3f(-1.8, -0.6, 0.0);
	glEnd();

	glColor3f(0.7, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.8, -0.6, 0.0);
	glVertex3f(-1.9, -0.2, 0.0);
	glVertex3f(-1.6, -0.5, 0.0);
	glEnd();

	glColor3f(0.7, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.2, -0.45, 0.0);
	glVertex3f(-1.6, -0.11, 0.0);
	glVertex3f(-1.6, -0.5, 0.0);
	glEnd();

	glColor3f(0.6, 0.2, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.2, -0.45, 0.0);
	glVertex3f(-1.6, -0.11, 0.0);
	glVertex3f(-0.75, -0.35, 0.0);
	glEnd();

	glColor3f(0.5, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.6, -0.11, 0.0);
	glVertex3f(-1.9, -0.2, 0.0);
	glVertex3f(-1.6, -0.5, 0.0);
	glEnd();

}

void tree(){

	glPushMatrix();
	glTranslatef(-5.88, 0.0, 0.0);
	glColor3f(0.0, 0.3, 0.0);
	circle(0.35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.27, 0.0, 0.0);
	glColor3f(0.0, 0.3, 0.0);
	circle(0.35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.6, 0.5, 0.0);
	glColor3f(0.0, 0.3, 0.0);
	circle(0.35);
	glPopMatrix();

	glColor3f(0.61, 0.3, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(-5.4, -1.0, 0.0);
	glVertex3f(-5.7, -1.0, 0.0);
	glVertex3f(-5.6, 0.0, 0.0);
	glVertex3f(-5.5, 0.0, 0.0);
	glEnd();

	glPushMatrix();
	glTranslatef(5.1, -0.5, 0.0);
	glColor3f(0.0, 0.4, 0.0);
	circle(0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.9, -0.5, 0.0);
	glColor3f(0.0, 0.4, 0.0);
	circle(0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.5, 0, 0.0);
	glColor3f(0.0, 0.4, 0.0);
	circle(0.5);
	glPopMatrix();

	glColor3f(0.61, 0.3, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(5.4, 0, 0.0);
	glVertex3f(5.5, 0, 0.0);
	glVertex3f(5.6, -2.0, 0.0);
	glVertex3f(5.3, -2.0, 0.0);
	glEnd();

	glPushMatrix();
	glTranslatef(-3.88, -0.75, 0.0);
	glColor3f(0.0, 0.45, 0.0);
	circle(0.4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.27, -0.75, 0.0);
	glColor3f(0.0, 0.45, 0.0);
	circle(0.4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.6, -0.25, 0.0);
	glColor3f(0.0, 0.45, 0.0);
	circle(0.4);
	glPopMatrix();

	glColor3f(0.61, 0.3, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(-3.4, -2.0, 0.0);
	glVertex3f(-3.7, -2.0, 0.0);
	glVertex3f(-3.6, -0.75, 0.0);
	glVertex3f(-3.5, -0.75, 0.0);
	glEnd();

	glPushMatrix();
	glTranslatef(1.58, 0.0, 0.0);
	glColor3f(0.0, 0.3, 0.0);
	circle(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.07, 0.0, 0.0);
	glColor3f(0.0, 0.3, 0.0);
	circle(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.3, 0.4, 0.0);
	glColor3f(0.0, 0.3, 0.0);
	circle(0.3);
	glPopMatrix();

	glColor3f(0.61, 0.3, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(1.2, -0.7, 0.0);
	glVertex3f(1.5, -0.7, 0.0);
	glVertex3f(1.4, 0.0, 0.0);
	glVertex3f(1.3, 0.0, 0.0);
	glEnd();

}

void surface(){

	glColor3f(0.0, 0.55, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-7.0, -0.5, 0.0);
	glVertex3f(7.0, -0.5, 0.0);
	glVertex3f(7.0, -3.0, 0.0);
	glVertex3f(-7.0, -3.0, 0.0);
	glEnd();
}


void peaks(){

	glPushMatrix();
	glTranslatef(5.07, -0.5, 0.0);
	glColor3f(0.3, 0.9, 0.3);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, -0.5, 0.0);
	glColor3f(0.2, 0.8, 0.2);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.05, -0.5, 0.0);
	glColor3f(0.3, 0.7, 0.2);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6, -0.5, 0.0);
	glColor3f(0.3, 0.8, 0.2);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.1, -0.5, 0.0);
	glColor3f(0.2, 1.0, 0.2);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4, -0.5, 0.0);
	glColor3f(0.2, 0.9, 0.2);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.9, -0.5, 0.0);
	glColor3f(0.3, 0.7, 0.2);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.9, -0.5, 0.0);
	glColor3f(0.3, 0.7, 0.3);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.4, -0.5, 0.0);
	glColor3f(0.3, 0.9, 0.3);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.9, -0.5, 0.0);
	glColor3f(0.2, 0.7, 0.2);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.4, -0.5, 0.0);
	glColor3f(0.3, 0.7, 0.3);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.9, -0.5, 0.0);
	glColor3f(0.3, 0.9, 0.3);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.4, -0.5, 0.0);
	glColor3f(0.2, 0.8, 0.2);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.9, -0.5, 0.0);
	glColor3f(0.3, 0.9, 0.3);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.4, -0.5, 0.0);
	glColor3f(0.3, 0.7, 0.3);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.9, -0.5, 0.0);
	glColor3f(0.3, 0.8, 0.3);
	circle(0.25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.4, -0.5, 0.0);
	glColor3f(0.2, 0.9, 0.2);
	circle(0.25);
	glPopMatrix();

}

void sky(){

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(-7.0, -0.55, 0.0);
	glVertex3f(7.0, -0.55, 0.0);
	glVertex3f(7.0, 3.0, 0.0);
	glVertex3f(-7.0, 3.0, 0.0);
	glEnd();
}


void window(float x, float y){

	glColor3f(1, 1, 1);
	glRectd(x - 0.16, y - 0.01, x + 0.16, y + 0.01);
	glRectd(x - 0.24, y - 0.28, x + 0.24, y - 0.26);
	glColor3f(0.9, 0.9, 0.9);
	glRectf(x - 0.16, y - 0.22, x + 0.16, y + 0.22);
	glColor3f(1.0, 1.0, 1.0);
	glRectf(x - 0.2, y - 0.26, x + 0.2, y + 0.26);

}


void house(){

	//chimney
	glColor3f(0.5, 0.5, 0.5);
	glRectd(3.35, 0.50, 3.65, 0.6);
	glColor3f(1, 1, 1);
	glRectd(3.4, 0.20, 3.6, 0.5);


	window(4.29, -0.37);
	window(2.55, -0.22);
	window(4.0, -1.4);
	window(4.6, -1.4);

	//little fence
	glColor3f(0.9, 0.0, 0.0);
	glRectf(1.75, -1.7, 1.85, -1.3);
	glPushMatrix();

	glTranslatef(1.95, 0.0, 0.0);
	glColor3f(0.9, 0.0, 0.0);
	glRectf(0.0, -1.7, 0.1, -1.3);
	glPushMatrix();

	glTranslated(0.2, 0.0, 0.0);
	glColor3f(0.9, 0.0, 0.0);
	glRectf(0.0, -1.7, 0.1, -1.3);
	glPushMatrix();

	glTranslated(0.2, 0.0, 0.0);
	glColor3f(0.9, 0.0, 0.0);
	glRectf(0.0, -1.7, 0.1, -1.3);
	glPushMatrix();

	glTranslated(0.2, 0.0, 0.0);
	glColor3f(0.9, 0.0, 0.0);
	glRectf(0.0, -1.7, 0.1, -1.3);
	glPushMatrix();

	glTranslated(1.8, -2.95, 0.0);
	glRotated(180, 0, 0, 1);
	glColor3f(0.8, 0.0, 0.0);
	glRectf(1.65, -1.5, 2.65, -1.4);
	glPushMatrix();
	glPopMatrix();

	window(2.2, -1.2);

	//pillar
	glColor3f(0.9, 0.0, 0.0);
	glRectf(2.7, -2.0, 2.8, -0.7);
	glPushMatrix();
	glPopMatrix();

	//stairs
	glColor3f(0.80, 0.4, 0.1);
	glRectf(2.9, -1.8, 3.5, -1.77);
	glColor3f(1.0, 1.0, 0.0);
	glRectf(2.9, -1.8, 3.5, -1.7);

	glColor3f(0.80, 0.4, 0.1);
	glRectf(2.85, -1.9, 3.55, -1.87);
	glColor3f(1.0, 1.0, 0.0);
	glRectf(2.85, -1.9, 3.55, -1.8);

	glColor3f(0.80, 0.4, 0.1);
	glRectf(2.8, -2.0, 3.6, -1.97);
	glColor3f(1.0, 1.0, 0.0);
	glRectf(2.8, -2.0, 3.6, -1.9);

	glPushMatrix();
	glPopMatrix();

	//lower part of the house
	glColor3f(0.86, 0.5, 0.2);
	glRectf(1.75, -2.0, 4.99, -1.96);
	glPushMatrix();
	glPopMatrix();

	//door
	glColor3f(0.5, 0.5, 0.5);
	glPointSize(7.0);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glVertex2f(3.0, -1.3);
	glEnd();
	glDisable(GL_POINT_SMOOTH);

	glColor3f(0.9, 0.9, 0.9);
	glRectf(3.05, -1.65, 3.35, -0.95);
	glPushMatrix();
	glColor3f(1, 1, 1);
	glRectf(3.0, -1.7, 3.4, -0.9);
	glPushMatrix();
	glPopMatrix();

	//balcony left part
	glColor3f(0.80, 0.4, 0.1);
	glLineWidth(0.3);
	glBegin(GL_LINES);
	glVertex2f(1.75, -1.7);
	glVertex2f(3.6, -1.70);
	glEnd();
	glPushMatrix();

	//right side
	glColor3f(0.80, 0.4, 0.1);
	glRectf(3.55, -0.82, 5.05, -0.85);
	glPushMatrix();

	//door side
	glColor3f(0.96, 0.8, 0.1);
	glRectf(1.75, -2, 3.6, -0.7);
	glPushMatrix();

	//right side
	glScalef(0.75, 1.0, 0.0);
	glTranslatef(3.05, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glRectf(1.75, -2, 3.6, -0.7);
	glPushMatrix();
	glPopMatrix();

	//right upstairs
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(3.6, -0.7);
	glVertex2f(4.99, -0.7);
	glVertex2f(4.29, 0.25);
	glEnd();
	glPushMatrix();
	glPopMatrix();

	//right roof
	glColor3f(0.75, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(3.5, -0.72);
	glVertex2f(4.31, 0.37);
	glVertex2f(5.08, -0.72);
	glEnd();
	glPushMatrix();
	glPopMatrix();

	//left upstairs window
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(2.3, -0.55);
	glVertex2f(2.8, -0.55);
	glVertex2f(2.8, 0.0);
	glVertex2f(2.55, 0.25);
	glVertex2f(2.3, 0.0);
	glEnd();
	glPushMatrix();
	glPopMatrix();

	//left roof of upstairs window
	glColor3f(0.75, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(2.2, -0.02);
	glVertex2f(2.9, -0.02);
	glVertex2f(2.55, 0.32);
	glEnd();
	glPushMatrix();
	glPopMatrix();

	//left roof
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(1.65, -0.7);
	glVertex2f(2, 0.20);
	glVertex2f(4.20, 0.20);
	glVertex2f(3.50, -0.72);
	glEnd();
	glPushMatrix();
	glPopMatrix();

}

void road(){

	glBegin(GL_POLYGON);
	glColor3f(0.55f, 0.5f, 0.1f);
	glVertex3f(2.80, -2, 0.0);
	glVertex3f(2.60, -2.40, 0.0);
	glVertex3f(2.00, -3.00, 0.0);
	glVertex3f(2.70, -3.00, 0.0);
	glVertex3f(3.30, -2.55, 0.0);
	glVertex3f(3.60, -2.00, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glColor3f(0.55f, 0.5f, 0.1f);
	glVertex3f(-4.9, -2, 0.0);
	glVertex3f(-4.1, -2, 0.0);
	glVertex3f(-3.0, -2.5, 0.0);
	glVertex3f(-3.9, -2.5, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.55f, 0.5f, 0.1f);
	glVertex3f(2.00, -3.00, 0.0);
	glVertex3f(2.60, -2.40, 0.0);
	glVertex3f(-0.60, -2.00, 0.0);
	glVertex3f(-0.40, -2.80, 0.0);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glColor3f(0.55f, 0.5f, 0.1f);
	glVertex3f(-6.00, -2.40, 0.0);
	glVertex3f(-6.00, -3.40, 0.0);
	glVertex3f(-0.60, -2.00, 0.0);
	glVertex3f(-0.40, -2.80, 0.0);
	glEnd();
	glFlush();

}

void gameover(const char *string, float x, float y, float z){

	//glColor3f(1.0, 1.0, 1.0);
	const char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}

}

void Score(char *string, float x, float y, float z){

	//glColor3f(1.0, 1.0, 1.0);
	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}

}

void drawBitmapText(char *string, float x, float y, float z){

	glColor3f(0.0, 0.0, 0.0);

	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}


void initRendering(){

	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h){

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


void drawScene(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units


	if (gameOver)
	{
		glColor3f(0.0, 0.0, 0.0);
		gameover("GAME OVER", -0.30, -0.70, 0.0);
		//gameover();
		char score[4];
		char scr[] = { "FINAL SCORE:   " };
		printf(score, "%d", count);
		drawBitmapText(score, 0.90, -0.90, 0.0);
		drawBitmapText(scr, -0.40, -0.90, 0);
		glColor3f(0.0, 0.0, 0.0);
		gameover("Press'R' to replay", -0.47, -1.10, 0.0);
	}
	else
	{
		char score[4];
		char scr[] = { "SCORE:   " };
		printf(score, "%d", count);
		drawBitmapText(score, 3.5, 3.00, 0.0);
		drawBitmapText(scr, 3.50, 3.00, 0.0);
		Score(scr, 5.0, 1.5, 0.0);
		drawBitmapText(score, 3.5, 3.00, 0.0);
		drawBitmapText(scr, 3.50, 3.00, 0.0);
		Score(score, 5.5, 1.3, 0.00);

		basket();
		apple(dimX, dimY);

		if (layapple)
		{
			dimX = marX + 0.37;
			dimY = marY + 0.5;
			layapple = false;
		}

	}

	if (marX + marWidth >= 0.50)
		moveRight = false;
	else if (marX <= -3.50)
		moveRight = true;

	if (moveRight)
		marX += marSpeed;
	else
		marX -= marSpeed;

	house();
	mainTree();
	fence();
	road();
	tree();
	surface();
	peaks();
	cloudOne();
	sun();
	cloudTwo();
	sky();

	if (sunY <= 2.2)
	{
		sunMoveup = true;
	}
	else
		sunY = 2.2;

	if (sunMoveup)
	{
		sunY += cloudspeed;
	}


	if (cloudX >= 11)
	{
		cloudMoveRight = false;
	}
	else if (cloudX <= -7)
	{
		cloudMoveRight = true;
	}


	if (cloudMoveRight)
	{
		cloudX += cloudspeed;
	}
	else
	{
		cloudX -= cloudspeed;
	}


	if (dimX >= basketX && dimX + dimWidth <= basketX + basketWidth && dimY<basketY + basketHeight && dimY>basketY + basketHeight - 5)
	{
		layapple = true;
		marSpeed += 0.003f;
		dimSpeed += 0.002f;
		count++;
	}
	else if (dimY - dimHeight <= -3.40)
	{
		gameOver = true;
		layapple = false;

	}
	else {
		dimY -= dimSpeed;
	}

	glutSwapBuffers();

}

void basketMove(int key, int x, int y) {

	//moving left and right from arrows
	if (gameOver) {

	}
	else {
		switch (key) {
		case GLUT_KEY_LEFT:
			if (basketX <= -5.50)
				break;
			else
				basketX -= 0.20f;

			break;
		case GLUT_KEY_RIGHT:
			if (basketX + basketWidth >= 1.50)
				break;
			else
				basketX += 0.20f;

			break;

		}

		basket();
	}
}

void rKeypress(unsigned char key, int x, int y) {

	switch (key)
	{
	case 'r':

		gameOver = false;
		count = -1;
		marX = 0;
		basketX = 0;
		dimX = 0;
		cloudX = 0;
		dimSpeed = 0.02;
		marSpeed = 0.03;
		glutPostRedisplay();
		break;
	}
}

void update(int value) {

	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1500, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Apples Catching Game");
	initRendering();

	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);
	glutKeyboardFunc(rKeypress);

	glutTimerFunc(25, update, 0);
	glutSpecialFunc(basketMove);
	glutMainLoop();
	return 0;

}