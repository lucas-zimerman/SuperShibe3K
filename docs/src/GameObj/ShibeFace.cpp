#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>


ObjectState** StateSF = NULL;

void init5(int sx, int sy) {
	Sprite* Sprites;
	MT2D_VAR* StateLoop = MT2D_Object_Create_Var_Pointer((char*)"loop");
	MT2D_VAR* StateHold = MT2D_Object_Create_Var_Pointer((char*)"hold");
	MT2D_VAR* MenuMusic = MT2D_Object_Create_Var_Pointer((char*)"assets/Music/mmenu.ogg");
	MT2D_VAR* PosY = MT2D_Object_Create_Var_Pointer((char*)"Pos_Y");
	MT2D_VAR* Var100 = MT2D_Object_Create_Var_Int((char*)"100",100);
	MT2D_VAR* Var10 = MT2D_Object_Create_Var_Int((char*)"10", 10);


	char Spath[] = "Sprites/Menu/mshibe.png";
	StateSF = (ObjectState**)malloc(3 * sizeof(ObjectState*));
	StateSF[0] = MT2D_OBJECT_CREATE_STATE((char*)"main");
	StateSF[1] = MT2D_OBJECT_CREATE_STATE((char*)"loop");
	StateSF[2] = MT2D_OBJECT_CREATE_STATE((char*)"hold");
	Sprites = (Sprite*)malloc(1 * sizeof(Sprite));
	Sprites[0] = *Load_Sprite_Image_From_Container(Spath, sx, sy);
	//MAIN
	MT2D_OBJECT_ADD_STATE(StateSF[0], NULL, 28, NULL);
	MT2D_OBJECT_ADD_STATE(StateSF[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(StateLoop), &Cscript_Object_SetState));
	MT2D_OBJECT_ADD_STATE(StateSF[1], &Sprites[0], 1, Cscript_New3(MT2D_VAR_Create_Matrix3(StateHold,PosY,Var100),&Cscript_JumpToStateIfVarLowerEq));
	MT2D_ObjectState_ADD(StateSF[1], &Sprites[0], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosY, Var10), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(StateSF[2], &Sprites[0], 1, NULL);
}

Object* ShibeFaceNew(int sx, int sy, int px, int py) {

	if (StateSF == NULL) {
		init5(sx, sy);
	}
	Object* obj = Object_Create(false, false, sx, sy, px, py, StateSF, 3);
	return obj;
}