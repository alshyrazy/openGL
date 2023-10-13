/*#version 430
out vec4 color;
void main(void)
{
	if (gl_FragCoord.x < 295) 
		color = vec4(1.0, 0.0, 1.0, 0.0);
	else 
		color = vec4(0.0, 0.0, 1.0, 1.0);
}*/


#version 430
out vec4 color;
uniform mat4 mv_matrix;
uniform mat4 proj_matrix;
in vec4 varyingColor;
void main(void)
{
	if (gl_FragCoord.x < 595)
		color = varyingColor;
	else
		color = vec4(0.0, 0.5, 0.0, 1.0);
}