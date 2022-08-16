#include "MenuCallback.h"

MenuCallback::MenuCallback()
{
}

void MenuCallback::start(int width, int height)
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// GLUT 초기화
	glutInitWindowPosition((int)((float)(screenWidth - width) / 2.0f), (int)((float)(screenHeight - height) / 2.0f));
	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGBA | GLUT_DOUBLE | GLUT_STENCIL);

	// GLUT 창 설정
	glutCreateWindow(mAppTitle);
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

	// 뷰포트 안정화
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	// 콜백 이벤트함수 설정
	glutDisplayFunc(GLCallback::display);
	glutReshapeFunc(GLCallback::reshape);
	glutIdleFunc(GLCallback::idle);
	glutMouseFunc(GLCallback::mouse);
	glutKeyboardFunc(GLCallback::keyboard);
	glutSpecialFunc(GLCallback::special);
}

void MenuCallback::run()
{
	glutMainLoop();
}

namespace GLCallback
{
	void display()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		glColor3f(1.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glVertex3f(-0.5f, 0.5f, 0.0f);
		glVertex3f(0.5f, 0.5f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.0f);
		glEnd();

		glFlush();
		glutSwapBuffers();
	}

	void keyboard(unsigned char key, int x, int y)
	{
		if (key == 'q')
		{
			exit(0);
		}
	}

	void special(int key, int x, int y)
	{

	}

	void reshape(int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void idle()
	{
		glutPostRedisplay();
	}

	void mouse(int mouse, int state, int x, int y)
	{

	}
}