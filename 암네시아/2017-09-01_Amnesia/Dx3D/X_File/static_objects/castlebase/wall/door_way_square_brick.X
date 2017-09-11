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


Material lambert14 {
 1.000000;1.000000;1.000000;1.000000;;
 0.000000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "castlebase_wall_square_bricks.dds";
 }
}

Material lambert13 {
 1.000000;1.000000;1.000000;1.000000;;
 0.000000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "castlebase_wall_extension.dds";
 }
}

Frame polySurface117 {
 

 FrameTransformMatrix {
  39.370080,0.000000,0.000000,0.000000,0.000000,-0.000002,-39.370080,0.000000,0.000000,39.370080,-0.000002,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Mesh polySurface117 {
  8;
  0.020000;-0.000000;0.040000;,
  0.020000;-0.000000;0.004592;,
  0.011685;-0.000000;0.029842;,
  0.011685;-0.000000;0.004592;,
  -0.020000;-0.000000;0.040000;,
  -0.011641;-0.000000;0.029842;,
  -0.020000;-0.000000;0.004592;,
  -0.011641;-0.000000;0.004592;;
  6;
  3;0,1,2;,
  3;2,1,3;,
  3;0,2,4;,
  3;4,2,5;,
  3;4,5,6;,
  3;7,6,5;;

  MeshNormals {
   8;
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;,
   0.000000;1.000000;0.000000;;
   6;
   3;0,1,2;,
   3;2,1,3;,
   3;0,2,4;,
   3;4,2,5;,
   3;4,5,6;,
   3;7,6,5;;
  }

  MeshMaterialList {
   1;
   6;
   0,
   0,
   0,
   0,
   0,
   0;
   { lambert14 }
  }

  MeshTextureCoords c1 {
   8;
   1.000000;0.000000;,
   1.000000;1.000000;,
   0.796459;0.281641;,
   0.786610;1.000000;,
   0.000000;0.000000;,
   0.205443;0.280329;,
   0.000000;1.000000;,
   0.205996;1.000000;;
  }
 }

 Frame polySurface120 {
  

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,-0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh polySurface120 {
   16;
   0.020000;0.001641;0.003725;,
   0.020000;0.002678;0.002152;,
   0.011685;0.001641;0.003725;,
   0.011685;0.002678;0.002152;,
   0.020000;0.003219;0.000000;,
   0.011685;0.003219;0.000000;,
   0.020000;-0.000000;0.004592;,
   0.011685;-0.000000;0.004592;,
   -0.011641;-0.000000;0.004592;,
   -0.011641;0.001641;0.003725;,
   -0.020000;-0.000000;0.004592;,
   -0.020000;0.001641;0.003725;,
   -0.011641;0.002678;0.002152;,
   -0.020000;0.002678;0.002152;,
   -0.011641;0.003219;0.000000;,
   -0.020000;0.003219;0.000000;;
   12;
   3;0,1,2;,
   3;2,1,3;,
   3;1,4,3;,
   3;3,4,5;,
   3;6,0,7;,
   3;7,0,2;,
   3;8,9,10;,
   3;10,9,11;,
   3;12,13,9;,
   3;9,13,11;,
   3;14,15,12;,
   3;12,15,13;;

   MeshNormals {
    16;
    0.000000;0.672090;0.740470;,
    0.000000;0.915299;0.402776;,
    0.000000;0.672090;0.740470;,
    0.000000;0.915299;0.402776;,
    0.000000;0.969868;0.243632;,
    0.000000;0.969868;0.243632;,
    0.000000;0.467309;0.884094;,
    0.000000;0.467309;0.884094;,
    0.000000;0.467309;0.884094;,
    0.000000;0.672090;0.740470;,
    0.000000;0.467309;0.884094;,
    0.000000;0.672090;0.740470;,
    0.000000;0.915299;0.402776;,
    0.000000;0.915299;0.402776;,
    0.000000;0.969868;0.243632;,
    0.000000;0.969868;0.243632;;
    12;
    3;0,1,2;,
    3;2,1,3;,
    3;1,4,3;,
    3;3,4,5;,
    3;6,0,7;,
    3;7,0,2;,
    3;8,9,10;,
    3;10,9,11;,
    3;12,13,9;,
    3;9,13,11;,
    3;14,15,12;,
    3;12,15,13;;
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
    { lambert13 }
   }

   MeshTextureCoords c1 {
    16;
    -0.130780;0.611297;,
    -0.167650;0.611297;,
    -0.130780;0.499074;,
    -0.167650;0.499355;,
    -0.243876;0.611297;,
    -0.243876;0.498408;,
    -0.093910;0.611297;,
    -0.093910;0.500997;,
    -0.093910;0.219959;,
    -0.130780;0.219725;,
    -0.093910;0.111121;,
    -0.130780;0.111121;,
    -0.167650;0.220035;,
    -0.167650;0.111121;,
    -0.243876;0.220385;,
    -0.243876;0.111121;;
   }
  }
 }
}

AnimTicksPerSecond  {
 4800;
}

AnimationSet Anim1 {
 

 Animation {
  
  { polySurface117 }

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

 Animation {
  
  { polySurface120 }

  AnimationKey S {
   1;
   2;
   0;3;1.000000,1.000000,1.000000;;,
   16000;3;1.000000,1.000000,1.000000;;;
  }

  AnimationKey R {
   0;
   2;
   0;4;1.000000,-0.000000,0.000000,0.000000;;,
   16000;4;1.000000,-0.000000,0.000000,0.000000;;;
  }

  AnimationKey T {
   2;
   2;
   0;3;0.000000,0.000000,0.000000;;,
   16000;3;0.000000,0.000000,0.000000;;;
  }
 }
}