#include <3ds.h>
#include <citro2d.h>

C2D_TextBuf g_staticBuf; //intresting
C2D_Text g_staticText;   //intresting
static const char teststring[] = "Hello World - now with citro2d!";

int main()
{
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

	g_staticBuf  = C2D_TextBufNew(4096);					//intresting
	C2D_TextParse(&g_staticText, g_staticBuf, teststring);  //intresting
	C2D_TextOptimize(&g_staticText);						//intresting

	while (aptMainLoop())
	{
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, C2D_Color32(0x68, 0xB0, 0xD8, 0xFF));
		C2D_SceneBegin(top);

		C2D_DrawText(&g_staticText, 0, 8.0f, 8.0f, 0.5f, 0.5f, 0.5f); //intresting
		
		C3D_FrameEnd(0);
	}

	C2D_TextBufDelete(g_staticBuf); //intresting

	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}







