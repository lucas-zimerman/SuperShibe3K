#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include "../Vars/GameVars.h"

ObjectState** TileState = NULL;

void TileInit() {

	Sprite* Sprites;

	char Spath[] = "Sprites/Game/decoration/Platform/normal.png";
	TileState = (ObjectState**)malloc(sizeof(ObjectState*));
	TileState[0] = MT2D_OBJECT_CREATE_STATE((char*)"loop");
	Sprites = (Sprite*)malloc(1 * sizeof(Sprite));
	Sprites[0] = *Load_Sprite_Image_From_Container(Spath, 102, 24);
	//MAIN
	MT2D_OBJECT_ADD_STATE(TileState[0], &Sprites[0], 1, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(TileState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateLoop,PosX,ConstMinus100), &Cscript_JumpToStateIfVarHigherEq));
	MT2D_OBJECT_ADD_STATE(TileState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX,Const400), &Cscript_Set_Var));
}

Object* TileClone(int px, int py) {

	Object* obj = Object_Create(true, false, 100, 24, px, py, TileState, 1);
	return obj;
}