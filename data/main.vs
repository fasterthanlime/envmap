uniform mat4 ModelWorldTransform;
uniform mat4 WorldCameraTransform;
uniform mat4 ProjectionMatrix;

uniform mat3 WorldCameraNormalTransform;
uniform mat3 ModelWorldNormalTransform;
uniform vec3 DiffuseColor;

varying vec3 VertexToLightVector;
varying vec3 Normal;
varying vec4 Color;
varying vec2 TextureCoordinate;

void main()
{
	// Exercise 3.2.5 and 3.3.1
	gl_Position = ProjectionMatrix * WorldCameraTransform * ModelWorldTransform * gl_Vertex;
	
	Color = vec4(DiffuseColor, 1.0);
	TextureCoordinate = vec2(gl_MultiTexCoord0);
	Normal = WorldCameraNormalTransform * ModelWorldNormalTransform * gl_Normal;
	VertexToLightVector = - vec3(WorldCameraTransform * ModelWorldTransform * gl_Vertex);
	
	// need this line so OpenGL doesn't optimize out the variables -- remove in your solution
    // {
	ModelWorldTransform; WorldCameraTransform; ProjectionMatrix; WorldCameraNormalTransform; ModelWorldNormalTransform; Normal; Color;
    // }
}
