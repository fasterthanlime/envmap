

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
    CubeMap(const std::string& prefix, const float size);
    void draw();

private:
    float m_size;
    Shader m_shader;
};

#endif