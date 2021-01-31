#ifndef _sprite_app_H
#define _sprite_app_H

#include <system/application.h>
#include <graphics/sprite.h>
#include <maths/vector4.h>
#include <vector>
#include <Player.h>
#include <system/platform.h>
#include <graphics/sprite_renderer.h>
#include <graphics/font.h>
#include <maths/math_utils.h>

// FRAMEWORK FORWARD DECLARATIONS
namespace gef
{
	class Platform;
	class SpriteRenderer;
	class Font;
}

class SpriteApp : public gef::Application
{
public:
	SpriteApp(gef::Platform& platform);
	void Init();
	void CleanUp();
	bool Update(float frame_time);
	void Render();
	
private:
	void InitFont();
	//gef::Sprite* initSprite(float xPos, float yPos, float zPos, float width, float height);
	void initPlayer();
	void CleanUpFont();
	void DrawHUD();

	gef::SpriteRenderer* sprite_renderer_;
	gef::Font* font_;

	float fps_;
	float x_speed, y_speed, z_speed;
	float timer;
	float totalTime;
	

	//Player* myPlayer_1;
	//Player* myPlayer_2;

	//Player* players[10];
	std::vector<Player*> players;
};

#endif // _sprite_app_H
