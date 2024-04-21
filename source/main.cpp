#include "main.h"
#include "gui.h"

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
