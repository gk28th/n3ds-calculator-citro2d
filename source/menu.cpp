
#include "menu.h"
#include "gui.h"

void menuInit()
{
	menuTextBuf  = C2D_TextBufNew(400); 

	C2D_TextParse(&menuText[0], menuTextBuf, title);
	C2D_TextParse(&menuText[1], menuTextBuf, options);

	C2D_TextOptimize(&menuText[0]);
	C2D_TextOptimize(&menuText[1]);
}

void menuTextDraw()
{
	frameStart();
	C2D_DrawText(&menuText[0], C2D_AlignCenter, 200.0f, 10.0f, 0.0f, 0.75f, 1.0f);
	C2D_DrawText(&menuText[1], C2D_WithColor | C2D_AlignCenter, 200.0f, 90.0f, 0.5f, 0.5f, 0.75f, C2D_Color32(200, 0, 0, 255));
	C3D_FrameEnd(0);
}

void menuFreeBuf()
{
	C2D_TextBufDelete(menuTextBuf);
}
