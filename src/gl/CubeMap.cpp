#include "CubeMap.h"
#include <cstdio>

CubeMap::CubeMap(const std::string& prefix, const float size, Shader *shader)
{
  std::cout << "Loading cube map " << prefix << std::endl;

  m_prefix = prefix;
  m_size = size;
  m_shader = shader;
  
  m_texture_names[0] = "_positive_x";
  m_texture_names[1] = "_negative_x";
  m_texture_names[2] = "_positive_y";
  m_texture_names[3] = "_negative_y";
  m_texture_names[4] = "_positive_z";
  m_texture_names[5] = "_negative_z";

  ILuint ilIDs[6];
  ilGenImages(6, ilIDs);
  glGenTextures(6, m_textures);
  
  for(int i = 0; i < 6; i++) {
    std::string texture_file = m_prefix + m_texture_names[i] + ".tga";
    std::cout << "Loading image " << texture_file << std::endl;
    ilBindImage(ilIDs[i]);
    
    int success = ilLoadImage(texture_file.c_str());
    if (success) {
      std::cout << "Image size: " << ilGetInteger(IL_IMAGE_WIDTH) << "x" << ilGetInteger(IL_IMAGE_HEIGHT) << std::endl;

      success = ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);

      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH),
         ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
         ilGetData());
    } 
  }

  ilDeleteImages(6, ilIDs);
}

void CubeMap::draw()
{
  // POSITIVE_X
  glBegin(GL_QUADS);
  glNormal3f( 1.0f, 0.0f, 0.0f );
  glBindTexture(GL_TEXTURE_2D, m_textures[0]);
  m_shader->setIntUniform("Texture", m_textures[0]);
  glTexCoord2f( 0.0f, 0.0f );
  glVertex3f( m_size, -m_size,-m_size);
  glTexCoord2f( 0.0f, 1.0f );
  glVertex3f( m_size, -m_size, m_size);
  glTexCoord2f( 1.0f, 1.0f );
  glVertex3f( m_size,  m_size, m_size);
  glTexCoord2f( 1.0f, 0.0f );
  glVertex3f( m_size,  m_size,-m_size);
  glEnd();
  
  // NEGATIVE_X
  glBegin(GL_QUADS);
  glNormal3f(-1.0f, 0.0f, 0.0f );
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, m_textures[1]);
  m_shader->setIntUniform("Texture", m_textures[1]);
  glTexCoord2f( 0.0f, 0.0f );
  glVertex3f(-m_size, -m_size,-m_size);
  glTexCoord2f( 0.0f, 1.0f );
  glVertex3f(-m_size, -m_size, m_size);
  glTexCoord2f( 1.0f, 1.0f );
  glVertex3f(-m_size,  m_size, m_size);
  glTexCoord2f( 1.0f, 0.0f );
  glVertex3f(-m_size,  m_size,-m_size);
  glEnd();

  // POSITIVE_Y
  glBegin(GL_QUADS);
  glNormal3f( 0.0f, 1.0f, 0.0f );
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, m_textures[2]);
  m_shader->setIntUniform("Texture", m_textures[2]);
  glTexCoord2f( 0.0f, 0.0f );
  glVertex3f(-m_size,  m_size,-m_size);
  glTexCoord2f( 0.0f, 1.0f );
  glVertex3f(-m_size,  m_size, m_size);
  glTexCoord2f( 1.0f, 1.0f );
  glVertex3f( m_size,  m_size, m_size);
  glTexCoord2f( 1.0f, 0.0f );
  glVertex3f( m_size,  m_size,-m_size);
  glEnd();

  // NEGATIVE_Y
  glBegin(GL_QUADS);
  glNormal3f( 0.0f,-1.0f, 0.0f );
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, m_textures[3]);
  m_shader->setIntUniform("Texture", m_textures[3]);
  glTexCoord2f( 0.0f, 0.0f );
  glVertex3f(-m_size, -m_size,-m_size);
  glTexCoord2f( 0.0f, 1.0f );
  glVertex3f(-m_size, -m_size, m_size);
  glTexCoord2f( 1.0f, 1.0f );
  glVertex3f( m_size, -m_size, m_size);
  glTexCoord2f( 1.0f, 0.0f );
  glVertex3f( m_size, -m_size,-m_size);
  glEnd();

  // POSITIVE_Z
  glBegin(GL_QUADS);
  glNormal3f( 0.0f, 0.0f, 1.0f );
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, m_textures[4]);
  m_shader->setIntUniform("Texture", m_textures[4]);
  glTexCoord2f( 0.0f, 0.0f );
  glVertex3f(-m_size, -m_size, m_size);
  glTexCoord2f( 0.0f, 1.0f );
  glVertex3f(-m_size,  m_size, m_size);
  glTexCoord2f( 1.0f, 1.0f );
  glVertex3f( m_size,  m_size, m_size);
  glTexCoord2f( 1.0f, 0.0f );
  glVertex3f( m_size, -m_size, m_size);
  glEnd();

  // NEGATIVE_Z
  glBegin(GL_QUADS);
  glNormal3f( 0.0f, 0.0f,-1.0f );
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, m_textures[5]);
  m_shader->setIntUniform("Texture", m_textures[5]);
  glTexCoord2f( 0.0f, 0.0f );
  glVertex3f(-m_size, -m_size, -m_size);
  glTexCoord2f( 0.0f, 1.0f );
  glVertex3f(-m_size,  m_size, -m_size);
  glTexCoord2f( 1.0f, 1.0f );
  glVertex3f( m_size,  m_size, -m_size);
  glTexCoord2f( 1.0f, 0.0f );
  glVertex3f( m_size, -m_size, -m_size);
  glEnd();
}