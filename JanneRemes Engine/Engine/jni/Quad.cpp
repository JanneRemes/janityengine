#include <Quad.h>
#include <cmath>

using namespace KaMo;

float* Quad::projection = NULL;

Quad::Quad(int X, int Y, float Z, int W, int H)
{
	x = X;
	y = Y;
	z = Z;
	h = H;
	w = W;

	translation = (float*)calloc(16,sizeof(float));
	rotation = (float*)calloc(16,sizeof(float));
	scale = (float*)calloc(16,sizeof(float));
	glGenBuffers(1, &vbo);
	GenBuffer();
	Move(x, y, z);
	Resize(w,h);
	Rotate(0);
}
void Quad::SetProjection(int desiredWidth, int desiredHeight)
{
	
	GLfloat GLProjection[16] = 
	{
		 1.0f/desiredWidth, 0,	0,	-1
		,0,	1.0f/desiredHeight,	0,	-1
		,0,	0,	1,	0
		,0,	0,	0,	1
	};

	projection = (GLfloat*)malloc(4*4*sizeof(float));
	projection[0] = GLProjection[0];
	projection[1] = GLProjection[1];
	projection[2] = GLProjection[2];
	projection[3] = GLProjection[3];
					
	projection[4] = GLProjection[4];
	projection[5] = GLProjection[5];
	projection[6] = GLProjection[6];
	projection[7] = GLProjection[7];
					
	projection[8] = GLProjection[8];
	projection[9] = GLProjection[9];
	projection[10] = GLProjection[10];
	projection[11] = GLProjection[11];
				 
	projection[12] = GLProjection[12];
	projection[13] = GLProjection[13];
	projection[14] = GLProjection[14];
	projection[15] = GLProjection[15];
	
}
Quad::~Quad()
{

}

void Quad::GenBuffer()
{
	float* Data = (float*)malloc(30*sizeof(float));

  	Data[0] = -0.5f; 
    Data[1] = -0.5f; 
    Data[2] = 0; 

    Data[3] = 0; 
    Data[4] = 0; 


    Data[5] = -0.5f; 
    Data[6] = 0.5f; 
    Data[7] = 0;

    Data[8] = 0; 
    Data[9] = 1; 


    Data[10] = 0.5f; 
    Data[11] = -0.5f; 
	Data[12] = 0; 

    Data[13] = 1; 
    Data[14] = 0; 
    

    Data[15] = -0.5f; 
    Data[16] = 0.5f; 
    Data[17] = 0; 

	Data[18] = 0; 
    Data[19] = 1; 


    Data[20] = 0.5f; 
    Data[21] = 0.5f; 
	Data[22] = 0; 

    Data[23] = 1; 
    Data[24] = 1; 


    Data[25] = 0.5f; 
    Data[26] = -0.5f; 
    Data[27] = 0; 

	Data[28] = 1; 
    Data[29] = 0; 

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER,sizeof(Data)*30,Data,GL_DYNAMIC_DRAW);
	free(Data);
}


void Quad::Move(glm::vec3 Vector3)
{
	Move(Vector3.x, Vector3.y, Vector3.z);
}
void Quad::Move(int X, int Y, float Z)
{
	translation[0] = 1; // x:n scaalaus
	translation[3] = X;
	translation[5] = 1; // y:h scaalaus
	translation[7] = Y;
	translation[10] = 1; // z: scaalaus
	translation[11] = z;
	translation[15] = 1;
	x = X; y = Y; z = Z;
}

void Quad::Resize(int W, int H)
{
	w = W;
	h = H;

	scale[0] = w;
	scale[5] = h;
	scale[10] = 1;
	scale[15] = 1;
}

void Quad::Rotate(float r)
{
	rotation[0] = std::cos(-r);
	rotation[1] = -std::sin(-r);
	rotation[4] = std::sin(-r);
	rotation[5] = std::cos(-r);
	rotation[10] = 1;
	rotation[15] = 1;
}

void Quad::SetTexture(Texture* Texture)
{
	texture = Texture;
	Resize(texture->GetWidth(), texture->GetHeight());	
}

void Quad::SetTexture(const char* Texture)
{
	texture = Texture::Load(Texture);
	Resize(texture->GetWidth(), texture->GetHeight());
}

void Quad::SetProgram(GLuint Program)
{
	program = Program;

	position = glGetAttribLocation(program,"vPosition");
	uv = glGetAttribLocation(program,"vUv");
	loc = glGetUniformLocation(program, "s_texture");
	loc2 = glGetUniformLocation(program, "Projection");
	loc3 = glGetUniformLocation(program, "Translation");
	loc4 = glGetUniformLocation(program, "Rotation");
	loc5 = glGetUniformLocation(program, "Scale");
}

void Quad::Draw()
{
	
	glUseProgram(program);

	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// VBO
	glBindBuffer(GL_ARRAY_BUFFER,vbo); 

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture->GetID());

	glUniform1i(loc, 0); 

    glVertexAttribPointer(position,3,GL_FLOAT,GL_FALSE,5*sizeof(GL_FLOAT),0); 
	glVertexAttribPointer(uv,2,GL_FLOAT,GL_FALSE,5*sizeof(GL_FLOAT),(void*)(sizeof(GL_FLOAT)*3)); 
	
	glEnableVertexAttribArray(position);    
	glEnableVertexAttribArray(uv);

	glUniformMatrix4fv(loc2,1,GL_FALSE,projection);
	glUniformMatrix4fv(loc3,1,GL_FALSE,translation);
	glUniformMatrix4fv(loc4,1,GL_FALSE,rotation);
	glUniformMatrix4fv(loc5,1,GL_FALSE,scale);

	
    glDrawArrays(GL_TRIANGLES,0,6); 

	glDisableVertexAttribArray(position);    
	glDisableVertexAttribArray(uv);  
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}