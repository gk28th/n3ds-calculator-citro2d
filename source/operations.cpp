#include "operations.h"

void whatOp()
{
    hidScanInput();
    u32 kDown = hidKeysDown();
    if (kDown & KEY_START) timeToFuckOff = true;
    if (kDown & KEY_A) operations(0);
    if (kDown & KEY_B) operations(1);
    if (kDown & KEY_X) operations(2);
    if (kDown & KEY_Y) operations(3); 	
}

void drawOpText()
{
    frameStart();
	  C2D_DrawText(&opText[0], C2D_AlignCenter, 200.0f, 10.0f, 0.0f, 0.75f, 1.0f);
	  C2D_DrawText(&opText[1], C2D_WithColor | C2D_AlignCenter, 200.0f, 90.0f, 0.5f, 0.5f, 0.75f, C2D_Color32(200, 0, 0, 255));
	  C3D_FrameEnd(0);
}

void operations(int op)
{
    double long num1;
    double long num2;

    opTextBuf  = C2D_TextBufNew(4000); 
    
    if(op == 0) C2D_TextParse(&opText[0], opTextBuf, "Addition");
    if(op == 1) C2D_TextParse(&opText[0], opTextBuf, "Subtraction");
    if(op == 2) C2D_TextParse(&opText[0], opTextBuf, "Multiplication");
    if(op == 3) C2D_TextParse(&opText[0], opTextBuf, "Division");
    
	  C2D_TextParse(&opText[1], opTextBuf, "Press  to input 1st number");
	  C2D_TextOptimize(&opText[0]);
    C2D_TextOptimize(&opText[1]); 
    
    while(true)
    {
      drawOpText();
      hidScanInput();
      u32 kDown = hidKeysDown();
      if (kDown & KEY_A) break;
    }
    
    inputKboard(num1);
    C2D_TextParse(&opText[1], opTextBuf, "Press  to input 2st number");
    C2D_TextOptimize(&opText[1]);
    
    while(true)
    {
      drawOpText();
      hidScanInput();
      u32 kDown = hidKeysDown();
      if (kDown & KEY_A) break;   
    }

    inputKboard(num2);
    if(op == 3 && num1 == num2) num1 = 1;
    
    char answ[22];

    if(op == 0) sprintf(answ, "%Lf", num1+num2);
    if(op == 1) sprintf(answ, "%Lf", num1-num2);
    if(op == 2) sprintf(answ, "%Lf", num1*num2);
    if(op == 3) sprintf(answ, "%Lf", num1/num2);
    
    C2D_TextParse(&opText[0], opTextBuf, answ);
    C2D_TextParse(&opText[1], opTextBuf, "is your answer. press  to go to menu");
    C2D_TextOptimize(&opText[0]);
    C2D_TextOptimize(&opText[1]);
    
    while(true)
    {
      drawOpText();
      hidScanInput();
      u32 kDown = hidKeysDown();
      if (kDown & KEY_A) break;   
    }
}