/*created by gk28th
  File Name: kboard.cpp
  Purpose: to use software keyboard to input numbers 
*/
#include "kboard.h"

void inputKboard(double long &text) // passed by reference so value can be changed
{
    SwkbdState swkbd;       // pass by reference so values can be changed
    char textBuffer[10];    // hold the inputed text have to use char array

    swkbdInit(&swkbd, SWKBD_TYPE_NUMPAD, 1, 8);                                                            // the type of kboard(numbpad)
    swkbdSetHintText(&swkbd, "Enter 1st Number");                                                          // the text that shows when nothing is inputed. to use this get rid of SWKBD_FIXED_WIDTH
    swkbdSetPasswordMode(&swkbd, SWKBD_PASSWORD_NONE);                                                     // no password mode
	swkbdSetValidation(&swkbd, SWKBD_NOTEMPTY_NOTBLANK, 0, 0);                                               // what can be inputed. SWKBD_NOTEMPTY_NOTBLANK disallows empty input or whitespaces
	swkbdSetFeatures(&swkbd, SWKBD_FIXED_WIDTH | SWKBD_ALLOW_HOME | SWKBD_ALLOW_RESET | SWKBD_ALLOW_POWER);  // when inputing numbers, they are inputed in boxes
	swkbdSetNumpadKeys(&swkbd, L'.', L'0');                                                                  // the 2 buttons on the left and right. 0 means no button

    swkbdInputText(&swkbd, textBuffer, sizeof(textBuffer) ); // actualy use the keyboard
    text = strtod(textBuffer, NULL); // convert text to double long
}