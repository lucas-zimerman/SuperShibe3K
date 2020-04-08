#include <stdlib.h>
#include <MT2D/MT2D_Debug.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include <MT2D/ObjectCore/STDContainer.h>
#include "../Vars/GameVars.h"

extern Object* Doggo; 
extern MT2D_VAR* DogHealth;

ObjectState** RailState = NULL;



void RailInit(){

	Sprite* Sprites;
	char Spath[] = "Sprites/Game/Enemies/Particle/rail0.png";
	RailState = (ObjectState**)malloc(5 * sizeof(ObjectState*));
	RailState[0] = MT2D_OBJECT_CREATE_STATE((char*)"main");
	RailState[1] = MT2D_OBJECT_CREATE_STATE((char*)"loop");
	RailState[2] = MT2D_OBJECT_CREATE_STATE((char*)"loop2");
	RailState[3] = MT2D_OBJECT_CREATE_STATE((char*)"hit");
	RailState[4] = MT2D_OBJECT_CREATE_STATE((char*)"death");
	Sprites = (Sprite*)malloc(5 * sizeof(Sprite));
	for (int i = 0; i < 5; i++) {
		Spath[34] = '0' + i;
		Sprites[i] = *Load_Sprite_Image_From_Container(Spath, 60, 220);
	}
	//MAIN
	MT2D_OBJECT_ADD_STATE(RailState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix2(RailSound, Const0), &Cscript_PlaySoundFromContainer));
	MT2D_OBJECT_ADD_STATE(RailState[0], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(stateLoop), &Cscript_Object_SetState));


	MT2D_OBJECT_ADD_STATE(RailState[1], &Sprites[0], 3, NULL);
	MT2D_OBJECT_ADD_STATE(RailState[1], NULL, 3, NULL);
	MT2D_OBJECT_ADD_STATE(RailState[1], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(CntPointer), &Cscript_VAR_INC));
	MT2D_OBJECT_ADD_STATE(RailState[1], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateLoop2,CntPointer, Const10), &Cscript_JumpToStateIfVarHigherEq));

	MT2D_OBJECT_ADD_STATE(RailState[2], &Sprites[1], 2, NULL);
	MT2D_OBJECT_ADD_STATE(RailState[2], &Sprites[2], 2, NULL);
	MT2D_OBJECT_ADD_STATE(RailState[2], &Sprites[3], 2, NULL);
	MT2D_OBJECT_ADD_STATE(RailState[2], &Sprites[4], 2, NULL);
	MT2D_OBJECT_ADD_STATE(RailState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(CntPointer), &Cscript_VAR_INC));
	MT2D_OBJECT_ADD_STATE(RailState[2], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix3(stateDeath, CntPointer, Const13), &Cscript_JumpToStateIfVarHigherEq));
	MT2D_OBJECT_ADD_STATE(RailState[2], NULL, 0, Cscript_New4(Doggo, MT2D_VAR_Create_Matrix1(stateHit), &Object_GotoState_IfHitObject));

	MT2D_OBJECT_ADD_STATE(RailState[3], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(DogHealth), &Cscript_VAR_DEC));
	MT2D_OBJECT_ADD_STATE(RailState[3], NULL, 0, Cscript_New3(MT2D_VAR_Create_Matrix1(stateLoop2), &Cscript_Object_SetState));

	//13
	MT2D_OBJECT_ADD_STATE(RailState[4], NULL, 0, Cscript_New2(&Cscript_RemoveObject));
	MT2D_OBJECT_ADD_STATE(RailState[4], NULL, 1, NULL);
}

Object* RailClone(int px) {

	Object* obj = Object_Create(true, false, 46, 220, px, 0, RailState, 5);

	MT2D_VAR* UserVars = (MT2D_VAR*)malloc(sizeof(MT2D_VAR));
	UserVars[0] = *MT2D_Object_Create_Var_Int("Cnt", 0);
	obj->User_Vars = UserVars;
	obj->User_Vars_Count = 1;
	return obj;
}