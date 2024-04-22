/*created by gk28th
  File Name: gui.h
  Purpose: Headerfile for gui.h with foward decleration 
*/
#ifndef GUI_H
#define GUI_H

#include "main.h"         // contains main header files and bool
#include "menu.h"         // to delete textbuffer/clean up
#include "operations.h"   // to delete textbuffer/clean up

inline C3D_RenderTarget* top; // screen can be used anywhere, never goes out of scope because inline

void sceneInit();         // forward declarations
void frameStart();
void sceneExit();

#endif
