
#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H
#include <Sprite.h>



namespace KaMo
{
	
	class SpriteComponent : Sprite
	{
	public:
		SpriteComponent();
		SpriteComponent(Texture* texture);
		~SpriteComponent();
		SpriteComponent(const SpriteComponent& spriteComponent);
	};
}
#endif