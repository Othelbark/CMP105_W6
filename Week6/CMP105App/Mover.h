#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Mover :
	public GameObject
{
public:
	Mover();
	~Mover();

	virtual void handleInput(float dt) override;
	virtual void update(float dt) override;



protected:

	sf::Vector2f target;
	float speed;
	float acceleration;

	sf::Vector2f direction;
};

