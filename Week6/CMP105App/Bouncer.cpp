#include "Bouncer.h"

Bouncer::Bouncer()
{
	// initialise gravity value (gravity 9.8, 200 scale, 200 p/s this will need to be uniform)
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;

	view = nullptr;
}

Bouncer::~Bouncer()
{
}

void Bouncer::handleInput(float dt)
{

}

void Bouncer::update(float dt)
{
	// Apply gravity force, increasing velocity
	// Move shape by new velocity
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut+ 1/2at^2
	stepVelocity += gravity * dt; // v = u + at  note the += is not =
	setPosition(getPosition() +pos);// Check for collision with bottom of window
	if (getPosition().y >= (view->getSize().y - getSize().y))
	{
		setPosition(getPosition().x, (view->getSize().y - getSize().y));
		stepVelocity = sf::Vector2f(0, 0);
	}
}
