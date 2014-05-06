#include <Shader.h>
using namespace Janity;
Shader::Shader()
{

}
Shader::~Shader()
{

}

// PUBLIC

GLuint Shader::CreateShader(const char* fragPath, const char* vertPath)
{
	GLuint PS = ReadShaderFile(fragPath, GL_FRAGMENT_SHADER);
	GLuint VS = ReadShaderFile(vertPath, GL_VERTEX_SHADER);

	GLuint Program = CreateProgram(VS, PS);

	//finalize shader 
	FrmLinkShaderProgram(Program );

	return Program;
}


// PRIVATE

GLuint Shader::ReadShaderFile(const char* path, GLenum type)
{
	long lenght;
	char *buffer;

	FileReader *FR = new FileReader(path);
	lenght = FR->FileLength();
	buffer = (char*) malloc(lenght+1);
	FR->ReadBytes(lenght, buffer);
	delete FR;
	buffer[lenght] = 0;

	#ifndef WINDOWS_FRAMEWORK
	LOGE("%lu", lenght);
	#endif
		GLuint shader = LoadShader(type,buffer);

	return shader;
}

GLuint Shader::CreateProgram(GLuint VS, GLuint PS)
{
	//make the shader program; 
    GLuint Program = glCreateProgram(); 
  
    //attach shaders to the program 
    glAttachShader(Program,VS); 
    glAttachShader(Program,PS);

	//bind position string to attrib at loc 0 
    glBindAttribLocation(Program,0,"vPosition"); 
	//bind Color string to attrib at loc 1 
	glBindAttribLocation(Program,1,"vUv");
	 
	return Program;
}

GLuint Shader::LoadShader(GLenum shaderType, const char* pSource) {
    GLuint shader = glCreateShader(shaderType);
    if (shader) {
        glShaderSource(shader, 1, &pSource, NULL);
        glCompileShader(shader);
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char* buf = (char*) malloc(infoLen);
                if (buf) {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    #ifndef WINDOWS_FRAMEWORK
                    LOGE("Could not compile shader %d:\n%s\n",
                            shaderType, buf);
                    #else
 
                    #endif
                     
                         
                    free(buf);
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
} 

//--------------------------------------------------------------------------------------
// Name: FrmLinkShaderProgram()
// Desc: Helper function to link a shader program
//--------------------------------------------------------------------------------------
bool Shader::FrmLinkShaderProgram( GLuint Program )
{
    // Link the whole program together
    glLinkProgram( Program );
	Debug::CheckGlError("Link Program");

    // Check for link success
    GLint LinkStatus;
    glGetProgramiv( Program, GL_LINK_STATUS, &LinkStatus );

	#ifndef WINDOWS_FRAMEWORK
	LOGE("%i", LinkStatus);
#endif
    if( LinkStatus == GL_FALSE )
    {		
        char strInfoLog[1024];
        int nLength;
        glGetProgramInfoLog( Program, 1024, &nLength, strInfoLog );
		#ifndef WINDOWS_FRAMEWORK
        Debug::checkGlError("Link Program");
		#endif
        return false;
    }
    return true;
}