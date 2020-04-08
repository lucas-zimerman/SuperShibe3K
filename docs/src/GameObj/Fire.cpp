#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include "../Vars/GameVars.h"

extern Object* Doggo;
extern MT2D_VAR* DogHealth;



ObjectState** FireState = NULL;


void FireInit() {

	Sprite* Sprites;

	char Spath[] = "Sprites/Game/Itens/Fire/Fire0000.png";
	FireState = (ObjectState**)malloc(3 * sizeof(ObjectState*));
	FireState[0] = MT2D_OBJECT_CREATE_STATE((char*)"loop");
	FireState[1] = MT2D_OBJECT_CREATE_STATE((char*)"hit");
	FireState[2] = MT2D_OBJECT_CREATE_STATE((char*)"death");
	Sprites = (Sprite*)malloc(6 * sizeof(Sprite));
	for (int i = 0; i < 6; i++) {
		Spath[40 - 9] = '0' + i;
		Sprites[i] = *Load_Sprite_Image_From_Container(Spath, 16, 32);

	}
	//MAIN
	MT2D_OBJECT_ADD_STATE(FireState[0], &Sprites[0], 3, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(FireState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDeath, PosX, ConstMinus100), &Cscript_JumpToStateIfVarLowerEq));
	MT2D_OBJECT_ADD_STATE(FireState[0], &Sprites[1], 3, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(FireState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDeath, PosX, ConstMinus100), &Cscript_JumpToStateIfVarLowerEq));
	MT2D_OBJECT_ADD_STATE(FireState[0], &Sprites[2], 3, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(FireState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDeath, PosX, ConstMinus100), &Cscript_JumpToStateIfVarLowerEq));
	MT2D_OBJECT_ADD_STATE(FireState[0], &Sprites[3], 3, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(FireState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDeath, PosX, ConstMinus100), &Cscript_JumpToStateIfVarLowerEq));
	MT2D_OBJECT_ADD_STATE(FireState[0], &Sprites[4], 3, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(FireState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDeath, PosX, ConstMinus100), &Cscript_JumpToStateIfVarLowerEq));
	MT2D_OBJECT_ADD_STATE(FireState[0], &Sprites[5], 3, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(FireState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDeath, PosX, ConstMinus100), &Cscript_JumpToStateIfVarLowerEq));
	MT2D_OBJECT_ADD_STATE(FireState[0], NULL, 0, Cscript_New4(Doggo, MT2D_VAR_Create_Matrix1(stateHit), &Object_GotoState_IfHitObject));

	MT2D_OBJECT_ADD_STATE(FireState[1], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(DogHealth), &Cscript_VAR_DEC));
	MT2D_OBJECT_ADD_STATE(FireState[1], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(stateLoop), &Cscript_Object_SetState));

	MT2D_OBJECT_ADD_STATE(FireState[2], NULL, 0, Cscript_New2(&Cscript_RemoveObject));
	MT2D_OBJECT_ADD_STATE(FireState[2], NULL, 1, NULL);
}

Object* FireClone(int px) {

	Object* obj = Object_Create(true, false, 8, 32, px, 220 - 30, FireState, 3);
	return obj;
}