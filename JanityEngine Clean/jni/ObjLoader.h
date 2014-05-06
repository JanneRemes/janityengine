#pragma once
#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
//#include <Win32toAndroid.h>
#include <Debug.h>

#include <glm\glm.hpp>

namespace Janity {
	class ObjLoader
	{
	public:
		ObjLoader();
		~ObjLoader();

		bool LoadOBJ(const char* path, std::vector<glm::vec3> & out_vertices,
									   std::vector<glm::vec2> & out_uvs,
									   std::vector<glm::vec3> & out_normals
									   );

	private:
		ObjLoader(ObjLoader&);

		void OpenFile(const char* path);
		void ParseData();
		void AddVertices(const size_t bufferIndex);
		void AddUvs(const size_t bufferIndex);
		void AddNormals(const size_t bufferIndex);
		void AddIndices(const size_t bufferIndex);
		
		std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
		std::vector<glm::vec3> temp_vertices;
		std::vector<glm::vec2> temp_uvs;
		std::vector<glm::vec3> temp_normals;

		long lenght;
		char *buff;

		std::vector<std::string> _tokens;
	};
}
#endif