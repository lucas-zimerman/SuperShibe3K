#include <stdlib.h>
#include <MT2D/ObjectCore/Object.h>
#include<MT2D/Container/MT2D_Container.h>

ObjectState** BackgroundState = NULL;
Sprite* BackgroundSprite;


void init1() {
	char Spath[] = "Sprites/Menu/mback.png";
	BackgroundState = (ObjectState**)malloc(sizeof(ObjectState*));
	BackgroundState[0] = MT2D_OBJECT_CREATE_STATE((char*)"main");
	BackgroundSprite = (Sprite*)malloc(1 * sizeof(Sprite));
	BackgroundSprite[0] = *Load_Sprite_Image_From_Container(Spath, 320, 240);
	//MAIN
	MT2D_OBJECT_ADD_STATE(BackgroundState[0], &BackgroundSprite[0], 1, NULL);
}

Object* BackgroundNew() {
	if (BackgroundState == NULL) {
		init1();
	}
	Object* background = Object_Create(false, true, 320, 240, 0, 0, BackgroundState, 1);
	return background;
}