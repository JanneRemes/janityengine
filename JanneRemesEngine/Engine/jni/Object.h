#pragma once
#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
namespace JanityEngine
{
	class Object
	{
	public:
		Object();
		Object(std::string name);
		~Object();
		Object(const Object& object);
		Object Instantiate(const Object& prefab);
		std::string name;
		std::string ToString();
		



	};
}



#endif