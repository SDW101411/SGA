//**************************************************************//
//  Effect File exported by RenderMonkey 1.6
//
//  - Although many improvements were made to RenderMonkey FX  
//    file export, there are still situations that may cause   
//    compilation problems once the file is exported, such as  
//    occasional naming conflicts for methods, since FX format 
//    does not support any notions of name spaces. You need to 
//    try to create workspaces in such a way as to minimize    
//    potential naming conflicts on export.                    
//    
//  - Note that to minimize resulting name collisions in the FX 
//    file, RenderMonkey will mangle names for passes, shaders  
//    and function names as necessary to reduce name conflicts. 
//**************************************************************//

//--------------------------------------------------------------//
// Textured Phong
//--------------------------------------------------------------//
//--------------------------------------------------------------//
// Pass 0
//--------------------------------------------------------------//
string Textured_Phong_Pass_0_Model : ModelData = "..\\..\\..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Models\\Sphere.x";

float3 fvLightPosition
<
   string UIName = "fvLightPosition";
   string UIWidget = "Numeric";
   bool UIVisible =  true;
   float UIMin = -100.00;
   float UIMax = 100.00;
> = float3( -100.00, 100.00, -100.00 );
float3 fvEyePosition
<
   string UIName = "fvEyePosition";
   string UIWidget = "Numeric";
   bool UIVisible =  false;
   float UIMin = -100.00;
   float UIMax = 100.00;
> = float3( 0.00, 0.00, -100.00 );
float4x4 matWorld : World;
float4x4 matWorldViewProjection : WorldViewProjection;
float4x4 matViewProjection : ViewProjection;

struct VS_INPUT 
{
   float4 Position : POSITION0;
   float2 Texcoord : TEXCOORD0;
   float3 Normal :   NORMAL0;
   
};

struct VS_OUTPUT 
{
   float4 Position :        POSITION0;
   float2 Texcoord :        TEXCOORD0;
   float3 ViewDirection :   TEXCOORD1;
   float3 LightDirection :  TEXCOORD2;
   float3 Normal :          TEXCOORD3;
   
};

VS_OUTPUT Textured_Phong_Pass_0_Vertex_Shader_vs_main( VS_INPUT Input )
{
   VS_OUTPUT Output;

   Output.Position         = mul( Input.Position, matWorldViewProjection );
   Output.Texcoord         = Input.Texcoord;
   
   float3 fvObjectPosition = mul( Input.Position, matWorld );
   
   Output.ViewDirection    = fvEyePosition - fvObjectPosition;
   Output.LightDirection   = fvLightPosition - fvObjectPosition;
   
   Output.ViewDirection    = mul(Output.ViewDirection, matViewProjection);
   Output.LightDirection   = mul(Output.LightDirection, matViewProjection);
   
   Output.Normal           = mul( Input.Normal, matWorldViewProjection );
      
   return( Output );
   
}



float4 fvAmbient
<
   string UIName = "fvAmbient";
   string UIWidget = "Color";
   bool UIVisible =  true;
> = float4( 0.37, 0.37, 0.37, 1.00 );
float4 fvSpecular
<
   string UIName = "fvSpecular";
   string UIWidget = "Color";
   bool UIVisible =  true;
> = float4( 0.49, 0.49, 0.49, 1.00 );
float4 fvDiffuse
<
   string UIName = "fvDiffuse";
   string UIWidget = "Color";
   bool UIVisible =  true;
> = float4( 0.89, 0.89, 0.89, 1.00 );
float fSpecularPower
<
   string UIName = "fSpecularPower";
   string UIWidget = "Numeric";
   bool UIVisible =  true;
   float UIMin = 1.00;
   float UIMax = 100.00;
> = float( 25.00 );
texture base_Tex
<
   string ResourceName = "..\\..\\..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Textures\\Bubble\\rainbowfilm_smooth.bmp";
>;
sampler2D baseMap = sampler_state
{
   Texture = (base_Tex);
   ADDRESSU = WRAP;
   ADDRESSV = WRAP;
   MINFILTER = LINEAR;
   MAGFILTER = LINEAR;
   MIPFILTER = LINEAR;
};

struct PS_INPUT 
{
   float2 Texcoord :        TEXCOORD0;
   float3 ViewDirection :   TEXCOORD1;
   float3 LightDirection:   TEXCOORD2;
   float3 Normal :          TEXCOORD3;
   
};

float4 Textured_Phong_Pass_0_Pixel_Shader_ps_main( PS_INPUT Input ) : COLOR0
{      
   float3 fvLightDirection = normalize( Input.LightDirection );
   float3 fvNormal         = normalize( Input.Normal );
   float  fNDotL           = dot( fvNormal, fvLightDirection ); 
   
   float fRDotV = 0.0f;
   if(fNDotL > 0.0f)
   {
      float3 fvReflection     = normalize(reflect(-fvLightDirection, fvNormal)); 
      float3 fvViewDirection  = normalize( Input.ViewDirection );
      fRDotV           = max( 0.0f, dot( fvReflection, fvViewDirection ) );
   
   }
   
   //float3 fvReflection     = normalize( ( ( 2.0f * fvNormal ) * ( fNDotL ) ) - fvLightDirection ); 
   
   float4 fvBaseColor      = tex2D( baseMap, Input.Texcoord );
   
   float4 fvTotalAmbient   = fvAmbient * fvBaseColor; 
   float4 fvTotalDiffuse   = fvDiffuse * fNDotL * fvBaseColor; 
   float4 fvTotalSpecular  = fvSpecular * pow( fRDotV, fSpecularPower );
   
   return( saturate( fvTotalAmbient + fvTotalDiffuse + fvTotalSpecular ) );
      
}



//--------------------------------------------------------------//
// Technique Section for Textured Phong
//--------------------------------------------------------------//
technique Textured_Phong
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 Textured_Phong_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 Textured_Phong_Pass_0_Pixel_Shader_ps_main();
   }

}

