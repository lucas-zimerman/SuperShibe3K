#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include "../Vars/GameVars.h"

ObjectState** GBack = NULL;


void BackgroundInit() {
	Sprite* BackgroundSprite;

	char Spath[] = "Sprites/Game/decoration/back/mountains.png";
	GBack = (ObjectState**)malloc(sizeof(ObjectState*));
	GBack[0] = MT2D_OBJECT_CREATE_STATE((char*)"main");
	BackgroundSprite = (Sprite*)malloc(1 * sizeof(Sprite));
	BackgroundSprite[0] = *Load_Sprite_Image_From_Container(Spath, 320, 240);
	//MAIN
	MT2D_OBJECT_ADD_STATE(GBack[0], &BackgroundSprite[0], 1, NULL);
}

Object* BackgroundClone() {
	Object* background = Object_Create(false, true, 320, 240, 0, 0, GBack, 1);
	return background;
}