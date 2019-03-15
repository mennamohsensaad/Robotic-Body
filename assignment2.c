#include <stdlib.h>
#include <gl/glut.h>
#include <math.h>

static int shoulder = 0, shoulder2 = 0, elbow = 0,  fingerBase = 0, fingerUp = 0, rhip = 0, rhip2=0, lhip = 0, lhip2=0, rknee = 0, lknee = 0, lfoot = 0, rfoot = 0;
int direction[] = { 0,0,0 };
double speed = 0.01;

double eye[] = { 0, 0, -20 };
double center[] = { 0, 0, 1 };
double up[] = { 0, 1, 0 };

GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */



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
	rotatePoint(up, 0.05, eye);
}

void Right()
{
	rotatePoint(up, -0.05, eye);
}

void Up()
{
	double V[] = { 0,0,0 };
	crossProduct(eye, up, V);
	normalize(V);
	rotatePoint(V, 0.05, eye);
	rotatePoint(V, 0.05, up);

}

void Down()
{
	double V[] = { 0,0,0 };
	crossProduct(eye, up, V);
	normalize(V);
	rotatePoint(V, -0.05, eye);
	rotatePoint(V, -0.05, up);

}

void moveForward()
{
	direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];

	eye[0] += direction[0] * speed;
	eye[1] += direction[1] * speed;
	eye[2] += direction[2] * speed;

	center[0] += direction[0] * speed;
	center[1] += direction[1] * speed;
	center[2] += direction[2] * speed;
}

void moveBack()
{
	direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];

	eye[0] -= direction[0] * speed;
	eye[1] -= direction[1] * speed;
	eye[2] -= direction[2] * speed;

	center[0] -= direction[0] * speed;
	center[1] -= direction[1] * speed;
	center[2] -= direction[2] * speed;

}


void draw_right_arm(void)
{
	//shoulder
	glPushMatrix();
	glTranslatef(2, 6, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)shoulder2, 0.0, 1.0, 0.0);
	glTranslatef(0.0, -1, 0.0);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(0.8, 2, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//elbow
	glTranslatef(0, -1, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(0, -1, 0);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(0.8, 2.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

         /////fingers
        //finger1
	glPushMatrix();
	glTranslatef(-.25, -1, 0.0);
	glRotatef((GLfloat)fingerBase, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glTranslatef(-.01, -0.2, 0.0);
	glRotatef((GLfloat)fingerUp, 1.0, 0.0, 0.0);
	glTranslatef(0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();


        //finger  2
	glPushMatrix();
	glTranslatef(-0.05, -1, 0.0);
	glRotatef((GLfloat)fingerBase, 1.0, 0.0, 0);
	glTranslatef(0.0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glTranslatef(-.01, -0.2, 0.0);
	glRotatef((GLfloat)fingerUp, 1.0, 0.0, 0);
	glTranslatef(0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();

	// finger 3
	glPushMatrix();
	glTranslatef(0.12, -1, 0.0);
	glRotatef((GLfloat)fingerBase, 1.0, 0.0, 0);
	glTranslatef(0.0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glTranslatef(-.01, -0.2, 0.0);
	glRotatef((GLfloat)fingerUp, 1.0, 0.0, 0);
	glTranslatef(0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();

        // finger  4
	glPushMatrix();
	glTranslatef(0.3, -1, 0.0);
	glRotatef((GLfloat)fingerBase, 1.0, 0.0, 0);
	glTranslatef(0.0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glTranslatef(-.01, -0.2, 0.0);
	glRotatef((GLfloat)fingerUp, 1.0, 0.0, 0);
	glTranslatef(0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();

}

void draw_left_arm(void)
{
	//sholder
	glPushMatrix();
	glTranslatef(-2, 6, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, -1.0);
	glRotatef((GLfloat)shoulder2, 0.0, -1.0, 0.0);
	glTranslatef(0.0, -1, 0.0);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(0.8, 2, 1.0);
	glutWireCube(1);
	glPopMatrix();
	//elbow
	glTranslatef(0, -1, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, -1.0);
	glTranslatef(0, -1, 0);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(0.8, 2.0, 1.0);
	glutWireCube(1);
	glPopMatrix();
	/////finfers
        // finger 1
	glPushMatrix();
	glTranslatef(-0.3, -1, 0.0);
	glRotatef((GLfloat)fingerBase, 1, 0.0,0.0);
	glTranslatef(0.0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glTranslatef(-.01, -0.2, 0.0);
	glRotatef((GLfloat)fingerUp, 1, 0.0, 0.0);
	glTranslatef(0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();

        // finger  2
	glPushMatrix();
	glTranslatef(-0.1, -1, 0.0);
	glRotatef((GLfloat)fingerBase, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glTranslatef(.01, -0.2, 0.0);
	glRotatef((GLfloat)fingerUp, 1.0, 0.0, 0.0);
	glTranslatef(0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();

	// finger 3
	glPushMatrix();
	glTranslatef(0.1, -1, 0.0);
	glRotatef((GLfloat)fingerBase, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glTranslatef(-.01, -0.2, 0.0);
	glRotatef((GLfloat)fingerUp, 1.0, 0.0, 0.0);
	glTranslatef(0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();

	// finger 4
	glPushMatrix();
	glTranslatef(0.3, -1, 0.0);
	glRotatef((GLfloat)fingerBase, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glTranslatef(-.01, -0.2, 0.0);
	glRotatef((GLfloat)fingerUp, 1.0, 0.0, 0.0);
	glTranslatef(0, -.175, 0.0);
	glPushMatrix();
	glScalef(0.2, 0.35, 0.15);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


}

void draw_righ_leg(void)
{
	//righthip
	glPushMatrix();
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)rhip, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)rhip2, 0.0, 0.0, 0.1);
	glTranslatef(0.0, -1.5, 0.0);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(1, 3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	//rightknee
	glTranslatef(0, -1.5, 0.0);
	glRotatef((GLfloat)rknee, 0.1, 0.0, 0.0);
	glTranslatef(0, -1.5, 0);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(1, 3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
        //rightfoot
	glPushMatrix();
	glTranslatef(0.1, -1.3, 0.1);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(1.3, 1, 2.5);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void draw_left_leg(void)
{
	//lefthip
	glPushMatrix();
	glTranslatef(-1, 0, 0.0);
	glRotatef((GLfloat)lhip, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)lhip2, 0.0, 0.0, 0.1);
	glTranslatef(0.0, -1.5, 0.0);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(1, 3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	///leftknee
	glTranslatef(0, -1.5, 0.0);
	glRotatef((GLfloat)lknee, 1.0, 0.0, 0.0);
	glTranslatef(0, -1.5, 0);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(1, 3, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
        //left foot
	glPushMatrix();
	glTranslatef(-0.1, -1.3, 0.1);
	glPushMatrix();
	glColor3f(0.5, 0.25, 0.25);
	glScalef(1.3, 1, 2.5);
	glutSolidCube(1);
	glPopMatrix();
        glPopMatrix();

	glPopMatrix();
}


void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	// draw head
	glPushMatrix();
	glTranslatef(0, 7.0, -0.1);
	glColor3f(0.5, 0.25, 0.25);
	glScalef(1.8, 1.8, 1);
	glutSolidCube(1);
	glPopMatrix();


	// draw trunck
	glPushMatrix();
	glTranslatef(0, 3, 0.0);
	glColor3f(0.5, 0.25, 0.25);
	glScalef(3, 6, 1);
	glutWireCube(1.0);
	glPopMatrix();




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
		// arms
	case 's':
		shoulder = (shoulder + 5) % 180;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 180;
		glutPostRedisplay();
		break;
	case 'a':
		shoulder2 = (shoulder2 + 5) % 180;
		glutPostRedisplay();
		break;
	case 'A':
		shoulder2 = (shoulder2 - 5) % 180;
		glutPostRedisplay();
		break;

	case 'd':
		elbow = (elbow + 5) % 180;
		glutPostRedisplay();
		break;
	case 'D':
		elbow = (elbow - 5) % 180;
		glutPostRedisplay();
		break;

               //fingers
        case 'z':
		fingerBase = (fingerBase + 5) % 90;
		glutPostRedisplay();
		break;
	case 'Z':
		fingerBase = (fingerBase - 5) % 90;
		glutPostRedisplay();
		break;
	case 'x':
		fingerUp = (fingerUp + 5) % 180;
		glutPostRedisplay();
		break;
	case 'X':
		fingerUp = (fingerUp - 5) % 180;
		glutPostRedisplay();
		break;

              //right leg
	case 'q':
		rhip = (rhip + 5) % 90;
		glutPostRedisplay();
		break;
	case 'Q':
		rhip = (rhip - 5) % 90;
		glutPostRedisplay();
		break;
        case 'w':
		rknee = (rknee + 5) % 180;
		glutPostRedisplay();
		break;
	case 'W':
		rknee = (rknee - 5) % 180;
		glutPostRedisplay();
		break;
	case 'e':
		rhip2 = (rhip2 + 5) % 90;
		glutPostRedisplay();
		break;
	case 'E':
		rhip2 = (rhip2 - 5) % 90;
		glutPostRedisplay();
		break;
		
            //left leg
        case 'r':
		lhip = (lhip + 5) % 90;
		glutPostRedisplay();
		break;
	case 'R':
		lhip = (lhip - 5) % 90;
		glutPostRedisplay();
		break;
	case 't':
		lknee = (lknee + 5) % 90;
		glutPostRedisplay();
		break;
	case 'T':
		lknee = (lknee - 5) % 90;
		glutPostRedisplay();
		break;
	case 'y':
		lhip2 = (lhip2 + 5)% 90;
		glutPostRedisplay();
		break;
	case 'Y':
		lhip2 = (lhip2 - 5) % 90;
		glutPostRedisplay();
		break;

             //move camera
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
