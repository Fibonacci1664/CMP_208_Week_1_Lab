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
	y_speed = 25.0f;
	z_speed = 0;

}

void SpriteApp::Init()
{
	// create a sprite renderer to draw your sprites
	sprite_renderer_ = gef::SpriteRenderer::Create(platform_);

	InitFont();

	initSprite(&sprite_1, platform_.width() * 0.5f, platform_.height() * 0.5f, 0.0f, 32.0f, 32.0f);
	initSprite(&sprite_2, platform_.width() * 0.75f, platform_.height() * 0.25f, 0.0f, 32.0f, 32.0f);	
}

void SpriteApp::initSprite(gef::Sprite* sprite, float xPos, float yPos, float zPos, float width, float height)
{
	sprite->set_position(xPos, yPos, zPos);
	sprite->set_width(width);
	sprite->set_height(height);
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

	sprite_1.set_position(sprite_1.position() + (gef::Vector4(x_speed * 0.5f, y_speed, z_speed) * frame_time));
	sprite_2.set_position(sprite_2.position() - (gef::Vector4(x_speed * 1.5f, -y_speed, z_speed) * frame_time));

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
	sprite_renderer_->DrawSprite(sprite_1);
	sprite_renderer_->DrawSprite(sprite_2);

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
			"FPS: %.1f Sprite 1 xPos: %.1f \t Sprite 2 xPos: %.1f", fps_, sprite_1.position().x(), sprite_2.position().x()	// string of text to render
			);

		// any variables used in formatted text string http://www.cplusplus.com/reference/cstdio/printf/
	}
}

