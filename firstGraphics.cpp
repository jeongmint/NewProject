#include <windows.h>
#include <gl/glut.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glShadeModel(GL_FLAT);
  glColor3f(0.0, 0.0, 1.0);
  gluLookAt(1.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // 변수가 9개나 들어간다..
  glScalef(1.0, 2.0, 1.0);
  glutWireTeapot(3.0);
  glFlush(); // 함수 명령어를 일일이 쌓지 않고 queue에 저장된 명령어 하나하나를 즉시 수행
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800, 400);
  glutCreateWindow("OpenGL을 공부하기 위한 티팟 샘플!");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glutDisplayFunc(display); // display 메서드 호출
  glutReshapeFunc(reshape); // reshape 메서드 호출
  glutMainLoop();
  return 0;
}