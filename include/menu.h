#ifndef MENU_H
#define MENU_H

#include "main.h"

inline C2D_TextBuf menuTextBuf;
inline C2D_Text menuText[4];

inline const char title[] =
	"The GK Calculator\n";

inline const char options[] =
	"Press  for addition\n"
	"Press  for subtraction\n"
	"Press  for multiplication\n"
    "Press  for division\n";

void menuInit();
void menuTextDraw();
void menuFreeBuf();


#endif
