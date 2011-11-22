#include "CubeMap.h"

CubeMap::CubeMap(const std::string& prefix)
{
  std::cout << "Loading cube map " << prefix << std::endl;
}

CubeMap::draw()
{
  // POSITIVE_X
  glBegin(GL_QUADS);
  glNormal3f( 1.0f, 0.0f, 0.0f );
  glVertex3f( size, -size,-size);
  glVertex3f( size, -size, size);
  glVertex3f( size,  size, size);
  glVertex3f( size,  size,-size);
  glEnd();
  
  // NEGATIVE_X
  glBegin(GL_QUADS);
  glNormal3f(-1.0f, 0.0f, 0.0f );
  glVertex3f(-size, -size,-size);
  glVertex3f(-size, -size, size);
  glVertex3f(-size,  size, size);
  glVertex3f(-size,  size,-size);
  glEnd();

  // POSITIVE_Y
  glBegin(GL_QUADS);
  glNormal3f( 0.0f, 1.0f, 0.0f );
  glVertex3f(-size,  size,-size);
  glVertex3f(-size,  size, size);
  glVertex3f( size,  size, size);
  glVertex3f( size,  size,-size);
  glEnd();

  // NEGATIVE_Y
  glBegin(GL_QUADS);
  glNormal3f( 0.0f,-1.0f, 0.0f );
  glVertex3f(-size, -size,-size);
  glVertex3f(-size, -size, size);
  glVertex3f( size, -size, size);
  glVertex3f( size, -size,-size);
  glEnd();

  // POSITIVE_Z
  glBegin(GL_QUADS);
  glNormal3f( 0.0f, 0.0f, 1.0f );
  glVertex3f(-size, -size, size);
  glVertex3f(-size,  size, size);
  glVertex3f( size,  size, size);
  glVertex3f( size, -size, size);
  glEnd();

  // NEGATIVE_Z
  glBegin(GL_QUADS);
  glNormal3f( 0.0f, 0.0f,-1.0f );
  glVertex3f(-size, -size, -size);
  glVertex3f(-size,  size, -size);
  glVertex3f( size,  size, -size);
  glVertex3f( size, -size, -size);
  glEnd();
}