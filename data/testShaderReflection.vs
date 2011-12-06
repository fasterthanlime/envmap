uniform mat4 ModelWorldTransform;
uniform mat4 WorldCameraTransform;
uniform mat4 ProjectionMatrix;

uniform mat3 WorldCameraNormalTransform;
uniform mat3 ModelWorldNormalTransform;
uniform vec3 DiffuseColor;

// input for reflection (part I)
uniform vec3 EyePosition;

// output for reflection (part I)
varying vec3 ReflectedRay;

// input for refraction (part II)

// output for refraction (part II)

// input for color dispersion (part IIIa)
//uniform vec3 EtaRatio;

// output for color dispersion (part IIIa)
/*
varying vec3 TransmittedRed;
varying vec3 TransmittedGreen;
varying vec3 TransmittedBlue;
varying vec3 Reflectance;
*/

// input for the fresnel effect(part IIIb), not using the original fresnel equations, but the
// approximation given in the pdf.
/*
uniform float FresnelBias;
uniform float FresnelScale;
uniform float FresnelPower;
*/
varying vec3 WorldPosition;

void main()
{

	gl_Position = ProjectionMatrix * WorldCameraTransform * ModelWorldTransform * gl_Vertex;
	
	vec3 WorldPosition = (ModelWorldTransform * gl_Vertex).xyz;
	vec3 Normal = normalize(ModelWorldNormalTransform * gl_Normal);
  
	vec3 IncidentRay = normalize(WorldPosition - EyePosition);
	ReflectedRay = normalize(reflect(IncidentRay, Normal));
	
	// uncomment this for color dispersion
	/*
	TransmittedRed = refract(IncidentRay, Normal, EtaRatio.x);
	TransmittedGreen = refract(IncidentRay, Normal, EtaRatio.y);
	TransmittedBlue = refract(IncidentRay, Normal, EtaRatio.z);
	*/

	// uncomment this for the simple Fresnel Effect
	//Reflectance = FresnelBias + FresnelScale * pow(1 + dot(IncidentRay, Normal), FresnelPower);
	
}
