#include <GL/glut.h>
#include <math.h>

static int shoulder = 0, shoulder2 = 0, elbow = 0, fingerBase = 0, fingerUp = 0, rhip = 0, rhip2 = 0, rknee = 0, lknee = 0, lhip = 0, lhip2 = 0 ;
double eye[] = { 0, 0, -20 };
double center[] = { 0, 0, 1 };
double up[] = { 0, 1, 0 };

void init(void)
{
    glMatrixMode(GL_PROJECTION);
	gluPerspective(65.0, (GLfloat)1024 / (GLfloat)869, 1.0, 60.0);
}

void crossProduct(double a[], double b[], double c[])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(double a[])
{
	double norm;
	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void rotatePoint(double a[], double theta, double p[])
{

	double temp[3];
	temp[0] = p[0];
	temp[1] = p[1];
	temp[2] = p[2];

	temp[0] = -a[2] * p[1] + a[1] * p[2];
	temp[1] = a[2] * p[0] - a[0] * p[2];
	temp[2] = -a[1] * p[0] + a[0] * p[1];

	temp[0] *= sin(theta);
	temp[1] *= sin(theta);
	temp[2] *= sin(theta);

	temp[0] += (1 - cos(theta))*(a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
	temp[1] += (1 - cos(theta))*(a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
	temp[2] += (1 - cos(theta))*(a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

	temp[0] += cos(theta)*p[0];
	temp[1] += cos(theta)*p[1];
	temp[2] += cos(theta)*p[2];

	p[0] = temp[0];
	p[1] = temp[1];
	p[2] = temp[2];

}

void Left()
{
}

void Right()
{
}

void Up()
{
}

void Down()
{
}

void moveForward()
{
}

void moveBack()
{
}


void draw_right_arm(void)
{
}

void draw_left_arm(void)
{
}

void draw_righ_leg(void)
{
}

void draw_left_leg(void)
{
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT );
   	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	// draw head

	// draw trunck

	draw_left_arm();
	draw_right_arm();

	draw_righ_leg();
	draw_left_leg();

	glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: Left(); break;
	case GLUT_KEY_RIGHT: Right(); break;
	case GLUT_KEY_UP:    Up(); break;
	case GLUT_KEY_DOWN:  Down(); break;
	}

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 's':
		shoulder = (shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'a':
		shoulder2 = (shoulder2 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'A':
		shoulder2 = (shoulder2 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'd':
		elbow = (elbow + 5) % 360;
		glutPostRedisplay();
		break;
	case 'D':
		elbow = (elbow - 5) % 360;
		glutPostRedisplay();
		break;
	case 'z':
		fingerBase = (fingerBase + 5) % 360;
		glutPostRedisplay();
		break;
	case 'Z':
		fingerBase = (fingerBase - 5) % 360;
		glutPostRedisplay();
		break;
	case 'x':
		fingerUp = (fingerUp + 5) % 360;
		glutPostRedisplay();
		break;
	case 'X':
		fingerUp = (fingerUp - 5) % 360;
		glutPostRedisplay();
		break;
	case 'q':
		rhip = (rhip + 5) % 360;
		glutPostRedisplay();
		break;
	case 'Q':
		rhip = (rhip - 5) % 360;
		glutPostRedisplay();
		break;
	case 'w':
		rknee = (rknee + 5) % 360;
		glutPostRedisplay();
		break;
	case 'W':
		rknee = (rknee - 5) % 360;
		glutPostRedisplay();
		break;
	case 'e':
		rhip2 = (rhip2 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'E':
		rhip2 = (rhip2 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'r':
		lhip = (lhip + 5) % 360;
		glutPostRedisplay();
		break;
	case 'R':
		lhip = (lhip - 5) % 360;
		glutPostRedisplay();
		break;
	case 't':
		lknee = (lknee + 5) % 360;
		glutPostRedisplay();
		break;
	case 'T':
		lknee = (lknee - 5) % 360;
		glutPostRedisplay();
		break;
	case 'y':
		lhip2 = (lhip2 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'Y':
		lhip2 = (lhip2 - 5) % 360;
		glutPostRedisplay();
		break;

	case 'F':
		moveForward(); 
		glutPostRedisplay(); 
		break;
	case 'B':
		moveBack(); 
		glutPostRedisplay(); 
		break;

	default:
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("body");
	init();
	glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}
