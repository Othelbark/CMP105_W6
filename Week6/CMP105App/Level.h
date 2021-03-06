#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "Bouncer.h"
#include "Mover.h"
#include "Launcher.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	// View Variable
	sf::View view;

	// More level variables

	// GameObjects
	Bouncer bouncer;
	sf::Texture bouncerTexture;

	Mover mover;

	Launcher launcher;
};