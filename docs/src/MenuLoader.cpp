#include <MT2D\Container\MT2D_Container.h>
#include "GameObj/WordSuper.h"
#include "GameObj/BackgroundObj.h"
#include "GameObj/WordShibe.h"
#include "GameObj/Word3000.h"
#include "GameObj/ShibeFace.h"
#include "GameObj/StartBlink.h"
#include "Vars/GlobalVars.h"
#include "Vars/SoundVar.h"
#include "Vars/MusicVar.h"
#include "MenuData.h"

MenuData LoadMenuObjectReferences() {
	MT2D_Container_Load((char*)"assets/Menu.mt2");
	MenuData data;

	data.menuScene = ObjectScene_CreateEmpty();
	ObjectScene_Add(data.menuScene, BackgroundNew());
	ObjectScene_Add(data.menuScene, WordSuperNew(64, 32, 98, 5));
	ObjectScene_Add(data.menuScene, WordShibeNew(64, 32, 162, 5));
	ObjectScene_Add(data.menuScene, Word3000New(64, 32, 130, 37));
	ObjectScene_Add(data.menuScene, ShibeFaceNew(120, 160, 200, 240));
	ObjectScene_Add(data.menuScene, StartBlinkNew(32, 16, 142, 150));
	data.i = 0;
	return data;
}

void FreeMenuObjectReferences(MenuData* data)
{
	for (data->i = 0; data->i < data->menuScene->Count; data->i++) {
		Object_Delete(data->menuScene->ObjectGroup[data->i], true);
	}
	data->menuScene = NULL;
//	MT2D_VAR_Free(MenuMusic, false);
//	MT2D_VAR_Free(superShibeSound, false);
}