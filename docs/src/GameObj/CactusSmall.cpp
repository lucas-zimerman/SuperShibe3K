#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include <MT2D/ObjectCore/STDContainer.h>
#include "../Vars/GameVars.h"

extern Object* Doggo;
extern MT2D_VAR* DogHealth;

ObjectState** CactusSmallState = NULL;


void CactusSmallInit() {

	Sprite* Sprites;

	char Spath[] = "Sprites/Game/Itens/Cactus/CactusSmall.png";
	char Spath2[] = "Sprites/Game/Itens/Cactus/CactusSmallHit.png";
	CactusSmallState = (ObjectState**)malloc(3 * sizeof(ObjectState*));
	CactusSmallState[0] = MT2D_OBJECT_CREATE_STATE((char*)"loop");
	CactusSmallState[1] = MT2D_OBJECT_CREATE_STATE((char*)"hit");
	CactusSmallState[2] = MT2D_OBJECT_CREATE_STATE((char*)"death");
	Sprites = (Sprite*)malloc(2 * sizeof(Sprite));
	Sprites[0] = *Load_Sprite_Image_From_Container(Spath, 8, 16);
	Sprites[1] = *Load_Sprite_Image_From_Container(Spath2, 8, 16);
	//MAIN
	MT2D_OBJECT_ADD_STATE(CactusSmallState[0], &Sprites[0], 1, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(CactusSmallState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDeath, PosX, ConstMinus100), &Cscript_JumpToStateIfVarLowerEq));
	MT2D_OBJECT_ADD_STATE(CactusSmallState[0], NULL, 0, Cscript_New4(Doggo, MT2D_VAR_Create_Matrix1(stateHit), &Object_GotoState_IfHitObject));

	MT2D_OBJECT_ADD_STATE(CactusSmallState[1], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(DogHealth), &Cscript_VAR_DEC));
	MT2D_OBJECT_ADD_STATE(CactusSmallState[1], &Sprites[1], 1, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(CactusSmallState[1], &Sprites[1], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(HitSound, Const0), &Cscript_PlaySoundFromContainer));
	MT2D_OBJECT_ADD_STATE(CactusSmallState[1], &Sprites[1], 1, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(CactusSmallState[1], &Sprites[1], 1, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(CactusSmallState[1], &Sprites[1], 1, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(CactusSmallState[1], &Sprites[1], 1, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(CactusSmallState[1], &Sprites[1], 1, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(CactusSmallState[1], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(stateDeath), &Cscript_Object_SetState));


	MT2D_OBJECT_ADD_STATE(CactusSmallState[2], NULL, 0, Cscript_New2(&Cscript_RemoveObject));
	MT2D_OBJECT_ADD_STATE(CactusSmallState[2], NULL, 1, NULL);
}

Object* CactusSmallClone(int px) {

	Object* obj = Object_Create(true, false, 8, 16, px, 220 - 16, CactusSmallState, 3);
	return obj;
}