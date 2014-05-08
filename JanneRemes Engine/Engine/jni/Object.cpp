#include <Object.h>
using namespace KaMo;

Object::Object()
{
	name = "Unnamed";
}

Object::~Object()
{
	
}

Object::Object(const Object& object)
{}

Object Object::Instantiate(const Object& prefab)
{
	return Object(prefab);
}

std::string Object::ToString()
{
	return name;
}

