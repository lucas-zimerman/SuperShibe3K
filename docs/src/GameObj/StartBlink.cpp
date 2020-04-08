#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>

ObjectState** StateSSB = NULL;

void init6(int sx, int sy) {
	Sprite* Sprites3000;
	MT2D_VAR* StateLoop = MT2D_Object_Create_Var_Pointer((char*)"loop");

	char Spath[] = "Sprites/Menu/start.png";
	StateSSB = (ObjectState**)malloc(2 * sizeof(ObjectState*));
	StateSSB[0] = MT2D_OBJECT_CREATE_STATE((char*)"main");
	StateSSB[1] = MT2D_OBJECT_CREATE_STATE((char*)"loop");
	Sprites3000 = (Sprite*)malloc(1 * sizeof(Sprite));
	Sprites3000[0] = *Load_Sprite_Image_From_Container(Spath, sx, sy);
	//MAIN
	MT2D_OBJECT_ADD_STATE(StateSSB[0], NULL, 36, NULL);
	MT2D_OBJECT_ADD_STATE(StateSSB[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(StateLoop), &Cscript_Object_SetState));
	MT2D_OBJECT_ADD_STATE(StateSSB[1], &Sprites3000[0], 20, NULL);
	MT2D_OBJECT_ADD_STATE(StateSSB[1], NULL, 20, NULL);
}

Object* StartBlinkNew(int sx, int sy, int px, int py) {

	if (StateSSB == NULL) {
		init6(sx, sy);
	}
	Object* obj = Object_Create(false, false, sx, sy, px, py, StateSSB, 2);
	return obj;
}