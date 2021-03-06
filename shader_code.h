/* File generated with Shader Minifier 1.2
 * http://www.ctrl-alt-test.fr
 */
#ifndef SHADER_CODE_H_
# define SHADER_CODE_H_
# define VAR_IMG_OUTPUT "v"
# define VAR_STAGE "i"
# define VAR_TEST "m"
# define VAR_TIME "f"

const char *shader1_cs =
 "#version 430\n"
 "layout(local_size_x=1,local_size_y=1,local_size_z=1)in;"
 "layout(rgba32f,binding=0)uniform image3D v;"
 "uniform float m=1.;"
 "uniform int i=0;"
 "uniform float f=0.;\n"
 "#define cellsize 2.0\n"
 "#define MAXSTEPS 1200\n"
 "#define SURFACEDIST 0.01\n"
 "#define MAXDIST 750.\n"
 "#define SIZEX 1280.0\n"
 "#define SIZEY 720.0\n"
 "vec3 r;"
 "ivec3 S=ivec3(gl_GlobalInvocationID.xyz);"
 "vec3 z=vec3(gl_GlobalInvocationID.xyz);"
 "float s(vec3 v)"
 "{"
   "return fract(sin(dot(cross(v,vec3(33.,77.,66.)),vec3(7777.,3333.,7777.)))*77777.);"
 "}"
 "mat3 d(float v)"
 "{"
   "float S=cos(v),f=sin(v);"
   "return mat3(vec3(1,0,0),vec3(0,S,-f),vec3(0,f,S));"
 "}"
 "mat3 n(float v)"
 "{"
   "float S=cos(v),f=sin(v);"
   "return mat3(vec3(S,0,f),vec3(0,1,0),vec3(-f,0,S));"
 "}"
 "mat3 t(float v)"
 "{"
   "float S=cos(v),f=sin(v);"
   "return mat3(vec3(S,-f,0),vec3(f,S,0),vec3(0,0,1));"
 "}"
 "float d(vec3 v,float f)"
 "{"
   "return length(v)-f;"
 "}"
 "float n(in vec3 v,vec4 S)"
 "{"
   "return dot(v,S.xyz)*S.w;"
 "}"
 "float e(in vec3 S)"
 "{"
   "float f=n(S,vec4(0.,1.,0.,2.));"
   "vec4 i=imageLoad(v,ivec3(mod(S.x*cellsize,SIZEX),mod(S.z*cellsize,SIZEY),0.));"
   "i=i*i*(s(vec3(f))*5);"
   //"//if(mod(f,4.) < 0.1){i*=100.;}"
   "return f-i.w;"
 "}"
 "float c(vec3 v)"
 "{"
   "float S=e(v)*.1,f=d(v-r,20.);"
   "return max(-f,S);"
 "}"
 "float c(vec3 v,vec3 S)"
 "{"
   "float f=0.;"
   "for(int i=0;i<MAXSTEPS;i++)"
     "{"
       "vec3 z=v+f*S;"
       "float m=c(z);"
       "f+=m;"
       "if(m<SURFACEDIST||f>MAXDIST)"
         "break;"
     "}"
   "return f;"
 "}"
 "vec3 a(vec3 v)"
 "{"
   "float S=c(v);"
   "vec3 f=vec3(.01,0.,1.),i=S-vec3(S-c(v-f.xyy),S-c(v-f.yxy),S-c(v-f.yyx));"
   "return normalize(i);"
 "}"
 "float M(vec3 v)"
 "{"
   "vec3 S=vec3(-20,20,6),f=normalize(S-v),i=a(v);"
   "float m=dot(i,f),z=c(v+i*SURFACEDIST*2.,f);"
   "if(z<length(S-v))"
     "m*=.1;"
   "return m;"
 "}"
 "void main()"
 "{"
   "vec4 m=imageLoad(v,S);"
   "if(S.z==1)"
     "{"
       "m=vec4(0.,0.,0.,1.);"
       "vec2 g=(z.xy-.5*vec2(SIZEX,SIZEY))/SIZEY;"
       "vec3 e=vec3(sin(f),720-min(f*50, 715+((f-90)/10.)),-10.+f*2.);"
       "r=e;"
       "vec3 y=normalize(vec3(g.x,g.y,2.)+vec3(0.,0.,0.));"
	   "if(f*5 > 72){y*=d(1.57-min(1.57, ((f*5.)-72)/10.));}"
	   "else {y*=d(1.57);}"
       "float n=c(e,y);"
       "vec3 u;"
       "if(n<MAXDIST)"
         "{"
           "vec3 Y=e+y*n;"
           "float X=M(Y);"
           "u=vec3(X);"
           "u=pow(u,vec3(.02545));"
           "vec4 a=vec4(floor(Y.y*100.)/100.);"
           "a=imageLoad(v,ivec3(mod(Y.x*cellsize,SIZEX),mod(Y.z*cellsize,SIZEY),0));"
           "u*=a;"
         "}"
       "else"
         " u=imageLoad(v,S+ivec3(0,0,1)).xyz;"
       "m=vec4(u,1.);"
       "imageStore(v,S,m);"
       "return;"
     "}"
   "if(i==0)"
     "{"
       "float Y=s(z);"
       "m=vec4(Y);"
     "}"
   "if(i==1)"
     "{"
       "int Y=0,a=1,y=1,e=16;"
       "float u=.001;"
       "if(S.z==2)"
         "a=1,y=1,e=15;"
       "for(int X=-a;X<=a;X++)"
         "for(int n=-abs(a-X);n<=abs(a-X);n++)"
           "for(int g=-abs(a-n);g<=abs(a-n);g++)"
             "{"
               "if(ivec3(X,n,g)==S)"
                 "break;"
               "vec4 D=imageLoad(v,ivec3(S.x+X,S.y+n,z.z));"
               "if(D.w-fract(m.w+1./e)<u)"
                 "Y+=1;"
             "}"
       "if(Y>y)"
         "m.w+=1./e,m=vec4(m.w),m=vec4(s(m.xyz),s(m.xyz+vec3(2.+z.z+floor(f/4.))),s(m.xyz+vec3(3.+z.z+floor(f/4.))),m.w);"
       "if(m.w>1.001)"
         "m=vec4(0.);"
     "}"
   "imageStore(v,S,m);"
 "}";

#endif // SHADER_CODE_H_
