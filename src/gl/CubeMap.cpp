#include "CubeMap.h"
#include <cstdio>

CubeMap::CubeMap(const std::string& prefix, const float size)
{
  std::cout << "Loading cube map " << prefix << std::endl;

  m_prefix = prefix;
  m_size = size;
  
  m_texture_names[0] = "_positive_x";
  m_texture_names[1] = "_negative_x";
  m_texture_names[2] = "_positive_y";
  m_texture_names[3] = "_negative_y";
  m_texture_names[4] = "_positive_z";
  m_texture_names[5] = "_negative_z";

  ilGenImages(6, m_textures);
  
  for(int i = 0; i < 6; i++) {
    std::string texture_file = m_prefix + m_texture_names[i] + ".tga";
    std::cout << "Loading image " << texture_file << std::endl;
    ilBindImage(m_textures[i]);
    
    ilLoadImage(texture_file.c_str());
    std::cout << "Image size: " << ilGetInteger(IL_IMAGE_WIDTH) << "x" << ilGetInteger(IL_IMAGE_HEIGHT) << std::endl;
  }
}

void CubeMap::draw()
{
    // Render the front quad
    glBindTexture(GL_TEXTURE_2D, m_textures[0]);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  m_size, -m_size, -m_size );
        glTexCoord2f(1.0f, 0.0f); glVertex3f( -m_size, -m_size, -m_size );
        glTexCoord2f(1.0f, 1.0f); glVertex3f( -m_size,  m_size, -m_size );
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  m_size,  m_size, -m_size );
    glEnd();
 
    // Render the left quad
    glBindTexture(GL_TEXTURE_2D, m_textures[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  m_size, -m_size,  m_size );
        glTexCoord2f(1.0f, 0.0f); glVertex3f(  m_size, -m_size, -m_size );
        glTexCoord2f(1.0f, 1.0f); glVertex3f(  m_size,  m_size, -m_size );
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  m_size,  m_size,  m_size );
    glEnd();
 
    // Render the back quad
    glBindTexture(GL_TEXTURE_2D, m_textures[2]);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( -m_size, -m_size,  m_size );
        glTexCoord2f(1.0f, 0.0f); glVertex3f(  m_size, -m_size,  m_size );
        glTexCoord2f(1.0f, 1.0f); glVertex3f(  m_size,  m_size,  m_size );
        glTexCoord2f(0.0f, 1.0f); glVertex3f( -m_size,  m_size,  m_size );
 
    glEnd();
 
    // Render the right quad
    glBindTexture(GL_TEXTURE_2D, m_textures[3]);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( -m_size, -m_size, -m_size );
        glTexCoord2f(1.0f, 0.0f); glVertex3f( -m_size, -m_size,  m_size );
        glTexCoord2f(1.0f, 1.0f); glVertex3f( -m_size,  m_size,  m_size );
        glTexCoord2f(0.0f, 1.0f); glVertex3f( -m_size,  m_size, -m_size );
    glEnd();
 
    // Render the top quad
    glBindTexture(GL_TEXTURE_2D, m_textures[4]);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( -m_size,  m_size, -m_size );
        glTexCoord2f(0.0f, 0.0f); glVertex3f( -m_size,  m_size,  m_size );
        glTexCoord2f(1.0f, 0.0f); glVertex3f(  m_size,  m_size,  m_size );
        glTexCoord2f(1.0f, 1.0f); glVertex3f(  m_size,  m_size, -m_size );
    glEnd();
 
    // Render the bottom quad
    glBindTexture(GL_TEXTURE_2D, m_textures[5]);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( -m_size, -m_size, -m_size );
        glTexCoord2f(0.0f, 1.0f); glVertex3f( -m_size, -m_size,  m_size );
        glTexCoord2f(1.0f, 1.0f); glVertex3f(  m_size, -m_size,  m_size );
        glTexCoord2f(1.0f, 0.0f); glVertex3f(  m_size, -m_size, -m_size );
    glEnd();
}
