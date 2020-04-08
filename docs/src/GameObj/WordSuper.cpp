#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include <MT2D/ObjectCore/STDContainer.h>
#include "../Vars/ConstNumbers.h"
#include "../Vars/SoundVar.h"
#include "../Vars/GameStates.h"

ObjectState** StateMS = NULL;

void init2(int sx, int sy) {

	Sprite* Sprites;


	char Spath[] = "Sprites/Menu/super.png";
	StateMS = (ObjectState**)malloc(2 * sizeof(ObjectState*));
	StateMS[0] = MT2D_OBJECT_CREATE_STATE((char*)"main");
	StateMS[1] = MT2D_OBJECT_CREATE_STATE((char*)"loop");
	Sprites = (Sprite*)malloc(1 * sizeof(Sprite));
	Sprites[0] = *Load_Sprite_Image_From_Container(Spath, sx, sy);
	//MAIN
	MT2D_OBJECT_ADD_STATE(StateMS[0], NULL, 1, Cscript_New3(MT2D_VAR_Create_Matrix2(superShibeSound,Const0), &Cscript_PlaySoundFromContainer));
	MT2D_OBJECT_ADD_STATE(StateMS[0], NULL, 1, Cscript_New3(MT2D_VAR_Create_Matrix1(stateLoop), &Cscript_Object_SetState));
	MT2D_OBJECT_ADD_STATE(StateMS[1], &Sprites[0], 1, NULL);
}

Object* WordSuperNew(int sx, int sy, int px, int py) {
	if (StateMS == NULL) {
		init2(sx, sy);
	}
	Object* obj = Object_Create(false, false, sx, sy, px, py, StateMS, 2);
	return obj;
}