#pragma once
#ifndef SPRITE_H
#define SPRITE_H
#include <Texture.h>
#include <GameObject.h>
#include <Quad.h>

// TODO: texture scale 1 = w*scale, h*scale

namespace Janity
{
	extern struct Transform;
	class Sprite : public Quad
	{	
		
	public:
		Sprite();
		Sprite(Texture* Texture);
		Sprite(Texture* Texture, Transform transform);
		~Sprite();


		void Draw();
	private:
	};
}

#endif