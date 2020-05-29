#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Block : public Drawable
{
public:
	Block(float t_x, float t_y, float t_w, float t_h);
	~Block() = default;

	void update();
	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

	bool isDestroyed();
	void destroy();

	Vector2f getSize();

private:
	
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	RectangleShape shape;
	bool destroyed{ false };

};

