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
// NormalMapping
//--------------------------------------------------------------//
//--------------------------------------------------------------//
// Pass 0
//--------------------------------------------------------------//
string NormalMapping_Pass_0_Model : ModelData = "..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Models\\Sphere.3ds";

float4x4 gWorldMatrix : World;
float4x4 gWorldViewProjectionMatrix : WorldViewProjection;

float4 gWorldLightPosition
<
   string UIName = "gWorldLightPosition";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 500.00, 500.00, -500.00, 1.00 );
float4 gWorldCameraPosition : ViewPosition;



struct VS_INPUT 
{
   float4 mPosition : POSITION;
   float3 mNormal: NORMAL;
   float3 mTangent: TANGENT;
   float3 mBinormal: BINORMAL;
   float2 mUV: TEXCOORD0;
};

struct VS_OUTPUT 
{
   float4 mPosition : POSITION;
   float2 mUV: TEXCOORD0;
   float3 mLightDir : TEXCOORD1;
   float3 mViewDir: TEXCOORD2;
   float3 T : TEXCOORD3;
   float3 B : TEXCOORD4;
   float3 N : TEXCOORD5;
};

VS_OUTPUT NormalMapping_Pass_0_Vertex_Shader_vs_main( VS_INPUT Input )
{
   VS_OUTPUT Output;

   Output.mPosition = mul( Input.mPosition, gWorldViewProjectionMatrix );
   Output.mUV = Input.mUV;

   float4 worldPosition = mul( Input.mPosition, gWorldMatrix );
   float3 lightDir = worldPosition.xyz - gWorldLightPosition.xyz;
   Output.mLightDir = normalize(lightDir);
   
   float3 viewDir = normalize(worldPosition.xyz - gWorldCameraPosition.xyz);
   Output.mViewDir = viewDir;
   
   float3 worldNormal = mul( Input.mNormal, (float3x3)gWorldMatrix );
   Output.N = normalize(worldNormal);
   
   float3 worldTangent = mul(Input.mTangent, (float3x3)gWorldMatrix );
   Output.T = normalize(worldTangent);
   
   float3 worldBinormal = mul(Input.mBinormal, (float3x3)gWorldMatrix );
   Output.B = normalize(worldBinormal);
   
   return Output;
}




struct PS_INPUT
{
   float2 mUV : TEXCOORD0;
   float3 mLightDir : TEXCOORD1;
   float3 mViewDir: TEXCOORD2;
   float3 T : TEXCOORD3;
   float3 B : TEXCOORD4;
   float3 N : TEXCOORD5;
};

texture DiffuseMap_Tex
<
   string ResourceName = "..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Textures\\Fieldstone.tga";
>;
sampler2D DiffuseSampler = sampler_state
{
   Texture = (DiffuseMap_Tex);
   MAGFILTER = LINEAR;
   MINFILTER = LINEAR;
};
texture SpecularMap_Tex
<
   string ResourceName = ".\\ptT �i\\PtT  ��\\07_NormalMapping\\fieldstone_SM.tga";
>;
sampler2D SpecularSampler = sampler_state
{
   Texture = (SpecularMap_Tex);
   MAGFILTER = LINEAR;
   MINFILTER = LINEAR;
};
texture NormalMap_Tex
<
   string ResourceName = "..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Textures\\FieldstoneBumpDOT3.tga";
>;
sampler2D NormalSampler = sampler_state
{
   Texture = (NormalMap_Tex);
   MAGFILTER = LINEAR;
   MINFILTER = LINEAR;
};

float3 gLightColor;

float4 gLightColor_1
<
   string UIName = "gLightColor_1";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 0.10, 0.10, 0.10, 1.00 );
float4 gLightColor_2
<
   string UIName = "gLightColor_2";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 1.00, 1.00, 1.00, 1.00 );

float gLightLength
<
   string UIName = "gLightLength";
   string UIWidget = "Numeric";
   bool UIVisible =  false;
   float UIMin = -1.00;
   float UIMax = 1.00;
> = float( 7.00 );

float4 NormalMapping_Pass_0_Pixel_Shader_ps_main(PS_INPUT Input) : COLOR
{
   float3 tangentNormal = tex2D(NormalSampler, Input.mUV).xyz;
   tangentNormal = normalize(tangentNormal * 2 - 1);
   
   float3x3 TBN = float3x3(normalize(Input.T), normalize(Input.B), normalize(Input.N));
   TBN = transpose(TBN);
   float3 worldNormal = mul(TBN, tangentNormal);
   
   float4 albedo = tex2D(DiffuseSampler, Input.mUV);
   float3 lightDir = normalize(Input.mLightDir);
   float3 diffuse = saturate(dot(worldNormal, -lightDir));
   if(gLightLength < 6.0f)
   {
      diffuse = gLightColor_2.xyz * albedo.rgb * diffuse;
   }
   else
   {
      diffuse = gLightColor_1.xyz * albedo.rgb * diffuse;
   }
   
   
   float3 specular = 0;
   if ( diffuse.x > 0 )
   {
      float3 reflection = reflect(lightDir, worldNormal);
      float3 viewDir = normalize(Input.mViewDir); 

      specular = saturate(dot(reflection, -viewDir ));
      specular = pow(specular, 20.0f);
      
      float4 specularIntensity  = tex2D(SpecularSampler, Input.mUV);
      specular *= specularIntensity.rgb * gLightColor_2.xyz;
   }

   float3 ambient = float3(0.1f, 0.1f, 0.1f) * albedo;
   
   return float4(ambient + diffuse + specular, 1);
}

//--------------------------------------------------------------//
// Technique Section for NormalMapping
//--------------------------------------------------------------//
technique NormalMapping
{
   pass Pass_0
   {
      VertexShader = compile vs_2_0 NormalMapping_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 NormalMapping_Pass_0_Pixel_Shader_ps_main();
   }

}

