#include <MT2D/ObjectCore/Object.h>
#include <MT2D/Container/MT2D_Container.h>
#include "GameObj/dog.h"
#include "GameObj/Tile.h"
#include "GameObj/RailGun.h"
#include "GameObj/GameBackground.h"
#include "GameObj/CactusBig.h"
#include "GameObj/CactusSmall.h"
#include "GameObj/Fire.h"
#include "GameObj/Rocket.h"
#include "GameObj/Explosion.h"
#include "GameObj/Coin1.h"
#include "GameObj/Coin2.h"
#include "GameObj/Coin5.h"
#include "GameObj/Heart.h"
#include "GameObj/FireBall.h"
#include "GameObj/Boss.h"
#include "ScoreRender.h"
#include "GameObj/CoinFunction.h"
#include "GameObj/Smoke.h"
#include "GameObj/dog.h"

extern Object* Doggo;
extern Object* FireBall;

void LoadObjectReferences() {
	//Init
	TileInit();
	BackgroundInit();
	DoggoInit();
	Doggo = DoggoClone(0, 200);
	RailInit();
	CactusBigInit();
	CactusSmallInit();
	FireInit();
	ExplosionInit();
	RocketInit();
	SmokeInit();
	HeartInit();
	FireBallInit();
	FireBall = FireBallClone(0);
	BossInit();
	Coin1Init();
	Coin2Init();
	Coin5Init();
}

void LoadTiles(ObjectScene* scene) {
	ObjectScene_Add(scene, TileClone(0, 220));
	ObjectScene_Add(scene, TileClone(100, 220));
	ObjectScene_Add(scene, TileClone(200, 220));
	ObjectScene_Add(scene, TileClone(300, 220));
	ObjectScene_Add(scene, TileClone(400, 220));
}


void LoadContainerFiles() {
	MT2D_Container_Load((char*)"assets/Game.mt2");
}