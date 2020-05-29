#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Ball : public sf::Drawable
{
public:
	Ball(float t_x, float t_y);
	~Ball() = default;
	void update();
	float left();
	float top();
	float bottom();
	float right();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	Vector2f getPosition();

private:
	CircleShape shape;
	const float ballRadius{ 10.0f };
	const float ballVelocity{ 5.0f };
	void draw(RenderTarget& target, RenderStates states) const override;
	Vector2f velocity{ ballVelocity, ballVelocity };


};

