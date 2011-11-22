

#ifndef CUBEMAP_HH
#define CUBEMAP_HH

#include <string>
#include <iostream>

#include "shader.h"
#include "Mesh3D.h"
#include "Light3D.h"
#include "texture.h"
#include "fbo.h"

#undef _UNICODE
#include "IL/il.h"

using namespace std;

class CubeMap
{
public:
    CubeMap(const std::string& prefix, const float size);
    void draw();

private:
    float m_size;
    std::string m_prefix;

    Shader m_shader;

    ILuint m_textures[6];
    std::string m_texture_names[6];
};

#endif