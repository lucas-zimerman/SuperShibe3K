
#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include <MT2D/ObjectCore/STDContainer.h>
#include "../Vars/GameVars.h"

extern Object* Doggo;
extern Object* FireBall;
extern MT2D_VAR* DogHealth;

MT2D_VAR* bossLoop1 = MT2D_Object_Create_Var_Int("", 0);
MT2D_VAR* bossLoop2 = MT2D_Object_Create_Var_Int("", 0);

ObjectState** BossState = NULL;


void SpawnProjectile(Object* Caller)
{
	int debug = Caller->SpacePosition.X - FireBall->Size.X / 2;
	MT2D_VAR* projX = MT2D_Object_Create_Var_Int("", Caller->SpacePosition.X - FireBall->Size.X / 2);
	MT2D_VAR* projY = MT2D_Object_Create_Var_Int("", Caller->SpacePosition.Y + Caller->Size.Y / 2);
	int debug2 = (Doggo->SpacePosition.X - *(int*)projX->Data) / 12;
	MT2D_VAR* acelX = MT2D_Object_Create_Var_Int("", ( Doggo->SpacePosition.X -  *(int*)projX->Data) / 12);
	MT2D_VAR* acelY = MT2D_Object_Create_Var_Int("", (Doggo->SpacePosition.Y  - *(int*)projY->Data) / 12);
 	Cscript_CreateObject(Caller, FireBall, MT2D_VAR_Create_Matrix4(projX, projY, acelX, acelY));
}

void BossInit() {
	Sprite* Sprites;

	char Spath[] = "Sprites/Game/Enemies/MrPop.png";
	BossState = (ObjectState**)malloc(5 * sizeof(ObjectState*));
	BossState[0] = MT2D_OBJECT_CREATE_STATE((char*)"main");
	BossState[1] = MT2D_OBJECT_CREATE_STATE((char*)"appearing");
	BossState[2] = MT2D_OBJECT_CREATE_STATE((char*)"loop");
	BossState[3] = MT2D_OBJECT_CREATE_STATE((char*)"shoot");
	BossState[4] = MT2D_OBJECT_CREATE_STATE((char*)"dissapearing");
	Sprites = (Sprite*)malloc(1 * sizeof(Sprite));
	Sprites[0] = *Load_Sprite_Image_From_Container(Spath, 96, 120);
	//MAIN
	MT2D_OBJECT_ADD_STATE(BossState[0], &Sprites[0], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(BossMusic, Const0), &Cscript_PlayMusicFromContainer));
	MT2D_OBJECT_ADD_STATE(BossState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(stateAppearing), &Cscript_Object_SetState));

	//Appearing
	MT2D_OBJECT_ADD_STATE(BossState[1], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(PosX), &Cscript_VAR_DEC));
	MT2D_OBJECT_ADD_STATE(BossState[1], &Sprites[0], 1, Cscript_New3(MT2D_VAR_Create_Matrix3(stateLoop, PosX, BossVisible), &Cscript_JumpToStateIfVarLowerEq));

	//Loop
	//	for (int i = 0; i < 9; i++) {
	MT2D_OBJECT_ADD_STATE(BossState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix4(bossLoop1,iPointer,ConstLower, Const9), &Cscript_While));
	{
		//  for (int j = 0; j < 20; j++) {
		MT2D_OBJECT_ADD_STATE(BossState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix2(jPointer, Const0), &Cscript_Set_Var));
		MT2D_OBJECT_ADD_STATE(BossState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix4(bossLoop2, jPointer, ConstLower, Const20), &Cscript_While));
		{
			MT2D_OBJECT_ADD_STATE(BossState[2], &Sprites[0], 3, Cscript_New3(MT2D_VAR_Create_Matrix1(PosY), &Cscript_VAR_DEC));
			MT2D_OBJECT_ADD_STATE(BossState[2], &Sprites[0], 3, Cscript_New3(MT2D_VAR_Create_Matrix1(PosY), &Cscript_VAR_DEC));
			MT2D_OBJECT_ADD_STATE(BossState[2], &Sprites[0], 3, Cscript_New3(MT2D_VAR_Create_Matrix1(PosY), &Cscript_VAR_DEC));

			MT2D_OBJECT_ADD_STATE(BossState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(Const1, Const190, Const200), &Cscript_JumpFramesIfRandom));
			MT2D_OBJECT_ADD_STATE(BossState[2], NULL, 0, Cscript_New2(&SpawnProjectile));

			MT2D_OBJECT_ADD_STATE(BossState[2], &Sprites[0], 3, Cscript_New3(MT2D_VAR_Create_Matrix1(PosY), &Cscript_VAR_INC));
			MT2D_OBJECT_ADD_STATE(BossState[2], &Sprites[0], 3, Cscript_New3(MT2D_VAR_Create_Matrix1(PosY), &Cscript_VAR_INC));
			MT2D_OBJECT_ADD_STATE(BossState[2], &Sprites[0], 3, Cscript_New3(MT2D_VAR_Create_Matrix1(PosY), &Cscript_VAR_INC));

			MT2D_OBJECT_ADD_STATE(BossState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(Const1, Const190, Const200), &Cscript_JumpFramesIfRandom));
			MT2D_OBJECT_ADD_STATE(BossState[2], NULL, 0, Cscript_New2(&SpawnProjectile));

			MT2D_OBJECT_ADD_STATE(BossState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(jPointer), &Cscript_VAR_INC));
		}
		MT2D_OBJECT_ADD_STATE(BossState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(bossLoop2), &Cscript_While_End));
		MT2D_OBJECT_ADD_STATE(BossState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(iPointer), &Cscript_VAR_INC));
	}
	MT2D_OBJECT_ADD_STATE(BossState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(bossLoop1), &Cscript_While_End));


	MT2D_OBJECT_ADD_STATE(BossState[2], &Sprites[0], 0, Cscript_New3(MT2D_VAR_Create_Matrix2(GameMusic, Const0), &Cscript_PlayMusicFromContainer));
	MT2D_OBJECT_ADD_STATE(BossState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(stateDissapearing), &Cscript_Object_SetState));

	//shoot

	//dissapearing
	MT2D_OBJECT_ADD_STATE(BossState[4], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(PosX), &Cscript_VAR_INC));
	MT2D_OBJECT_ADD_STATE(BossState[4], &Sprites[0], 1, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDissapearing, PosX, Const400), &Cscript_JumpToStateIfVarLowerEq));
	MT2D_OBJECT_ADD_STATE(BossState[4], NULL, 0, Cscript_New2(&Cscript_RemoveObject));
	MT2D_OBJECT_ADD_STATE(BossState[4], NULL, 1, NULL);

	
}

Object* BossClone() {

	Object* obj = Object_Create(true, false, 96, 128, 320, 0, BossState, 5);
	MT2D_VAR* UserVars = (MT2D_VAR*)malloc(2 * sizeof(MT2D_VAR));
	UserVars[0] = *MT2D_Object_Create_Var_Int("i", 0);
	UserVars[1] = *MT2D_Object_Create_Var_Int("j", 0);
	obj->User_Vars = UserVars;
	obj->User_Vars_Count = 2;

	return obj;
}