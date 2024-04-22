/*created by gk28th
  File Name: operations.h
  Purpose: Headerfile for operations.h with foward decleration 
*/
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "main.h"     // contains main header files and bool
#include "gui.h"      // for basic render functions
#include "kboard.h"   // to use keyboard

inline C2D_TextBuf opTextBuf;   // text buffer to store text. can be used anywhere
inline C2D_Text opText[2];      // the text. can be used anywhere

void whatOp();              // forward declarations
void operations(int op);
void opFreeBuf();


#endif