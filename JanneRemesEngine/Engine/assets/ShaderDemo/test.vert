attribute vec3 vPosition;
attribute vec2 vUv;

uniform mat4 Projection;
uniform mat4 Translation;
uniform mat4 Scale;
uniform mat4 Rotation;

varying vec2 Uv;

void main() {
	gl_Position = vec4(vPosition,1.0);
	gl_Position *= Scale;
	gl_Position *= Rotation;
	gl_Position *= Translation*Projection;	
	Uv = vUv;
    }
