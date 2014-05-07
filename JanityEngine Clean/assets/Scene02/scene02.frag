precision mediump float;

varying vec2 Uv;
uniform sampler2D s_texture;

void main() {
	gl_FragColor = texture2D(s_texture,Uv);
}