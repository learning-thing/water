#version 330

out vec4 finalColor;

in vec4 fragColor;
in vec3 fragPosition;
in vec3 fragNormal;

uniform vec3 LightPos;
uniform vec3 viewPos;

uniform float iTime;

vec3 lightPosition = LightPos;
float ambientStrength = 0.1;

void main() {
    vec3 col = vec3(0.0941, 0.502, 0.8784)+1+sin(iTime+fragPosition.x+fragPosition.z)*.5;
    
    vec3 ambientColor = vec3(0.4392, 0.4392, 0.4392);
    // ambient
    vec3 ambient = ambientStrength * ambientColor;
    float dist =  length(viewPos-fragPosition);
    // diffuse 
    vec3 norm = normalize(fragNormal);//Frag Normal
    vec3 lightDir = normalize(lightPosition - fragPosition);//normalised Light direction vector
    float diff = max(dot(norm, lightDir), 0.0);//Raw diffused value
    vec3 diffuse = diff * ambientColor;//Final Diffused Value

    vec3 result = (ambient + diffuse) * col; 
    finalColor = vec4(result, fragColor.a);
} 