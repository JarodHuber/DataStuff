#include "MainGame.h"

Color MainGame::background() const
{
	return Color{ 13, 2, 33, 255 };
}

void MainGame::onInit()
{
	generatePlatforms();
	generateOtherObjs();

	plyr = Player(800, 1000, 2500, plats, 30, ORANGE, CENTER);
	plyr.init();
}
void MainGame::onTick()
{
	plyr.update();

	plats.update();

	for (int x = 0; x < objSize; ++x)
	{
		otherObjs[x]->update();
	}

	cameracenter::instance().setPos(CENTER);
}
void MainGame::onDraw()
{
	plats.draw();

	for (int x = 0; x < objSize; ++x)
	{
		otherObjs[x]->draw();
	}
	
	plyr.draw();
}
void MainGame::onExit()
{
	plats.destroy();
	for (int x = 0; x < objSize; ++x)
	{
		delete otherObjs[x];
	}

	delete[] otherObjs;
}

void MainGame::generateOtherObjs()
{
	objSize = 5;
	otherObjs = new SpriteObject *[]
	{
		new TextObject("  AD to move\nspace to jump", 16, DARKRED, Vec2(1150, 425)),
		new TextObject("use the bottom ledge\n  to make the jump", 16, DARKRED, Vec2(3375, 125)),
		new TextObject(" jump while wall sliding\nto perform a wall jump", 16, DARKRED, Vec2(3675, -200)),
		new TextObject("shift to dash", 16, DARKRED, Vec2(4925, -350)),
		new TextObject("   jump while in the air\nto perform a double jump", 16, DARKRED, Vec2(6525, -575)),
	};
}
void MainGame::generatePlatforms()
{
	plats = new BoxObject*[]
	{
		new BoxObject(Rectangle{ -400, 50, 400, 800 },   LIME),							// back wall
		new BoxObject(Rectangle{ 0, 550, 1100, 300 },  LIME),							// start platform
		new BoxObject(Rectangle{ 1100, 350, 500, 500 }, LIME),							// first platform
		new BoxObject(Rectangle{ 2200, 350, 650, 500 }, LIME),							// second platform
		new BoxObject(Rectangle{ 3450, 100, 550, 100 }, LIME),							// ledge
		new BoxObject(Rectangle{ 3550, 400, 700, 500 }, LIME),							// landing platform
		new BoxObject(Rectangle{ 4250, 300, 200, 600 }, LIME),							// step stool
		new BoxObject(Rectangle{ 4000, 150, 100, 50 }, LIME),							// ledge lip
		new BoxObject(Rectangle{ 4450, -125, 100, 1025 }, LIME),						// right wall
		new BoxObject(Rectangle{ 3350, -1300, 100, 1500 }, LIME),						// wall jump wall
		new BoxObject(Rectangle{ 3650, -225, 1200, 100 }, LIME),						// wall jump platform
		new BoxObject(Rectangle{ 5100, -225, 600, 100 }, LIME),							// dash platform
		new BoxObject(Rectangle{ 4500, -1300, 1200, 995 }, LIME),						// dash ceiling
		new BoxObject(Rectangle{ 5700, -225, 2000, 1075 }, LIME),						// double Jump floor
		new BoxObject(Rectangle{ 6500, -600, 1200, 100 }, LIME),						// double Jump platform
		new BoxObject(Rectangle{ 7700, -1150, 100, 2000 }, LIME),						// double Jump wall
		new BoxObject(Rectangle{ 6650, -1550, 100, 300 }, LIME),						// long jump
		new BoxObject(Rectangle{ 6300, -3650, 100, 2600 }, LIME),						// wall jump tunnel left
		new BoxObject(Rectangle{ 6650, -3000, 100, 1100 }, LIME),						// wall jump tunnel right
		new BoxObject(Rectangle{ 7000, -3700, 100, 400 }, LIME),						// special wall
		new BoxObject(Rectangle{ 4500, -4500, 1500, 3000 }, LIME),						// wall slide left
		new BoxObject(Rectangle{ 4100, -1550, 400, 50 }, LIME),							// wall slide left
		new movingObject(400, 0, 1000, true, Rectangle{ 0, -150, 200, 100 }, LIME),		// moving object test
		nullptr
	};
}