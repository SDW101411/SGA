
//--------------------------------------------------------------//
// NormalMapping
//--------------------------------------------------------------//
//--------------------------------------------------------------//
// CreateShadow
//--------------------------------------------------------------//
//string NormalMapping_CreateShadow_Model : ModelData = "..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Models\\Torus.3ds";

float4x4 gWorldMatrix : World;
float4x4 gLightViewMatrix;
float4x4 gProjectionMatrix : Projection;
float4x4 gLightProjection;
float4x4 gWorldViewProjectionMatrix : WorldViewProjection;

float4 gWorldLightPosition;
float4 gWorldCameraPosition : ViewPosition;
float4 gLightColor_1;
float4 gLightColor_2;

float Light_Length;


texture ShadowMap_Tex : RenderColorTarget;



texture DiffuseMap_Tex;

sampler2D DiffuseSampler = sampler_state
{
	Texture = (DiffuseMap_Tex);
	MAGFILTER = LINEAR;
	MINFILTER = LINEAR;
};
texture SpecularMap_Tex;

sampler2D SpecularSampler = sampler_state
{
	Texture = (SpecularMap_Tex);
	MAGFILTER = LINEAR;
	MINFILTER = LINEAR;
};
texture NormalMap_Tex;

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

/////////���ؽ�


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

   Output.Position = mul( Input.Position, gWorldMatrix );
   Output.Position = mul( Output.Position, gLightViewMatrix);
   Output.Position = mul( Output.Position, gLightProjection);
  
   Output.ClipPosition = Output.Position;
  
   return( Output );
}

/////////�ȼ�

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
/////////���ؽ�
//string NormalMapping_Pass_0_Model : ModelData = "..\\..\\..\\Program Files (x86)\\AMD\\RenderMonkey 1.82\\Examples\\Media\\Models\\Torus.3ds";

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
   
   Output.mClip_Position = mul( Input.mPosition, gWorldMatrix );
   
   Output.ClipPosition = mul(Input.mPosition, gWorldMatrix);
   Output.ClipPosition = mul(Output.ClipPosition, gLightViewMatrix);
   Output.ClipPosition = mul(Output.ClipPosition, gLightProjection);
   
   
   return Output;
}


/////////�ȼ�





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
   
   float LEGTH_FLOAT = distance(Input.mClip_Position, gWorldLightPosition);

   float3x3 TBN = float3x3(normalize(Input.T), normalize(Input.B), normalize(Input.N));
   TBN = transpose(TBN);
   
   float3 worldNormal = mul(TBN, tangentNormal);
   
   float4 albedo = tex2D(DiffuseSampler, Input.mUV);
   float3 lightDir = normalize(Input.mLightDir);
   float3 diffuse = saturate(dot(worldNormal, -lightDir));
   
   if(LEGTH_FLOAT < 10.0f)
   {
     float InterSept =  (10.0f - LEGTH_FLOAT) / 10.0f; 
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

