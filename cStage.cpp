#include "cStage.h"



cStage::cStage() :b_gameStatus(false), i_score(0), i_lvl(0)
{
	bird = new cBird(960, 540, 50);
	srand(time(NULL));
	window.setFramerateLimit(60);
}
cStage::~cStage()
{
	delete bird;
	for (auto itr : v_obstaclesLVL1)
	{
		delete itr.first;
		delete itr.second;
	}
	for (auto itr : v_obstaclesLVL2)
	{
		delete itr;
	}
}
void cStage::obctaclesGeneration()
{
	if (b_gameStatus)
	{
		switch (i_lvl)
		{
			case 0:
			{
				if (v_obstaclesLVL1.back().first->edgeRight() < 1700)
				{
					int i_hole = 200;
					int i_margin = 100;
					int i_ob1Y = rand() % ((int)(540 - i_hole/2 - i_margin)/2) + i_margin;
					pair<cObstacle*, cObstacle*> p_nextObstacle = { new cObstacle(1950, i_ob1Y, 50, 2 * i_ob1Y, -5, 0), new cObstacle(1950, 1080 - (440 - i_ob1Y), 50, 2*(440 - i_ob1Y), -5, 0) };
					v_obstaclesLVL1.push_back(p_nextObstacle);
				}
				if (v_obstaclesLVL1[0].first->edgeRight() < 0)
				{
					v_obstaclesLVL1.erase(v_obstaclesLVL1.begin());
				}
				break;
			}
			case 1:
			{
				break;
			}
		}
	}
}
void cStage::keyClickReaction()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Space))
	{
		if (b_gameStatus == false)
		{
			b_gameStatus = true;
		}
		bird->setVel(0, -12);
		bird->setAcc(0.7);
		if (v_obstaclesLVL1.empty())
		{
			int i_hole = 200;
			int i_margin = 100;
			int i_ob1Y = rand() % ((int)(540 - i_hole / 2 - i_margin) / 2) + i_margin;
			pair<cObstacle*, cObstacle*> p_nextObstacle = { new cObstacle(1950, i_ob1Y, 50, 2 * i_ob1Y, -5, 0), new cObstacle(1950, 1080 - (440 - i_ob1Y), 50, 2 * (440 - i_ob1Y), -5, 0) };
			v_obstaclesLVL1.push_back(p_nextObstacle);
		}
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
	if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Key::Escape))
	{
		window.close();
		return true;
	}
	return false;
}
void cStage::isColision()
{
	if (b_gameStatus)
	{
		switch (i_lvl)
		{
			case 0:
			{
				if (v_obstaclesLVL1.back().first->edgeRight() < 1700)
				{
					for (auto itr : v_obstaclesLVL1)
					{
						if (bird->getGlobalBounds().intersects(itr.first->getGlobalBounds()) || bird->getGlobalBounds().intersects(itr.second->getGlobalBounds()))
						{
							b_gameStatus = false;
						}
					}
					break;
				}
			}
			case 1:
			{
				break;
			}
		}
	}
}