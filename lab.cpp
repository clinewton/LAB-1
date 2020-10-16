
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <math.h>

void display(void)
{
	/* clear all pixels */
	glClear(GL_COLOR_BUFFER_BIT);


	// Door
	glBegin(GL_POLYGON);
	glLineWidth(5.0);
	glColor3f(1.0, 1.0, 1.0);	//Set the line color to blue
	glVertex2f(-2.0, -6.0);
	glVertex2f(-2.0, 6.0);
	glVertex2f(4.0, 6.0);
	glVertex2f(4.0, -6.0);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.5, 1.0);

	glVertex2f(-2.0, -6.0);
	glVertex2f(-2.0, 6.0);
	glVertex2f(-2.0, 6.0);
	glVertex2f(4.0, 6.0);
	glVertex2f(4.0, 6.0);
	glVertex2f(4.0, -6.0);

	glEnd();

	// Door end



	// Door knob
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 1.0);

	for (float i = 0; i < 360; i += 0.0001) {
		float theta = i * 3.14159 / 180;
		glVertex2f(3.0f + 0.3f * cos(theta), -1.0f + 0.3f * sin(theta));
	}

	glEnd();

	glBegin(GL_POINTS);
	glLineWidth(7.0);
	glColor3f(0.0, 0.0, 1.0);
	for (float i = 0; i < 360; i += 0.0001) {
		float theta = i * 3.14159 / 180;
		glVertex2f(3.0f + 0.3f * cos(theta), -1.0f + 0.3f * sin(theta));
	}
	glEnd();

	//Door knob end



	// Windows

	// Right Window
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(7.0, 2.0);
	glVertex2f(7.0, 6.0);
	glVertex2f(13.0, 6.0);
	glVertex2f(13.0, 2.0);

	glEnd();

	// Left Window
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-5.0, 2.0);
	glVertex2f(-5.0, 6.0);
	glVertex2f(-11.0, 6.0);
	glVertex2f(-11.0, 2.0);

	glEnd();

	// Window grills
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(10.0, 2.0);
	glVertex2f(10.0, 6.0);
	glVertex2f(7.0, 4.0);
	glVertex2f(13.0, 4.0);
	glVertex2f(-8.0, 2.0);
	glVertex2f(-8.0, 6.0);
	glVertex2f(-5.0, 4.0);
	glVertex2f(-11.0, 4.0);

	glEnd();

	// Windows end



	// Wall
	glBegin(GL_LINES);
	glColor3f(0.0, 0.5, 1.0);
	glVertex2f(-12.0, -6.0);
	glVertex2f(-12.0, 8.0);
	glVertex2f(-12.0, 8.0);
	glVertex2f(-14.0, 8.0);
	glVertex2f(-14.0, 8.0);
	glVertex2f(-14.0, 12.0);
	glVertex2f(-14.0, 12.0);
	glVertex2f(16.0, 12.0);
	glVertex2f(16.0, 12.0);
	glVertex2f(16.0, 8.0);
	glVertex2f(16.0, 8.0);
	glVertex2f(14.0, 8.0);
	glVertex2f(14.0, 8.0);
	glVertex2f(14.0, -6.0);
	glVertex2f(14.0, -6.0);
	glVertex2f(-12.0, -6.0);

	glEnd();

	// Wall end



	// Roof
	float arc_rad = 9.0f; // radius of the roof

	glBegin(GL_POINTS);

	for (float i = 0; i < 180; i += 0.0001) {
		float theta = i * 3.14159 / 180;
		glVertex2f(1.0 + arc_rad * cos(theta), 12.0f + arc_rad * sin(theta));
	}
	glEnd();

	//Roof end



	// Crescent Moon
	float outer_rad = 3.4f; // outer radius of the moon
	float inner_rad = 4.0f; // inner radius of the moon


	// Outer border
	glBegin(GL_POINTS);
	glLineWidth(9.0);

	for (float i = 150; i < 300; i += 0.0001) {
		float theta = i * 3.14159 / 180;
		glVertex2f(16.0 + outer_rad * cos(theta), 22.0f + outer_rad * sin(theta));
	}

	glEnd();

	// Crescent color
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.1, 0.1);

	for (float i = 150; i < 300; i += 0.0001) {
		float theta = i * 3.14159 / 180;
		glVertex2f(16.0 + outer_rad * cos(theta), 22.0f + outer_rad * sin(theta));
	}

	glEnd();

	// Inner border
	glBegin(GL_POINTS);
	glLineWidth(9.0);
	glColor3f(0.0, 0.5, 1.0);

	for (float i = 170; i < 280; i += 0.0001) {
		float theta = i * 3.14159 / 180;
		glVertex2f(17.0 + inner_rad * cos(theta), 23.0f + inner_rad * sin(theta));
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);

	for (float i = 170; i < 280; i += 0.0001) {
		float theta = i * 3.14159 / 180;
		glVertex2f(17.0 + inner_rad * cos(theta), 23.0f + inner_rad * sin(theta));
	}
	glEnd();

	// Crescent moon end
	glFlush();
}

void init(void)
{
	/* select clearing (background) color */
	glClearColor(1.0, 0.5, 0.0, 1.0);
	/* initialize viewing values */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-18, 20, -10, 26);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Lab 1");

	init();
	glutDisplayFunc(display);
	glutMainLoop();
}