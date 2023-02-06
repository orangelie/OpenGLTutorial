#if defined(HELLOWORLD)
#define APP HelloWorld
#include "Tutorials/HelloWorld/HelloWorld.h"
#endif

#if defined(MENUCALLBACK)
#define APP MenuCallback
#include "Tutorials/MenuCallback/MenuCallback.h"
#endif

#if defined(VERTEXARRAY)
#define APP VertexArray
#include "Tutorials/VertexArray/VertexArray.h"
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