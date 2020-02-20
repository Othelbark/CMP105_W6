#include "Mover.h"

Mover::Mover()
{
	target = getPosition();
	speed = 250.0f;
	acceleration = 50.0f;
}
Mover::~Mover()
{
}

void Mover::handleInput(float dt)
{
	/* On left mouse-click
	if (input->isMouseLDown())
	{
		target = sf::Vector2f(input->getMouseX() - (getSize().x / 2), input->getMouseY() - (getSize().y / 2));
	}
	*/
}

void Mover::update(float dt)
{
	// calculate direction and move
	target = sf::Vector2f(input->getMouseX() - (getSize().x / 2), input->getMouseY() - (getSize().y / 2));
	direction = target -getPosition();
	direction = Vector::normalise(direction);

	speed += acceleration * dt;

	velocity = (direction * speed);
	//velocity += (direction * acceleration) * dt;
	setPosition(getPosition() + (velocity*dt));

	// if object is close enough to target
	if (Vector::magnitude(target - getPosition()) < Vector::magnitude(velocity * dt)) //10.0f)//
	{
		setPosition(target);
		speed = 0.0f;
		//velocity = sf::Vector2f(0, 0);
	}
}
