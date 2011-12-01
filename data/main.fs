
uniform samplerCube Texture;

varying vec3 Normal;
varying vec3 VertexToLightVector;
varying vec4 Color;
varying vec3 TextureCoordinate;

void main()
{
	gl_FragColor = textureCube(Texture, TextureCoordinate);
  // gl_FragColor.xyz = TextureCoordinate;
 
	// need this line so OpenGL doesn't optimize out the variables -- remove in your solution
    // {
	Normal; Color; Texture;
    // }
}
