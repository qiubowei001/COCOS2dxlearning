varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

float waveHeight(vec2 p){
    float timeFactor=4.0;
    float texFactor=12.0;
    float ampFactor=0.01;
    float dist=length(p);
    return cos(CC_Time.y*timeFactor+dist*texFactor)*ampFactor;
}

void main(){
    //convertto[-1,1]
    vec2 p=-1.0+2.0*v_texCoord;
    vec2 normal=normalize(p);
    //offset texcoord along distdirection
    v_texCoord+=normal*waveHeight(p);
    gl_FragColor=texture2D(CC_Texture0,v_texCoord)*v_fragmentColor;
}