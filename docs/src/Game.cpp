#include <MT2D/MT2D_Debug.h>
#include <stdlib.h>
#include <MT2D/MT2D_Display.h>
#include <MT2D/Audio/MT2D_Audio_core.h>
#include <MT2D/ObjectCore/Object.h>
#include <MT2D/ObjectCore/STDFunctions.h>
#include <MT2D/Joystick/MT2D_Joystick.h>
#include <MT2D/Audio/MT2D_Audio_core.h>
#include <MT2D/ObjectCore/STDContainer.h>
#include "ScoreRender.h"
#include "GameObj/CoinFunction.h"
#include "Vars/GameVars.h"
#include "Randomizer.h"
#include "Enums/Level.h"
#include "ItemSpawn.h"
#include "Loader.h"
#include "GameObj/Heart.h"
#include "GameObj/GameBackground.h"
#include "GameData.h"
#if  defined(__EMSCRIPTEN__)
#include <emscripten.h>
#endif


GameData ctx;
extern MT2D_VAR* DogCoin; 
extern Object* Doggo;
Object* FireBall;
MT2D_VAR** yes;


int jumpReqiests = 0;
bool jumpLock;


void ControlJoystick() {
	/*if (jumpReqiests > 0)
	{

	}
	*/ if (MT2D_Joystick_LeftArrow_Touched()) {
		if (MT2D_Joystick_Get_LeftAxisX() > 0) {
			Doggo->Aceleration.X = 2;
		}
		else if (MT2D_Joystick_Get_LeftAxisX() < 0) {
			Doggo->Aceleration.X = -2;
		}
	}
	else
	{
		Doggo->Aceleration.X = 0;
	}
	if (MT2D_Joystick_Button_Touched(1))
	{
		if (jumpReqiests < 2 && !jumpLock) {
			jumpLock = true;
			jumpReqiests++;
			Doggo->Aceleration.Y = -8;
			Doggo->SpacePosition.Y -= 25;
			MT2D_Object_VAR_SetVar(JumpRequest, Const1);
		}
	}
	else
	{
		jumpLock = false;
	}
}
int delayAcel = 0;

void GameOverAppearing();
void GameOverAppeared();
void DogDeathAnimation();
void GameLoop();
void GameOverAppeared();

MT2D_VAR** rip;

void runDogAceleration() {
	Doggo->SpacePosition.X += Doggo->Aceleration.X;
	Doggo->SpacePosition.Y += Doggo->Aceleration.Y;

	//Reset X
	if (Doggo->SpacePosition.X < 0) {
		Doggo->SpacePosition.X = 0;
	}
	else if (Doggo->SpacePosition.X > 320 - Doggo->Size.X)
	{
		Doggo->SpacePosition.X = 320 - Doggo->Size.X;
	}

	if (Doggo->SpacePosition.Y == 201);
	else if (Doggo->SpacePosition.Y > 201) {
		Doggo->SpacePosition.Y = 201;
		Doggo->Aceleration.Y = 0;
		jumpReqiests = 0;
	}
	else if ((delayAcel & 1) == 1 && Doggo->Aceleration.Y < 10) {
		Doggo->Aceleration.Y++;
	}
	delayAcel++;
}


void GameDataResetSoft() {
	ctx.tick = 0;
	ctx.j = 0;
	ctx.seconds = 0;
	ctx.bossAppear = 119;

	ctx.bossActive = 0;
	ctx.nextTickSecond = constTick;
	ctx.nextCactusSecond = 2;
	ctx.nextRailSecond = 5;
	ctx.nextRocketSecond = 5;
	ctx.nextFireSecond = 5;
	ctx.nextBossSecond = 0;
	ctx.nextLevelSecond = 60;
	ctx.RailCount = 0;
	ctx.RocketCount = 0;
	ctx.level = easy;

	ResetCash();
	rCount = 0;

	MT2D_Object_VAR_SetVar(DogHealth, Const8);
	MT2D_Object_VAR_SetVar(GameSpeed, Const2);
	Cscript_Object_SetState(Doggo, &stateLoop);
	Doggo->ActualFrame = 0;

	ctx.level = easy;
	Doggo->SpacePosition.X = 0;
	Doggo->SpacePosition.Y = 200;
	Doggo->Aceleration.X = 0;
	Doggo->Aceleration.X = 0;
	for (ctx.j = 1; ctx.j < ctx.objectsFloor->Count; ctx.j++) {
		ctx.objectsFloor->ObjectGroup[ctx.j]->CanDelete = true;
	}
	for (ctx.j = 1; ctx.j < ctx.sceneEffects->Count; ctx.j++) {
		ctx.sceneEffects->ObjectGroup[ctx.j]->CanDelete = true;
	}
	for (ctx.j = 5; ctx.j < ctx.backgroundFloor->Count; ctx.j++) {
		ctx.backgroundFloor->ObjectGroup[ctx.j]->CanDelete = true;
	}

	Cscript_PlayMusicFromContainer(NULL, yes);

	MT2D_Joystick_Init();
	MT2D_Joystick_Map_Button01(32);

}


void DogDeathInit()
{
	Cscript_Object_SetState(Doggo, &stateDeath);
	Doggo->ActualFrame = 0;
	Cscript_PlaySoundFromContainer(NULL, rip);
}

void DogDeathAnimation()
{
	MT2D_Clear_Main_Window();
	Object_Goto_NextStep(Doggo);
	ObjectScene_Render(ctx.sceneEffects);
	ObjectScene_Render(ctx.objectsFloor);
	ObjectScene_Render(ctx.backgroundFloor);
	MT2D_Draw_Window(0);
	if (Doggo->SpacePosition.Y >= 240)
	{
		ctx.j = 320;
#if  defined(__EMSCRIPTEN__)
		emscripten_cancel_main_loop();
		emscripten_set_main_loop(GameOverAppearing, 0, 1);
#endif
	}
}

void GameOverAppearing() {
	MT2D_Clear_Main_Window();
	ObjectScene_Render(ctx.sceneEffects);
	ObjectScene_Render(ctx.objectsFloor);
	ObjectScene_Render(ctx.backgroundFloor);
	Sprite_Render_on_Window(ctx.GameOverSprite, 0, 32, ctx.j);
	insert_score_on_display(*(int*)DogCoin->Data, ctx.j + 42, 128, ctx.NumbersSprites);
	MT2D_Draw_Window(0);
	ctx.j -= 4;
#if  defined(__EMSCRIPTEN__)
	if (ctx.j <= 64) 
	{
		emscripten_cancel_main_loop();
		emscripten_set_main_loop(GameOverAppeared, 0, 1);
	}
#endif
}

void GameLoop()
{
	ControlJoystick();
	runDogAceleration();

	if (ctx.tick == ctx.nextTickSecond)
	{
		ctx.seconds++;
		ctx.nextTickSecond += constTick;

		if (GetRandom() <= 150 + (50 * (1 + ctx.level)))
		{
			if (GetRandom() % 100 < 35 + ctx.level) {
				ctx.k = GetRandom() % 150;
				for (ctx.j = 0; ctx.j < GetRandom() % 15 + ctx.level; ctx.j++) {
					ObjectScene_Add(ctx.objectsFloor, SelectCoin(320 + ctx.j * 30, ctx.k));
				}
			}
			else if (GetRandom() % 100 < 50 + ctx.level)
			{
				for (ctx.j = 0; ctx.j < GetRandom() % 15 + ctx.level; ctx.j++) {
					ObjectScene_Add(ctx.objectsFloor, SelectCoin(320 + ctx.j * 30, GetRandom() % 200));
				}

			}
		}

		if (ctx.nextCactusSecond == ctx.seconds)
		{
			ctx.nextCactusSecond += 2 + (ctx.bossActive << 1) + ctx.level;
			SpawnCactus((Level)(ctx.level - ctx.bossActive), ctx.objectsFloor);
		}
		if (ctx.nextRailSecond == ctx.seconds || ctx.RailCount > 0)
		{

			SpawnRail((Level)(ctx.level - ctx.bossActive), ctx.objectsFloor);
			if (ctx.RailCount == 0) {
				ctx.nextRailSecond += 5 - ctx.level + ctx.bossActive;
				ctx.RailCount = GetRandom() % (ctx.level + 1);
			}
			else
			{
				ctx.RailCount--;
			}
		}
		if (ctx.level > easy) {
			if (ctx.nextRocketSecond == ctx.seconds || ctx.RocketCount > 0)
			{
				SpawnRocket(ctx.level, ctx.objectsFloor);
				if (ctx.RocketCount == 0)
				{
					ctx.nextRocketSecond += 6 - ctx.level + ctx.bossActive * 2;
					ctx.RocketCount = GetRandom() % (ctx.level + 2);
				}
				else
				{
					ctx.RocketCount--;
				}
			}
			if (ctx.nextFireSecond == ctx.seconds)
			{
				ctx.nextFireSecond += 12 - (2 - ctx.bossActive) * ctx.level;
				SpawnFire(ctx.level, ctx.objectsFloor);
			}
			if (ctx.nextBossSecond == ctx.seconds) {
				if (ctx.bossActive) {
					ctx.nextBossSecond += 200 - (ctx.level * 60);
					ctx.bossActive = 0;
				}
				else
				{
					ctx.nextBossSecond += 80;
					ctx.bossActive = 1;
					Spawnboss(ctx.backgroundFloor);
				}
			}
		}
		if (ctx.nextLevelSecond == ctx.seconds) {
			if (ctx.level == easy) {
				ctx.nextBossSecond += 120;
				ctx.nextFireSecond += ctx.seconds + 10;
				ctx.nextRocketSecond = ctx.seconds + 5;
				ctx.nextLevelSecond += 80;
			}
			if (ctx.level < hard) {
				ctx.nextLevelSecond += 120;
				if (ctx.level == easy) {
					ctx.level = medium;
				}
				else {
					ctx.level = hard;
					MT2D_Object_VAR_SetVar(GameSpeed, Const3);
				}
			}
		}

	}

	ObjectScene_Goto_NextSteps(ctx.sceneEffects);
	ObjectScene_Goto_NextSteps(ctx.objectsFloor);
	ObjectScene_Goto_NextSteps(ctx.backgroundFloor);

	MT2D_Clear_Main_Window();
	ObjectScene_Render(ctx.sceneEffects);
	ObjectScene_Render(ctx.objectsFloor);
	ObjectScene_Render(ctx.backgroundFloor);
	MT2D_Joystick_Update();
	HeartDraw();
	MT2D_Draw_Window(0);
	ctx.tick++;
	if (*(int*)DogHealth->Data <= 0) {
		DogDeathInit();
		MT2D_Joystick_Close();
#if  defined(__EMSCRIPTEN__)
		emscripten_cancel_main_loop();
		emscripten_set_main_loop(DogDeathAnimation, 0, 1);
#endif
	}
}

void GameOverAppeared() {
	MT2D_Clear_Main_Window();
	ObjectScene_Render(ctx.sceneEffects);
	ObjectScene_Render(ctx.objectsFloor);
	ObjectScene_Render(ctx.backgroundFloor);
	Sprite_Render_on_Window(ctx.GameOverSprite, 0, 32, 64);
	insert_score_on_display(*(int*)DogCoin->Data, 64 + 42, 128, ctx.NumbersSprites);
	MT2D_Draw_Window(0);
	if (MT2D_Keyboard_touched()) {
		ctx.j = MT2D_Keyboard_keytouched();
		if (ctx.j == 'e' || ctx.j == 'E') {
			MT2D_Audio_Close();
			exit(0);
		}
		else if (ctx.j == 'a' || ctx.j == 'A') {
			GameDataResetSoft();
#if  defined(__EMSCRIPTEN__)
			emscripten_cancel_main_loop();
			emscripten_set_main_loop(GameLoop, 0, 1);
#endif
		}
		else if (ctx.j == arrow_key_pressed) {
			ctx.j = MT2D_Keyboard_keytouched();
		}
	}
}


void GameDataInit()
{
	yes = MT2D_VAR_Create_Matrix2(GameMusic, Const0);
	rip = MT2D_VAR_Create_Matrix2(DoggoRipSound, Const0);

	ctx.backgroundFloor = ObjectScene_CreateEmpty();
	ctx.objectsFloor = ObjectScene_CreateEmpty();
	ctx.sceneEffects = ObjectScene_CreateEmpty();

	char GameOverSpritePath[] = "Sprites/Game/message/message.png";
	ctx.GameOverSprite = Load_Sprite_Image_From_Container(GameOverSpritePath, 256, 96);
	ctx.NumbersSprites = (Sprite**)malloc(10 * sizeof(Sprite*));
	char NumberSpritePath[] = "Sprites/Game/Numbers/0.png";
	for (int n = 0; n < 10; n++) {
		NumberSpritePath[30 - 9] = '0' + n;
		ctx.NumbersSprites[n] = Load_Sprite_Image_From_Container(NumberSpritePath, 10, 8);
	}

	LoadTiles(ctx.backgroundFloor);
	ObjectScene_Add(ctx.sceneEffects, BackgroundClone());
	ObjectScene_Add(ctx.objectsFloor, Doggo);

}

void Game() {

	LoadContainerFiles();

	LoadObjectReferences();

	GameDataInit();

	GameDataResetSoft();

#if  defined(__EMSCRIPTEN__)
	emscripten_cancel_main_loop();
	emscripten_set_main_loop(GameLoop, 0, 1);
#else
	while (true) {
		while (*(int*)DogHealth->Data > 0) {
			GameLoop();
		}
		while (Doggo->SpacePosition.Y <= 240) {
			DogDeathAnimation();
		}
		while (ctx.j > 64) {
			GameOverAppearing();
		}
		while (ctx.tick > 0) {
			GameOverAppeared();
		}
	}
#endif
}