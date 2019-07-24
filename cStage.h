#ifndef STAGE
#define STAGE

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <vector>
#include <utility>

#include "cObstacle.h"
#include "cBird.h"

using namespace sf;
using namespace std;

class cStage
{
private:
	RenderWindow window{ VideoMode(1920, 1080),"Custom Flappy Bird" };
	Event event;
	vector<pair<cObstacle*, cObstacle*>> v_obstaclesLVL1;
	vector <cObstacle*> v_obstaclesLVL2;
	bool b_gameStatus;
	int i_score;
	int i_lvl;
	cBird* bird;
public:
	cStage();
	~cStage();
	void obctaclesGeneration();
	void update();
	void keyClickReaction();
	void isColision();
	bool isClosed();
};
#endif //STAGE

