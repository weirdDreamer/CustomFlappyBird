#include "cBird.h"

cBird::cBird()
{}
cBird::cBird(float f_x, float f_y, float f_s) :f_size(f_s), f_acc(0), v_vel({ 0, 0 })
{
	shape.setPosition(f_x, f_y);
	shape.setSize({ f_size,f_size });
	shape.setFillColor(Color::Yellow);
	shape.setOrigin(f_size / 2, f_size / 2);
}
void cBird::update()
{
	v_vel.y = v_vel.y + f_acc;
	shape.move(v_vel);
}
void cBird::draw(RenderTarget &target, RenderStates state) const
{
	target.draw(shape, state);
}
void cBird::setAcc(float f_a)
{
	f_acc = f_a;
}
void cBird::setVel(float f_vX, float f_vY)
{
	v_vel.x = f_vX;
	v_vel.y = f_vY;
}
float cBird::edgeLeft()
{
	return shape.getPosition().x - f_size / 2;
}
float cBird::edgeRight()
{
	return shape.getPosition().x + f_size / 2;
}
float cBird::edgeTop()
{
	return shape.getPosition().y - f_size / 2;
}
float cBird::edgeBottom()
{
	return shape.getPosition().y + f_size / 2;
}
FloatRect cBird::getGlobalBounds()
{
	return shape.getGlobalBounds();
}