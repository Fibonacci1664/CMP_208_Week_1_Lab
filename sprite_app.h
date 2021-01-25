#ifndef _sprite_app_H
#define _sprite_app_H

#include <system/application.h>
#include <graphics/sprite.h>
#include <maths/vector4.h>
#include <vector>

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
	gef::Sprite* initSprite(float xPos, float yPos, float zPos, float width, float height);
	void CleanUpFont();
	void DrawHUD();

	gef::SpriteRenderer* sprite_renderer_;
	gef::Font* font_;

	float fps_;
	float x_speed, y_speed, z_speed;
	float timer;
	float totalTime;

	/*gef::Sprite sprite_1;
	gef::Sprite sprite_2;*/

	//gef::Sprite sprites[10];

	std::vector<gef::Sprite*> spritesV;
};

#endif // _sprite_app_H
