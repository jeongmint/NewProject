#include <windows.h>
#include <gl/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

bool mouseDown = false;

float xRot = 0.0f; // ĳ���� ȸ���� ���� �ʱ� ����
float yRot = 0.0f;
float zRot = 0.0f;

GLfloat nRange = 30.0f; // ĳ���� ������ ��� ���� ����

GLfloat xSize = 2.0f; // ĳ���� ������ ���� ����
GLfloat ySize = 2.0f;
GLfloat zSize = 2.0f;

void myCharacter(void);

void reshape(int w, int h)
{
	if (h == 0)
		h = 1;

	// �������� ���� ���� ����
	glViewport(0, 0, w, h);
	// ���� ��� ���� �缳��
	glMatrixMode(GL_PROJECTION);
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);
	gluPerspective(0.0, w / h, 0.0, 100.0);

	glLoadIdentity();
	// ĳ���͸� Ŭ������ ���� ����
	if (w <= h)
		glOrtho
		(-nRange, nRange,
			-nRange * h / w, nRange * h / w,
			-nRange, nRange);
	else
		glOrtho
		(-nRange * w / h, nRange * w / h,
			-nRange, nRange,
			-nRange, nRange);

	// �� �� ��� ���� �缳��
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// ���콺 �巡���� �ν��ϱ� ���� �Լ�
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		mouseDown = true;
	else
		mouseDown = false;
}

// ���콺 �巡�� �� ȸ�������ִ� �Լ�
void mouseDrag(int x, int y)
{
	if (mouseDown)
	{
		xRot += 1.5;
		yRot += 1.5;
		zRot += 1.5;
		glutPostRedisplay();
	}
}

// ���� �ܾƿ� �Լ�
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'a') {        // zoom in
		xSize += 0.15;
		ySize += 0.15;
		zSize += 0.15;
		glutPostRedisplay();
	}
	if (key == 'z') {        // zoom out
		xSize -= 0.15;
		ySize -= 0.15;
		zSize -= 0.15;
		glutPostRedisplay();
	}
}

void init(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 10, 0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(120, 1, 1, 20);
}

void myCharacter() {

	//������
	glPushMatrix();
	glColor3f(0.1, 0.23, 0.84);
	glScalef(5, 5, 5);
	glTranslated(0, 1, 0);
	glutSolidCone(1, 1, 3, 3);
	glPopMatrix();

	//�Ӹ�
	glPushMatrix();
	glColor3f(0.98, 0.8, 0.69);
	glScalef(5, 5, 5);
	glutSolidCube(1);
	glPopMatrix();

	//��
	glPushMatrix();
	glColor3f(0.98, 0.8, 0.69);
	glTranslated(0, -3, 0);
	glScalef(3, 1, 3);
	glutSolidCube(1);
	glPopMatrix();

	//���� ��	
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(2.5, .5, .5);
	glScalef(.5, 2, 2);
	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();

	//���� ������
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(2.6, .5, .5);
	glScalef(.5, .75, .75);
	glutSolidSphere(0.8, 60, 50);
	glPopMatrix();

	//������ ��	
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(-2.5, .5, .5);
	glScalef(.5, 2, 2);
	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();

	//������ ������
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(-2.6, .5, .5);
	glScalef(.5, .75, .75);
	glutSolidSphere(0.8, 60, 50);
	glPopMatrix();

	//�Լ�
	glPushMatrix();
	glColor3f(1.0, 0.72, 0.82);
	glTranslated(0, 0, 3);
	glScalef(2, 1, 2);
	glutSolidIcosahedron();
	glPopMatrix();

	//����
	glPushMatrix();
	glColor3f(0.60, 0.22, 0.84);
	glTranslated(0, -5, 0);
	glScalef(5, 3, 5);
	glutSolidCube(1);
	glPopMatrix();

	//������
	glPushMatrix();
	glColor3f(0.52, 0.25, 0.87);
	glScalef(1, 2, 2.5);
	glTranslated(3, -2, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.98, 0.8, 0.69);
	glScalef(1, 2, 2.5);
	glTranslated(3, -3, 0);
	glutSolidCube(1);
	glPopMatrix();

	//��������
	glPushMatrix();
	glColor3f(0.52, 0.25, 0.87);
	glScalef(1, 2, 2.5);
	glTranslated(-3, -2, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.98, 0.8, 0.69);
	glScalef(1, 2, 2.5);
	glTranslated(-3, -3, 0);
	glutSolidCube(1);
	glPopMatrix();

	//����
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.6);
	glTranslated(0, -7, 0);
	glScalef(5, 1, 5);
	glutSolidCube(1);
	glPopMatrix();

	//��ȭ
	glPushMatrix();
	glTranslated(2, 0, 0);
	glColor3f(0.67, 0.65, 0);
	glPushMatrix();
	glTranslated(0, -9, 0);
	glScalef(2, .2, 2);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, -8, 0);
	glScalef(.5, 2, 1);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-2, 0, 0);
	glColor3f(0.67, 0.65, 0);
	glPushMatrix();
	glTranslated(0, -9, 0);
	glScalef(2, .2, 2);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, -8, 0);
	glScalef(.5, 2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

}

void display()
{
	glMatrixMode(GL_MODELVIEW);
	glutInitDisplayMode(GLUT_DEPTH);
	glClear(GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glRotatef(zRot, 0.0f, 0.0f, 1.0f);
	glScalef(xSize, ySize, zSize);
	myCharacter();
	glPopMatrix();
	glFlush();

}

int main(int argc, char** argv) {
	glutInitWindowSize(800, 800);
	glutInit(&argc, argv);
	glutCreateWindow("CG Assignment | Choi Jeong Min");
	init();

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseDrag);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;

}