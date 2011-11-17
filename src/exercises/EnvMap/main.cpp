//=============================================================================
//                                                                            
//   Exercise code for the lecture
//                                                                            
//=============================================================================

#include "EnvMap.h"



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	
	EnvMap window("Environment Mapping", 800, 800);
  window.loadMesh("teapot.obj", "teapot.mtl");
	
	glutMainLoop();
}
