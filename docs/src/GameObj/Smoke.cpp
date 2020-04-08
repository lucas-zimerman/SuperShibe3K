#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include "../Vars/GameVars.h"
#include <MT2D\MT2D_Debug.h>
#include "../GameData.h"

ObjectState** SmokeState = NULL;
extern GameData ctx;

void SmokeInit() {

	Sprite* Sprites;

	char Spath[] = "Sprites/Game/Itens/Smoke/Smoke0000.png";
	SmokeState = (ObjectState**)malloc(1 * sizeof(ObjectState*));
	SmokeState[0] = MT2D_OBJECT_CREATE_STATE((char*)"death");
	Sprites = (Sprite*)malloc(7 * sizeof(Sprite));

	//MAIN
	for (int i = 0; i < 7; i++) {
		Spath[33] = '0' + i;
		Sprites[i] = *Load_Sprite_Image_From_Container(Spath, 22, 22);
		MT2D_OBJECT_ADD_STATE(SmokeState[0], &Sprites[i], 10, NULL);
	}

	MT2D_OBJECT_ADD_STATE(SmokeState[0], NULL, 0, Cscript_New2(&Cscript_RemoveObject));
	MT2D_OBJECT_ADD_STATE(SmokeState[0], NULL, 1, NULL);
}

Object* SmokeClone(int px, int py) {

	Object* obj = Object_Create(true, false, 22, 22, px, py, SmokeState, 1);
	return obj;
}

void SmokeSpawnRight(Object *caller) {
	Object* obj = Object_Create(true, false, 22, 22, caller->SpacePosition.X + caller->Size.X - 10 , caller->SpacePosition.Y, SmokeState, 1);
 	ObjectScene_Add(ctx.sceneEffects, obj);
}