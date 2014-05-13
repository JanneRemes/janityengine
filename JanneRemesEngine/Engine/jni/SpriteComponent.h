
#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H
#include <Sprite.h>



namespace JanityEngine
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