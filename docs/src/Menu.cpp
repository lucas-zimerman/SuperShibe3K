#include <MT2D/MT2D_Display.h>
#include <MT2D/MT2D_System_Calls.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/Container/MT2D_Container.h>
#include <MT2D/MT2D_Keyboard.h>
#include "Game.h"
#include "MenuData.h"
#include "MenuLoader.h"
#if  defined(__EMSCRIPTEN__)
#include <emscripten.h>
#endif
#include <MT2D\MT2D_Debug.h>
MenuData data;
void StartLoop()
{
	MT2D_Ide_Printf("Clearing Screen");
	MT2D_Clear_Main_Window();
	MT2D_Ide_Printf("Next Scene");
	ObjectScene_Goto_NextSteps(data.menuScene);
	MT2D_Ide_Printf("Render");
	ObjectScene_Render(data.menuScene);
	MT2D_Ide_Printf("Draw");
	MT2D_Draw_Window(0);
	MT2D_System_Delay(30);
	if (data.i < 36) {
		data.i++;
	}
	else {
		if (MT2D_Keyboard_touched()) {
			MT2D_Keyboard_keytouched();
			if (MT2D_Keyboard_touched()) {
				MT2D_Keyboard_keytouched();
			}
			FreeMenuObjectReferences(&data);
#if  defined(__EMSCRIPTEN__)
			Game();
#endif
		}
	}
}

void MenuInitAndRun() {
	MT2D_Ide_Printf("Menu Started");
	data = LoadMenuObjectReferences();
	MT2D_Ide_Printf("Menu Data Loaded");
#if  defined(__EMSCRIPTEN__)
	emscripten_set_main_loop(StartLoop, 0, 1);
#else
	while (data.menuScene != NULL) {
		StartLoop();
	}
	Game();
#endif
}