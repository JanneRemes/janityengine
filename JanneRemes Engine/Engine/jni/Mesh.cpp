#include <Mesh.h>
#include <cmath>
#include <Debug.h>
#include <Camera.h>

using namespace Janity;

Mesh::Mesh(int X, int Y, int Z, float scale, const char* objPath)
{
	x = X;
	y = Y;
	z = Z;

	LoadObj(objPath);
	Debug::CheckGlError("load obj: ");
	HandleData();
	GenBuffer();
	Move(x, y, z);
	Resize(scale, scale, scale);
	Rotate(0, 1,1,1);
	
	model = glm::mat4(1.0f);
}
Mesh::Mesh(int Size, float* _data)
{
	x = 0;
	y = 0;
	z = 0;

	Data = (float*)malloc(Size*sizeof(float)*8);

	Debug::WriteLog("_data mesh: %d\n", _data);
	//Data = _data;
	Debug::WriteLog("Data mesh: %d\n", Data);

	_size = Size;

	int j=0;
	for(int i=0; i<_size;i++)
	{
		Data[j+0] = _data[j+0];
		Data[j+1] = _data[j+1];
		Data[j+2] = _data[j+2];
		Data[j+3] = _data[j+3];
		Data[j+4] = _data[j+4];
		Data[j+5] = _data[j+5];
		Data[j+6] = _data[j+6];
		Data[j+7] = _data[j+7];
		Data[j+8] = _data[j+8];


		Debug::WriteLog("_data: %f - Data: %f\n",_data[j+0], Data[j+0]);
		Debug::WriteLog("_data: %f - Data: %f\n",_data[j+1], Data[j+1]);
		Debug::WriteLog("_data: %f - Data: %f\n",_data[j+2], Data[j+2]);
		Debug::WriteLog("_data: %f - Data: %f\n",_data[j+3], Data[j+3]);
		Debug::WriteLog("_data: %f - Data: %f\n",_data[j+4], Data[j+4]);
		Debug::WriteLog("_data: %f - Data: %f\n",_data[j+5], Data[j+5]);
		Debug::WriteLog("_data: %f - Data: %f\n",_data[j+6], Data[j+6]);
		Debug::WriteLog("_data: %f - Data: %f\n",_data[j+7], Data[j+7]);
		j=j+8;
		//Sleep(1000);
	}


	GenBuffer();

	Move(x, y, z);
	Resize(0.1f,0.1f,0.1f);
	Rotate(0, 1,1,1);

	model = glm::mat4(1.0f);
}
Mesh::Mesh(std::vector<glm::vec3> _vertices, std::vector<glm::vec2> _uvs, std::vector<glm::vec3> _normals)
{
	x = 0;
	y = 0;
	z = 0;

	vertices = _vertices;
	uvs = _uvs;
	normals = _normals;

	HandleData();
	GenBuffer();

	Move(x, y, z);
	Resize(0.1f, 0.1f, 0.1f);
	Rotate(0,1,1,1);

	model = glm::mat4(1.0f);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &vbo);
	free(Data);
}

// PRIVATE
void Mesh::LoadObj(const char* _objPath)
{
	obj = new ObjLoader();
	bool a = obj->LoadOBJ(_objPath, vertices, uvs, normals);
	assert(a==1);
	delete obj;
}
void Mesh::HandleData()
{
	Data = (float*)malloc(vertices.size()*sizeof(float)*8);

	int j = 0;
	for(int i = 0; i < vertices.size(); i++)
	{
		Data[j] = vertices[i][0];
		Data[j+1] = vertices[i][1];
		Data[j+2] = vertices[i][2];

		Data[j+3] = uvs[i][0];
		Data[j+4] = uvs[i][1];

		Data[j+5] = normals[i][0];
		Data[j+6] = normals[i][1];
		Data[j+7] = normals[i][2];
		

		//Debug::WriteLog("Data mesh hanska: %f\n", Data[j+0]);
		//Debug::WriteLog("Data mesh hanska: %f\n", Data[j+1]);
		//Debug::WriteLog("Data mesh hanska: %f\n", Data[j+2]);
		//Debug::WriteLog("Data mesh hanska: %f\n", Data[j+3]);
		//Debug::WriteLog("Data mesh hanska: %f\n", Data[j+4]);
		//Debug::WriteLog("Data mesh hanska: %f\n", Data[j+5]);
		//Debug::WriteLog("Data mesh hanska: %f\n", Data[j+6]);
		//Debug::WriteLog("Data mesh hanska: %f\n", Data[j+7]);
		//Sleep(1000);

		j = j+8;
	}
	_size = vertices.size();
}
void Mesh::GenBuffer()
{
	glGenBuffers(1, &vbo);
		Debug::CheckGlError("glGenBuffers: ");
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
		Debug::CheckGlError("glBindBuffer: ");
	glBufferData(GL_ARRAY_BUFFER,_size*sizeof(float)*8,Data,GL_DYNAMIC_DRAW);
		Debug::CheckGlError("glBufferData: ");
}


// PUBLIC
void Mesh::Move(float X, float Y, float Z)
{
	x = X; y = Y; z = Z;
	translation = glm::translate(glm::vec3(x, y, z));
}

void Mesh::Move(glm::vec3 vec3)
{
	translation = glm::translate(vec3);
}

void Mesh::Resize(float W, float H, float D)
{
	scale = glm::scale(W, H, D);
}

void Mesh::Rotate(float r, int X, int Y, int Z)
{
	int rX, rY, rZ;
	rX = X;
	rY = Y;
	rZ = Z;
	rotation = glm::rotate(r, glm::vec3(rX,rY,rZ));
}

void Mesh::SetTexture(const char* Texture)
{
	texture = Texture::Load(Texture);
}

void Mesh::SetProgram(GLuint program)
{
	this->program = program;

	position = glGetAttribLocation(program,"vPosition");
	uv = glGetAttribLocation(program,"vUv");
	loc = glGetUniformLocation(program, "s_texture");
	loc2 = glGetUniformLocation(program, "Projection");
	loc3 = glGetUniformLocation(program, "Translation");
	loc4 = glGetUniformLocation(program, "Rotation");
	loc5 = glGetUniformLocation(program, "Scale");
								
	loc6 = glGetUniformLocation(program, "View");
	loc7 = glGetUniformLocation(program, "Model");
}

void Mesh::SetProjection(int desiredWidth, int desiredHeight)
{ 
	float dW = desiredWidth;
	float dH = desiredHeight;

	projection = Camera::GetProjMat(45.0f, dW/dH, 0.1f, 1000.0f);
}

void Mesh::Draw()
{
	view = Camera::GetViewMat();
	model = translation * rotation * scale;

	glUseProgram(program);

	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// VBO
	glBindBuffer(GL_ARRAY_BUFFER, vbo); 

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture->GetID());

	glUniform1i(loc, 0); 

    glVertexAttribPointer(position,3,GL_FLOAT,GL_FALSE,8*sizeof(GL_FLOAT),0); 
	glVertexAttribPointer(uv,2,GL_FLOAT,GL_FALSE,8*sizeof(GL_FLOAT),(void*)(sizeof(GL_FLOAT)*3)); 

	glEnableVertexAttribArray(position); 
	glEnableVertexAttribArray(uv);


	glUniformMatrix4fv(loc2,1,GL_FALSE,&projection[0][0]);
	glUniformMatrix4fv(loc6,1,GL_FALSE,&view[0][0]);
	glUniformMatrix4fv(loc7,1,GL_FALSE,&model[0][0]);

	glDrawArrays(GL_TRIANGLES,0,vertices.size()); 

	glDisableVertexAttribArray(position);    
	glDisableVertexAttribArray(uv); 

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
}