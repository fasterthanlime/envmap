uniform mat4 ModelWorldTransform;
uniform mat4 WorldCameraTransform;
uniform mat4 ProjectionMatrix;

uniform mat3 WorldCameraNormalTransform;
uniform mat3 ModelWorldNormalTransform;
uniform vec3 DiffuseColor;

uniform float3 EyePosition

varying vec3 VertexToLightVector;
varying vec3 Normal;
varying vec4 Color;


void main()
{
	// Exercise 3.2.5 and 3.3.1
	gl_Position = ProjectionMatrix * WorldCameraTransform * ModelWorldTransform * gl_Vertex;
	
	color = vec4(diffuseColor, 1.0);
	//gl_TexCoord[0] = gl_MultiTexCoord0;
	normal = WorldCameraNormalTransform * ModelWorldNormalTransform * gl_Normal;
	//vertex_to_light_vector = - vec3(WorldCameraTransform * ModelWorldTransform * gl_Vertex);
	
	// need this line so OpenGL doesn't optimize out the variables -- remove in your solution
    // {
	ModelWorldTransform; WorldCameraTransform; ProjectionMatrix; WorldCameraNormalTransform; ModelWorldNormalTransform; normal; color;
    // }
}
