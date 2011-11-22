

#ifndef CUBEMAP_HH
#define CUBEMAP_HH

#include <string>
#include <iostream>
#include "shader.h"

using namespace std;

class CubeMap
{
public:
    CubeMap(const std::string& prefix);

private:
    Shader m_shader;
};

#endif