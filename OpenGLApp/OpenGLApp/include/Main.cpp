#if defined(HELLOWORLD)
#define APP HelloWorld
#include "Tutorials/HelloWorld/HelloWorld.h"
#else if defined(MENUCALLBACK)
#define APP MenuCallback
#include "Tutorials/MenuCallback/MenuCallback.h"
#endif

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	{
		std::unique_ptr<APP> app(new APP);
		app->start(1280, 720);
		app->run();
	}

	return 0;
}