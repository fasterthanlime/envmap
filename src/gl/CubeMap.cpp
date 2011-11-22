#include "CubeMap.h"

CubeMap::CubeMap(const std::string& prefix, const float size)
{
  std::cout << "Loading cube map " << prefix << std::endl;
  m_size = size;
}

void CubeMap::draw()
{
  // POSITIVE_X
  glBegin(GL_QUADS);
  glNormal3f( 1.0f, 0.0f, 0.0f );
  glVertex3f( m_size, -m_size,-m_size);
  glVertex3f( m_size, -m_size, m_size);
  glVertex3f( m_size,  m_size, m_size);
  glVertex3f( m_size,  m_size,-m_size);
  glEnd();
  
  // NEGATIVE_X
  glBegin(GL_QUADS);
  glNormal3f(-1.0f, 0.0f, 0.0f );
  glVertex3f(-m_size, -m_size,-m_size);
  glVertex3f(-m_size, -m_size, m_size);
  glVertex3f(-m_size,  m_size, m_size);
  glVertex3f(-m_size,  m_size,-m_size);
  glEnd();

  // POSITIVE_Y
  glBegin(GL_QUADS);
  glNormal3f( 0.0f, 1.0f, 0.0f );
  glVertex3f(-m_size,  m_size,-m_size);
  glVertex3f(-m_size,  m_size, m_size);
  glVertex3f( m_size,  m_size, m_size);
  glVertex3f( m_size,  m_size,-m_size);
  glEnd();

  // NEGATIVE_Y
  glBegin(GL_QUADS);
  glNormal3f( 0.0f,-1.0f, 0.0f );
  glVertex3f(-m_size, -m_size,-m_size);
  glVertex3f(-m_size, -m_size, m_size);
  glVertex3f( m_size, -m_size, m_size);
  glVertex3f( m_size, -m_size,-m_size);
  glEnd();

  // POSITIVE_Z
  glBegin(GL_QUADS);
  glNormal3f( 0.0f, 0.0f, 1.0f );
  glVertex3f(-m_size, -m_size, m_size);
  glVertex3f(-m_size,  m_size, m_size);
  glVertex3f( m_size,  m_size, m_size);
  glVertex3f( m_size, -m_size, m_size);
  glEnd();

  // NEGATIVE_Z
  glBegin(GL_QUADS);
  glNormal3f( 0.0f, 0.0f,-1.0f );
  glVertex3f(-m_size, -m_size, -m_size);
  glVertex3f(-m_size,  m_size, -m_size);
  glVertex3f( m_size,  m_size, -m_size);
  glVertex3f( m_size, -m_size, -m_size);
  glEnd();
}