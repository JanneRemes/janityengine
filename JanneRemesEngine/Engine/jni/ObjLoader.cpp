#include <ObjLoader.h>

#include <FileReader.h>

using namespace JanityEngine;

ObjLoader::ObjLoader()
{

}

ObjLoader::~ObjLoader()
{

}

bool ObjLoader::LoadOBJ(const char* path, std::vector<Vector3> & out_vertices,
									      std::vector<Vector2> & out_uvs,
									      std::vector<Vector3> & out_normals
									   )
{
	OpenFile(path);
	ParseData();
	
	for(unsigned int i=0; i<vertexIndices.size(); i++)
	{
		unsigned int vertexIndex = vertexIndices[i];
		Vector3 vertex = temp_vertices[vertexIndex-1];
		out_vertices.push_back(vertex);
	}
	
	for(unsigned int i=0; i<uvIndices.size(); i++)
	{
		unsigned int uvIndex = uvIndices[i];
		float x = temp_uvs[uvIndex-1].x;
		float y = temp_uvs[uvIndex-1].y;
		Vector2 uv = Vector2(x,y);//temp_uvs[uvIndex-1]);
		out_uvs.push_back(uv);
	}
	
	
	for(unsigned int i=0; i<normalIndices.size(); i++)
	{
		unsigned int normalIndex = normalIndices[i];
		Vector3 normal = temp_normals[normalIndex-1];
		out_normals.push_back(normal);
	}
	
	return 1;
}

void ObjLoader::OpenFile(const char* path)
{
	FileReader* FR = new FileReader(path);
	lenght = FR->FileLength();
	buff = (char*) malloc(lenght+1);
	FR->ReadBytes(lenght, buff);
	delete FR;
}

void ObjLoader::ParseData()
{
	char character;
	std::string token;
	for(size_t i = 0; i<lenght; i++)
	{
		character = (char)buff[i];
		switch(character)
		{
		case '\t':
		case '\n':
		case '\r':
		case ' ':
		case '/':
			if(!token.empty())
			{
				_tokens.push_back(token);
				token = std::string();
			}
			break;
		case '#':
			//while(character != '\n')
				character = (char)buff[i];

			break;
		default:
			token.push_back(character);
			break;
		}
	}

	if(!token.empty())
		_tokens.push_back(token);

	for(size_t i = 0; i< _tokens.size(); ++i)
	{
		if(_tokens[i] == "v")
		{
			AddVertices(i);
			i += 3;
		}
		else if(_tokens[i] == "vt")
		{
			AddUvs(i);
			i += 2;
		}
		else if(_tokens[i] == "vn")
		{
			AddNormals(i);
			i += 3;
		}
		else if(_tokens[i] == "f")
		{
			AddIndices(i);
			i += 9;
		}
	}	
}

void ObjLoader::AddVertices(const size_t bufferIndex)
{
	Vector3 vertex;
	vertex.x = (float)atof(_tokens[bufferIndex+1].c_str());
	vertex.y = (float)atof(_tokens[bufferIndex+2].c_str());
	vertex.z = (float)atof(_tokens[bufferIndex+3].c_str());
	temp_vertices.push_back(vertex);
}

void ObjLoader::AddUvs(const size_t bufferIndex)
{
	Vector2 uv;
	uv.x = (float)atof(_tokens[bufferIndex+1].c_str());
	uv.y = (float)atof(_tokens[bufferIndex+2].c_str());
	temp_uvs.push_back(uv);
}

void ObjLoader::AddNormals(const size_t bufferIndex)
{
	Vector3 normal;
	normal.x = (float)atof(_tokens[bufferIndex+1].c_str());
	normal.y = (float)atof(_tokens[bufferIndex+2].c_str());
	normal.z = (float)atof(_tokens[bufferIndex+3].c_str());
	temp_normals.push_back(normal);
}

void ObjLoader::AddIndices(const size_t bufferIndex)
{
	unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];

	vertexIndex[0]	= (int)atof(_tokens[bufferIndex+1].c_str());
	uvIndex[0]		= (int)atof(_tokens[bufferIndex+2].c_str());
	normalIndex[0]	= (int)atof(_tokens[bufferIndex+3].c_str());
	vertexIndex[1]	= (int)atof(_tokens[bufferIndex+4].c_str());
	uvIndex[1]		= (int)atof(_tokens[bufferIndex+5].c_str());
	normalIndex[1]	= (int)atof(_tokens[bufferIndex+6].c_str());
	vertexIndex[2]	= (int)atof(_tokens[bufferIndex+7].c_str());
	uvIndex[2]		= (int)atof(_tokens[bufferIndex+8].c_str());
	normalIndex[2]	= (int)atof(_tokens[bufferIndex+9].c_str());

	vertexIndices.push_back(vertexIndex[0]);
	vertexIndices.push_back(vertexIndex[1]);
	vertexIndices.push_back(vertexIndex[2]);
	uvIndices	 .push_back(uvIndex[0]);
	uvIndices	 .push_back(uvIndex[1]);
	uvIndices	 .push_back(uvIndex[2]);
	normalIndices.push_back(normalIndex[0]);
	normalIndices.push_back(normalIndex[1]);
	normalIndices.push_back(normalIndex[2]);
}
