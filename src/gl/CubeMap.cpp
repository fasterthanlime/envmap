#include "CubeMap.h"
#include <cstdio>

CubeMap::CubeMap(const std::string& prefix, const float size, Shader *shader)
{
  std::cout << "Loading cube map " << prefix << std::endl;

  m_prefix = prefix;
  m_size = size;
  m_shader = shader;
  
  m_texture_suffixes[0] = "_positive_z";
  m_texture_suffixes[1] = "_negative_x";
  m_texture_suffixes[2] = "_negative_z";
  m_texture_suffixes[3] = "_positive_x";
  m_texture_suffixes[4] = "_positive_y";
  m_texture_suffixes[5] = "_negative_y";

  for(int i = 0; i < 6; i++) {
    m_texture_paths[i] = m_prefix + m_texture_suffixes[i] + ".tga";
  }

  m_cubeTexture.createCubeMap(m_texture_paths);
}

Texture CubeMap::getCubeTexture()
{
  return m_cubeTexture;
}

void CubeMap::draw()
{
    glBegin(GL_QUADS);

    // Render the front quad
    glTexCoord3f(  1.0f, -1.0f, -1.0f ); glVertex3f(  m_size, -m_size, -m_size );
    glTexCoord3f( -1.0f, -1.0f, -1.0f ); glVertex3f( -m_size, -m_size, -m_size );
    glTexCoord3f( -1.0f,  1.0f, -1.0f ); glVertex3f( -m_size,  m_size, -m_size );
    glTexCoord3f(  1.0f,  1.0f, -1.0f ); glVertex3f(  m_size,  m_size, -m_size );
 
    // Render the left quad
    glTexCoord3f(  1.0f, -1.0f,  1.0f ); glVertex3f(  m_size, -m_size,  m_size );
    glTexCoord3f(  1.0f, -1.0f, -1.0f ); glVertex3f(  m_size, -m_size, -m_size );
    glTexCoord3f(  1.0f,  1.0f, -1.0f ); glVertex3f(  m_size,  m_size, -m_size );
    glTexCoord3f(  1.0f,  1.0f,  1.0f ); glVertex3f(  m_size,  m_size,  m_size );
 
    // Render the back quad
    glTexCoord3f( -1.0f, -1.0f,  1.0f ); glVertex3f( -m_size, -m_size,  m_size );
    glTexCoord3f(  1.0f, -1.0f,  1.0f ); glVertex3f(  m_size, -m_size,  m_size );
    glTexCoord3f(  1.0f,  1.0f,  1.0f ); glVertex3f(  m_size,  m_size,  m_size );
    glTexCoord3f( -1.0f,  1.0f,  1.0f ); glVertex3f( -m_size,  m_size,  m_size );
 
    // Render the right quad
    glTexCoord3f( -1.0f, -1.0f, -1.0f ); glVertex3f( -m_size, -m_size, -m_size );
    glTexCoord3f( -1.0f, -1.0f,  1.0f ); glVertex3f( -m_size, -m_size,  m_size );
    glTexCoord3f( -1.0f,  1.0f,  1.0f ); glVertex3f( -m_size,  m_size,  m_size );
    glTexCoord3f( -1.0f,  1.0f, -1.0f ); glVertex3f( -m_size,  m_size, -m_size );
 
    // Render the top quad
    glTexCoord3f( -1.0f,  1.0f, -1.0f ); glVertex3f( -m_size,  m_size, -m_size );
    glTexCoord3f( -1.0f,  1.0f,  1.0f ); glVertex3f( -m_size,  m_size,  m_size );
    glTexCoord3f(  1.0f,  1.0f,  1.0f ); glVertex3f(  m_size,  m_size,  m_size );
    glTexCoord3f(  1.0f,  1.0f, -1.0f ); glVertex3f(  m_size,  m_size, -m_size );
 
    // Render the bottom quad
    glTexCoord3f( -1.0f, -1.0f, -1.0f ); glVertex3f( -m_size, -m_size, -m_size );
    glTexCoord3f( -1.0f, -1.0f,  1.0f ); glVertex3f( -m_size, -m_size,  m_size );
    glTexCoord3f(  1.0f, -1.0f,  1.0f ); glVertex3f(  m_size, -m_size,  m_size );
    glTexCoord3f(  1.0f, -1.0f, -1.0f ); glVertex3f(  m_size, -m_size, -m_size );

    glEnd();
}
