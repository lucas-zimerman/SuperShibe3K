#pragma once
#include <MT2D/ObjectCore/Object.h>
#include "Enums/Level.h"

#define constTick 67

struct GameData {
	int tick = 0;
	int j = 0;
	int seconds = 0;
	int bossAppear = 119;
	int k;

	int bossActive = 0;
	int nextTickSecond = constTick;
	int nextCactusSecond = 2;
	int nextRailSecond = 5;
	int nextRocketSecond = 5;
	int nextFireSecond = 5;
	int nextBossSecond = 0;
	int nextLevelSecond = 60;
	unsigned int RailCount = 0;
	unsigned int RocketCount = 0;
	Level level = easy;

	ObjectScene* objectsFloor;
	ObjectScene* backgroundFloor;
	ObjectScene* sceneEffects;

	Sprite* GameOverSprite;
	Sprite** NumbersSprites;
};