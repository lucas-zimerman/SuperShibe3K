#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include <MT2D/ObjectCore/STDContainer.h>
#include "CoinFunction.h"
#include "../Vars/GameVars.h"

extern Object* Doggo;
extern Object* ExplosionObj;

ObjectState** Coin1State = NULL;


void Coin1Init() {

	Sprite* Sprites;

	char Spath[] = "Sprites/Game/Itens/Coin/1Coin.png";
	Coin1State = (ObjectState**)malloc(3 * sizeof(ObjectState*));
	Coin1State[0] = MT2D_OBJECT_CREATE_STATE((char*)"spawn");
	Coin1State[1] = MT2D_OBJECT_CREATE_STATE((char*)"hit");
	Coin1State[2] = MT2D_OBJECT_CREATE_STATE((char*)"death");
	Sprites = (Sprite*)malloc(1 * sizeof(Sprite));
	Sprites[0] = *Load_Sprite_Image_From_Container(Spath, 8, 8);

	//MAIN

	MT2D_OBJECT_ADD_STATE(Coin1State[0], &Sprites[0], 1, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, GameSpeed), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(Coin1State[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDeath, PosX, ConstMinus100), &Cscript_JumpToStateIfVarLowerEq));
	MT2D_OBJECT_ADD_STATE(Coin1State[0], NULL, 0, Cscript_New4(Doggo, MT2D_VAR_Create_Matrix1(stateHit), &Object_GotoState_IfHitObject));

	MT2D_OBJECT_ADD_STATE(Coin1State[1], NULL, 0, Cscript_New3( MT2D_VAR_Create_Matrix2(CoinSound, Const0), &Cscript_PlaySoundFromContainer));
	MT2D_OBJECT_ADD_STATE(Coin1State[1], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(Const1), &GetCash));
	MT2D_OBJECT_ADD_STATE(Coin1State[1], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(stateDeath), &Cscript_Object_SetState));

	MT2D_OBJECT_ADD_STATE(Coin1State[2], NULL, 0, Cscript_New2(&Cscript_RemoveObject));
	MT2D_OBJECT_ADD_STATE(Coin1State[2], NULL, 1, NULL);
}

Object* Coin1Clone(int px, int py) {

	Object* obj = Object_Create(true, false, 8, 8, px, py, Coin1State, 4);
	return obj;
}