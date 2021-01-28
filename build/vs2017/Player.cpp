#include"Player.h"


//////////////////////////////////////////////////////////////////////////

Player::Player(gef::Vector4 position, float width,  float height)
{
	position_ = position;
	width_ = width;
	height_ = height;
	speed = 0.5;
	velocity = gef::Vector4(0, 0, 0);
	timer = 0;
}

Player::~Player()
{

}

//////////////////////////////////////////////////////////////////////////

void Player::handleInput(float dt)
{

}

//////////////////////////////////////////////////////////////////////////

void Player::update(float dt)
{
	timer += dt;

	if (timer > 0.5)
	{
		int randXPos = rand() % 880 + 40;		// Random num between 40-920
		int randYPos = rand() % 464 + 40;		// Random num between 40-504

		int randColValue1 = rand() % 255;
		int randColValue2 = rand() % 255;
		int randColValue3 = rand() % 255;
		int randAlphaValue = rand() % 255;

		gef::Colour randCol(randColValue1, randColValue2, randColValue3, randAlphaValue);

		set_colour(randCol.GetRGBA());

		timer = 0;
	}

	rotation_ += (dt * speed);
	move(dt);
}

//////////////////////////////////////////////////////////////////////////

void Player::render(gef::SpriteRenderer* sprite_renderer)
{
	sprite_renderer->DrawSprite(*this);
}

//////////////////////////////////////////////////////////////////////////

void Player::initPlayer()
{

}

//////////////////////////////////////////////////////////////////////////

void Player::move(float dt)
{
	position_ += velocity * dt;
}

//////////////////////////////////////////////////////////////////////////

void Player::jump()
{

}



////////////////////////// GETTERS AND SETTERS ///////////////////////////

void Player::setSpeed(float newSpeed)
{
	speed = newSpeed;
}

//////////////////////////////////////////////////////////////////////////

void Player::setVelocity(gef::Vector4 direction, float speed)
{
	velocity = direction * speed;
}