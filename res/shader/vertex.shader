/*#version 430

layout(location = 0) in vec3 position;
// T R A N S L A T E
mat4 buildTranslate(float x, float y, float z)
{
    mat4 trans = mat4(
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        x, y, z, 1.0);
    return trans;
}
// R O T A T I O N
mat4 buildRotateZ(float rad)
{
    mat4 zrot = mat4(
        cos(rad), -sin(rad), 0.0, 0.0,
        sin(rad), cos(rad), 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0);
    return zrot;
}

uniform float offsetM;

void main(void)
{
    // Original triangle points
    vec4 vertex0 = vec4(0.25, -0.25, 0.0, 1.0);
    vec4 vertex1 = vec4(-0.25, -0.25, 0.0, 1.0);
    vec4 vertex2 = vec4(0.25, 0.25, 0.0, 1.0);

    //Apply rotation by calling the buildRotateZ function
    float angle = radians(offsetM);  // Convert offset to radians
    mat4 rotationMatrix = buildRotateZ(angle);

    mat4 transMatrex = buildTranslate(-0.5, 0.5, 0);
    // Rotate each vertex
    vertex0 = rotationMatrix * vertex0;
    vertex1 = rotationMatrix * vertex1;
    vertex2 = rotationMatrix * vertex2;

    //vertex0 = transMatrex * vertex0;
    //vertex1 = transMatrex * vertex1;
    //vertex2 = transMatrex * vertex2;

    // Set the position of the vertices after rotation
    if (gl_VertexID == 0) gl_Position = vertex0;
    else if (gl_VertexID == 1) gl_Position = vertex1;
    else gl_Position = vertex2;
}*/


#version 430
layout(location = 0) in vec3 position;

/*mat4 buildRotateX(float rad) {
    float c = cos(rad);
    float s = sin(rad);
    return mat4(
        1.0, 0.0, 0.0, 0.0,
        0.0, c, -s, 0.0,
        0.0, s, c, 0.0,
        0.0, 0.0, 0.0, 1.0
    );
}

mat4 buildRotateY(float rad) {
    float c = cos(rad);
    float s = sin(rad);
    return mat4(
        c, 0.0, s, 0.0,
        0.0, 1.0, 0.0, 0.0,
        -s, 0.0, c, 0.0,
        0.0, 0.0, 0.0, 1.0
    );
}

mat4 buildRotateZ(float rad) {
    float c = cos(rad);
    float s = sin(rad);
    return mat4(
        c, -s, 0.0, 0.0,
        s, c, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    );
}

mat4 buildTranslate(float x, float y, float z) {
    return mat4(
        1.0, 0.0, 0.0, x,
        0.0, 1.0, 0.0, y,
        0.0, 0.0, 1.0, z,
        0.0, 0.0, 0.0, 1.0
    );
}*/


//uniform mat4 v_matrix;
//uniform float tf;
uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

out vec4 varyingColor;

void main(void)
{
   /* //float i = gl_InstanceID + tf; 
    float i = gl_InstanceID + tf * gl_InstanceID; // Modify tf to differentiate instances
    float a = sin(203.0 * i / 8000.0) * 403.0;
    float b = cos(301.0 * i / 4001.0) * 401.0;
    float c = sin(400.0 * i / 6003.0) * 405.0;


    mat4 localRotX = buildRotateX(1000 * i);
    mat4 localRotY = buildRotateY(1000 * i);
    mat4 localRotZ = buildRotateZ(1000 * i);
    mat4 localTrans = buildTranslate(a, b, c);
    // build the model matrix and then the model-view matrix
    mat4 newM_matrix = localTrans * localRotX * localRotY * localRotZ;
    mat4 mv_matrix = v_matrix * newM_matrix;*/
 
    gl_Position = proj_matrix * mv_matrix * vec4(position, 1.0);
    varyingColor = vec4(position, 1.0) * 0.5 + vec4(0.5, 0.5, 0.5, 0.5);
}