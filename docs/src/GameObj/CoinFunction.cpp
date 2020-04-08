#include <MT2D/ObjectCore/Object.h>
#include <stdio.h>

extern MT2D_VAR* DogHealth;
extern MT2D_VAR* DogCoin;
extern MT2D_VAR* Const0;
int goal = 48;
/*VAR[0]  The ammount to increase*/
void GetCash(Object* Caller, MT2D_VAR** Vars) {
	*(int*)DogCoin->Data += *(int*)Vars[0]->Data;
	if (*(int*)DogCoin->Data > goal) {
		*(int*)DogHealth->Data += 1;
		goal += 48;
	}
}

void ResetCash() {
	MT2D_Object_VAR_SetVar(DogCoin, Const0);
	goal = 48;
}