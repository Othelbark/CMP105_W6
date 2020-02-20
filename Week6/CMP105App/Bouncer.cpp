#include "Bouncer.h"

Bouncer::Bouncer()
{

	view = nullptr;
	// initialise gravity value (gravity 9.8, 200 scale, 200 p/s this will need to be uniform)
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale; 
	jumpVector = sf::Vector2f(0, -4.0f) * scale; 
	isJumping = false;
}

Bouncer::~Bouncer()
{
}

void Bouncer::handleInput(float dt)
{
	// Jump, check if already jumping
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping) 
		{
			velocity = jumpVector; 
			isJumping = true;
		}
	}

	// On right mouse-click
	if (input->isMouseRDown())
	{
		input->setMouseRDown(false);
		setPosition(input->getMouseX() - (getSize().x / 2), input->getMouseY() - (getSize().y / 2));
	}

}

void Bouncer::update(float dt)
{
	// Apply gravity force, increasing velocity
	// Move shape by new velocity
	sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt * dt; //ut+ 1/2at^2
	velocity += gravity * dt; // v = u + at  note the += is not =
	setPosition(getPosition() +pos);// Check for collision with bottom of window
	if (getPosition().y >= (view->getSize().y - getSize().y))
	{
		setPosition(getPosition().x, (view->getSize().y - getSize().y));
		velocity = sf::Vector2f(0, 0);
		isJumping = false;
	}
}
