#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include <MT2D/ObjectCore/STDContainer.h>
#include "../Vars/GameVars.h"
#include <MT2D\MT2D_Debug.h>
#include <stdio.h>

Object* Doggo;

ObjectState** DogState = NULL;


void DoggoInit() {

	Sprite* Sprites;
	char Spath[] = "Sprites/Game/dog/dog1.png";
	DogState = (ObjectState**)malloc(5 * sizeof(ObjectState*));
	DogState[0] = MT2D_OBJECT_CREATE_STATE((char*)"loop");
	DogState[1] = MT2D_OBJECT_CREATE_STATE((char*)"doJmp");
	DogState[2] = MT2D_OBJECT_CREATE_STATE((char*)"Jmp");
	DogState[3] = MT2D_OBJECT_CREATE_STATE((char*)"death");
	DogState[4] = MT2D_OBJECT_CREATE_STATE((char*)"loop2");
	Sprites = (Sprite*)malloc(9 * sizeof(Sprite));
	for (int i = 0; i < 9; i++) {
		Spath[29 - 9] = '1' + i;
		Sprites[i] = *Load_Sprite_Image_From_Container(Spath, 32, 24);
	}
	//MAIN
	MT2D_OBJECT_ADD_STATE(DogState[0], &Sprites[0], 2, Cscript_New3(MT2D_VAR_Create_Matrix3(StateDoJump, JumpRequest, Const1), &Cscript_JumpToStateIfVarEq));
	MT2D_OBJECT_ADD_STATE(DogState[0], &Sprites[1], 2, Cscript_New3(MT2D_VAR_Create_Matrix3(StateDoJump, JumpRequest, Const1), &Cscript_JumpToStateIfVarEq));
	MT2D_OBJECT_ADD_STATE(DogState[0], &Sprites[2], 2, Cscript_New3(MT2D_VAR_Create_Matrix3(StateDoJump, JumpRequest, Const1), &Cscript_JumpToStateIfVarEq));
	MT2D_OBJECT_ADD_STATE(DogState[0], &Sprites[3], 2, Cscript_New3(MT2D_VAR_Create_Matrix3(StateDoJump, JumpRequest, Const1), &Cscript_JumpToStateIfVarEq));
	MT2D_OBJECT_ADD_STATE(DogState[0], &Sprites[4], 2, Cscript_New3(MT2D_VAR_Create_Matrix3(StateDoJump, JumpRequest, Const1), &Cscript_JumpToStateIfVarEq));
	MT2D_OBJECT_ADD_STATE(DogState[0], &Sprites[5], 2, Cscript_New3(MT2D_VAR_Create_Matrix3(StateDoJump, JumpRequest, Const1), &Cscript_JumpToStateIfVarEq));
	MT2D_OBJECT_ADD_STATE(DogState[0], &Sprites[6], 2, Cscript_New3(MT2D_VAR_Create_Matrix3(StateDoJump, JumpRequest, Const1), &Cscript_JumpToStateIfVarEq));
	MT2D_OBJECT_ADD_STATE(DogState[0], &Sprites[7], 2, Cscript_New3(MT2D_VAR_Create_Matrix3(StateDoJump, JumpRequest, Const1), &Cscript_JumpToStateIfVarEq));
	 
	//do Jump
	MT2D_OBJECT_ADD_STATE(DogState[1], &Sprites[6], 1, Cscript_New3(MT2D_VAR_Create_Matrix2(JumpSound, Const0), &Cscript_PlaySoundFromContainer));
//	MT2D_OBJECT_ADD_STATE(DogState[1], &Sprites[6], 1, Cscript_New3(MT2D_VAR_Create_Matrix1(JumpSound), &Cscript_PlaySound));
	MT2D_OBJECT_ADD_STATE(DogState[1], &Sprites[6], 1, Cscript_New3(MT2D_VAR_Create_Matrix2(JumpRequest, Const0), &Cscript_Set_Var));	
	MT2D_OBJECT_ADD_STATE(DogState[1], &Sprites[6], 1, Cscript_New3(MT2D_VAR_Create_Matrix1(StateJumping), &Cscript_Object_SetState));

	//Jump
	MT2D_OBJECT_ADD_STATE(DogState[2], &Sprites[6], 1, Cscript_New3(MT2D_VAR_Create_Matrix3(StateDoJump, JumpRequest, Const1), &Cscript_JumpToStateIfVarEq));
	MT2D_OBJECT_ADD_STATE(DogState[2], &Sprites[6], 1, Cscript_New3(MT2D_VAR_Create_Matrix3(stateLoop,PosY, Const200), &Cscript_JumpToStateIfVarHigherEq));
	
	//Death
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 1, NULL);
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosY, Const3), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, Const3), &Cscript_VAR_ADD));
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 1, NULL);
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosY, Const3), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, Const3), &Cscript_VAR_ADD));
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 1, NULL);
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 2, NULL);
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosY, Const3), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, Const3), &Cscript_VAR_ADD));
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 1, NULL);
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosY, Const3), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, Const3), &Cscript_VAR_ADD));
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 1, NULL);
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosY, Const3), &Cscript_VAR_SUB));
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosX, Const3), &Cscript_VAR_ADD));
	MT2D_OBJECT_ADD_STATE(DogState[3], &Sprites[8], 0, Cscript_New3(MT2D_VAR_Create_Matrix1(stateLoop2), &Cscript_Object_SetState));

	//Loop2
	MT2D_OBJECT_ADD_STATE(DogState[4], &Sprites[8], 1, NULL);
	MT2D_OBJECT_ADD_STATE(DogState[4], &Sprites[8], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(PosY, Const3), &Cscript_VAR_ADD));

}

Object* DoggoClone(int px, int py) {

	char buff[100];
	Object* obj = Object_Create(true, false, 32, 24, px, py, DogState, 5);
	sprintf(buff, "DOG CLONED ID %p", obj);
	MT2D_Ide_Printf(buff);
	return obj;
}