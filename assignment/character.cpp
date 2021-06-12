#include <windows.h>
#include <gl/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

bool mouseDown = false;

float xRot = 0.0f; // 캐릭터 회전을 위한 초기 변수
float yRot = 0.0f;
float zRot = 0.0f;

GLfloat nRange = 30.0f; // 캐릭터 윈도우 출력 범위 지정

GLfloat xSize = 2.0f; // 캐릭터 사이즈 지정 변수
GLfloat ySize = 2.0f;
GLfloat zSize = 2.0f;

void myCharacter(void);

void reshape(int w, int h)
{
	if (h == 0)
		h = 1;

	// 윈도우의 폭과 넓이 설정
	glViewport(0, 0, w, h);
	// 투영 행렬 스택 재설정
	glMatrixMode(GL_PROJECTION);
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 1.0, 0.0);
	gluPerspective(0.0, w / h, 0.0, 100.0);

	glLoadIdentity();
	// 캐릭터를 클리핑할 공간 설정
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

	// 모델 뷰 행렬 스택 재설정
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// 마우스 드래깅을 인식하기 위한 함수
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		mouseDown = true;
	else
		mouseDown = false;
}

// 마우스 드래깅 시 회전시켜주는 함수
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

// 줌인 줌아웃 함수
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

	//고깔모자
	glPushMatrix();
	glColor3f(0.1, 0.23, 0.84);
	glScalef(5, 5, 5);
	glTranslated(0, 1, 0);
	glutSolidCone(1, 1, 3, 3);
	glPopMatrix();

	//머리
	glPushMatrix();
	glColor3f(0.98, 0.8, 0.69);
	glScalef(5, 5, 5);
	glutSolidCube(1);
	glPopMatrix();

	//목
	glPushMatrix();
	glColor3f(0.98, 0.8, 0.69);
	glTranslated(0, -3, 0);
	glScalef(3, 1, 3);
	glutSolidCube(1);
	glPopMatrix();

	//왼쪽 눈	
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(2.5, .5, .5);
	glScalef(.5, 2, 2);
	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();

	//왼쪽 눈동자
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(2.6, .5, .5);
	glScalef(.5, .75, .75);
	glutSolidSphere(0.8, 60, 50);
	glPopMatrix();

	//오른쪽 눈	
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslated(-2.5, .5, .5);
	glScalef(.5, 2, 2);
	glutSolidSphere(0.5, 50, 50);
	glPopMatrix();

	//오른쪽 눈동자
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(-2.6, .5, .5);
	glScalef(.5, .75, .75);
	glutSolidSphere(0.8, 60, 50);
	glPopMatrix();

	//입술
	glPushMatrix();
	glColor3f(1.0, 0.72, 0.82);
	glTranslated(0, 0, 3);
	glScalef(2, 1, 2);
	glutSolidIcosahedron();
	glPopMatrix();

	//상의
	glPushMatrix();
	glColor3f(0.60, 0.22, 0.84);
	glTranslated(0, -5, 0);
	glScalef(5, 3, 5);
	glutSolidCube(1);
	glPopMatrix();

	//왼쪽팔
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

	//오른쪽팔
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

	//바지
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.6);
	glTranslated(0, -7, 0);
	glScalef(5, 1, 5);
	glutSolidCube(1);
	glPopMatrix();

	//장화
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