xof 0303txt 0032
template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}

template Frame {
 <3d82ab46-62da-11cf-ab39-0020af71e433>
 [...]
}

template Matrix4x4 {
 <f6f23f45-7686-11cf-8f52-0040333594a3>
 array FLOAT matrix[16];
}

template FrameTransformMatrix {
 <f6f23f41-7686-11cf-8f52-0040333594a3>
 Matrix4x4 frameMatrix;
}

template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template AnimTicksPerSecond {
 <9e415a43-7ba6-4a73-8743-b73d47e88476>
 DWORD AnimTicksPerSecond;
}

template Animation {
 <3d82ab4f-62da-11cf-ab39-0020af71e433>
 [...]
}

template AnimationSet {
 <3d82ab50-62da-11cf-ab39-0020af71e433>
 [Animation <3d82ab4f-62da-11cf-ab39-0020af71e433>]
}

template FloatKeys {
 <10dd46a9-775b-11cf-8f52-0040333594a3>
 DWORD nValues;
 array FLOAT values[nValues];
}

template TimedFloatKeys {
 <f406b180-7b3b-11cf-8f52-0040333594a3>
 DWORD time;
 FloatKeys tfkeys;
}

template AnimationKey {
 <10dd46a8-775b-11cf-8f52-0040333594a3>
 DWORD keyType;
 DWORD nKeys;
 array TimedFloatKeys keys[nKeys];
}


Material lambert2 {
 1.000000;1.000000;1.000000;1.000000;;
 0.000000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "organ_parts.dds";
 }
}

Frame organ_parts_02 {
 

 FrameTransformMatrix {
  39.370080,0.000000,0.000000,0.000000,0.000000,-0.000002,-39.370080,0.000000,0.000000,39.370080,-0.000002,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Mesh organ_parts_02 {
  15;
  0.000358;0.000491;0.000243;,
  0.001142;0.000391;0.000000;,
  0.000358;0.001012;0.000000;,
  -0.000370;0.000462;0.000253;,
  -0.000302;0.001028;0.000000;,
  0.000358;-0.000575;0.000232;,
  -0.000029;0.000043;0.000355;,
  -0.000372;-0.001028;-0.000000;,
  0.000358;-0.000885;-0.000000;,
  -0.000398;-0.000575;0.000232;,
  0.000875;-0.000575;-0.000000;,
  -0.000961;-0.000796;-0.000000;,
  -0.001267;0.000238;0.000000;,
  0.001267;0.000118;0.000000;,
  -0.001267;-0.000460;-0.000000;;
  18;
  3;0,1,2;,
  3;3,0,4;,
  3;0,2,4;,
  3;5,0,6;,
  3;7,8,9;,
  3;8,5,9;,
  3;10,5,8;,
  3;11,7,9;,
  3;12,3,4;,
  3;9,5,6;,
  3;0,5,13;,
  3;5,10,13;,
  3;11,9,14;,
  3;9,6,3;,
  3;6,0,3;,
  3;3,12,14;,
  3;9,3,14;,
  3;13,1,0;;

  MeshNormals {
   15;
   0.173312;0.234000;0.956665;,
   0.316583;0.273692;0.908223;,
   0.165777;0.416066;0.894096;,
   -0.201272;0.178997;0.963042;,
   -0.113466;0.421568;0.899670;,
   0.223638;-0.280055;0.933571;,
   -0.001751;0.006443;0.999978;,
   -0.046106;-0.457874;0.887821;,
   0.144257;-0.546010;0.825265;,
   -0.137986;-0.293438;0.945967;,
   0.375392;-0.402010;0.835146;,
   -0.232022;-0.358548;0.904217;,
   -0.314319;0.213853;0.924916;,
   0.325733;-0.031332;0.944943;,
   -0.272817;-0.089804;0.957865;;
   18;
   3;0,1,2;,
   3;3,0,4;,
   3;0,2,4;,
   3;5,0,6;,
   3;7,8,9;,
   3;8,5,9;,
   3;10,5,8;,
   3;11,7,9;,
   3;12,3,4;,
   3;9,5,6;,
   3;0,5,13;,
   3;5,10,13;,
   3;11,9,14;,
   3;9,6,3;,
   3;6,0,3;,
   3;3,12,14;,
   3;9,3,14;,
   3;13,1,0;;
  }

  MeshMaterialList {
   1;
   18;
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0;
   { lambert2 }
  }

  MeshTextureCoords c1 {
   15;
   0.625000;0.394460;,
   0.655119;0.386758;,
   0.625000;0.434594;,
   0.596972;0.392214;,
   0.599601;0.435775;,
   0.625000;0.312500;,
   0.610105;0.360014;,
   0.596892;0.277649;,
   0.625000;0.288673;,
   0.595903;0.312500;,
   0.644879;0.312500;,
   0.574240;0.295468;,
   0.562500;0.375000;,
   0.659931;0.365819;,
   0.562500;0.321326;;
  }
 }
}

AnimTicksPerSecond  {
 4800;
}

AnimationSet Anim1 {
 

 Animation {
  
  { organ_parts_02 }

  AnimationKey S {
   1;
   2;
   0;3;39.370080,39.370080,39.370080;;,
   16000;3;39.370080,39.370080,39.370080;;;
  }

  AnimationKey R {
   0;
   2;
   0;4;0.707107,0.707107,0.000000,0.000000;;,
   16000;4;0.707107,0.707107,0.000000,0.000000;;;
  }

  AnimationKey T {
   2;
   2;
   0;3;0.000000,0.000000,0.000000;;,
   16000;3;0.000000,0.000000,0.000000;;;
  }
 }
}