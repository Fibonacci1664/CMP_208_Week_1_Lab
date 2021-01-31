#include "sprite_app.h"
#include<maths/math_utils.h>

SpriteApp::SpriteApp(gef::Platform& platform) :
	Application(platform),
	sprite_renderer_(NULL),
	font_(NULL)
{
	timer = 0;
	totalTime = 0;
}

void SpriteApp::Init()
{
	// create a sprite renderer to draw your sprites
	sprite_renderer_ = gef::SpriteRenderer::Create(platform_);

	InitFont();
	initPlayer();
}

void SpriteApp::initPlayer()
{
	// Init single player objects.
	//myPlayer_1 = new Player(gef::Vector4(platform_.width() * 0.5f, platform_.height() * 0.5f, 0.0f), 32.0f, 32.0f);
	//myPlayer_2 = new Player(gef::Vector4(platform_.width() * 0.25f, platform_.height() * 0.25f, 0.0f), 16.0f, 16.0f);

	//myPlayer_1->setVelocity(gef::Vector4(1, 1, 0), 500.0f);
	//myPlayer_2->setVelocity(gef::Vector4(-1, 0, 0), 10.0f);

	/*for (int i = 0; i < 10; ++i)
	{
		players[i] = new Player(gef::Vector4(platform_.width() * 0.5f, platform_.height() * 0.09f * (i + 1), 0.0f), 32.0f, 32.0f);
	}*/

	
	
	for (int i = 0; i < 10; ++i)
	{
		int randXPos = rand() % 880 + 40;		// Random num between 40-920
		int randYPos = rand() % 464 + 40;		// Random num between 40-504
		float randXVel = (float)rand() / RAND_MAX;
		float randYVel = (float)rand() / RAND_MAX;
		float randZVel = (float)rand() / RAND_MAX;
		int randSpeed = rand() % 200 + 100;

		players.push_back(new Player(gef::Vector4(randXPos, randYPos, 0.0f), 32.0f, 32.0f));
		players[i]->set_rotation(0.0f);
		players[i]->setVelocity(gef::Vector4(randXVel, randYVel, randZVel), randSpeed);
	}
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
	
	//totalTime += frame_time;

	//myPlayer_1->update(frame_time);
	//myPlayer_2->update(frame_time);

	// Use with array.
	//for (int i = 0; i < 10; ++i)
	//{
	//	players[i]->update(frame_time);
	//}

	//if (totalTime > 5.0f)
	//{
	//	for (int i = 0; i < players.size(); ++i)
	//	{
	//		delete players[i];
	//		players[i] = nullptr;
	//	}

	//	// Resize vector back to zero so the next for loop doesnt run until there is at least 1 element.
	//	players.resize(0);

	//	totalTime = 0;
	//}

	//Use with vector.
	for (int i = 0; i < players.size(); ++i)
	{
		players[i]->update(frame_time);
	}

	return true;
}

void SpriteApp::Render()
{
	// draw all sprites between the Begin() and End() calls
	sprite_renderer_->Begin();

	//myPlayer_1->render(sprite_renderer_);
	
	//myPlayer_2->render(sprite_renderer_);

	/*for (int i = 0; i < 10; ++i)
	{
		players[i]->render(sprite_renderer_);
	}*/

	for (int i = 0; i < players.size(); ++i)
	{
		players[i]->render(sprite_renderer_);
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
	float degrees = gef::RadToDeg(players[0]->rotation());

	if(font_)
	{
		// display frame rate
		// sprite renderer to draw the letters, position on screen, scale, colour ABGR, justification, string of text to render.
		font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 20.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "FPS: %.1f", fps_);
		font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 50.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "xPos: %.1f", players[0]->position().x());
		font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 80.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "yPos: %.1f", players[0]->position().y());
		font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 110.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "zPos: %.1f", players[0]->position().z());
		font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 140.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "Width: %.1f", players[0]->width());
		font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 170.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "Height: %.1f", players[0]->height());
		font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 200.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "Rotational Angle: % .1f", degrees);

		// any variables used in formatted text string http://www.cplusplus.com/reference/cstdio/printf/
	}

	//float degrees = gef::RadToDeg(myPlayer_1->rotation());

	//if (font_)
	//{
	//	// display frame rate
	//	// sprite renderer to draw the letters, position on screen, scale, colour ABGR, justification, string of text to render.
	//	font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 20.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "FPS: %.1f", fps_);
	//	font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 50.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "xPos: %.1f", myPlayer_1->position().x());
	//	font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 80.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "yPos: %.1f", myPlayer_1->position().y());
	//	font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 110.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "zPos: %.1f", myPlayer_1->position().z());
	//	font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 140.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "Width: %.1f", myPlayer_1->width());
	//	font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 170.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "Height: %.1f", myPlayer_1->height());
	//	font_->RenderText(sprite_renderer_, gef::Vector4(20.0f, 200.0f, -0.9f), 0.6f, 0xffffffff, gef::TJ_LEFT, "Rotational Angle: % .1f", degrees);

	//	// any variables used in formatted text string http://www.cplusplus.com/reference/cstdio/printf/
	//}
}

