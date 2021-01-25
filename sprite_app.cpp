#include "sprite_app.h"
#include <system/platform.h>
#include <graphics/sprite_renderer.h>
#include <graphics/font.h>
#include <maths/math_utils.h>


SpriteApp::SpriteApp(gef::Platform& platform) :
	Application(platform),
	sprite_renderer_(NULL),
	font_(NULL)
{
	x_speed = 50.0f;
	y_speed = 0;
	z_speed = 0;
	timer = 0.0f;
}

void SpriteApp::Init()
{
	// create a sprite renderer to draw your sprites
	sprite_renderer_ = gef::SpriteRenderer::Create(platform_);

	InitFont();

	/*initSprite(&sprite_1, platform_.width() * 0.5f, platform_.height() * 0.5f, 0.0f, 32.0f, 32.0f);
	initSprite(&sprite_2, platform_.width() * 0.75f, platform_.height() * 0.25f, 0.0f, 32.0f, 32.0f);*/

	/*for (int i = 0; i < 10; ++i)
	{
		sprites[i] = initSprite(platform_.width() * 0.5f, platform_.height() * 0.09f * (i + 1), 0.0f, 32.0f, 32.0f);
	}*/

	//for (int i = 0; i < 10; ++i)
	//{
	//	float randXPos = rand() % 920 + 40;		// Random num between 40-920
	//	float randYPos = rand() % 504 + 40;		// Random num between 40-504

	//	spritesV.push_back(initSprite(randXPos, randYPos, 0.0f, 32.0f, 32.0f));
	//}

	// Draw the first sprite.
	float randXPos = rand() % 920 + 40;		// Random num between 40-920
	float randYPos = rand() % 504 + 40;		// Random num between 40-504

	spritesV.push_back(initSprite(randXPos, randYPos, 0.0f, 32.0f, 32.0f));
}

gef::Sprite SpriteApp::initSprite(float xPos, float yPos, float zPos, float width, float height)
{
	gef::Sprite sprite;

	sprite.set_position(xPos, yPos, zPos);
	sprite.set_width(width);
	sprite.set_height(height);

	return sprite;
}

void SpriteApp::CleanUp()
{
	CleanUpFont();

	// destroy sprite renderer once you've finished using it
	delete sprite_renderer_;
	sprite_renderer_ = NULL;
}

bool SpriteApp::Update(float frame_time)
{
	// frame rate = 1 second / frame_delta_time
	fps_ = 1.0f / frame_time;

	// move the sprite along the x-axis

	// get a copy of the current position of the sprite
	//gef::Vector4 sprite_position = my_sprite_.position();

	//sprite_1.set_position(sprite_1.position() + (gef::Vector4(x_speed * 0.5f, y_speed, z_speed) * frame_time));
	//sprite_2.set_position(sprite_2.position() - (gef::Vector4(x_speed * 1.5f, -y_speed, z_speed) * frame_time));

	/*for (int i = 0; i < 10; ++i)
	{
		sprites[i].set_position(sprites[i].position() + (gef::Vector4(x_speed * 0.5f, y_speed, z_speed) * frame_time));
	}*/
	
	float randXPos = rand() % 880 + 40;		// Random num between 40-920
	float randYPos = rand() % 464 + 40;		// Random num between 40-504

	timer += frame_time;

	if (timer > 0.5f)
	{
		spritesV.push_back(initSprite(randXPos, randYPos, 0.0f, 32.0f, 32.0f));
		timer = 0.0f;
	}


	/*for (int i = 0; i < 10; ++i)
	{
		timer += frame_time;

		if (timer > 0.5f)
		{
			spritesV[i].set_position(spritesV[i].position() + (gef::Vector4(x_speed * 0.5f, y_speed, z_speed) * frame_time));
			timer = 0.0f;
		}	
	}*/


	// update the x-axis on the COPY of the current position
	//sprite_position.set_x(sprite_position.x() + 1);

	// update the sprite with the new position
	//my_sprite_.set_position(sprite_position);

	return true;
}

void SpriteApp::Render()
{
	// draw all sprites between the Begin() and End() calls
	sprite_renderer_->Begin();

	// draw my sprite here
	/*sprite_renderer_->DrawSprite(sprite_1);
	sprite_renderer_->DrawSprite(sprite_2);*/

	/*for (int i = 0; i < 10; ++i)
	{
		sprite_renderer_->DrawSprite(sprites[i]);
	}*/

	for (int i = 0; i < spritesV.size(); ++i)
	{
		sprite_renderer_->DrawSprite(spritesV[i]);
	}

	DrawHUD();
	sprite_renderer_->End();
}


void SpriteApp::InitFont()
{
	// create a Font object and load in the comic_sans font data
	font_ = new gef::Font(platform_);
	font_->Load("comic_sans");
}

void SpriteApp::CleanUpFont()
{
	// destroy the Font object
	delete font_;
	font_ = NULL;
}

void SpriteApp::DrawHUD()
{
	if(font_)
	{
		// display frame rate
		font_->RenderText(
			sprite_renderer_,										// sprite renderer to draw the letters
			gef::Vector4(50.0f, 510.0f, -0.9f),						// position on screen
			1.0f,													// scale
			0xffffffff,												// colour ABGR
			gef::TJ_LEFT,											// justification
			"FPS: %.1f Sprite 1 xPos: %.1f", fps_, spritesV[0].position().x()	// string of text to render
			);
		
		// any variables used in formatted text string http://www.cplusplus.com/reference/cstdio/printf/
	}
}

