#include <MT2D/ObjectCore/Object.h>
#include "Randomizer.h"
#include "GameObj/CactusBig.h"
#include "GameObj/CactusSmall.h"
#include "GameObj/RailGun.h"
#include "GameObj/Rocket.h"
#include "GameObj/Fire.h"
#include "Enums/Level.h"
#include <stdlib.h>
#include "GameObj/Coin1.h"
#include "GameObj/Coin5.h"
#include "GameObj/Coin2.h"
#include "GameObj/Boss.h"


Object* RandCactusSize(int posX) {
	if (GetRandom() < 500) {
		return CactusBigClone(posX);
	}
	return CactusSmallClone(posX);
}

void SpawnRail(Level level, ObjectScene* objectsFloor) {
	int i = GetRandom();
	switch (level)
	{
	case easy:
		if (i < 400) {
			ObjectScene_Add(objectsFloor, RailClone(i % 280));
		}

		break;
	case medium:
		if (i < 430) {
			ObjectScene_Add(objectsFloor, RailClone(i % 280));
		}
		break;
	case hard:
		if (i < 400) {
			ObjectScene_Add(objectsFloor, RailClone(i % 280));
		}

		break;
	default:
		break;
	}
}

void SpawnCactus(Level level, ObjectScene* objectsFloor) {
	int i = GetRandom();
	if (i < 800) {
		switch (level)
		{
		case easy:
			ObjectScene_Add(objectsFloor, RandCactusSize(320));
			if (i < 300) {
				ObjectScene_Add(objectsFloor, RandCactusSize(340));
				if (i < 100) {
					ObjectScene_Add(objectsFloor, RandCactusSize(360));
				}
			}

			break;
		case medium:
		case hard:
			ObjectScene_Add(objectsFloor, RandCactusSize(320));
			if (i < 480) {
				ObjectScene_Add(objectsFloor, RandCactusSize(335));
				if (i < 250) {
					ObjectScene_Add(objectsFloor, RandCactusSize(350));
					if (i < 200) {
						ObjectScene_Add(objectsFloor, RandCactusSize(365));
					}
				}


			}
			break;
		default:
			break;
		}
	}
}

void SpawnRocket(Level level, ObjectScene* objectsFloor) {
	int i = GetRandom();
	if (i < 600) {
		switch (level)
		{
		case medium:
			if (i < 200) {
				ObjectScene_Add(objectsFloor, RocketClone(GetRandom() % 160 + 40));
			}
			break;
		case hard:
			if (i < 300) {
				ObjectScene_Add(objectsFloor, RocketClone(GetRandom() % 160 + 40));
			}
			break;
		default:
			break;
		}
	}
}

void SpawnFire(Level level, ObjectScene* objectsFloor) {
	int i = GetRandom();
	if (i < 800) {
		switch (level)
		{
		case medium:
			if (i < 100) {
				ObjectScene_Add(objectsFloor, FireClone(i % 40 + 320));
				if (i < 10) {
					ObjectScene_Add(objectsFloor, FireClone(GetRandom() % 80 + 320));
				}
			}
			break;
		case hard:
			if (i < 150) {
				ObjectScene_Add(objectsFloor, FireClone(i % 40 + 320));
				if (i < 30) {
					ObjectScene_Add(objectsFloor, FireClone(GetRandom() % 320 + 320));
					if (i < 10) {
						ObjectScene_Add(objectsFloor, FireClone(GetRandom() % 500 + 320));
					}
				}
			}
			break;
		default:
			break;
		}
	}
}

void Spawnboss(ObjectScene* scene) {
	ObjectScene_Add(scene, BossClone());
}


Object* SelectCoin(int x, int y) {
	int i = rand() % 100;
	if (i < 60) {
		return Coin1Clone(x, y);
	}
	else if (i < 90) {
		return Coin2Clone(x, y);
	}
	return Coin5Clone(x, y);
}