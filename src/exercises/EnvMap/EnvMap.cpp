//=============================================================================
//                                                                            
//   Environment mapping demo application
//                                                                            
//=============================================================================
//=============================================================================
//
//  CLASS EnvMap - IMPLEMENTATION
//
//=============================================================================

//== INCLUDES =================================================================

#include "EnvMap.h"
#include "../../utils/Mesh3DReader.h"

//== IMPLEMENTATION ========================================================== 


EnvMap::
EnvMap(const char* _title, int _width, int _height)
: TrackballViewer(_title, _width, _height)
{
  init();
}


//-----------------------------------------------------------------------------


void 
EnvMap::
init()
{
	// initialize parent
	TrackballViewer::init();

	// set camera to look at world coordinate center
	set_scene_pos(Vector3(0.0, 0.0, 0.0), 2.0);

	// load shaders
	m_mainShader.create("main.vs", "main.fs");

  // load cube map
  m_cubeMap = new CubeMap("deadmeat_skymorning", 15.0f);
}



//-----------------------------------------------------------------------------

void
EnvMap::
loadMesh(const std::string& filenameOBJ, const std::string& filenameMTL)
{
	// load mesh from obj
	Mesh3DReader::read( filenameOBJ, m_mesh, filenameMTL);

	// calculate normals
	m_mesh.calculateVertexNormals();
	
	// get bounding box & reset scene camera accordingly
	Vector3 bbmin, bbmax;
	m_mesh.calculateBoundingBox(bbmin, bbmax);
	
	double radius = 0.5*(bbmin - bbmax).length();
	Vector3 center = 0.5*(bbmin + bbmax);
	
	set_scene_pos(center, radius);
}



//-----------------------------------------------------------------------------


void
EnvMap::
keyboard(int key, int x, int y)
{
	switch (key)
	{			
		case 'h':
			printf("Help:\n");
			printf("'h'\t-\thelp\n");
			break;
		default:
			TrackballViewer::special(key, x, y);
			break;
	}
	
	glutPostRedisplay();
}

//-----------------------------------------------------------------------------


void 
EnvMap::
draw_scene(DrawMode _draw_mode)
{
	// clear screen
	glEnable(GL_DEPTH_TEST);
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // draw environment cube
  drawEnvironment();

	// draw main object
	drawObject();	
}



//-----------------------------------------------------------------------------
void 
EnvMap::
drawEnvironment() {
  m_mainShader.bind(); 

  // set parameters
	m_mainShader.setMatrix4x4Uniform("WorldCameraTransform", m_camera.getTransformation().Inverse());
  m_mainShader.setMatrix3x3Uniform("WorldCameraNormalTransform", m_camera.getTransformation().Transpose());
	m_mainShader.setMatrix4x4Uniform("ProjectionMatrix", m_camera.getProjectionMatrix());
  m_mainShader.setMatrix4x4Uniform("ModelWorldTransform", Matrix4().loadIdentity());
  m_mainShader.setMatrix4x4Uniform("ModelWorldNormalTransform", Matrix4().loadIdentity());

  m_mainShader.setVector3Uniform("DiffuseColor", 0.0f, 0.0f, 1.0f);

  m_cubeMap->draw();
  
  m_mainShader.unbind();
}

//-----------------------------------------------------------------------------
void 
EnvMap::
drawObject() {
	m_mainShader.bind(); 

  // set parameters
	m_mainShader.setMatrix4x4Uniform("WorldCameraTransform", m_camera.getTransformation().Inverse());
  m_mainShader.setMatrix3x3Uniform("WorldCameraNormalTransform", m_camera.getTransformation().Transpose());
	m_mainShader.setMatrix4x4Uniform("ProjectionMatrix", m_camera.getProjectionMatrix());
	m_mainShader.setMatrix4x4Uniform("ModelWorldTransform", m_mesh.getTransformation() );
  m_mainShader.setMatrix4x4Uniform("ModelWorldNormalTransform", m_mesh.getTransformation().Inverse().Transpose() );
	
  // test computing the camera's position
  Vector3 origin;
  origin = m_camera.getTransformation() * origin;

  glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	if(m_mesh.hasUvTextureCoord())
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer( 3, GL_DOUBLE, 0, m_mesh.getVertexPointer() );
	glNormalPointer( GL_DOUBLE, 0, m_mesh.getNormalPointer() );
	if(m_mesh.hasUvTextureCoord())
		glTexCoordPointer( 2, GL_DOUBLE, 0, m_mesh.getUvTextureCoordPointer() );

	for(unsigned int i = 0; i < m_mesh.getNumberOfParts(); i++)
	{
		bool hasTexture = m_mesh.hasUvTextureCoord() && m_mesh.getMaterial(i).hasDiffuseTexture();
		m_mainShader.setIntUniform("UseTexture", hasTexture);
		m_mainShader.setVector3Uniform("DiffuseColor", 
										  m_mesh.getMaterial(i).m_diffuseColor.x, 
										  m_mesh.getMaterial(i).m_diffuseColor.y, 
										  m_mesh.getMaterial(i).m_diffuseColor.z );
		if(hasTexture)
		{
			m_mesh.getMaterial(i).m_diffuseTexture.bind();
			m_mainShader.setIntUniform("TextureDiffuse", m_mesh.getMaterial(i).m_diffuseTexture.getLayer());
		}

   	glDrawElements( GL_TRIANGLES, m_mesh.getNumberOfFaces(i)*3, GL_UNSIGNED_INT, m_mesh.getVertexIndicesPointer(i) );
    
		if(hasTexture)
		{
			m_mesh.getMaterial(i).m_diffuseTexture.unbind();
		}
	}
	
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	if(m_mesh.hasUvTextureCoord())
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  
	m_mainShader.unbind();
}

//=============================================================================
