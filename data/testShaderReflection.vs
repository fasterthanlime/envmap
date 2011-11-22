uniform mat4 ModelWorldTransform;
uniform mat4 WorldCameraTransform;
uniform mat4 ProjectionMatrix;

uniform mat3 WorldCameraNormalTransform;
uniform mat3 ModelWorldNormalTransform;
uniform vec3 DiffuseColor;

uniform vec3 EyePosition;
varying vec3 Normal;
varying vec4 Color;

varying vec3 ReflectedRay;

vec3 reflect(vec3 I, vec3 N){	return I - 2.0 * N * dot(N, I);}

void main()
{

	gl_Position = ProjectionMatrix * WorldCameraTransform * ModelWorldTransform * gl_Vertex;
	
	vec3 WorldPosition = (ModelWorldTransform * gl_Vertex).xyz;
	Normal = normalize((ModelWorldNormalTransform * gl_Normal));
	
	vec3 IncidentRay = WorldPosition - EyePosition;
	ReflectedRay = reflect(IncidentRay, Normal);
	
}
