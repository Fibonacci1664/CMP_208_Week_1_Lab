#pragma once
#include <graphics/sprite.h>
#include <graphics/sprite_renderer.h>
#include<graphics/colour.h>

class Player : public gef::Sprite
{
public:
	Player(gef::Vector4 position, float width, float height);
	~Player();

	void handleInput(float dt);
	void update(float dt);
	void render(gef::SpriteRenderer* sprite_renderer);

	void setSpeed(float newSpeed);
	void setVelocity(gef::Vector4 direction, float speed);

protected:
	

private:
	void initPlayer();
	void move(float dt);
	void jump();

	float speed;
	gef::Vector4 velocity;
	float timer;
};