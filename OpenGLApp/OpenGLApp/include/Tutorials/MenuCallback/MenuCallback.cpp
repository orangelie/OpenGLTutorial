#include "MenuCallback.h"

static int gGeometryState = 0;
static float gDeltaTime = 0.0f;

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


	// 메뉴 이벤트함수 설정
	int subMenuID = glutCreateMenu(GLCallback::subMenu);
	glutAddMenuEntry("Box", 1);
	glutAddMenuEntry("Teapot", 2);
	glutAddMenuEntry("Sphere", 3);

	glutCreateMenu(GLCallback::mainMenu);
	glutAddMenuEntry("Exit", 1);

	glutAddSubMenu("Shape", subMenuID);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// 타이머 이벤트함수 설정
	glutTimerFunc(40, GLCallback::timer, 1);
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

		switch (gGeometryState)
		{
		case 1:
			glutSolidCube(1.0); break;
		case 2:
			glutSolidTeapot(0.5); break;
		case 3:
			glutSolidSphere(1.0, 20, 20); break;
		}

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
		
	}

	void mouse(int mouse, int state, int x, int y)
	{

	}


	void mainMenu(int value)
	{
		switch (value)
		{
		case 1:
			exit(0); break;
		}
	}

	void subMenu(int value)
	{
		switch (value)
		{
		case 1:
			gGeometryState = 1; break;
		case 2:
			gGeometryState = 2; break;
		case 3:
			gGeometryState = 3; break;
		}
	}

	void timer(int value)
	{
		glutPostRedisplay();

		gDeltaTime += 0.001f;
		std::cout << "GameTime: " << gDeltaTime << std::endl;
		glutTimerFunc(40, timer, 1);
	}
}