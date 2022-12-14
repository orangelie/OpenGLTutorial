#pragma once

#include "Utils.h"

class HelloWorld
{
public:
	HelloWorld();

	void start(int width, int height);
	void run();

private:
	const char* mAppTitle = "HelloWorld";

};

namespace GLCallback
{
	void display();
	void keyboard(unsigned char key, int x, int y);
	void special(int key, int x, int y);
	void reshape(int width, int height);
	void idle();
	void mouse(int mouse, int state, int x, int y);
}