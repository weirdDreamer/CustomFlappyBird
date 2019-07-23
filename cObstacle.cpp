#include "cObstacle.h"

cObstacle::cObstacle()
{}
cObstacle::cObstacle(float f_x, float f_y, float f_w, float f_h, float f_vX, float f_vY) :f_width(f_w), f_height(f_h), f_velX(f_vX), f_velY(f_vY)
{
	v_vel = { f_velX, f_velY};
	shape.setPosition(f_x, f_y);
	shape.setSize({ f_width,f_height });
	shape.setFillColor(Color::Red);
	shape.setOrigin(0,0);
}
void cObstacle::update()
{
	shape.move(v_vel);
}
void cObstacle::draw(RenderTarget &target, RenderStates state) const
{
	target.draw(shape, state);
}
void cObstacle::setVel(float f_vX, float f_vY)
{
	f_velX = f_vX;
	f_velY = f_vY;
}
float cObstacle::edgeLeft()
{
	return shape.getPosition().x;
}
float cObstacle::edgeTop()
{
	return shape.getPosition().y ;
}
float cObstacle::edgeBottom()
{
	return shape.getPosition().y-f_height;
}
float cObstacle::edgeRight()
{
	return shape.getPosition().x-f_width;
}
FloatRect cObstacle::getGlobalBounds()

{
	return shape.getGlobalBounds();
}