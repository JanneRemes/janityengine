/**
 * @file
 * OpenGL.h
 *
 * OpenGL 2.1 function declarations
 */

#ifndef OPENGL_H
#define OPENGL_H

#include <Windows.h>
#include <GL/GL.h>
#include <GL/glext.h>

void LoadOpenGLFunctions();

extern PFNGLACTIVETEXTUREPROC				glActiveTexture;
extern PFNGLATTACHSHADERPROC				glAttachShader;

extern PFNGLBEGINQUERYPROC					glBeginQuery;
extern PFNGLBINDATTRIBLOCATIONPROC			glBindAttribLocation;
extern PFNGLBINDBUFFERPROC					glBindBuffer;
extern PFNGLBLENDCOLORPROC					glBlendColor;
extern PFNGLBLENDEQUATIONPROC				glBlendEquation;
extern PFNGLBLENDEQUATIONSEPARATEPROC		glBlendEquationSeparate;
extern PFNGLBLENDFUNCSEPARATEPROC			glBlendFuncSeparate;
extern PFNGLBUFFERDATAPROC					glBufferData;
extern PFNGLBUFFERSUBDATAPROC				glBufferSubData;

extern PFNGLCLIENTACTIVETEXTUREPROC			glClientActiveTexture;
extern PFNGLCOLORSUBTABLEPROC				glColorSubTable;
extern PFNGLCOLORTABLEPROC					glColorTable;
extern PFNGLCOLORTABLEPARAMETERFVPROC		glColorTableParameterfv;
extern PFNGLCOLORTABLEPARAMETERIVPROC		glColorTableParameteriv;
extern PFNGLCOMPILESHADERPROC				glCompileShader;
extern PFNGLCOMPRESSEDTEXIMAGE1DPROC		glCompressedTexImage1D;
extern PFNGLCOMPRESSEDTEXIMAGE2DPROC		glCompressedTexImage2D;
extern PFNGLCOMPRESSEDTEXIMAGE3DPROC		glCompressedTexImage3D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC		glCompressedTexSubImage1D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC		glCompressedTexSubImage2D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC		glCompressedTexSubImage3D;
extern PFNGLCONVOLUTIONFILTER1DPROC			glConvolutionFilter1D;
extern PFNGLCONVOLUTIONFILTER2DPROC			glConvolutionFilter2D;
extern PFNGLCONVOLUTIONPARAMETERFPROC		glConvolutionParameterf;
extern PFNGLCONVOLUTIONPARAMETERFVPROC		glConvolutionParameterfv;
extern PFNGLCONVOLUTIONPARAMETERIPROC		glConvolutionParameteri;
extern PFNGLCONVOLUTIONPARAMETERIVPROC		glConvolutionParameteriv;
extern PFNGLCOPYCOLORSUBTABLEPROC			glCopyColorSubTable;
extern PFNGLCOPYCOLORTABLEPROC				glCopyColorTable;
extern PFNGLCOPYCONVOLUTIONFILTER1DPROC		glCopyConvolutionFilter1D;
extern PFNGLCOPYCONVOLUTIONFILTER2DPROC		glCopyConvolutionFilter2D;
extern PFNGLCOPYTEXSUBIMAGE3DPROC			glCopyTexSubImage3D;
extern PFNGLCREATEPROGRAMPROC				glCreateProgram;
extern PFNGLCREATESHADERPROC				glCreateShader;

extern PFNGLDELETEBUFFERSPROC				glDeleteBuffers;
extern PFNGLDELETEPROGRAMPROC				glDeleteProgram;
extern PFNGLDELETEQUERIESPROC				glDeleteQueries;
extern PFNGLDELETESHADERPROC				glDeleteShader;
extern PFNGLDETACHSHADERPROC				glDetachShader;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC	glDisableVertexAttribArray;
extern PFNGLDRAWBUFFERSPROC					glDrawBuffers;
extern PFNGLDRAWRANGEELEMENTSPROC			glDrawRangeElements;

extern PFNGLENABLEVERTEXATTRIBARRAYPROC		glEnableVertexAttribArray;
extern PFNGLENDQUERYPROC					glEndQuery;

extern PFNGLFOGCOORDFPROC					glFogCoordf;
extern PFNGLFOGCOORDFVPROC					glFogCoordfv;
extern PFNGLFOGCOORDDPROC					glFogCoordd;
extern PFNGLFOGCOORDDVPROC					glFogCoorddv;
extern PFNGLFOGCOORDPOINTERPROC				glFogCoordPointer;

extern PFNGLGENBUFFERSPROC					glGenBuffers;
extern PFNGLGENQUERIESPROC					glGenQueries;
extern PFNGLGETACTIVEATTRIBPROC				glGetActiveAttrib;
extern PFNGLGETACTIVEUNIFORMPROC			glGetActiveUniform;
extern PFNGLGETATTACHEDSHADERSPROC			glGetAttachedShaders;
extern PFNGLGETATTRIBLOCATIONPROC			glGetAttribLocation;
extern PFNGLGETBUFFERPARAMETERIVPROC		glGetBufferParameteriv;
extern PFNGLGETBUFFERPOINTERVPROC			glGetBufferPointerv;
extern PFNGLGETBUFFERSUBDATAPROC			glGetBufferSubData;

extern PFNGLGETCOLORTABLEPROC				glGetColorTable;
extern PFNGLGETCOLORTABLEPARAMETERFVPROC	glGetColorTableParameterfv;
extern PFNGLGETCOLORTABLEPARAMETERIVPROC	glGetColorTableParameteriv;
extern PFNGLGETCOMPRESSEDTEXIMAGEPROC		glGetCompressedTexImage;
extern PFNGLGETCONVOLUTIONFILTERPROC		glGetConvolutionFilter;
extern PFNGLGETCONVOLUTIONPARAMETERFVPROC	glGetConvolutionParameterfv;
extern PFNGLGETCONVOLUTIONPARAMETERIVPROC	glGetConvolutionParameteriv;
extern PFNGLGETHISTOGRAMPROC				glGetHistogram;
extern PFNGLGETHISTOGRAMPARAMETERFVPROC		glGetHistogramParameterfv;
extern PFNGLGETHISTOGRAMPARAMETERIVPROC		glGetHistogramParameteriv;
extern PFNGLGETMINMAXPROC					glGetMinmax;
extern PFNGLGETMINMAXPARAMETERFVPROC		glGetMinmaxParameterfv;
extern PFNGLGETMINMAXPARAMETERIVPROC		glGetMinmaxParameteriv;
extern PFNGLGETPROGRAMIVPROC				glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC			glGetProgramInfoLog;
extern PFNGLGETQUERYIVPROC					glGetQueryiv;
extern PFNGLGETQUERYOBJECTIVPROC			glGetQueryObjectiv;
extern PFNGLGETQUERYOBJECTUIVPROC			glGetQueryObjectuiv;
extern PFNGLGETSEPARABLEFILTERPROC			glGetSeparableFilter;
extern PFNGLGETSHADERIVPROC					glGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC			glGetShaderInfoLog;
extern PFNGLGETSHADERPRECISIONFORMATPROC	glGetShaderPrecisionFormat;
extern PFNGLGETSHADERSOURCEPROC				glGetShaderSource;
extern PFNGLGETUNIFORMFVPROC				glGetUniformfv;
extern PFNGLGETUNIFORMIVPROC				glGetUniformiv;
extern PFNGLGETUNIFORMLOCATIONPROC			glGetUniformLocation;
extern PFNGLGETVERTEXATTRIBDVPROC			glGetVertexAttribdv;
extern PFNGLGETVERTEXATTRIBFVPROC			glGetVertexAttribfv;
extern PFNGLGETVERTEXATTRIBIVPROC			glGetVertexAttribiv;
extern PFNGLGETVERTEXATTRIBPOINTERVPROC		glGetVertexAttribPointerv;

extern PFNGLHISTOGRAMPROC					glHistogram;

extern PFNGLISBUFFERPROC					glIsBuffer;
extern PFNGLISPROGRAMPROC					glIsProgram;
extern PFNGLISQUERYPROC						glIsQuery;
extern PFNGLISSHADERPROC					glIsShader;

extern PFNGLLINKPROGRAMPROC					glLinkProgram;
extern PFNGLLOADTRANSPOSEMATRIXDPROC		glLoadTransposeMatrixd;
extern PFNGLLOADTRANSPOSEMATRIXFPROC		glLoadTransposeMatrixf;

extern PFNGLMAPBUFFERPROC					glMapBuffer;
extern PFNGLMINMAXPROC						glMinmax;
extern PFNGLMULTTRANSPOSEMATRIXDPROC		glMultTransposeMatrixd;
extern PFNGLMULTTRANSPOSEMATRIXFPROC		glMultTransposeMatrixf;
extern PFNGLMULTIDRAWARRAYSPROC				glMultiDrawArrays;
extern PFNGLMULTIDRAWELEMENTSPROC			glMultiDrawElements;
extern PFNGLMULTITEXCOORD1DPROC				glMultiTexCoord1d;
extern PFNGLMULTITEXCOORD1DVPROC			glMultiTexCoord1dv;
extern PFNGLMULTITEXCOORD1FPROC				glMultiTexCoord1f;
extern PFNGLMULTITEXCOORD1FVPROC			glMultiTexCoord1fv;
extern PFNGLMULTITEXCOORD1IPROC				glMultiTexCoord1i;
extern PFNGLMULTITEXCOORD1IVPROC			glMultiTexCoord1iv;
extern PFNGLMULTITEXCOORD1SPROC				glMultiTexCoord1s;
extern PFNGLMULTITEXCOORD1SVPROC			glMultiTexCoord1sv;
extern PFNGLMULTITEXCOORD2DPROC				glMultiTexCoord2d;
extern PFNGLMULTITEXCOORD2DVPROC			glMultiTexCoord2dv;
extern PFNGLMULTITEXCOORD2FPROC				glMultiTexCoord2f;
extern PFNGLMULTITEXCOORD2FVPROC			glMultiTexCoord2fv;
extern PFNGLMULTITEXCOORD2IPROC				glMultiTexCoord2i;
extern PFNGLMULTITEXCOORD2IVPROC			glMultiTexCoord2iv;
extern PFNGLMULTITEXCOORD2SPROC				glMultiTexCoord2s;
extern PFNGLMULTITEXCOORD2SVPROC			glMultiTexCoord2sv;
extern PFNGLMULTITEXCOORD3DPROC				glMultiTexCoord3d;
extern PFNGLMULTITEXCOORD3DVPROC			glMultiTexCoord3dv;
extern PFNGLMULTITEXCOORD3FPROC				glMultiTexCoord3f;
extern PFNGLMULTITEXCOORD3FVPROC			glMultiTexCoord3fv;
extern PFNGLMULTITEXCOORD3IPROC				glMultiTexCoord3i;
extern PFNGLMULTITEXCOORD3IVPROC			glMultiTexCoord3iv;
extern PFNGLMULTITEXCOORD3SPROC				glMultiTexCoord3s;
extern PFNGLMULTITEXCOORD3SVPROC			glMultiTexCoord3sv;
extern PFNGLMULTITEXCOORD4DPROC				glMultiTexCoord4d;
extern PFNGLMULTITEXCOORD4DVPROC			glMultiTexCoord4dv;
extern PFNGLMULTITEXCOORD4FPROC				glMultiTexCoord4f;
extern PFNGLMULTITEXCOORD4FVPROC			glMultiTexCoord4fv;
extern PFNGLMULTITEXCOORD4IPROC				glMultiTexCoord4i;
extern PFNGLMULTITEXCOORD4IVPROC			glMultiTexCoord4iv;
extern PFNGLMULTITEXCOORD4SPROC				glMultiTexCoord4s;
extern PFNGLMULTITEXCOORD4SVPROC			glMultiTexCoord4sv;

extern PFNGLPOINTPARAMETERFPROC				glPointParameterf;
extern PFNGLPOINTPARAMETERFVPROC			glPointParameterfv;
extern PFNGLPOINTPARAMETERIPROC				glPointParameteri;
extern PFNGLPOINTPARAMETERIVPROC			glPointParameteriv;

extern PFNGLRESETHISTOGRAMPROC				glResetHistogram;
extern PFNGLRESETMINMAXPROC					glResetMinmax;

extern PFNGLSAMPLECOVERAGEPROC				glSampleCoverage;
extern PFNGLSECONDARYCOLOR3BPROC			glSecondaryColor3b;
extern PFNGLSECONDARYCOLOR3BVPROC			glSecondaryColor3bv;
extern PFNGLSECONDARYCOLOR3DPROC			glSecondaryColor3d;
extern PFNGLSECONDARYCOLOR3DVPROC			glSecondaryColor3dv;
extern PFNGLSECONDARYCOLOR3FPROC			glSecondaryColor3f;
extern PFNGLSECONDARYCOLOR3FVPROC			glSecondaryColor3fv;
extern PFNGLSECONDARYCOLOR3IPROC			glSecondaryColor3i;
extern PFNGLSECONDARYCOLOR3IVPROC			glSecondaryColor3iv;
extern PFNGLSECONDARYCOLOR3SPROC			glSecondaryColor3s;
extern PFNGLSECONDARYCOLOR3SVPROC			glSecondaryColor3sv;
extern PFNGLSECONDARYCOLOR3UBPROC			glSecondaryColor3ub;
extern PFNGLSECONDARYCOLOR3UBVPROC			glSecondaryColor3ubv;
extern PFNGLSECONDARYCOLOR3UIPROC			glSecondaryColor3ui;
extern PFNGLSECONDARYCOLOR3UIVPROC			glSecondaryColor3uiv;
extern PFNGLSECONDARYCOLOR3USPROC			glSecondaryColor3us;
extern PFNGLSECONDARYCOLOR3USVPROC			glSecondaryColor3usv;
extern PFNGLSECONDARYCOLORPOINTERPROC		glSecondaryColorPointer;
extern PFNGLSEPARABLEFILTER2DPROC			glSeparableFilter2D;
extern PFNGLSHADERSOURCEPROC				glShaderSource;
extern PFNGLSTENCILFUNCSEPARATEPROC			glStencilFuncSeparate;
extern PFNGLSTENCILMASKSEPARATEPROC			glStencilMaskSeparate;
extern PFNGLSTENCILOPSEPARATEPROC			glStencilOpSeparate;

extern PFNGLTEXIMAGE3DPROC					glTexImage3D;
extern PFNGLTEXSUBIMAGE3DPROC				glTexSubImage3D;

extern PFNGLUNIFORM1FPROC					glUniform1f;
extern PFNGLUNIFORM1FVPROC					glUniform1fv;
extern PFNGLUNIFORM1IPROC					glUniform1i;
extern PFNGLUNIFORM1IVPROC					glUniform1iv;
extern PFNGLUNIFORM2FPROC					glUniform2f;
extern PFNGLUNIFORM2FVPROC					glUniform2fv;
extern PFNGLUNIFORM2IPROC					glUniform2i;
extern PFNGLUNIFORM2IVPROC					glUniform2iv;
extern PFNGLUNIFORM3FPROC					glUniform3f;
extern PFNGLUNIFORM3FVPROC					glUniform3fv;
extern PFNGLUNIFORM3IPROC					glUniform3i;
extern PFNGLUNIFORM3IVPROC					glUniform3iv;
extern PFNGLUNIFORM4FPROC					glUniform4f;
extern PFNGLUNIFORM4FVPROC					glUniform4fv;
extern PFNGLUNIFORM4IPROC					glUniform4i;
extern PFNGLUNIFORM4IVPROC					glUniform4iv;
extern PFNGLUNIFORMMATRIX2FVPROC			glUniformMatrix2fv;
extern PFNGLUNIFORMMATRIX2X3FVPROC			glUniformMatrix2x3fv;
extern PFNGLUNIFORMMATRIX2X4FVPROC			glUniformMatrix2x4fv;
extern PFNGLUNIFORMMATRIX3FVPROC			glUniformMatrix3fv;
extern PFNGLUNIFORMMATRIX3X2FVPROC			glUniformMatrix3x2fv;
extern PFNGLUNIFORMMATRIX3X4FVPROC			glUniformMatrix3x4fv;
extern PFNGLUNIFORMMATRIX4FVPROC			glUniformMatrix4fv;
extern PFNGLUNIFORMMATRIX4X2FVPROC			glUniformMatrix4x2fv;
extern PFNGLUNIFORMMATRIX4X3FVPROC			glUniformMatrix4x3fv;
extern PFNGLUNMAPBUFFERPROC					glUnmapBuffer;
extern PFNGLUSEPROGRAMPROC					glUseProgram;

extern PFNGLVALIDATEPROGRAMPROC				glValidateProgram;
extern PFNGLVERTEXATTRIB1FPROC				glVertexAttrib1f;
extern PFNGLVERTEXATTRIB1FVPROC				glVertexAttrib1fv;
extern PFNGLVERTEXATTRIB1DPROC				glVertexAttrib1d;
extern PFNGLVERTEXATTRIB1DVPROC				glVertexAttrib1dv;
extern PFNGLVERTEXATTRIB1SPROC				glVertexAttrib1s;
extern PFNGLVERTEXATTRIB1SVPROC				glVertexAttrib1sv;
extern PFNGLVERTEXATTRIB2FPROC				glVertexAttrib2f;
extern PFNGLVERTEXATTRIB2FVPROC				glVertexAttrib2fv;
extern PFNGLVERTEXATTRIB2DPROC				glVertexAttrib2d;
extern PFNGLVERTEXATTRIB2DVPROC				glVertexAttrib2dv;
extern PFNGLVERTEXATTRIB2SPROC				glVertexAttrib2s;
extern PFNGLVERTEXATTRIB2SVPROC				glVertexAttrib2sv;
extern PFNGLVERTEXATTRIB3FPROC				glVertexAttrib3f;
extern PFNGLVERTEXATTRIB3FVPROC				glVertexAttrib3fv;
extern PFNGLVERTEXATTRIB3DPROC				glVertexAttrib3d;
extern PFNGLVERTEXATTRIB3DVPROC				glVertexAttrib3dv;
extern PFNGLVERTEXATTRIB3SPROC				glVertexAttrib3s;
extern PFNGLVERTEXATTRIB3SVPROC				glVertexAttrib3sv;
extern PFNGLVERTEXATTRIB4BVPROC				glVertexAttrib4bv;
extern PFNGLVERTEXATTRIB4FPROC				glVertexAttrib4f;
extern PFNGLVERTEXATTRIB4FVPROC				glVertexAttrib4fv;
extern PFNGLVERTEXATTRIB4DPROC				glVertexAttrib4d;
extern PFNGLVERTEXATTRIB4DVPROC				glVertexAttrib4dv;
extern PFNGLVERTEXATTRIB4IVPROC				glVertexAttrib4iv;
extern PFNGLVERTEXATTRIB4SPROC				glVertexAttrib4s;
extern PFNGLVERTEXATTRIB4SVPROC				glVertexAttrib4sv;
extern PFNGLVERTEXATTRIB4UBVPROC			glVertexAttrib4ubv;
extern PFNGLVERTEXATTRIB4UIVPROC			glVertexAttrib4uiv;
extern PFNGLVERTEXATTRIB4USVPROC			glVertexAttrib4usv;
extern PFNGLVERTEXATTRIB4NBVPROC			glVertexAttrib4Nbv;
extern PFNGLVERTEXATTRIB4NIVPROC			glVertexAttrib4Niv;
extern PFNGLVERTEXATTRIB4NSVPROC			glVertexAttrib4Nsv;
extern PFNGLVERTEXATTRIB4NUBPROC			glVertexAttrib4Nub;
extern PFNGLVERTEXATTRIB4NUBVPROC			glVertexAttrib4Nubv;
extern PFNGLVERTEXATTRIB4NUIVPROC			glVertexAttrib4Nuiv;
extern PFNGLVERTEXATTRIB4NUSVPROC			glVertexAttrib4Nusv;
extern PFNGLVERTEXATTRIBPOINTERPROC			glVertexAttribPointer;

extern PFNGLWINDOWPOS2DPROC					glWindowPos2d;
extern PFNGLWINDOWPOS2DVPROC				glWindowPos2dv;
extern PFNGLWINDOWPOS2FPROC					glWindowPos2f;
extern PFNGLWINDOWPOS2FVPROC				glWindowPos2fv;
extern PFNGLWINDOWPOS2IPROC					glWindowPos2i;
extern PFNGLWINDOWPOS2IVPROC				glWindowPos2iv;
extern PFNGLWINDOWPOS2SPROC					glWindowPos2s;
extern PFNGLWINDOWPOS2SVPROC				glWindowPos2sv;
extern PFNGLWINDOWPOS3DPROC					glWindowPos3d;
extern PFNGLWINDOWPOS3DVPROC				glWindowPos3dv;
extern PFNGLWINDOWPOS3FPROC					glWindowPos3f;
extern PFNGLWINDOWPOS3FVPROC				glWindowPos3fv;
extern PFNGLWINDOWPOS3IPROC					glWindowPos3i;
extern PFNGLWINDOWPOS3IVPROC				glWindowPos3iv;
extern PFNGLWINDOWPOS3SPROC					glWindowPos3s;
extern PFNGLWINDOWPOS3SVPROC				glWindowPos3sv;

#endif