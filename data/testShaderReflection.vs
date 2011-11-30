uniform mat4 ModelWorldTransform;
uniform mat4 WorldCameraTransform;
uniform mat4 ProjectionMatrix;

uniform mat3 WorldCameraNormalTransform;
uniform mat3 ModelWorldNormalTransform;
uniform vec3 DiffuseColor;

uniform vec3 EyePosition;

varying vec3 ReflectedRay;
varying vec3 WorldPosition;

void main()
{

	gl_Position = ProjectionMatrix * WorldCameraTransform * ModelWorldTransform * gl_Vertex;
	
	vec3 WorldPosition = (ModelWorldTransform * gl_Vertex).xyz;
	vec3 Normal = normalize((ModelWorldNormalTransform * gl_Normal));
  
	vec3 IncidentRay = normalize(WorldPosition - EyePosition);
	ReflectedRay = normalize(reflect(IncidentRay, Normal));
	
}
