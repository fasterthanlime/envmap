
uniform sampler2D Texture;

varying vec3 Normal;
varying vec3 VertexToLightVector;
varying vec4 Color;
varying vec2 TextureCoordinate;

void main()
{
	// Exercise 3.3.2
	// gl_FragColor = clamp(dot(normalize(normal), normalize(VertexToLightVector)) * color, 0.0, 1.0);
   	// gl_FragColor = Color;
	gl_FragColor = vec4(Normal, 1.0) + texture2D(Texture, TextureCoordinate);
	
	// need this line so OpenGL doesn't optimize out the variables -- remove in your solution
    // {
	Normal; Color;
    // }
}
