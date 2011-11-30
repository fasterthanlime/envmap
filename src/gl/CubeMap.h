

#ifndef CUBEMAP_HH
#define CUBEMAP_HH

#include <string>
#include <iostream>

#include "shader.h"
#include "Mesh3D.h"
#include "Light3D.h"
#include "texture.h"
#include "fbo.h"

using namespace std;

class CubeMap
{
public:
    CubeMap(const std::string& prefix, const float size, Shader *shader);
    void draw();
    Texture getCubeTexture();

private:
    float m_size;
    std::string m_prefix;

    Shader *m_shader;

    Texture m_cubeTexture;

    std::string m_texture_suffixes[6];
    std::string m_texture_paths[6];
};

#endif