#include <MT2D/MT2D.h>
#include <MT2D/File/MT2D_File.h>
#include <MT2D/MT2D_Debug.h>
#include <MT2D/MT2D_Display.h>
#include <MT2D/Audio/MT2D_Audio_core.h>
#include "Menu.h"
#include <MT2D/Container/MT2D_Container.h>


extern MT2D_ContainerList ListFilePaths;;
void createContainers() {
	MT2D_Container_Load_File((char*)"Music/mmenu.ogg");
	MT2D_Container_Load_File((char*)"Sounds/ss3k.ogg");

	MT2D_Container_Load_File((char*)"Sprites/Menu/3000.png");
	MT2D_Container_Load_File((char*)"Sprites/Menu/mback.png");
	MT2D_Container_Load_File((char*)"Sprites/Menu/mshibe.png");
	MT2D_Container_Load_File((char*)"Sprites/Menu/shibe.png");
	MT2D_Container_Load_File((char*)"Sprites/Menu/start.png");
	MT2D_Container_Load_File((char*)"Sprites/Menu/super.png");


	MT2D_Container_Load_File((char*)"Music/boss.ogg");
	MT2D_Container_Load_File((char*)"Music/mgame.ogg");

	MT2D_Container_Load_File((char*)"Sounds/cget.ogg");
	MT2D_Container_Load_File((char*)"Sounds/deadh.wav");
	MT2D_Container_Load_File((char*)"Sounds/dogrip.ogg");
	MT2D_Container_Load_File((char*)"Sounds/enemysummon.wav");
	MT2D_Container_Load_File((char*)"Sounds/explosion.ogg");
	MT2D_Container_Load_File((char*)"Sounds/fireball.ogg");
	MT2D_Container_Load_File((char*)"Sounds/jump.ogg");
	MT2D_Container_Load_File((char*)"Sounds/laser.ogg");
	MT2D_Container_Load_File((char*)"Sounds/rocket.ogg");

	MT2D_Container_Load_File((char*)"Sprites/Game/decoration/back/mountains.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/decoration/Explosion/explosion1.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/decoration/Explosion/explosion2.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/decoration/Explosion/explosion3.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/decoration/Explosion/explosion4.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/decoration/Explosion/explosion5.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/decoration/Explosion/explosion6.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/decoration/Platform/normal.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/dog/dog1.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/dog/dog2.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/dog/dog3.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/dog/dog4.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/dog/dog5.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/dog/dog6.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/dog/dog7.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/dog/dog8.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/dog/dog9.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Enemies/MrPop.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Enemies/Particle/rail0.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Enemies/Particle/rail1.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Enemies/Particle/rail2.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Enemies/Particle/rail3.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Enemies/Particle/rail4.png");

	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Cactus/CactusBig.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Cactus/CactusBigHit.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Cactus/CactusSmall.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Cactus/CactusSmallHit.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Coin/1Coin.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Coin/2Coin.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Coin/5Coin.png");

	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Fire/Fire0000.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Fire/Fire0001.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Fire/Fire0002.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Fire/Fire0003.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Fire/Fire0004.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Fire/Fire0005.png");

	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Health/Health.png");

	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Projectile/Aproj1.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Projectile/Aproj2.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Projectile/Aproj3.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Projectile/Aproj4.png");

	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Projectile/Bproj1.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Projectile/Bproj2.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Projectile/Bproj3.png");

	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Smoke/Smoke0000.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Smoke/Smoke0001.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Smoke/Smoke0002.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Smoke/Smoke0003.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Smoke/Smoke0004.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Smoke/Smoke0005.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Itens/Smoke/Smoke0006.png");

	MT2D_Container_Load_File((char*)"Sprites/Game/message/message.png");

	MT2D_Container_Load_File((char*)"Sprites/Game/Numbers/0.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Numbers/1.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Numbers/2.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Numbers/3.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Numbers/4.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Numbers/5.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Numbers/6.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Numbers/7.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Numbers/8.png");
	MT2D_Container_Load_File((char*)"Sprites/Game/Numbers/9.png");

	int i = 0;
	int id = 0;
	MT2D_FILE* file = MT2D_FILE_OPEN("Menu.mt2", "w"); MT2D_FILE_CLOSE(file);
	MT2D_Container_Load((char*)"Menu.mt2");
	file = MT2D_FILE_OPEN("Game.mt2", "w"); MT2D_FILE_CLOSE(file);
	MT2D_Container_Load((char*)"Game.mt2");

	MT2D_ContainerFilePath* path = ListFilePaths.start;
	for (; i < 8; i++) {
		id = MT2D_Container_Get_FileId(path->file);
		MT2D_Container_Export_into_Container(id, (char*)"Menu.mt2", false);
		path = path->next;
	}
	while (path->refCount == 1)
	{
		id = MT2D_Container_Get_FileId(path->file);
		MT2D_Container_Export_into_Container(id, (char*)"Game.mt2", false);
		path = path->next;
	}
	MT2D_Container_Clear();
}

void loop()
{
//	MT2D_Ide_Printf("Main chamado");
//	createContainers();
//	MT2D_Ide_Printf("AUdio fechado");

}

int main(int argc, char* argv[])
{
	MT2D_Init();
	MT2D_Audio_Init();
	MT2D_Container_Init();
	MT2D_Ide_Printf("Container Started");
	MenuInitAndRun();
	return 0;
}