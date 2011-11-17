//=============================================================================
//                                                                            
//   Environment mapping demo application
//                                                                            
//=============================================================================
//=============================================================================
//
//  CLASS MeshViewer
//
//=============================================================================


#ifndef MESH_VIEWER_HH
#define MESH_VIEWER_HH


//== INCLUDES =================================================================
#include <string>
#include <vector>

#include "../../gl/TrackballViewer.h"
#include "../../gl/shader.h"
#include "../../gl/Mesh3D.h"
#include "../../gl/Light3D.h"
#include "../../gl/texture.h"
#include "../../gl/fbo.h"

//== CLASS DEFINITION =========================================================


	      
/*
 EnvMap.
*/
class EnvMap : public TrackballViewer
{
public:
   
  EnvMap(const char* _title, int _width, int _height);
  
	
  void loadMesh(const std::string& filenameOBJ, const std::string& filenameMTL = std::string());
	
protected:

	// overloaded GUI function
  virtual void init();
	virtual void keyboard(int key, int x, int y);
	
  virtual void draw_scene(DrawMode _draw_mode);

private:
	void drawObject();
	
protected:
	
	// mesh object
	Mesh3D m_mesh;
	
	// main shader
	Shader m_mainShader;
	
};


//=============================================================================
#endif // MESH_VIEWER_HH defined
//=============================================================================
