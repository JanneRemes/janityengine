attribute vec3 vPosition;
attribute vec2 vUv;

uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Model;

varying vec2 Uv;

void main() {
	vec4 pos = vec4(vPosition,1.0);
	gl_Position = Projection * View * Model * pos;
	Uv = vUv;
    }
