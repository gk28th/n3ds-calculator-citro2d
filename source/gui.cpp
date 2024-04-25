/*created by gk28th
  File Name: gui.cpp
  Purpose: Basic functions for gui
*/
#include "gui.h"

void sceneInit() // initialise scene
{
	gfxInitDefault();					// init graphics library?
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);	// init citro3D?
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);	// init citro2D with the defualt number of things that can be displayed
	C2D_Prepare();						// prepare citro2D
	top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);	// set top to point to top screen left eye

    menuInit();	  // init the menu, menu.cpp
}

void frameStart() // start frame
{
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW); // begin frame
	C2D_TargetClear(top, C2D_Color32(149, 165, 166, 50 )); // fill top screen with colour/clear it
	C2D_SceneBegin(top); // begin the scene?
}

void sceneExit()	// leave rn
{
	menuFreeBuf();	// free text buffer for menu
	opFreeBuf();		// free text buffer for operations
    C2D_Fini();			// citro2D finished
	C3D_Fini();			// citro3D finished
	gfxExit();			// graphics finished
}
