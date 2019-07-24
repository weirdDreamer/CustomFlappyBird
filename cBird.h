#ifndef BIRD
#define BIRD

#include <SFML/Graphics.hpp>

using namespace sf;

class cBird :
	public Drawable
{
private:
	RectangleShape shape;
	float f_size;
	float f_acc;    //acceleration
	Vector2f v_vel;
	virtual void draw(RenderTarget &target, RenderStates state) const override;
public:
	cBird();
	cBird(float f_x, float f_y, float f_s);
	~cBird() = default;
	void update();
	void setAcc(float f_a);
	void setVel(float f_vX, float f_vY);
	void setPosition(float f_x, float f_y);
	float edgeRight();
	float edgeLeft();
	float edgeTop();
	float edgeBottom();
	FloatRect getGlobalBounds();
};
#endif //BIRD
