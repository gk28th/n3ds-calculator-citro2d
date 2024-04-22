/*created by gk28th
  File Name: main.cpp
  Purpose: Main entry point
*/
#include "main.h"	// contains main header files and bool
#include "gui.h"	// for basic render functions

int main()
{
	sceneInit();	// init scene with function gui.cpp

	while (aptMainLoop())	// main loop
	{
		whatOp();	// what operations should we do? operation.cpp
		if (timeToFuckOff) break; // if its time to go, lets go
        menuTextDraw();			  // draw the menu text, menu.cpp
	}
	
	sceneExit();				// clean up and exit, gui.cpp
	return 0;
}
