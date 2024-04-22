/*created by gk28th
  File Name: operations.cpp
  Purpose: Performs the maths for operations
*/
#include "operations.h"

void whatOp() // find operation
{
    hidScanInput(); // scan for input
    u32 kDown = hidKeysDown(); // store keys down in variable
    if (kDown & KEY_START) timeToFuckOff = true; // if start is pressed leave
    if (kDown & KEY_A) operations(0); // call addition
    if (kDown & KEY_B) operations(1); // call subtraction
    if (kDown & KEY_X) operations(2); // call multiplication
    if (kDown & KEY_Y) operations(3); // call division 
}

void drawOpText() // draw text
{
    frameStart(); // start frame
	  C2D_DrawText(&opText[0], C2D_AlignCenter, 200.0f, 10.0f, 0.0f, 0.75f, 1.0f); // draw text 
	  C2D_DrawText(&opText[1], C2D_WithColor | C2D_AlignCenter, 200.0f, 90.0f, 0.5f, 0.5f, 0.75f, C2D_Color32(200, 0, 0, 255));
	  C3D_FrameEnd(0); // emd frame
}

void opFreeBuf() // free text buffer
{
	C2D_TextBufDelete(opTextBuf); // delete text buffer
}

void operations(int op) // actual maths. int stores operation
{
    double long num1; // keyboard input
    double long num2;

    opTextBuf  = C2D_TextBufNew(4000); 
    
    if(op == 0) C2D_TextParse(&opText[0], opTextBuf, "Addition");  // checks what operation was passed in function call
    if(op == 1) C2D_TextParse(&opText[0], opTextBuf, "Subtraction");
    if(op == 2) C2D_TextParse(&opText[0], opTextBuf, "Multiplication");
    if(op == 3) C2D_TextParse(&opText[0], opTextBuf, "Division");
    
	  C2D_TextParse(&opText[1], opTextBuf, "Press  to input 1st number");
	  C2D_TextOptimize(&opText[0]);
    C2D_TextOptimize(&opText[1]); 
    
    while(true) // have to enter loop
    {
      drawOpText(); // draws text that was parsed and optimised
      hidScanInput();
      u32 kDown = hidKeysDown();
      if (kDown & KEY_A) break; // when a is pressed get out of loop
    }
    
    inputKboard(num1);  // call keyboard to input text in
    C2D_TextParse(&opText[1], opTextBuf, "Press  to input 2st number"); // change text
    C2D_TextOptimize(&opText[1]); // optimise it
    
    while(true)
    {
      drawOpText(); // same old loop
      hidScanInput();
      u32 kDown = hidKeysDown();
      if (kDown & KEY_A) break; // when a is pressed get out
    }

    inputKboard(num2); // input second number 
    if(op == 3 && num1 == num2) num1 = 1; // prevent divide by 0 crashes
    
    char answ[22]; // store answer in string

    if(op == 0) sprintf(answ, "%Lf", num1+num2); // depending on the option set the variable
    if(op == 1) sprintf(answ, "%Lf", num1-num2);
    if(op == 2) sprintf(answ, "%Lf", num1*num2);
    if(op == 3) sprintf(answ, "%Lf", num1/num2);
    
    C2D_TextParse(&opText[0], opTextBuf, answ); // draw anser
    C2D_TextParse(&opText[1], opTextBuf, "is your answer. press  to go to menu");
    C2D_TextOptimize(&opText[0]);
    C2D_TextOptimize(&opText[1]);
    
    while(true)
    {
      drawOpText();
      hidScanInput();
      u32 kDown = hidKeysDown();
      if (kDown & KEY_A) break;    // when a is pressed back to home menu
    }
}