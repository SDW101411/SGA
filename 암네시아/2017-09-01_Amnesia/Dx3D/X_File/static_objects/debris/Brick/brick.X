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
  "ceiling02_window.dds";
 }
}

Frame pCube1 {
 

 FrameTransformMatrix {
  14.497323,0.000000,0.000000,0.000000,0.000000,-0.000001,-24.618070,0.000000,0.000000,8.206023,-0.000000,0.000000,0.000000,0.041264,0.000000,1.000000;;
 }

 Mesh pCube1 {
  24;
  -0.005000;0.005000;-0.005000;,
  -0.005000;0.005000;0.005000;,
  0.005000;0.005000;-0.005000;,
  0.005000;0.005000;0.005000;,
  -0.005000;0.005000;0.005000;,
  -0.005000;-0.005000;0.005000;,
  0.005000;0.005000;0.005000;,
  0.005000;-0.005000;0.005000;,
  -0.005000;-0.005000;0.005000;,
  -0.005000;-0.005000;-0.005000;,
  0.005000;-0.005000;0.005000;,
  0.005000;-0.005000;-0.005000;,
  -0.005000;-0.005000;-0.005000;,
  -0.005000;0.005000;-0.005000;,
  0.005000;-0.005000;-0.005000;,
  0.005000;0.005000;-0.005000;,
  0.005000;0.005000;-0.005000;,
  0.005000;0.005000;0.005000;,
  0.005000;-0.005000;-0.005000;,
  0.005000;-0.005000;0.005000;,
  -0.005000;-0.005000;-0.005000;,
  -0.005000;-0.005000;0.005000;,
  -0.005000;0.005000;-0.005000;,
  -0.005000;0.005000;0.005000;;
  12;
  3;0,1,2;,
  3;2,1,3;,
  3;4,5,6;,
  3;6,5,7;,
  3;8,9,10;,
  3;10,9,11;,
  3;12,13,14;,
  3;14,13,15;,
  3;16,17,18;,
  3;18,17,19;,
  3;20,21,22;,
  3;22,21,23;;

  MeshNormals {
   24;
   0.000000;1.000000;-0.000000;,
   0.000000;1.000000;-0.000000;,
   0.000000;1.000000;-0.000000;,
   0.000000;1.000000;-0.000000;,
   0.000000;-0.000000;1.000000;,
   0.000000;-0.000000;1.000000;,
   0.000000;-0.000000;1.000000;,
   0.000000;-0.000000;1.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;-1.000000;0.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   0.000000;0.000000;-1.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;,
   -1.000000;0.000000;0.000000;;
   12;
   3;0,1,2;,
   3;2,1,3;,
   3;4,5,6;,
   3;6,5,7;,
   3;8,9,10;,
   3;10,9,11;,
   3;12,13,14;,
   3;14,13,15;,
   3;16,17,18;,
   3;18,17,19;,
   3;20,21,22;,
   3;22,21,23;;
  }

  MeshMaterialList {
   1;
   12;
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
   24;
   0.024713;0.118642;,
   0.024713;0.003499;,
   0.228132;0.118642;,
   0.228132;0.003499;,
   0.500972;0.266235;,
   0.712111;0.266235;,
   0.500972;0.383121;,
   0.712111;0.383121;,
   0.024713;0.118642;,
   0.024713;0.003499;,
   0.228132;0.118642;,
   0.228132;0.003499;,
   0.712111;0.383121;,
   0.500972;0.383121;,
   0.712111;0.266235;,
   0.500972;0.266234;,
   0.344860;0.387099;,
   0.344860;0.507040;,
   0.019785;0.387099;,
   0.019785;0.507040;,
   0.019785;0.507039;,
   0.019785;0.387099;,
   0.344860;0.507040;,
   0.344861;0.387099;;
  }
 }
}

AnimTicksPerSecond  {
 4800;
}

AnimationSet Anim1 {
 

 Animation {
  
  { pCube1 }

  AnimationKey S {
   1;
   2;
   0;3;14.497323,24.618070,8.206023;;,
   16000;3;14.497323,24.618070,8.206023;;;
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
   0;3;0.000000,0.041264,0.000000;;,
   16000;3;0.000000,0.041264,0.000000;;;
  }
 }
}