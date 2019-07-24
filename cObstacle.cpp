#include "cObstacle.h"

cObstacle::cObstacle()
{}
cObstacle::cObstacle(float f_x, float f_y, float f_w, float f_h, float f_vX, float f_vY) :f_width(f_w), f_height(f_h), f_velX(f_vX), f_velY(f_vY), b_status(false)
{
	v_vel = { f_velX, f_velY };
	shape.setPosition(f_x, f_y);
	shape.setSize({ f_width,f_height });
	shape.setFillColor(Color::Red);
	shape.setOrigin(f_width/2, f_height/2);
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
bool cObstacle::isCounted()
{
	return b_status;
}
void cObstacle::passed(bool b_newStatus)
{
	b_status = b_newStatus;
}
float cObstacle::edgeLeft()
{
	return shape.getPosition().x- f_width/2;
}
float cObstacle::edgeTop()
{
	return shape.getPosition().y - f_height/2;
}
float cObstacle::edgeBottom()
{
	return shape.getPosition().y + f_height/2;
}
float cObstacle::edgeRight()
{
	return shape.getPosition().x + f_width/2;
}
FloatRect cObstacle::getGlobalBounds()
{
	return shape.getGlobalBounds();
}