#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>

ObjectState** StateMM = NULL;

void init3(int sx, int sy) {

	Sprite* Sprites;
	MT2D_VAR* stateLoop = MT2D_Object_Create_Var_Pointer((char*)"loop");

	char Spath[] = "Sprites/Menu/shibe.png";
	StateMM = (ObjectState**)malloc(2 * sizeof(ObjectState*));
	StateMM[0] = MT2D_OBJECT_CREATE_STATE((char*)"main");
	StateMM[1] = MT2D_OBJECT_CREATE_STATE((char*)"loop");
	Sprites = (Sprite*)malloc(1 * sizeof(Sprite));
	Sprites[0] = *Load_Sprite_Image_From_Container(Spath, sx, sy);
	//MAIN
	MT2D_OBJECT_ADD_STATE(StateMM[0], NULL, 16, NULL);
	MT2D_OBJECT_ADD_STATE(StateMM[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(stateLoop), &Cscript_Object_SetState));
	MT2D_OBJECT_ADD_STATE(StateMM[1], &Sprites[0], 1, NULL);
}

Object* WordShibeNew(int sx, int sy, int px, int py) {
	if (StateMM == NULL) {
		init3(sx, sy);
	}
	Object* obj = Object_Create(false, false, sx, sy, px, py, StateMM, 2);
	return obj;
}