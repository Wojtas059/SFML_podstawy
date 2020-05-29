#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class React : public Drawable
{
	

public:
	React(float t_x, float t_y);
	React() = default;
	void update();
	float left();
	float top();
	float bottom();
	float right();
	Vector2f getPosition();

private:

	void draw(RenderTarget& target, RenderStates states) const override;
	RectangleShape shape;
	const float reactWidth{ 80.0f };
	const float reactHeight{ 20.0f };
	const float reactVelocity{ 6.0f };
	Vector2f velocity{ reactVelocity, 0.f };


};

