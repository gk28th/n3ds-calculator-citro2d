/*created by gk28th
  File Name: menu.h
  Purpose: Headerfile for menu.h with foward decleration 
*/
#ifndef MENU_H
#define MENU_H

#include "main.h"   // contains main header files and bool

inline C2D_TextBuf menuTextBuf;		// text buffer to store text. can be used anywhere
inline C2D_Text menuText[4];		// the text. can be used anywhere

inline const char title[] =			// string that has the title
	"The GK Calculator\n";

inline const char options[] =		// string with options
	"Press  for addition\n"
	"Press  for subtraction\n"
	"Press  for multiplication\n"
    "Press  for division\n";

void menuInit();		// forward declarations
void menuTextDraw();
void menuFreeBuf();


#endif
