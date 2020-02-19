#pragma once
#include "Framework/GameObject.h"
class Bouncer :
	public GameObject
{
public:
	Bouncer();
	~Bouncer();

	virtual void handleInput(float dt) override;
	virtual void update(float dt) override;

	
	void setView(sf::View* vw) { view = vw; };

protected:
	sf::View* view;

	sf::Vector2f gravity;
	float scale;
	sf::Vector2f stepVelocity;
};

