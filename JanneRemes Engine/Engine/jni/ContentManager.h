#pragma once
#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include <Shader.h>
#include <Texture.h>
#include <Quad.h>

namespace KaMo
{
	class ContentManager
	{
	public:
		ContentManager();
		~ContentManager();
	private:
		ContentManager(const ContentManager& contentManager);
	};

}
#endif