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
// CreateShadow
//--------------------------------------------------------------//
string NormalMapping_CreateShadow_Model : ModelData = "..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Models\\Torus.3ds";

texture ShadowMap_Tex : RenderColorTarget
<
   float2 RenderTargetDimensions = {2048,2048};
   string Format="D3DFMT_R32F";
   float  ClearDepth=1.000000;
   int    ClearColor=-1;
>;
float4x4 gWorldMatrix : World;
float4x4 gProjectionMatrix : Projection;
float4x4 gLightViewMatrix;
float4x4 gLightProjection;
float4 gWorldLightPosition
<
   string UIName = "gWorldLightPosition";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 500.00, 500.00, -500.00, 1.00 );

struct VS_INPUT 
{
   float4 Position : POSITION0;
};

struct VS_OUTPUT 
{
   float4 Position       : POSITION0;
   float4 ClipPosition   : TEXCOORD1;
};

VS_OUTPUT NormalMapping_CreateShadow_Vertex_Shader_vs_main( VS_INPUT Input )
{
   VS_OUTPUT Output;
   
   float4x4 lightViewMatrix = gLightViewMatrix;   

   Output.Position = mul( Input.Position, gWorldMatrix );
   Output.Position = mul( Output.Position, lightViewMatrix );
   Output.Position = mul( Output.Position, gLightProjection);
  
   Output.ClipPosition = Output.Position;
  
   return( Output );
}


struct PS_INPUT
{
   float4 ClipPosition: TEXCOORD1;
};
float4 NormalMapping_CreateShadow_Pixel_Shader_ps_main(PS_INPUT Input) : COLOR0
{   
   float depth = Input.ClipPosition.z / Input.ClipPosition.w;
   return float4(depth.xxx, 1.0f);
}

//--------------------------------------------------------------//
// Pass 0
//--------------------------------------------------------------//
string NormalMapping_Pass_0_Model : ModelData = "..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Models\\Torus.3ds";

float4x4 NormalMapping_Pass_0_Vertex_Shader_gWorldMatrix : World;
float4x4 gWorldViewProjectionMatrix : WorldViewProjection;

float4 NormalMapping_Pass_0_Vertex_Shader_gWorldLightPosition
<
   string UIName = "NormalMapping_Pass_0_Vertex_Shader_gWorldLightPosition";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 500.00, 500.00, -500.00, 1.00 );
float4 gWorldCameraPosition : ViewPosition;
float4x4 NormalMapping_Pass_0_Vertex_Shader_gProjectionMatrix : Projection;

float4x4 NormalMapping_Pass_0_Vertex_Shader_gLightViewMatrix;

float4x4 gLightProjection_2;


struct NormalMapping_Pass_0_Vertex_Shader_VS_INPUT 
{
   float4 mPosition : POSITION0;
   float3 mNormal: NORMAL;
   float3 mTangent: TANGENT;
   float3 mBinormal: BINORMAL;
   float2 mUV: TEXCOORD0;
};

struct NormalMapping_Pass_0_Vertex_Shader_VS_OUTPUT 
{
   float4 mPosition : POSITION0;
   float2 mUV: TEXCOORD0;
   float3 mLightDir : TEXCOORD1;
   float3 mViewDir: TEXCOORD2;
   float3 T : TEXCOORD3;
   float3 B : TEXCOORD4;
   float3 N : TEXCOORD5;
   float4 mClip_Position : TEXCOORD6;
   float4 ClipPosition   :  TEXCOORD7;
};

NormalMapping_Pass_0_Vertex_Shader_VS_OUTPUT NormalMapping_Pass_0_Vertex_Shader_vs_main( NormalMapping_Pass_0_Vertex_Shader_VS_INPUT Input )
{
   NormalMapping_Pass_0_Vertex_Shader_VS_OUTPUT Output;
   
  float4x4 lightViewMatrix = NormalMapping_Pass_0_Vertex_Shader_gLightViewMatrix;
   

   Output.mPosition = mul( Input.mPosition, gWorldViewProjectionMatrix );
   Output.mUV = Input.mUV;

   float4 worldPosition = mul( Input.mPosition, NormalMapping_Pass_0_Vertex_Shader_gWorldMatrix );
   float3 lightDir = worldPosition.xyz - NormalMapping_Pass_0_Vertex_Shader_gWorldLightPosition.xyz;
   Output.mLightDir = normalize(lightDir);
   
   float3 viewDir = normalize(worldPosition.xyz - gWorldCameraPosition.xyz);
   Output.mViewDir = viewDir;
   
   float3 worldNormal = mul( Input.mNormal, (float3x3)NormalMapping_Pass_0_Vertex_Shader_gWorldMatrix );
   Output.N = normalize(worldNormal);
   
   float3 worldTangent = mul(Input.mTangent, (float3x3)NormalMapping_Pass_0_Vertex_Shader_gWorldMatrix );
   Output.T = normalize(worldTangent);
   
   float3 worldBinormal = mul(Input.mBinormal, (float3x3)NormalMapping_Pass_0_Vertex_Shader_gWorldMatrix );
   Output.B = normalize(worldBinormal);
   
   Output.mClip_Position = mul( Input.mPosition, NormalMapping_Pass_0_Vertex_Shader_gWorldMatrix );
   
   Output.ClipPosition = Input.mPosition;
   Output.ClipPosition = mul(Output.ClipPosition, NormalMapping_Pass_0_Vertex_Shader_gWorldMatrix);
   Output.ClipPosition = mul(Output.ClipPosition, lightViewMatrix);
   Output.ClipPosition = mul(Output.ClipPosition, gLightProjection_2);
   
   
   return Output;
}




float4 gLightColor_1
<
   string UIName = "gLightColor_1";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 0.00, 0.00, 0.00, 1.00 );
float4 gLightColor_2
<
   string UIName = "gLightColor_2";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 1.00, 1.00, 1.00, 1.00 );
float4 NormalMapping_Pass_0_Pixel_Shader_gWorldLightPosition
<
   string UIName = "NormalMapping_Pass_0_Pixel_Shader_gWorldLightPosition";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 500.00, 500.00, -500.00, 1.00 );

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
sampler2D ShadowMap = sampler_state
{
   Texture = (ShadowMap_Tex);
};

struct NormalMapping_Pass_0_Pixel_Shader_PS_INPUT
{
   float2 mUV : TEXCOORD0;
   float3 mLightDir : TEXCOORD1;
   float3 mViewDir: TEXCOORD2;
   float3 T : TEXCOORD3;
   float3 B : TEXCOORD4;
   float3 N : TEXCOORD5;
   float4 mClip_Position : TEXCOORD6;
   float4 ClipPosition   :  TEXCOORD7;
};



float4 NormalMapping_Pass_0_Pixel_Shader_ps_main(NormalMapping_Pass_0_Pixel_Shader_PS_INPUT Input) : COLOR
{
   float depth = Input.ClipPosition.z / Input.ClipPosition.w;
   float2 uv = Input.ClipPosition.xy / Input.ClipPosition.w;
   uv.y = -uv.y;
   uv = uv * 0.5f + 0.5f;
   
   float shadowMapDepth = tex2D(ShadowMap,uv).x;
   float colorWeight = 1.0f;
   if(depth > shadowMapDepth + 0.0000125f)
   {
      colorWeight *= 0.3f;
   }
   
   float3 tangentNormal = tex2D(NormalSampler, Input.mUV).xyz;
   tangentNormal = normalize(tangentNormal * 2 - 1);
   
   float LEGTH_FLOAT = distance(Input.mClip_Position, NormalMapping_Pass_0_Pixel_Shader_gWorldLightPosition);
   
   
   
   float3x3 TBN = float3x3(normalize(Input.T), normalize(Input.B), normalize(Input.N));
   TBN = transpose(TBN);
   
   float3 worldNormal = mul(TBN, tangentNormal);
   
   float4 albedo = tex2D(DiffuseSampler, Input.mUV);
   float3 lightDir = normalize(Input.mLightDir);
   float3 diffuse = saturate(dot(worldNormal, -lightDir));
   
   if(LEGTH_FLOAT < 10.0f)
   {
     float InterSept =  (10.0f-LEGTH_FLOAT)/ 10.0f; 
     float4 gLightColor_2_Inter = gLightColor_2;
     gLightColor_2_Inter.xyz *= InterSept;
     diffuse = gLightColor_2_Inter.xyz * albedo.rgb * diffuse;
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
   return float4((ambient + diffuse + specular) , 1)* colorWeight;
}

//--------------------------------------------------------------//
// Technique Section for NormalMapping
//--------------------------------------------------------------//
technique NormalMapping
{
   pass CreateShadow
   <
      string Script = "RenderColorTarget0 = ShadowMap_Tex;"
                      "ClearColor = (255, 255, 255, 255);"
                      "ClearDepth = 1.000000;";
   >
   {
      VertexShader = compile vs_2_0 NormalMapping_CreateShadow_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 NormalMapping_CreateShadow_Pixel_Shader_ps_main();
   }

   pass Pass_0
   {
      VertexShader = compile vs_2_0 NormalMapping_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_2_0 NormalMapping_Pass_0_Pixel_Shader_ps_main();
   }

}

