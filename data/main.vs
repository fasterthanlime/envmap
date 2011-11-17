uniform mat4 ModelWorldTransform;
uniform mat4 WorldCameraTransform;
uniform mat4 ProjectionMatrix;

uniform mat3 WorldCameraNormalTransform;
uniform mat3 ModelWorldNormalTransform;
uniform vec3 diffuseColor;

varying vec3 vertex_to_light_vector;
varying vec3 normal;
varying vec4 color;


void main()
{
	// Exercise 3.2.5 and 3.3.1
	gl_Position = ProjectionMatrix * WorldCameraTransform * ModelWorldTransform * gl_Vertex;
	
	color = vec4(diffuseColor, 1.0);
	normal = WorldCameraNormalTransform * ModelWorldNormalTransform * gl_Normal;
	vertex_to_light_vector = - vec3(WorldCameraTransform * ModelWorldTransform * gl_Vertex);
	
	// need this line so OpenGL doesn't optimize out the variables -- remove in your solution
    // {
	ModelWorldTransform; WorldCameraTransform; ProjectionMatrix; WorldCameraNormalTransform; ModelWorldNormalTransform; normal; color;
    // }
}
