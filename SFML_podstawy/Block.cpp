#include "Block.h"

Block::Block(float t_x, float t_y, float t_w, float t_h)
{
	shape.setPosition(t_x, t_y);
	shape.setSize({ t_w, t_h });
	shape.setFillColor(Color::Yellow);
	shape.setOrigin(t_w / 2.f, t_h / 2.f);


}

void Block::draw(RenderTarget& target, RenderStates states) const
{

	target.draw(this->shape);
}

float Block::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}
float Block::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}
float Block::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}
float Block::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Vector2f Block::getPosition() {
	return shape.getPosition();
}

bool Block::isDestroyed() {
	return this->destroyed;

}
void Block::destroy() {
	this->destroyed = true;

}

Vector2f Block::getSize() {
	return shape.getSize();
}

void Block::update() {

}