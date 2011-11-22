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
    m_textures[i].create(m_texture_paths[i]);
  }

  m_cubeTexture.createCubeMap(m_texture_paths);
}

Texture CubeMap::getCubeTexture()
{
  return m_cubeTexture;
}

void CubeMap::draw()
{

    // Render the front quad
    m_textures[0].bind();
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  m_size, -m_size, -m_size );
        glTexCoord2f(1.0f, 0.0f); glVertex3f( -m_size, -m_size, -m_size );
        glTexCoord2f(1.0f, 1.0f); glVertex3f( -m_size,  m_size, -m_size );
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  m_size,  m_size, -m_size );
    glEnd();
    m_textures[0].unbind();
 
    // Render the left quad
    m_textures[1].bind();
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  m_size, -m_size,  m_size );
        glTexCoord2f(1.0f, 0.0f); glVertex3f(  m_size, -m_size, -m_size );
        glTexCoord2f(1.0f, 1.0f); glVertex3f(  m_size,  m_size, -m_size );
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  m_size,  m_size,  m_size );
    glEnd();
    m_textures[1].unbind();
 
    // Render the back quad
    m_textures[2].bind();
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( -m_size, -m_size,  m_size );
        glTexCoord2f(1.0f, 0.0f); glVertex3f(  m_size, -m_size,  m_size );
        glTexCoord2f(1.0f, 1.0f); glVertex3f(  m_size,  m_size,  m_size );
        glTexCoord2f(0.0f, 1.0f); glVertex3f( -m_size,  m_size,  m_size );
    glEnd();
    m_textures[2].unbind();
 
    // Render the right quad
    m_textures[3].bind();
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( -m_size, -m_size, -m_size );
        glTexCoord2f(1.0f, 0.0f); glVertex3f( -m_size, -m_size,  m_size );
        glTexCoord2f(1.0f, 1.0f); glVertex3f( -m_size,  m_size,  m_size );
        glTexCoord2f(0.0f, 1.0f); glVertex3f( -m_size,  m_size, -m_size );
    glEnd();
    m_textures[3].unbind();
 
    // Render the top quad
    m_textures[4].bind();
    glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( -m_size,  m_size, -m_size );
        glTexCoord2f(1.0f, 1.0f); glVertex3f( -m_size,  m_size,  m_size );
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  m_size,  m_size,  m_size );
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  m_size,  m_size, -m_size );
    glEnd();
    m_textures[4].unbind();
 
    // Render the bottom quad
    m_textures[5].bind();
    glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f); glVertex3f( -m_size, -m_size, -m_size );
        glTexCoord2f(1.0f, 0.0f); glVertex3f( -m_size, -m_size,  m_size );
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  m_size, -m_size,  m_size );
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  m_size, -m_size, -m_size );
    glEnd();
    m_textures[5].unbind();
}
