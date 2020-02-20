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

	float scale;
	//sf::Vector2f stepVelocity;
	sf::Vector2f gravity;
	sf::Vector2f jumpVector;
	bool isJumping;
};

