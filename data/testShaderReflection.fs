varying vec3 ReflectedRay;

//in case we also want to add a texture to the cube, and then perform a linear interpolation for the colors. 
//uniform float Reflectivity;
//uniform sampler2D TextureMap
uniform samplerCube EnvironmentMap;


void main()
{

gl_FragColor = textureCube(EnvironmentMap,ReflectedRay);
}
