#include <stdlib.h>Sprites/Game/decoration/Explosion/Explosion1.png
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include <MT2D/ObjectCore/STDContainer.h>
#include "../Vars/GameVars.h"

ObjectState** ExplosionState = NULL;


void ExplosionInit() {

	Sprite* Sprites;

	char Spath[] = "Sprites/Game/decoration/Explosion/explosion1.png";
	ExplosionState = (ObjectState**)malloc(1 * sizeof(ObjectState*));
	ExplosionState[0] = MT2D_OBJECT_CREATE_STATE((char*)"death");
	Sprites = (Sprite*)malloc(6 * sizeof(Sprite));
	for (int i = 0; i < 6; i++) {
		Spath[52 - 9] = '1' + i;
		Sprites[i] = *Load_Sprite_Image_From_Container(Spath, 32, 32);
	}
	Sprites[1] = *Load_Sprite_Image_From_Container(Spath, 16, 32);
	//MAIN
	MT2D_OBJECT_ADD_STATE(ExplosionState[0], &Sprites[0], 5, Cscript_New3(MT2D_VAR_Create_Matrix2(ExplosionSound, Const0), &Cscript_PlaySoundFromContainer));
	MT2D_OBJECT_ADD_STATE(ExplosionState[0], &Sprites[1], 5, NULL);
	MT2D_OBJECT_ADD_STATE(ExplosionState[0], &Sprites[2], 5, NULL);
	MT2D_OBJECT_ADD_STATE(ExplosionState[0], &Sprites[3], 5, NULL);
	MT2D_OBJECT_ADD_STATE(ExplosionState[0], &Sprites[4], 5, NULL);
	MT2D_OBJECT_ADD_STATE(ExplosionState[0], &Sprites[5], 5, NULL);

	MT2D_OBJECT_ADD_STATE(ExplosionState[0], NULL, 0, Cscript_New2(&Cscript_RemoveObject));
	MT2D_OBJECT_ADD_STATE(ExplosionState[0], NULL, 1, NULL);
}

Object* ExplosionClone(int px, int py) {

	Object* obj = Object_Create(true, false, 32, 32, px, py, ExplosionState, 1);
	return obj;
}

void ExplosionSpawn(Object* caller) {
	Object* obj = Object_Create(true, false, 32, 32, caller->SpacePosition.X, caller->SpacePosition.Y + caller->Size.Y / 2, ExplosionState, 1);
	ObjectScene_Add(caller->MyScene, obj);
}