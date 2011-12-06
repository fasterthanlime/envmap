varying vec3 ReflectedRay;

// input from vertex shader for parts IIIa and IIIb
/*
varying vec3 TransmittedRed;
varying vec3 TransmittedGreen;
varying vec3 TransmittedBlue;
varying vec3 Reflectance;
*/

// in case we also want to add a texture to the cube, and then perform a linear interpolation for the colors. 
// uniform float Reflectivity;
// uniform sampler2D TextureMap
uniform samplerCube EnvironmentMap;

void main()
{

	vec4 ReflectedColor = textureCube(EnvironmentMap, vec3(0.0,0.0,1.0));
	// comment this out if you want other effects in addition to reflection
	vec4 FinalColor = clamp(ReflectedColor, 0.0, 1.0);

	// uncomment this for color dispersion
	/*
	vec4 RefractedColor;
	RefractedColor.r = textureCube(EnvironmentMap, TransmittedRed).r;
	RefractedColor.g = textureCube(EnvironmentMap, TransmittedGreen).g;
	RefractedColor.b = textureCube(EnvironmentMap, TransmittedBlue).b;
	RefractedColor.a = 1;
	*/
	
	// uncomment this for fresnel type refraction
	//vec4 FinalColor = Reflectance * ReflectedColor + (1 - Reflectance) * RefractedColor;

    gl_FragColor = ReflectedColor;//clamp(FinalColor, 0.0,1.0);
   //gl_FragColor.xyz = 0.5*ReflectedRay+vec3(0.5,0.5,0.5);
	// gl_FragColor = clamp(textureCube(EnvironmentMap, ReflectedRay),0.0,1.0);
  gl_FragColor = vec4(1.0, 0.0, 0.0, 0.0);
}
