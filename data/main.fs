
uniform sampler2D Texture;

varying vec3 Normal;
varying vec3 VertexToLightVector;
varying vec4 Color;
varying vec2 TextureCoordinate;

void main()
{
	gl_FragColor = texture2D(Texture, TextureCoordinate);
	
	// need this line so OpenGL doesn't optimize out the variables -- remove in your solution
    // {
	Normal; Color;
    // }
}
