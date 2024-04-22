/*created by gk28th
  File Name: menu.cpp
  Purpose: Draw main menu for options
*/
#include "menu.h"
#include "gui.h"

void menuInit()	  // init menu
{
	menuTextBuf  = C2D_TextBufNew(400); // create a text buffer to hold menu text

	C2D_TextParse(&menuText[0], menuTextBuf, title);	// analyse string, store it in buffer and allocate variable to it
	C2D_TextParse(&menuText[1], menuTextBuf, options);	// analyse string, store it in buffer and allocate variable to it

	C2D_TextOptimize(&menuText[0]);	// optimise text so it can be drawn efficiently 
	C2D_TextOptimize(&menuText[1]); // optimise text so it can be drawn efficiently 
}

void menuTextDraw()	// draw menu text
{
	frameStart();  // start frame, gui.cpp
	C2D_DrawText(&menuText[0], C2D_AlignCenter, 200.0f, 10.0f, 0.0f, 0.75f, 1.0f); // draw text at those coordinates at this scale
	C2D_DrawText(&menuText[1], C2D_WithColor | C2D_AlignCenter, 200.0f, 90.0f, 0.5f, 0.5f, 0.75f, C2D_Color32(200, 0, 0, 255)); 
	C3D_FrameEnd(0); // end the frame
}

void menuFreeBuf() // free text buffer
{
	C2D_TextBufDelete(menuTextBuf); // delete text buffer
}
