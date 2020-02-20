#pragma once
#include "Framework/GameObject.h"
class Launcher :
	public GameObject
{
public:
	Launcher();
	~Launcher();

	virtual void handleInput(float dt) override;
	virtual void update(float dt) override;

	void setView(sf::View* vw) { view = vw; };

protected:
	sf::View* view;

	bool launched;
	float launchSpeed;

	//varables for mouse drag
	bool mouseDragInProces;
	sf::Vector2f mouseDragStartPos;

	float scale;
	sf::Vector2f gravity;
};

