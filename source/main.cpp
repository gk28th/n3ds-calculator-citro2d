#include "main.h"
#include "gui.h"
#include "operations.h"

int main()
{
	sceneInit();

	while (aptMainLoop())
	{
		whatOp();
		if (timeToFuckOff) break;
        menuTextDraw();	
	}
	
	sceneExit();
	return 0;
}
