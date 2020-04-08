#pragma once
#include <MT2D/ObjectCore/Object.h>
void ExplosionInit();
Object* ExplosionClone(int px, int py);
void ExplosionSpawn(Object* caller);