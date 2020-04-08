#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include <MT2D/ObjectCore/STDContainer.h>
#include "Explosion.h"
#include "../Vars/GameVars.h"

extern Object* Doggo;
extern MT2D_VAR* DogHealth;

ObjectState** FireBallState = NULL;

void FireBallInit() {

	Sprite* Sprites;

	char Spath[] = "Sprites/Game/Itens/Projectile/Aproj1.png";
	FireBallState = (ObjectState**)malloc(4 * sizeof(ObjectState*));
	FireBallState[0] = MT2D_OBJECT_CREATE_STATE((char*)"spawn");
	FireBallState[1] = MT2D_OBJECT_CREATE_STATE((char*)"loop");
	FireBallState[2] = MT2D_OBJECT_CREATE_STATE((char*)"hit");
	FireBallState[3] = MT2D_OBJECT_CREATE_STATE((char*)"death");
	Sprites = (Sprite*)malloc(4 * sizeof(Sprite));
	Sprites[0] = *Load_Sprite_Image_From_Container(Spath, 20, 20);
	Spath[44 - 9] = '2';
	Sprites[1] = *Load_Sprite_Image_From_Container(Spath, 20, 20);
	Spath[44 - 9] = '3';
	Sprites[2] = *Load_Sprite_Image_From_Container(Spath, 20, 20);
	Spath[44 - 9] = '4';
	Sprites[3] = *Load_Sprite_Image_From_Container(Spath, 20, 20);

	//MAIN
	MT2D_OBJECT_ADD_STATE(FireBallState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix2(FireballSound, Const0), &Cscript_PlaySoundFromContainer));
	MT2D_OBJECT_ADD_STATE(FireBallState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(stateLoop), &Cscript_Object_SetState));

	MT2D_OBJECT_ADD_STATE(FireBallState[1], &Sprites[0], 1, Cscript_New2(&Cscript_Move));
	MT2D_OBJECT_ADD_STATE(FireBallState[1], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDeath, PosX, ConstMinus100), &Cscript_JumpToStateIfVarLowerEq));
	MT2D_OBJECT_ADD_STATE(FireBallState[1], NULL, 0, Cscript_New4(Doggo, MT2D_VAR_Create_Matrix1(stateHit), &Object_GotoState_IfHitObject));
	MT2D_OBJECT_ADD_STATE(FireBallState[1], &Sprites[1], 1, Cscript_New2(&Cscript_Move));
	MT2D_OBJECT_ADD_STATE(FireBallState[1], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDeath, PosX, ConstMinus100), &Cscript_JumpToStateIfVarLowerEq));
	MT2D_OBJECT_ADD_STATE(FireBallState[1], NULL, 0, Cscript_New4(Doggo, MT2D_VAR_Create_Matrix1(stateHit), &Object_GotoState_IfHitObject));
	MT2D_OBJECT_ADD_STATE(FireBallState[1], &Sprites[2], 1, Cscript_New2(&Cscript_Move));
	MT2D_OBJECT_ADD_STATE(FireBallState[1], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDeath, PosX, ConstMinus100), &Cscript_JumpToStateIfVarLowerEq));
	MT2D_OBJECT_ADD_STATE(FireBallState[1], NULL, 0, Cscript_New4(Doggo, MT2D_VAR_Create_Matrix1(stateHit), &Object_GotoState_IfHitObject));

	MT2D_OBJECT_ADD_STATE(FireBallState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(DogHealth), &Cscript_VAR_DEC));
	MT2D_OBJECT_ADD_STATE(FireBallState[2], NULL, 0, Cscript_New2(&ExplosionSpawn));
	MT2D_OBJECT_ADD_STATE(FireBallState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(stateDeath), &Cscript_Object_SetState));

	MT2D_OBJECT_ADD_STATE(FireBallState[3], NULL, 0, Cscript_New2(&Cscript_RemoveObject));
	MT2D_OBJECT_ADD_STATE(FireBallState[3], NULL, 1, NULL);
}

Object* FireBallClone(int py) {

	Object* obj = Object_Create(true, false, 20, 20, 320, py, FireBallState, 4);
	return obj;
}