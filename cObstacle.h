#ifndef OBSTACLE
#define OBSTACLE

#include <SFML/Graphics.hpp>

using namespace sf;

class cObstacle :
	public Drawable
{
private:
	RectangleShape shape;
	bool b_status;
	float f_width;
	float f_height;
	float f_velX;
	float f_velY;
	Vector2f v_vel;
	virtual void draw(RenderTarget &target, RenderStates state) const override;

public:
	cObstacle();
	cObstacle(float f_x, float f_y, float f_w, float f_h, float f_vX, float f_vY);
	~cObstacle() = default;
	void update();
	void setVel(float f_vX, float f_vY);
	void passed(bool b_newStatus);
	bool isCounted();
	float edgeLeft();
	float edgeTop();
	float edgeBottom();
	float edgeRight();
	FloatRect getGlobalBounds();
};

#endif //OBSTACLE