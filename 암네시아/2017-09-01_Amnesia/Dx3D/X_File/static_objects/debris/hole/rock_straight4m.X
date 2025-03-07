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
  "broken_rock.dds";
 }
}

Frame pCube13 {
 

 FrameTransformMatrix {
  39.370080,0.000000,0.000000,0.000000,0.000000,-0.000002,-39.370080,0.000000,0.000000,39.370080,-0.000002,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Mesh pCube13 {
  41;
  0.000000;-0.000000;0.002552;,
  0.007038;0.001575;0.001027;,
  0.003463;0.001320;0.000220;,
  -0.007962;0.001623;-0.003020;,
  -0.020000;-0.000996;-0.002696;,
  -0.020000;0.001504;-0.002723;,
  0.007022;0.001689;-0.000605;,
  0.003524;0.001594;-0.001097;,
  -0.008546;0.003505;0.000197;,
  -0.020000;0.001504;0.000769;,
  -0.020000;-0.000000;0.002552;,
  -0.020000;0.001504;-0.001355;,
  -0.007228;0.002959;-0.002008;,
  0.000000;0.000000;-0.002696;,
  0.003585;0.000287;-0.002414;,
  0.020000;-0.000996;-0.002696;,
  0.007005;0.000739;-0.002236;,
  0.020000;0.001504;-0.002723;,
  0.011089;0.002986;-0.001659;,
  0.011089;0.003277;0.000471;,
  0.011089;0.003056;-0.000772;,
  0.020000;-0.000000;0.002552;,
  -0.007372;0.001536;0.001224;,
  -0.000111;0.002488;-0.000641;,
  0.000027;0.002772;-0.001189;,
  0.000165;0.001971;-0.001736;,
  0.020000;0.001504;0.000769;,
  0.020000;0.001504;-0.001355;,
  -0.020000;0.001504;-0.002723;,
  -0.007962;0.001623;-0.003020;,
  0.000165;0.001971;-0.001736;,
  0.003585;0.000287;-0.002414;,
  0.007005;0.000739;-0.002236;,
  0.011089;0.002986;-0.001659;,
  0.020000;0.001504;-0.002723;,
  0.000000;-0.002500;-0.002545;,
  0.020000;-0.002500;-0.002545;,
  -0.020000;-0.002500;-0.002545;,
  0.000000;-0.002500;0.002613;,
  -0.020000;-0.002500;0.002613;,
  0.020000;-0.002500;0.002613;;
  50;
  3;0,1,2;,
  3;3,4,5;,
  3;1,6,2;,
  3;7,2,6;,
  3;8,9,10;,
  3;11,9,12;,
  3;12,9,8;,
  3;13,14,15;,
  3;16,15,14;,
  3;15,16,17;,
  3;17,16,18;,
  3;1,19,6;,
  3;6,19,20;,
  3;0,21,1;,
  3;8,10,22;,
  3;23,24,8;,
  3;12,8,24;,
  3;13,3,25;,
  3;4,3,13;,
  3;21,26,1;,
  3;1,26,19;,
  3;0,2,23;,
  3;7,24,2;,
  3;24,23,2;,
  3;13,25,14;,
  3;26,27,19;,
  3;19,27,20;,
  3;11,12,28;,
  3;28,12,29;,
  3;29,12,30;,
  3;30,12,24;,
  3;7,31,24;,
  3;30,24,31;,
  3;6,32,7;,
  3;31,7,32;,
  3;32,6,33;,
  3;20,33,6;,
  3;34,33,27;,
  3;27,33,20;,
  3;10,0,22;,
  3;8,22,23;,
  3;0,23,22;,
  3;13,15,35;,
  3;15,36,35;,
  3;13,35,4;,
  3;4,35,37;,
  3;0,10,38;,
  3;10,39,38;,
  3;0,38,21;,
  3;21,38,40;;

  MeshNormals {
   41;
   0.003856;0.614615;0.788818;,
   -0.119301;0.897166;0.425277;,
   0.041501;0.935330;0.351333;,
   0.030770;0.377862;-0.925350;,
   -0.004944;-0.081493;-0.996662;,
   -0.057498;0.507659;-0.859637;,
   -0.211838;0.950379;-0.227826;,
   0.113662;0.959776;-0.256732;,
   0.002049;0.868025;0.496516;,
   -0.136775;0.955633;0.260878;,
   -0.017557;0.505071;0.862899;,
   -0.112174;0.939493;-0.323681;,
   -0.010471;0.914553;-0.404331;,
   0.031794;0.167039;-0.985438;,
   0.066550;0.589397;-0.805098;,
   -0.010693;0.166787;-0.985935;,
   -0.109616;0.610808;-0.784155;,
   0.077666;0.743735;-0.663947;,
   -0.101156;0.822187;-0.560158;,
   -0.059526;0.958629;0.278364;,
   -0.098201;0.987349;-0.124490;,
   0.006822;0.454082;0.890934;,
   0.059530;0.620100;0.782261;,
   0.139156;0.858364;0.493809;,
   0.189991;0.907883;-0.373700;,
   0.120162;0.526681;-0.841527;,
   0.115808;0.893443;0.433991;,
   0.173574;0.983679;-0.047410;,
   -0.057498;0.507659;-0.859637;,
   0.030770;0.377862;-0.925350;,
   0.120162;0.526681;-0.841527;,
   0.066550;0.589397;-0.805098;,
   -0.109616;0.610808;-0.784155;,
   -0.101156;0.822187;-0.560158;,
   0.077666;0.743735;-0.663947;,
   0.000000;-0.075283;-0.997162;,
   -0.001874;-0.075283;-0.997160;,
   0.001874;-0.075283;-0.997160;,
   0.000000;0.024289;0.999705;,
   0.000000;0.024289;0.999705;,
   0.000000;0.024289;0.999705;;
   50;
   3;0,1,2;,
   3;3,4,5;,
   3;1,6,2;,
   3;7,2,6;,
   3;8,9,10;,
   3;11,9,12;,
   3;12,9,8;,
   3;13,14,15;,
   3;16,15,14;,
   3;15,16,17;,
   3;17,16,18;,
   3;1,19,6;,
   3;6,19,20;,
   3;0,21,1;,
   3;8,10,22;,
   3;23,24,8;,
   3;12,8,24;,
   3;13,3,25;,
   3;4,3,13;,
   3;21,26,1;,
   3;1,26,19;,
   3;0,2,23;,
   3;7,24,2;,
   3;24,23,2;,
   3;13,25,14;,
   3;26,27,19;,
   3;19,27,20;,
   3;11,12,28;,
   3;28,12,29;,
   3;29,12,30;,
   3;30,12,24;,
   3;7,31,24;,
   3;30,24,31;,
   3;6,32,7;,
   3;31,7,32;,
   3;32,6,33;,
   3;20,33,6;,
   3;34,33,27;,
   3;27,33,20;,
   3;10,0,22;,
   3;8,22,23;,
   3;0,23,22;,
   3;13,15,35;,
   3;15,36,35;,
   3;13,35,4;,
   3;4,35,37;,
   3;0,10,38;,
   3;10,39,38;,
   3;0,38,21;,
   3;21,38,40;;
  }

  MeshMaterialList {
   1;
   50;
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
   { lambert3 }
  }

  MeshTextureCoords c1 {
   41;
   2.125280;0.846470;,
   2.442400;0.670217;,
   2.281340;0.658466;,
   0.261459;0.714838;,
   -0.243624;0.893854;,
   -0.243624;0.722974;,
   2.450520;0.585467;,
   2.289880;0.569078;,
   1.740210;0.660558;,
   1.224130;0.662075;,
   1.224110;0.846470;,
   1.225300;0.558918;,
   1.796050;0.494764;,
   0.595535;0.825769;,
   0.745956;0.806120;,
   1.434690;0.825769;,
   0.889469;0.775267;,
   1.434690;0.722974;,
   1.060800;0.621642;,
   2.624930;0.599222;,
   2.637310;0.539841;,
   3.026450;0.846470;,
   1.793110;0.760668;,
   2.120280;0.553723;,
   2.129250;0.511142;,
   0.602443;0.691076;,
   3.026430;0.665267;,
   3.027330;0.549025;,
   1.225300;0.452866;,
   1.762330;0.416310;,
   2.135580;0.468697;,
   2.292680;0.466903;,
   2.449770;0.458913;,
   2.637310;0.470998;,
   3.027330;0.442973;,
   0.595535;0.996650;,
   1.434690;0.996650;,
   -0.243624;0.996650;,
   2.125280;0.986109;,
   1.225300;0.986109;,
   3.026690;0.986109;;
  }
 }
}

AnimTicksPerSecond  {
 4800;
}

AnimationSet Anim1 {
 

 Animation {
  
  { pCube13 }

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