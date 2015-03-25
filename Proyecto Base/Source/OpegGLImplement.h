#ifndef __OPENGL_IMPLEMENT_H__
#define __OPENGL_IMPLEMENT_H__
#include "Config.h"
#include "SDL_opengl.h"
#include "SDL.h"
#include <stdio.h>
#include <string>
#include <fstream>

class OpenGlImplement
{
	PFNGLCREATEPROGRAMPROC glCreateProgram;
	PFNGLATTACHSHADERPROC glAttachShader;
	PFNGLLINKPROGRAMPROC glLinkProgram;
	PFNGLUSEPROGRAMPROC glUseProgram;
	PFNGLCREATESHADERPROC glCreateShader;
	PFNGLSHADERSOURCEPROC glShaderSource;
	PFNGLCOMPILESHADERPROC glCompileShader;
	PFNGLBINDBUFFERPROC glBindBuffer;
	PFNGLGENBUFFERSPROC glGenBuffers;
	PFNGLBUFFERDATAPROC glBufferData;
	PFNGLDELETEPROGRAMPROC glDeleteProgram;
	PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
	PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
	PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
	PFNGLGETPROGRAMIVPROC glGetProgramiv;
	PFNGLGETSHADERIVPROC glGetShaderiv;
	PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
	PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
	PFNGLISSHADERPROC glIsShader;
	PFNGLISPROGRAMPROC glIsProgram;
	PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;

	SDL_Window *window;
	std::string readFile(const char *filePath);
public:
	OpenGlImplement();
	~OpenGlImplement();

	void setSDLWindow(SDL_Window *window);
	void InitGL();
	void InitShaders();
	void InitBuffers();
	void QuitShaders();
	void Draw(GLuint texture, GLfloat * texcoord);
	void DrawStart();
	void DrawEnd();

	GLuint gProgramID = 0;
	GLint gVertexPos2DLocation = -1;
	GLuint gVBO = 0;
	GLuint gIBO = 0;
};
#endif