varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
void main(){
    float timeFactor=1;
    float texFactor=10;
    float ampFactor=0.01f;
    float timeFactorV=1;
    float texFactorV=10;
    float ampFactorV=0.01f;
    v_texCoord.x+=sin(CC_Time.y*timeFactorV+v_texCoord.x*texFactorV)*ampFactorV;
    v_texCoord.y+=cos(CC_Time.y*timeFactorV+v_texCoord.y*texFactorV)*ampFactorV;
    gl_FragColor=texture2D(CC_Texture0,v_texCoord)*v_fragmentColor;
}


