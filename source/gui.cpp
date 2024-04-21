#include "gui.h"

void sceneInit()
{
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

    menuInit();
}

void frameStart()
{
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(top, C2D_Color32(149, 165, 166, 50 ));
	C2D_SceneBegin(top);
}

void sceneExit()
{
	void menuFreeBuf();
	opFreeBuf();
    C2D_Fini();
	C3D_Fini();
	gfxExit();
}
