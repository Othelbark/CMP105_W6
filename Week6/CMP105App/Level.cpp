#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	view = window->getView();

	// initialise game objects
	bouncer.setInput(input);
	bouncer.setView(&view);
	bouncer.setPosition(200, 100);
	bouncer.setSize(sf::Vector2f(80, 80));
	bouncerTexture.loadFromFile("gfx/Beach_Ball.png");
	bouncer.setTexture(&bouncerTexture);


	mover.setInput(input);
	mover.setPosition(0, 0);
	mover.setSize(sf::Vector2f(50, 50));
	mover.setTexture(&bouncerTexture);

	launcher.setInput(input);
	launcher.setView(&view);
	launcher.setPosition(50, 600);
	launcher.setSize(sf::Vector2f(25, 25));
	launcher.setTexture(&bouncerTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}


	bouncer.handleInput(dt);
	mover.handleInput(dt);
	launcher.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	bouncer.update(dt);
	mover.update(dt);
	launcher.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(bouncer);
	window->draw(mover);
	window->draw(launcher);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}