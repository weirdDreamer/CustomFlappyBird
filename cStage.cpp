#include "cStage.h"



cStage::cStage() :b_gameStatus(false), i_score(0), i_lvl(0)
{
	bird = new cBird(960, 540, 50, 0, -5, 0.05);
	srand(time(NULL));
	window.setFramerateLimit(60);
}
cStage::~cStage()
{
	delete &bird;
	for (auto itr : v_obstaclesLVL1)
	{
		delete &itr.first;
		delete &itr.second;
	}
	for (auto itr : v_obstaclesLVL2)
	{
		delete &itr;
	}
}
void cStage::keyClickReaction()
{
	if (Keyboard::Key::Space)
	{
		if (b_gameStatus == false)
		{
			b_gameStatus = true;
		}
		bird->setVel(5, 0);
	}
}
void cStage::update()
{
	bird->update();
	for (auto itr : v_obstaclesLVL1)
	{
		itr.first->update();
		itr.second->update();
	}
	window.clear(Color::Blue);
	window.pollEvent(event);
	window.draw(*bird);
	for (auto itr : v_obstaclesLVL1)
	{
		window.draw(*itr.first);
		window.draw(*itr.second);
	}
	window.display();
}
bool cStage::isClosed()
{
	if (event.type == Event::Closed)
	{
		window.close();
		return true;
	}
	return false;
}
bool cStage::isColision()
{
	for (auto itr : v_obstaclesLVL1)
	{
		if (bird->getGlobalBounds().intersects(itr.first->getGlobalBounds()) || bird->getGlobalBounds().intersects(itr.second->getGlobalBounds()))
		{
			return true;
		}
	}
	return false;
}