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
// Normal_Light_ALL
//--------------------------------------------------------------//
//--------------------------------------------------------------//
// OutLine
//--------------------------------------------------------------//
string Normal_Light_ALL_OutLine_Model : ModelData = "..\\..\\..\\..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Models\\ElephantBody.3ds";

float4x4 gVPmatrix : ViewProjection;
float4x4 gWorldViewProjectionMatrix : WorldViewProjection;
float4x4 gViewMatrix : View;
float4x4 gProjectionMatrix : Projection;
float4x4 gWorldMatrix : World;
bool OutLine_On_Off
<
   string UIName = "OutLine_On_Off";
   string UIWidget = "Numeric";
   bool UIVisible =  false;
> = bool( true );


struct VS_INPUT 
{
   float4 Position : POSITION0;
   float4 Normal: NORMAL0; 
};

struct VS_OUTPUT 
{
   float4 Position : POSITION0;
   
};

VS_OUTPUT Normal_Light_ALL_OutLine_Vertex_Shader_vs_main( VS_INPUT Input )
{
   VS_OUTPUT Output;

   Output.Position = mul( Input.Position, gWorldMatrix );
   float3 fvWorldNormal = normalize(mul(Input.Normal, gWorldMatrix));
   if(OutLine_On_Off)
   {
      Output.Position.xy += fvWorldNormal.xy * 0.004f;
   }
   else
   {
      Output.Position.xy += fvWorldNormal.xy * 0.0f;
   }
   
   Output.Position  = mul(Output.Position, gViewMatrix);
   Output.Position  = mul(Output.Position, gProjectionMatrix);
   return( Output );
   
}

float4 Normal_Light_ALL_OutLine_Pixel_Shader_ps_main() : COLOR0
{   
   return( float4( 1.0f, 1.0f, 1.0f, 1.0f ) );
   
}




//--------------------------------------------------------------//
// Pass 0
//--------------------------------------------------------------//
string Normal_Light_ALL_Pass_0_Model : ModelData = "..\\..\\..\\..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Models\\ElephantBody.3ds";

//float4x4 gWorldMatrix : World;


float4 gWorldLightPosition
<
   string UIName = "gWorldLightPosition";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( -300.00, 0.00, 0.00, 1.00 );
float4 gWorldLightPosition_2
<
   string UIName = "gWorldLightPosition_2";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 100.00, 100.00, -200.00, 1.00 );
float4 gWorldLightPosition_3
<
   string UIName = "gWorldLightPosition_3";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( -100.00, 100.00, -200.00, 1.00 );
float4 gWorldLightPosition_4
<
   string UIName = "gWorldLightPosition_4";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( -100.00, -100.00, -200.00, 1.00 );

float4 gWorldCameraPosition : ViewPosition;




struct Normal_Light_ALL_Pass_0_Vertex_Shader_VS_INPUT 
{
   float4 mPosition : POSITION0;
   float3 mNormal: NORMAL;
   float3 mTangent: TANGENT;
   float3 mBinormal: BINORMAL;
   float2 mUV: TEXCOORD0;
};

struct Normal_Light_ALL_Pass_0_Vertex_Shader_VS_OUTPUT 
{
   float4 mPosition : POSITION0;
   float2 mUV: TEXCOORD0;
   float3 mLightDir : TEXCOORD1;
   float3 mViewDir: TEXCOORD2;
   float3 T : TEXCOORD3;
   float3 B : TEXCOORD4;
   float3 N : TEXCOORD5;
   float4 mClip_Position : TEXCOORD6;
   float3 mLightDir_2 : TEXCOORD7;
   float3 mLightDir_3 : TEXCOORD8;
   float3 mLightDir_4 : TEXCOORD9;
};

Normal_Light_ALL_Pass_0_Vertex_Shader_VS_OUTPUT Normal_Light_ALL_Pass_0_Vertex_Shader_vs_main( Normal_Light_ALL_Pass_0_Vertex_Shader_VS_INPUT Input )
{
   Normal_Light_ALL_Pass_0_Vertex_Shader_VS_OUTPUT Output;

   Output.mPosition = mul( Input.mPosition, gWorldViewProjectionMatrix );
   Output.mUV = Input.mUV;

   float4 worldPosition = mul( Input.mPosition, gWorldMatrix );
   float3 lightDir = worldPosition.xyz - gWorldLightPosition.xyz;
   float3 lightDir_2 = worldPosition.xyz - gWorldLightPosition_2.xyz;
   float3 lightDir_3 = worldPosition.xyz - gWorldLightPosition_3.xyz;
   float3 lightDir_4 = worldPosition.xyz - gWorldLightPosition_4.xyz;
 
   Output.mLightDir = normalize(lightDir);
   Output.mLightDir_2 = normalize(lightDir_2);
   Output.mLightDir_3 = normalize(lightDir_3);
   Output.mLightDir_4 = normalize(lightDir_4);
   
   float3 viewDir = normalize(worldPosition.xyz - gWorldCameraPosition.xyz);
   Output.mViewDir = viewDir;
   
   float3 worldNormal = mul( Input.mNormal, (float3x3)gWorldMatrix );
   Output.N = normalize(worldNormal);
   
   float3 worldTangent = mul(Input.mTangent, (float3x3)gWorldMatrix );
   Output.T = normalize(worldTangent);
   
   float3 worldBinormal = mul(Input.mBinormal, (float3x3)gWorldMatrix );
   Output.B = normalize(worldBinormal);
   
   Output.mClip_Position = mul( Input.mPosition, gWorldMatrix );
   
   return Output;
}




texture DiffuseMap_Tex
<
   string ResourceName = "..\\..\\..\\..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Textures\\Fieldstone.tga";
>;
sampler2D DiffuseSampler = sampler_state
{
   Texture = (DiffuseMap_Tex);
   MAGFILTER = LINEAR;
   MINFILTER = LINEAR;
};
texture SpecularMap_Tex
<
   string ResourceName = ".\\fieldstone_SM.tga";
>;
sampler2D SpecularSampler = sampler_state
{
   Texture = (SpecularMap_Tex);
   MAGFILTER = LINEAR;
   MINFILTER = LINEAR;
};
texture NormalMap_Tex
<
   string ResourceName = "..\\..\\..\\..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Textures\\FieldstoneBumpDOT3.tga";
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
float4 gLightColor_3
<
   string UIName = "gLightColor_3";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 1.00, 1.00, 1.00, 1.00 );

float gLightLength;

float4 Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition
<
   string UIName = "Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( -300.00, 0.00, 0.00, 1.00 );
float4 Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition_2
<
   string UIName = "Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition_2";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( 100.00, 100.00, -200.00, 1.00 );
float4 Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition_3
<
   string UIName = "Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition_3";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( -100.00, 100.00, -200.00, 1.00 );
float4 Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition_4
<
   string UIName = "Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition_4";
   string UIWidget = "Direction";
   bool UIVisible =  false;
   float4 UIMin = float4( -10.00, -10.00, -10.00, -10.00 );
   float4 UIMax = float4( 10.00, 10.00, 10.00, 10.00 );
   bool Normalize =  false;
> = float4( -100.00, -100.00, -200.00, 1.00 );

bool Light_2
<
   string UIName = "Light_2";
   string UIWidget = "Numeric";
   bool UIVisible =  false;
> = bool( true );
bool Light_3
<
   string UIName = "Light_3";
   string UIWidget = "Numeric";
   bool UIVisible =  false;
> = bool( true );
bool Light_4
<
   string UIName = "Light_4";
   string UIWidget = "Numeric";
   bool UIVisible =  false;
> = bool( true );

float cLight_Length
<
   string UIName = "cLight_Length";
   string UIWidget = "Numeric";
   bool UIVisible =  false;
   float UIMin = -1.00;
   float UIMax = 1.00;
> = float( 600.00 );

struct PS_INPUT
{
   float2 mUV : TEXCOORD0;
   float3 mLightDir : TEXCOORD1;
   float3 mViewDir: TEXCOORD2;
   float3 T : TEXCOORD3;
   float3 B : TEXCOORD4;
   float3 N : TEXCOORD5;
   float4 mClip_Position : TEXCOORD6;
   float3 mLightDir_2 : TEXCOORD7;
   float3 mLightDir_3 : TEXCOORD8;
   float3 mLightDir_4 : TEXCOORD9;
};



float4 Normal_Light_ALL_Pass_0_Pixel_Shader_ps_main(PS_INPUT Input) : COLOR
{
   
   float3 tangentNormal = tex2D(NormalSampler, Input.mUV).xyz;
   tangentNormal = normalize(tangentNormal * 2 - 1);
   
   float LEGTH_FLOAT = distance(Input.mClip_Position, Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition);
   float LEGTH_FLOAT_2 = distance(Input.mClip_Position, Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition_2);
   float LEGTH_FLOAT_3 = distance(Input.mClip_Position, Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition_3);
   float LEGTH_FLOAT_4 = distance(Input.mClip_Position, Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition_4);
   
   
   float3x3 TBN = float3x3(normalize(Input.T), normalize(Input.B), normalize(Input.N));
   TBN = transpose(TBN);
   
   float3 worldNormal = mul(TBN, tangentNormal);
   
   float4 albedo = tex2D(DiffuseSampler, Input.mUV);
   float3 lightDir = normalize(Input.mLightDir);
   float3 diffuse = saturate(dot(worldNormal, -lightDir));
   
  
   
   if(LEGTH_FLOAT < cLight_Length)
   {
     float InterSept =  (cLight_Length-LEGTH_FLOAT)/ cLight_Length; 
     float4 gLightColor_2_Inter = gLightColor_2;
     gLightColor_2_Inter.xyz *= 1.0f;
     diffuse = gLightColor_2_Inter.xyz * albedo.rgb * diffuse;
   }
   else
   {
      diffuse = gLightColor_1.xyz * albedo.rgb * diffuse;
   }
   
   if(Light_2)
   {
      float3 lightDir_2 = normalize(Input.mLightDir_2);
      float3 diffuse_2 = saturate(dot(worldNormal, -lightDir_2));
      if(LEGTH_FLOAT_2 < cLight_Length)
      {
        float InterSept_2 =  (cLight_Length-LEGTH_FLOAT_2)/ cLight_Length; 
        float4 gLightColor_2_Inter_2 = gLightColor_3;
        gLightColor_2_Inter_2.xyz *= 1.0f;
        diffuse_2 = gLightColor_2_Inter_2.xyz * albedo.rgb * diffuse_2;
      }
      else
      {
        diffuse_2 = gLightColor_1.xyz * albedo.rgb * diffuse_2;
      }
      diffuse.x = max(diffuse.x, diffuse_2.x);
      diffuse.y = max(diffuse.y, diffuse_2.y);
      diffuse.z = max(diffuse.z, diffuse_2.z);
   }
   
   if(Light_3)
   {
      float3 lightDir_3 = normalize(Input.mLightDir_3);
      float3 diffuse_3 = saturate(dot(worldNormal, -lightDir_3));
      if(LEGTH_FLOAT_3 < cLight_Length)
      {
        float InterSept_3 =  (cLight_Length-LEGTH_FLOAT_3)/ cLight_Length; 
        float4 gLightColor_3_Inter_3 = gLightColor_3;
        gLightColor_3_Inter_3.xyz *= 1.0f;
        diffuse_3 = gLightColor_3_Inter_3.xyz * albedo.rgb * diffuse_3;
      }
      else
      {
        diffuse_3 = gLightColor_1.xyz * albedo.rgb * diffuse_3;
      }
      diffuse.x = max(diffuse.x, diffuse_3.x);
      diffuse.y = max(diffuse.y, diffuse_3.y);
      diffuse.z = max(diffuse.z, diffuse_3.z);
   }
   
   if(Light_4)
   {
      float3 lightDir_4 = normalize(Input.mLightDir_4);
      float3 diffuse_4 = saturate(dot(worldNormal, -lightDir_4));
      if(LEGTH_FLOAT_4 < cLight_Length)
      {
        float InterSept_4 =  (cLight_Length-LEGTH_FLOAT_4)/ cLight_Length; 
        float4 gLightColor_4_Inter_4 = gLightColor_3;
        gLightColor_4_Inter_4.xyz *= 1.0f;
        diffuse_4 = gLightColor_4_Inter_4.xyz * albedo.rgb * diffuse_4;
      }
      else
      {
        diffuse_4 = gLightColor_1.xyz * albedo.rgb * diffuse_4;
      }
      diffuse.x = max(diffuse.x, diffuse_4.x);
      diffuse.y = max(diffuse.y, diffuse_4.y);
      diffuse.z = max(diffuse.z, diffuse_4.z);
   }
   
   
   
   
   
   float3 diffuse_FULL = diffuse;
   
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
   
   return float4(ambient + diffuse_FULL + specular, 1);
}

//--------------------------------------------------------------//
// Technique Section for Normal_Light_ALL
//--------------------------------------------------------------//
technique Normal_Light_ALL
{
   pass OutLine
   {
      CULLMODE = CW;
      ZWRITEENABLE = FALSE;

      VertexShader = compile vs_3_0 Normal_Light_ALL_OutLine_Vertex_Shader_vs_main();
      PixelShader = compile ps_3_0 Normal_Light_ALL_OutLine_Pixel_Shader_ps_main();
   }

   pass Pass_0
   {
      CULLMODE = CCW;
      ZWRITEENABLE = TRUE;

      VertexShader = compile vs_3_0 Normal_Light_ALL_Pass_0_Vertex_Shader_vs_main();
      PixelShader = compile ps_3_0 Normal_Light_ALL_Pass_0_Pixel_Shader_ps_main();
   }

}

