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


Material lambert3 {
 1.000000;1.000000;1.000000;1.000000;;
 0.000000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "cellarbase_wood_floor.dds";
 }
}

Material lambert1 {
 0.400000;0.400000;0.400000;1.000000;;
 0.000000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;
}

Frame polySurface4 {
 

 FrameTransformMatrix {
  39.370080,0.000000,0.000000,0.000000,0.000000,-0.000002,-39.370080,0.000000,0.000000,39.370080,-0.000002,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Mesh polySurface4 {
  18;
  0.010000;-0.020000;0.017500;,
  -0.010000;-0.020000;0.017500;,
  0.010000;-0.010019;0.017500;,
  -0.010000;0.020000;0.017500;,
  0.010000;0.010009;0.017500;,
  0.010000;0.020000;0.017500;,
  0.020000;-0.020000;0.005000;,
  -0.020000;0.020000;0.000000;,
  -0.020000;0.020000;0.005000;,
  -0.020000;-0.020000;-0.000000;,
  -0.020000;-0.020000;0.005000;,
  0.020000;0.020000;0.005000;,
  0.010000;0.010009;0.017500;,
  0.020000;0.010000;0.017500;,
  0.010000;-0.010019;0.017500;,
  0.020000;-0.010000;0.017500;,
  0.020000;-0.020000;0.005000;,
  0.020000;0.020000;0.005000;;
  14;
  3;0,1,2;,
  3;1,3,2;,
  3;2,3,4;,
  3;3,5,4;,
  3;2,6,0;,
  3;7,8,9;,
  3;9,8,10;,
  3;8,3,10;,
  3;10,3,1;,
  3;5,11,4;,
  3;12,13,14;,
  3;13,15,14;,
  3;15,16,14;,
  3;17,13,12;;

  MeshNormals {
   18;
   -0.433189;0.000000;-0.901303;,
   0.433189;0.000000;-0.901303;,
   -0.227948;0.227508;-0.946721;,
   0.433189;0.000000;-0.901303;,
   -0.227727;-0.227521;-0.946771;,
   -0.433189;0.000000;-0.901303;,
   -0.780869;0.000000;-0.624695;,
   1.000000;0.000000;0.000000;,
   0.943628;0.000000;-0.331007;,
   1.000000;0.000000;0.000000;,
   0.943628;0.000000;-0.331007;,
   -0.780869;0.000000;-0.624695;,
   -0.227727;-0.227521;-0.946771;,
   -0.000392;-0.433189;-0.901303;,
   -0.227948;0.227508;-0.946721;,
   -0.000836;0.433188;-0.901303;,
   -0.001508;0.780868;-0.624694;,
   -0.000707;-0.780869;-0.624695;;
   14;
   3;0,1,2;,
   3;1,3,2;,
   3;2,3,4;,
   3;3,5,4;,
   3;2,6,0;,
   3;7,8,9;,
   3;9,8,10;,
   3;8,3,10;,
   3;10,3,1;,
   3;5,11,4;,
   3;12,13,14;,
   3;13,15,14;,
   3;15,16,14;,
   3;17,13,12;;
  }

  MeshMaterialList {
   2;
   14;
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
   { lambert3 }
   { lambert1 }
  }

  MeshTextureCoords c1 {
   18;
   0.000000;0.375762;,
   0.000000;1.131070;,
   0.249517;0.375762;,
   1.000000;1.131070;,
   0.750226;0.375762;,
   1.000000;0.375762;,
   0.000000;-0.372940;,
   1.000000;1.996536;,
   1.000000;1.752997;,
   0.000000;1.996536;,
   0.000000;1.752997;,
   1.000000;-0.372940;,
   0.749978;1.131070;,
   1.000000;1.131070;,
   0.750347;0.375762;,
   1.000000;0.375762;,
   1.000000;-0.372940;,
   1.000000;1.752997;;
  }
 }
}

AnimTicksPerSecond  {
 4800;
}

AnimationSet Anim1 {
 

 Animation {
  
  { polySurface4 }

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