#include <MT2D/ObjectCore/Vars.h>
#include <MT2D/ObjectCore/Sprites.h>
#include "../Vars/GameVars.h"

extern MT2D_VAR* DogHealth;

Sprite *HeartSprite;

void HeartInit() {
	HeartSprite = Load_Sprite_Image_From_Container((char*)"Sprites/Game/Itens/Health/Health.png", 10, 10);
}

void HeartDraw() {
	for (int i = 0; i < *(int*)DogHealth->Data;  i++) {
		Sprite_Render_on_Window(HeartSprite, 0, 11 * i, 2);
	}
}