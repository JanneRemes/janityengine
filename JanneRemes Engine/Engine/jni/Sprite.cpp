#include <Sprite.h>
using namespace JanityEngine;

Sprite::Sprite() 
	: Quad(0,0,0,32,32) 	
{
	Quad::SetTexture("TextureError.tga");
}
Sprite::Sprite(Texture* Texture) : Quad(0,0,0, 32,32)
{
	Quad::SetTexture(Texture);
}
Sprite::Sprite(Texture* Texture, ::Transform Transform) 
	: 	Quad(Transform.position.x,Transform.position.y, Transform.position.z,0,0)
{
	Quad::SetTexture(Texture);
	Quad::Resize(Transform.scale.x, Transform.scale.y);
}

Sprite::~Sprite()
{
}

void Sprite::Draw()
{
	Quad::Draw();
}

