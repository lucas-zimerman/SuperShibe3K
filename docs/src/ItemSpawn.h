#pragma once
#include <MT2D/ObjectCore/Object.h>
#include "Enums/Level.h"

void SpawnRail(Level level, ObjectScene* objectsFloor);

void SpawnCactus(Level level, ObjectScene* objectsFloor);

void SpawnRocket(Level level, ObjectScene* objectsFloor);

void SpawnFire(Level level, ObjectScene* objectsFloor);

void Spawnboss(ObjectScene* scene);

Object* SelectCoin(int x, int y);