varying vec3 Normal;
varying vec3 VertexToLightVector;
varying vec4 Color;

void main()
{
	// Exercise 3.3.2
	/// gl_FragColor = clamp(dot(normalize(normal), normalize(VertexToLightVector)) * color, 0.0, 1.0);
    	gl_FragColor = Color;
	
	// need this line so OpenGL doesn't optimize out the variables -- remove in your solution
    // {
	Normal; Color;
    // }
}
