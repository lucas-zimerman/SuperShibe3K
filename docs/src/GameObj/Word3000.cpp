#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include <MT2D/ObjectCore/STDContainer.h>
#include "../Vars/ConstNumbers.h"
#include "../Vars/MusicVar.h"

ObjectState** State3k = NULL;

void init4(int sx, int sy) {
	Sprite* Sprites3000;
	MT2D_VAR* StateLoop = MT2D_Object_Create_Var_Pointer((char*)"loop");

	char Spath[] = "Sprites/Menu/3000.png";
	State3k = (ObjectState**)malloc(2 * sizeof(ObjectState*));
	State3k[0] = MT2D_OBJECT_CREATE_STATE((char*)"main");
	State3k[1] = MT2D_OBJECT_CREATE_STATE((char*)"loop");
	Sprites3000 = (Sprite*)malloc(1 * sizeof(Sprite));
	Sprites3000[0] = *Load_Sprite_Image_From_Container(Spath, sx, sy);
	//MAIN
	MT2D_OBJECT_ADD_STATE(State3k[0], NULL, 28, NULL);
	MT2D_OBJECT_ADD_STATE(State3k[0], &Sprites3000[0], 20, NULL);
	MT2D_OBJECT_ADD_STATE(State3k[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix2(MenuMusic,Const0), &Cscript_PlayMusicFromContainer));
	MT2D_OBJECT_ADD_STATE(State3k[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(StateLoop), &Cscript_Object_SetState));
	MT2D_OBJECT_ADD_STATE(State3k[1], &Sprites3000[0], 1, NULL);
}

Object* Word3000New(int sx, int sy, int px, int py) {

	if (State3k == NULL) {
		init4(sx, sy);
	}
	Object* obj = Object_Create(false, false, sx, sy, px, py, State3k, 2);
	return obj;
}