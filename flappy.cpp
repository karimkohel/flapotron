#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <random>
#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include <time.h>

void anim();
void Key(unsigned char key);
void drawRect(int x, int y, int w, int h);
void drawCircle(int x, int y, float r);
void print(int x, int y, char* string);
void bariers(double x, double h);
void bariers2(double x, double h);
void  bariers3(double x, double h);
void bariers22(double x, double h);

bool power = false;
bool gameover = false;
int random1;
int ballx = 100;
int h;
int h1 = 40;
int h2 = -40;
int ballAtBarrierX;
float powercolor = 0;
int scoren = 0;
int bar1X = 50;
int hearts = 3;
double  ballY = 100;
void Timer(int value);
void drawtrip(int x, int h);
void  bariers(double x, double h) { // 350 550 750 950 1150 1350 1550 1750 1950

	glColor3f(0, 1, 0);
	drawRect(100 + x + bar1X, 0, 50, 150 + h); //r11

	glColor3f(0, 1, 0);
	drawRect(100 + x + bar1X, 300 + h, 50, 600);//r12

	glColor3f(0, 1, 0);
	drawRect(300 + x + bar1X, 0, 50, 200 + h);//r21

	glColor3f(0, 1, 0);
	drawRect(300 + x + bar1X, 350 + h, 50, 600);//r22

	glColor3f(0, 1, 0);
	drawRect(500 + x + bar1X, 0, 50, 250 + h);//r31

	glColor3f(0, 1, 0);
	drawRect(500 + x + bar1X, 400 + h, 50, 600);//r32

	// the ball exceeded the window size game over
	if (ballY >= 580 || ballY <= 20) {
		hearts = 0;

	}

	if (100 + x + bar1X <= 115 && 100 + x + bar1X >= 50) {
		// check birdY with this barrier's Y's
		if (ballY <= 160 || ballY >= 280) {    //1    testimg -15
			hearts--;
			ballY = 220;
		}
	}
	if (300 + x + bar1X <= 115 && 300 + x + bar1X >= 50) {
		if (ballY <= 210 || ballY >= 330) {///2
			hearts--;
			ballY = 270;
		}
	}
	if ((500 + x + bar1X <= 115 && 500 + x + bar1X >= 50)) {
		if (ballY <= 260 || ballY >= 380) {  //3
			hearts--;
			ballY = 320;
		}
	}
	//
}
void  bariers2(double x, double h) { // 350 550 750 950 1150 1350 1550 1750 1950

	glColor3f(0, 1, 0);
	drawRect(100 + x + bar1X, 0, 50, 150 + h); //r11

	glColor3f(0, 1, 0);
	drawRect(100 + x + bar1X, 300 + h, 50, 600);//r12

	glColor3f(0, 1, 0);
	drawRect(300 + x + bar1X, 0, 50, 200 + h);//r21

	glColor3f(0, 1, 0);
	drawRect(300 + x + bar1X, 350 + h, 50, 600);//r22

	glColor3f(0, 1, 0);
	drawRect(500 + x + bar1X, 0, 50, 250 + h);//r31

	glColor3f(0, 1, 0);
	drawRect(500 + x + bar1X, 400 + h, 50, 600);//r32

	if (ballY >= 580 || ballY <= 20) {
		hearts -= 3;
	}
	if (120 + x + bar1X == 115) {
		if (ballY >= 115) {

			power = true;
			powercolor = 0.5;
		}

	}
	if (bar1X == -785 && power == false) {
		if (ballY <= 110 || ballY >= (230)) {    //1
			hearts--;
			ballY = 180;
		}
	}
	if (bar1X == -985 && power == false) {
		if (ballY <= 160 || ballY >= (280)) {///2
			hearts--;
			ballY = 230;
		}

	}
	if (bar1X == -1185 && power == false) {
		if (ballY <= 210 || ballY >= (330)) {  //3
			hearts--;
			ballY = 280;
		}

	}

	if (bar1X == -1285 && power == true) {
		power = false;
	}
}
void  bariers22(double x, double h) { 

	glColor3f(0, 1 - powercolor, 0 + powercolor);
	drawRect(100 + x + bar1X, 0, 50, 150 + h); //r11

	glColor3f(0, 1 - powercolor, 0 + powercolor);
	drawRect(100 + x + bar1X, 300 + h, 50, 600);//r12

	glColor3f(0, 1 - powercolor, 0 + powercolor);
	drawRect(300 + x + bar1X, 0, 50, 200 + h);//r21

	glColor3f(0, 1 - powercolor, 0 + powercolor);
	drawRect(300 + x + bar1X, 350 + h, 50, 600);//r22

	glColor3f(0, 1 - powercolor, 0 + powercolor);
	drawRect(500 + x + bar1X, 0, 50, 250 + h);//r31

	glColor3f(0, 1 - powercolor, 0 + powercolor);
	drawRect(500 + x + bar1X, 400 + h, 50, 600);//r32

	if (100 + x + bar1X <= 115 && 100 + x + bar1X >= 50 && power == false) {
		if (ballY <= 120 || ballY >= (240)) {  
			hearts--;
			ballY = 180;

		}

	}
	if (120 + x + bar1X == 115) {
		if (ballY >= 115 && ballY <= 180) {
			power = true;
			powercolor = 0.5;
		}
	}

	if (300 + x + bar1X <= 115 && 300 + x + bar1X >= 50 && power == false) {
		if (ballY <= 170 || ballY >= (290)) {///2
			hearts--;
			//bar1X--;
			ballY = 230;
			//ballY--;
		}

	}
	if (500 + x + bar1X <= 115 && 500 + x + bar1X >= 50 && power == false) {
		if (ballY <= 220 || ballY >= (340)) {  //3
			hearts--;
			//bar1X--;
			ballY = 280;
		//	ballY--;
		}

	}

	if (600 + x + bar1X == 115 && power == true) {
		power = false;
	}
}
void  bariers3(double x, double h) { // 350 550 750 950 1150 1350 1550 1750 1950
	glColor3f(0, 1, 0);
	drawRect(100 + x + bar1X, 0, 50, 150 + h); //r11

	glColor3f(0, 1, 0);
	drawRect(100 + x + bar1X, 300 + h, 50, 600);//r12

	glColor3f(0, 1, 0);
	drawRect(300 + x + bar1X, 0, 50, 200 + h);//r21

	glColor3f(0, 1, 0);
	drawRect(300 + x + bar1X, 350 + h, 50, 600);//r22

	glColor3f(0, 1, 0);
	drawRect(500 + x + bar1X, 0, 50, 250 + h);//r31

	glColor3f(0, 1, 0);
	drawRect(500 + x + bar1X, 400 + h, 50, 600);//r32

	if (100 + x + bar1X <= 115 && 100 + x + bar1X >= 50) {  //111
		if (ballY <= 200 || ballY >= (320)) {    //1
			hearts--;
			bar1X--;
			ballY = 260;
		}
	}
	if (300 + x + bar1X <= 115 && 300 + x + bar1X >= 50) {///222
		if (ballY <= 250 || ballY >= 370) {///2
			hearts--;
			ballY = 310;
		}
	}
	if (500 + x + bar1X <= 115 && 500 + x + bar1X >= 50) {  //333
		if (ballY <= 300 || ballY >= 420) {  //3
			hearts--;
			ballY = 360;
		}
	}
	if (scoren == 2250 || hearts < 1) {
		gameover = true;
	}
}
void Key(unsigned char key, int x, int y) {
	if (key == ' ')
		ballY += 30;
	glutPostRedisplay();
}


void Display() {
	if (hearts > 0 && gameover == false) {
		glClear(GL_COLOR_BUFFER_BIT);

		glPushMatrix();
		glColor3f(1, 1, 0);//background 1
		drawRect(0 + bar1X, 0, 800, 600);
		bariers(200, 0);//bar1
		glColor3f(1, 0, 1);//background 2
		drawRect(750 + bar1X, 0, 800, 600);
		bariers22(800, -40);//bar2
		glColor3f(0, 1, 1);
		drawRect(1500 + bar1X, 0, 800, 600);//background 3
		if (power == false) {
			drawtrip(905 + bar1X, 130);
			glColor3f(1, 1, 1);
			drawRect(924 + bar1X, 140, 3, 3);
		}
		bariers3(1400, 40);//bar3

		drawCircle(100, ballY, 15);
		glColor3f(1, 0, 0);
		glBegin(GL_LINES);
		glVertex2f(90, 10 + ballY);
		glVertex2f(111, 10 + ballY);
		glEnd();
		drawRect(97, ballY, 6, 5);
		glColor3f(1, 0.7, 0.2);
		char* p0s[20];
		sprintf((char*)p0s, "Score: %d", scoren);
		print(500, 500, (char*)p0s);
		glColor3f(1, 0.7, 0.2);
		sprintf((char*)p0s, "hearts: %d", hearts);
		print(800, 500, (char*)p0s);

		glPopMatrix();
		glFlush();
		glutPostRedisplay();
	}
	else {
		glColor3f(1, 0.7, 0.2);
		char* p0s[20];
		sprintf((char*)p0s, "Game Over", 0);
		print(500, 400, (char*)p0s);
		glFlush();
		glutPostRedisplay();

	}

}
void drawRect(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y + h);
	glVertex2f(x, y + h);
	glEnd();
}
void drawtri(int x, int h) {
	glBegin(GL_TRIANGLES);

	glVertex3f(0 + x, 10 + h, 0);
	glVertex3f(25 + x, 40 + h, 0);
	glVertex3f(50 + x, 10 + h, 0);

	glEnd();
}
void drawtrip(int x, int h) {

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(10.0f + x, 5.0f + h, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(20.0f + x, 20.0f + h, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(30.0f + x, 5.0f + h, 0.0f);
	glEnd();
}


void drawCircle(int x, int y, float r) {

	glPushMatrix();
	glTranslatef(x, y, 0);
	glColor3f(0, 0, 1);
	GLUquadric* quadObj = gluNewQuadric();
	gluDisk(quadObj, 0, r, 50, 50);
	glPopMatrix();
}
int main(int argc, char** argr) {
	srand(time(NULL));
	random1 = rand() % 3 + 1; // Random number = 1 to 3
	glutInit(&argc, argr);

	glutInitWindowSize(900, 600);
	glutInitWindowPosition(150, 150);

	glutTimerFunc(1000 / 60, Timer, 0);

	glutCreateWindow("OpenGL - 2D Template");
	glutDisplayFunc(Display);
	glutKeyboardFunc(Key);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	gluOrtho2D(0.0, 900, 0.0, 600);
	glutIdleFunc(anim);
	glutMainLoop();
	return 0;
}
void anim() {

	glutPostRedisplay();
}
void print(int x, int y, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}


void Timer(int value) {
	bar1X -= 1;
	ballY -= 0.6;
	scoren += 1;
	// ask OpenGL to recall the display function to reflect the changes on the window
	glutPostRedisplay();
	glutTimerFunc(10, Timer, 0);
}