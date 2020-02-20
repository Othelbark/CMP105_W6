#include "Launcher.h"

Launcher::Launcher()
{
	view = nullptr;

	launched = false;
	launchSpeed = 5.0f;

	mouseDragInProces = false;
	mouseDragStartPos = getPosition();

	// initialise gravity value (gravity 9.8, 200 scale, 200 p/s this will need to be uniform)
	scale = 100.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
}

Launcher::~Launcher()
{
}

void Launcher::handleInput(float dt)
{
	//mouse drag
	if (input->isMouseLDown() && !mouseDragInProces)
	{
		mouseDragInProces = true;

		// "Catch" the launcher
		launched = false;
		velocity = { 0,0 };

		// Set start point
		mouseDragStartPos = sf::Vector2f(input->getMouseX(), input->getMouseY());
	}
	if (!input->isMouseLDown() && mouseDragInProces)
	{
		mouseDragInProces = false;

		// Launch the launcher
		launched = true;
		velocity = mouseDragStartPos - sf::Vector2f(input->getMouseX(), input->getMouseY());
		velocity *= launchSpeed;
	}
}

void Launcher::update(float dt)
{
	if (launched)
	{
		// Apply gravity force, increasing velocity
		// Move shape by new velocity
		sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt * dt; //ut+ 1/2at^2
		velocity += gravity * dt; // v = u + at  note the += is not =
		setPosition(getPosition() + pos);

		if ((getPosition().x + getSize().x) > view->getSize().x)
		{
			setPosition((view->getSize().x - getSize().x), getPosition().y);
			velocity.x *= -1.0f;
			velocity = velocity * 0.8f;
		}
		else if (getPosition().x < 0)
		{
			setPosition(0, getPosition().y);
			velocity.x *= -1.0f;
			velocity = velocity * 0.8f;
		}

		if ((getPosition().y + getSize().y) > view->getSize().y)
		{
			setPosition(getPosition().x, (view->getSize().y - getSize().y));
			velocity.y *= -1.0f;
			velocity = velocity * 0.8f;
		}
		else if (getPosition().y < 0)
		{
			setPosition(getPosition().x, 0);
			velocity.y *= -1.0f;
			velocity = velocity * 0.8f;
		}
	}
}
