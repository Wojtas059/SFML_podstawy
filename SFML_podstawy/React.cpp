#include "React.h"


React::React(float t_x, float t_y)
{
	shape.setPosition(t_x, t_y);
	shape.setSize({ this->reactWidth, this->reactHeight });
	shape.setFillColor(Color::Green);
	shape.setOrigin(this->reactWidth / 2.f, reactHeight / 2.f);


}

void React::draw(RenderTarget& target, RenderStates states)const
{
	
	target.draw(this->shape);
}

void React::update()
{
	this->shape.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::A) && this->left() > 0)
	{
		velocity.x = -reactVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::D) && this->right() < 800)
	 {
		velocity.x = reactVelocity;
	 }
	else
	{
		velocity.x = 0;
	}
}

float React::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}
float React::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}
float React::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}
float React::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Vector2f React::getPosition() {
	return shape.getPosition();
}