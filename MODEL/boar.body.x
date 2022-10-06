xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 347;
 0.08716;11.88045;2.35885;,
 4.46691;9.87690;-2.50134;,
 0.26345;11.06553;-3.72623;,
 0.08716;11.88045;2.35885;,
 2.63175;11.94273;10.08916;,
 0.08716;11.88045;2.35885;,
 -2.70968;11.94273;10.08916;,
 0.08716;11.88045;2.35885;,
 -4.36028;10.15317;-2.60982;,
 0.08716;11.88045;2.35885;,
 0.26345;11.06553;-3.72623;,
 4.17644;6.54816;-8.41383;,
 0.21761;6.79496;-8.45685;,
 6.27405;6.71842;2.71036;,
 -4.23042;6.51920;-8.51640;,
 -6.35198;6.71842;2.71036;,
 0.21761;6.79496;-8.45685;,
 4.82226;2.06429;-8.21815;,
 -0.03897;1.80470;-8.54314;,
 6.27405;1.46602;2.71036;,
 -4.25170;1.46602;-8.26032;,
 -6.35198;1.46602;2.71036;,
 -0.03897;1.80470;-8.54314;,
 4.96446;-2.99562;-8.38755;,
 0.14178;-2.88530;-6.13106;,
 3.86269;-3.19603;3.37624;,
 -4.45336;-3.05423;-7.90894;,
 -3.94063;-3.19603;3.37624;,
 0.14178;-2.88530;-6.13106;,
 -0.03897;-3.33425;-2.93738;,
 -0.03897;-3.33425;-2.93738;,
 -0.03897;-3.33425;-2.93738;,
 -0.03897;-3.33425;-2.93738;,
 -0.03897;-3.33425;-2.93738;,
 -2.60522;10.13173;14.49849;,
 2.52729;10.13173;14.49849;,
 -2.78373;6.47385;17.25399;,
 2.70579;6.47385;17.25399;,
 -2.32120;1.50843;17.61417;,
 2.24326;1.50843;17.61417;,
 -2.05886;-1.84486;15.92814;,
 1.98093;-1.84486;15.92814;,
 -1.76804;8.63549;-20.82996;,
 -0.09985;6.77050;-19.76133;,
 0.02850;1.88250;-17.62178;,
 -4.12666;1.87823;-17.58486;,
 1.74922;8.63549;-20.82996;,
 4.90817;1.88250;-17.76884;,
 0.07456;0.61090;-17.02575;,
 -1.57863;-0.86100;-16.12396;,
 2.36027;-0.85246;-16.14538;,
 1.74922;8.63549;-20.82996;,
 3.65474;6.34598;-12.97123;,
 4.92553;1.87823;-13.18613;,
 4.90817;1.88250;-17.76884;,
 4.20806;6.64870;-8.38265;,
 4.87091;2.07028;-8.00624;,
 4.92553;-2.97378;-13.02294;,
 2.36027;-0.85246;-16.14538;,
 4.94974;-2.99120;-8.37917;,
 4.20806;6.64870;-8.38265;,
 0.23325;6.78031;-8.45212;,
 0.07353;1.87823;-8.33413;,
 4.87091;2.07028;-8.00624;,
 -4.27083;6.52391;-8.37714;,
 -4.32226;1.60959;-8.11688;,
 0.07353;-2.97378;-6.11349;,
 4.94974;-2.99120;-8.37917;,
 -4.47428;-3.04248;-7.90846;,
 -4.27083;6.52391;-8.37714;,
 -2.97410;6.21681;-12.95342;,
 -4.46146;1.87823;-13.04705;,
 -4.32226;1.60959;-8.11688;,
 -1.76804;8.63549;-20.82996;,
 -4.12666;1.87823;-17.58486;,
 -4.77847;-2.97378;-13.18613;,
 -4.47428;-3.04248;-7.90846;,
 -1.57863;-0.86100;-16.12396;,
 0.01443;6.71881;-12.97719;,
 -2.97410;6.21681;-12.95342;,
 3.65474;6.34598;-12.97123;,
 -0.09985;6.77050;-19.76133;,
 -1.76804;8.63549;-20.82996;,
 1.74922;8.63549;-20.82996;,
 -4.77847;-2.97378;-13.18613;,
 0.21237;-2.97378;-12.98349;,
 4.92553;-2.97378;-13.02294;,
 -1.57863;-0.86100;-16.12396;,
 0.07456;0.61090;-17.02575;,
 2.36027;-0.85246;-16.14538;,
 -4.73962;7.41127;-6.05183;,
 -8.25914;12.58068;-2.15057;,
 -4.25232;9.83544;-3.97820;,
 -8.25914;12.58068;-2.15057;,
 -5.04042;7.60832;-2.04505;,
 -8.25914;12.58068;-2.15057;,
 -4.73962;7.41127;-6.05183;,
 -5.12125;7.88991;-3.49745;,
 -4.73962;7.41127;-6.05183;,
 -4.25232;9.83544;-3.97820;,
 -5.04042;7.60832;-2.04505;,
 4.84744;6.85722;-6.19229;,
 4.28270;9.42133;-4.09643;,
 8.81866;11.66164;-1.23031;,
 4.96248;7.41616;-2.12269;,
 8.81866;11.66164;-1.23031;,
 4.84744;6.85722;-6.19229;,
 8.81866;11.66164;-1.23031;,
 5.39051;7.88991;-3.56607;,
 4.28270;9.42133;-4.09643;,
 4.84744;6.85722;-6.19229;,
 4.96248;7.41616;-2.12269;,
 -4.92491;-0.38402;-11.50353;,
 -6.71876;1.95577;-15.97499;,
 -4.98792;0.90903;-6.89610;,
 -6.71876;1.95577;-15.97499;,
 -4.71353;-2.19866;-8.20200;,
 -6.71876;1.95577;-15.97499;,
 -4.92491;-0.38402;-11.50353;,
 -4.85538;-0.52891;-9.09504;,
 -4.92491;-0.38402;-11.50353;,
 -4.98792;0.90903;-6.89610;,
 -4.71353;-2.19866;-8.20200;,
 4.92612;-0.38402;-11.50353;,
 4.89336;1.14181;-6.84013;,
 6.78793;1.95577;-15.96192;,
 5.00751;-2.19866;-8.20200;,
 6.78793;1.95577;-15.96192;,
 4.92612;-0.38402;-11.50353;,
 6.78793;1.95577;-15.96192;,
 4.81956;-0.52891;-8.83982;,
 4.89336;1.14181;-6.84013;,
 4.92612;-0.38402;-11.50353;,
 5.00751;-2.19866;-8.20200;,
 0.12910;11.10238;-3.08828;,
 0.05904;15.18277;1.32103;,
 1.13411;11.19783;-0.03006;,
 0.05904;15.18277;1.32103;,
 -0.86362;11.19897;-0.04226;,
 0.05904;15.18277;1.32103;,
 0.12910;11.10238;-3.08828;,
 0.09957;11.58961;-1.06764;,
 0.12910;11.10238;-3.08828;,
 1.13411;11.19783;-0.03006;,
 -0.86362;11.19897;-0.04226;,
 2.28523;10.94008;-2.53262;,
 3.06444;14.92326;1.89722;,
 3.31681;10.81373;0.51561;,
 3.06444;14.92326;1.89722;,
 1.35884;11.21042;0.52380;,
 3.06444;14.92326;1.89722;,
 2.28523;10.94008;-2.53262;,
 2.37102;11.40967;-0.50943;,
 2.28523;10.94008;-2.53262;,
 3.31681;10.81373;0.51561;,
 1.35884;11.21042;0.52380;,
 -2.17125;10.85700;-2.56092;,
 -3.23603;10.69156;0.47397;,
 -3.15458;14.80732;1.85772;,
 -1.29448;11.16096;0.50696;,
 -3.15458;14.80732;1.85772;,
 -2.17125;10.85700;-2.56092;,
 -3.15458;14.80732;1.85772;,
 -2.30018;11.32258;-0.53909;,
 -3.23603;10.69156;0.47397;,
 -2.17125;10.85700;-2.56092;,
 -1.29448;11.16096;0.50696;,
 0.12910;11.10238;0.75908;,
 0.05904;15.18277;5.16838;,
 1.13411;11.19783;3.81727;,
 0.05904;15.18277;5.16838;,
 -0.86362;11.19897;3.80508;,
 0.05904;15.18277;5.16838;,
 0.12910;11.10238;0.75908;,
 0.09957;11.58961;2.77970;,
 0.12910;11.10238;0.75908;,
 1.13411;11.19783;3.81727;,
 -0.86362;11.19897;3.80508;,
 2.28523;10.94008;1.31473;,
 3.06444;14.92326;5.74458;,
 3.31681;11.04385;4.36294;,
 3.06444;14.92326;5.74458;,
 1.35884;11.21042;4.37114;,
 3.06444;14.92326;5.74458;,
 2.28523;10.94008;1.31473;,
 2.37102;11.40967;3.33793;,
 2.28523;10.94008;1.31473;,
 3.31681;11.04385;4.36294;,
 1.35884;11.21042;4.37114;,
 -2.17125;10.85700;1.28642;,
 -3.23603;11.22235;4.32132;,
 -3.15458;14.80732;5.70508;,
 -1.29448;11.16096;4.35429;,
 -3.15458;14.80732;5.70508;,
 -2.17125;10.85700;1.28642;,
 -3.15458;14.80732;5.70508;,
 -2.30018;11.32258;3.30826;,
 -3.23603;11.22235;4.32132;,
 -2.17125;10.85700;1.28642;,
 -1.29448;11.16096;4.35429;,
 0.12230;11.99742;6.13234;,
 0.05761;15.76483;10.20345;,
 1.05022;12.08554;8.95598;,
 0.05761;15.76483;10.20345;,
 -0.79429;12.08658;8.94472;,
 0.05761;15.76483;10.20345;,
 0.12230;11.99742;6.13234;,
 0.09503;12.44728;7.99798;,
 0.12230;11.99742;6.13234;,
 1.05022;12.08554;8.95598;,
 -0.79429;12.08658;8.94472;,
 2.11304;11.84757;6.64538;,
 2.83250;15.52524;10.73546;,
 3.06551;11.73090;9.45981;,
 2.83250;15.52524;10.73546;,
 1.25772;12.09717;9.46738;,
 2.83250;15.52524;10.73546;,
 2.11304;11.84757;6.64538;,
 2.19227;12.28115;8.51338;,
 2.11304;11.84757;6.64538;,
 3.06551;11.73090;9.45981;,
 1.25772;12.09717;9.46738;,
 -2.00161;11.77085;6.61923;,
 -2.98473;11.85413;9.42136;,
 -2.90953;15.41818;10.69898;,
 -1.19209;12.05151;9.45181;,
 -2.90953;15.41818;10.69898;,
 -2.00161;11.77085;6.61923;,
 -2.90953;15.41818;10.69898;,
 -2.12066;12.20072;8.48599;,
 -2.98473;11.85413;9.42136;,
 -2.00161;11.77085;6.61923;,
 -1.19209;12.05151;9.45181;,
 1.22221;6.80932;-8.07046;,
 2.81847;13.24971;-5.24733;,
 2.66648;9.20146;-6.00705;,
 2.81847;13.24971;-5.24733;,
 0.66957;8.84038;-5.78229;,
 2.81847;13.24971;-5.24733;,
 1.22221;6.80932;-8.07046;,
 1.47449;8.95499;-6.91189;,
 1.22221;6.80932;-8.07046;,
 2.66648;9.20146;-6.00705;,
 0.66957;8.84038;-5.78229;,
 -1.49548;6.82837;-8.12239;,
 -2.99020;9.20146;-6.00705;,
 -2.80867;13.24971;-5.24733;,
 -1.01516;9.34400;-5.74259;,
 -2.80867;13.24971;-5.24733;,
 -1.49548;6.82837;-8.12239;,
 -2.80867;13.24971;-5.24733;,
 -1.79821;8.95499;-6.91189;,
 -2.99020;9.20146;-6.00705;,
 -1.49548;6.82837;-8.12239;,
 -1.01516;9.34400;-5.74259;,
 4.13781;4.66515;-10.60205;,
 4.02134;6.14152;-11.23287;,
 4.16158;4.87414;-12.22866;,
 4.13781;4.66515;-10.60205;,
 4.12662;5.94247;-9.62068;,
 4.13781;4.66515;-10.60205;,
 4.37216;4.47603;-9.00427;,
 4.13781;4.66515;-10.60205;,
 4.51241;3.20866;-10.00007;,
 4.13781;4.66515;-10.60205;,
 4.40712;3.40772;-11.61225;,
 4.13781;4.66515;-10.60205;,
 4.16158;4.87414;-12.22866;,
 4.27947;6.16143;-11.26168;,
 4.41972;4.89406;-12.25749;,
 4.38475;5.96238;-9.64949;,
 4.63029;4.49595;-9.03308;,
 4.77054;3.22858;-10.02888;,
 4.66526;3.42763;-11.64105;,
 4.41972;4.89406;-12.25749;,
 4.65407;4.70495;-10.65968;,
 4.65407;4.70495;-10.65968;,
 4.65407;4.70495;-10.65968;,
 4.65407;4.70495;-10.65968;,
 4.65407;4.70495;-10.65968;,
 4.65407;4.70495;-10.65968;,
 -4.08140;4.39411;-10.58699;,
 -4.02115;4.59808;-12.21329;,
 -4.00599;5.87321;-11.21764;,
 -4.08140;4.39411;-10.58699;,
 -4.19458;5.67235;-9.61329;,
 -4.08140;4.39411;-10.58699;,
 -4.39834;4.19633;-9.00458;,
 -4.08140;4.39411;-10.58699;,
 -4.41350;2.92120;-10.00022;,
 -4.08140;4.39411;-10.58699;,
 -4.22491;3.12208;-11.60457;,
 -4.08140;4.39411;-10.58699;,
 -4.02115;4.59808;-12.21329;,
 -4.27785;4.60430;-12.25718;,
 -4.26269;5.87944;-11.26153;,
 -4.45128;5.67856;-9.65717;,
 -4.65504;4.20255;-9.04846;,
 -4.67020;2.92742;-10.04410;,
 -4.48161;3.12829;-11.64845;,
 -4.27785;4.60430;-12.25718;,
 -4.59480;4.40652;-10.67476;,
 -4.59480;4.40652;-10.67476;,
 -4.59480;4.40652;-10.67476;,
 -4.59480;4.40652;-10.67476;,
 -4.59480;4.40652;-10.67476;,
 -4.59480;4.40652;-10.67476;,
 -1.35097;6.24115;-19.69652;,
 -1.12289;6.24115;-19.69652;,
 -1.12289;1.87037;-17.70465;,
 -1.35097;1.87037;-17.70465;,
 -1.12289;6.24115;-19.69652;,
 -1.12289;6.26812;-19.61430;,
 -1.12289;1.95262;-17.52417;,
 -1.12289;1.87037;-17.70465;,
 -1.12289;6.26812;-19.61430;,
 -1.35097;6.26812;-19.61430;,
 -1.35097;1.95262;-17.52417;,
 -1.12289;1.95262;-17.52417;,
 -1.35097;6.26812;-19.61430;,
 -1.35097;6.24115;-19.69652;,
 -1.35097;1.87037;-17.70465;,
 -1.35097;1.95262;-17.52417;,
 -1.12289;6.24115;-19.69652;,
 -1.35097;6.24115;-19.69652;,
 -1.35097;1.87037;-17.70465;,
 -1.12289;1.87037;-17.70465;,
 1.35097;6.24115;-19.69652;,
 1.35097;1.87037;-17.70465;,
 1.12289;1.87037;-17.70465;,
 1.12289;6.24115;-19.69652;,
 1.12289;6.24115;-19.69652;,
 1.12289;1.87037;-17.70465;,
 1.12289;1.95262;-17.52417;,
 1.12289;6.26812;-19.61430;,
 1.12289;6.26812;-19.61430;,
 1.12289;1.95262;-17.52417;,
 1.35097;1.95262;-17.52417;,
 1.35097;6.26812;-19.61430;,
 1.35097;6.26812;-19.61430;,
 1.35097;1.95262;-17.52417;,
 1.35097;1.87037;-17.70465;,
 1.35097;6.24115;-19.69652;,
 1.35097;6.24115;-19.69652;,
 1.12289;6.24115;-19.69652;,
 1.35097;1.87037;-17.70465;,
 1.12289;1.87037;-17.70465;;
 
 195;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 4;2,1,11,12;,
 4;1,4,13,11;,
 4;6,8,14,15;,
 4;8,10,16,14;,
 4;12,11,17,18;,
 4;11,13,19,17;,
 4;15,14,20,21;,
 4;14,16,22,20;,
 4;18,17,23,24;,
 4;17,19,25,23;,
 4;21,20,26,27;,
 4;20,22,28,26;,
 3;24,23,29;,
 3;23,25,30;,
 3;25,27,31;,
 3;27,26,32;,
 3;26,28,33;,
 4;34,35,4,6;,
 4;36,34,6,15;,
 4;35,37,13,4;,
 4;35,34,36,37;,
 4;38,36,15,21;,
 4;37,39,19,13;,
 4;37,36,38,39;,
 4;40,38,21,27;,
 4;41,40,27,25;,
 4;39,41,25,19;,
 4;39,38,40,41;,
 4;42,43,44,45;,
 4;43,46,47,44;,
 4;45,44,48,49;,
 4;44,47,50,48;,
 4;51,52,53,54;,
 4;52,55,56,53;,
 4;54,53,57,58;,
 4;53,56,59,57;,
 4;60,61,62,63;,
 4;61,64,65,62;,
 4;63,62,66,67;,
 4;62,65,68,66;,
 4;69,70,71,72;,
 4;70,73,74,71;,
 4;72,71,75,76;,
 4;71,74,77,75;,
 4;69,61,78,79;,
 4;61,55,80,78;,
 4;79,78,81,82;,
 4;78,80,83,81;,
 4;84,85,66,76;,
 4;85,86,59,66;,
 4;87,88,85,84;,
 4;88,89,86,85;,
 3;90,91,92;,
 3;92,93,94;,
 3;94,95,96;,
 3;97,98,99;,
 3;97,99,100;,
 3;97,100,98;,
 3;101,102,103;,
 3;102,104,105;,
 3;104,106,107;,
 3;108,109,110;,
 3;108,111,109;,
 3;108,110,111;,
 3;112,113,114;,
 3;114,115,116;,
 3;116,117,118;,
 3;119,120,121;,
 3;119,121,122;,
 3;119,122,120;,
 3;123,124,125;,
 3;124,126,127;,
 3;126,128,129;,
 3;130,131,132;,
 3;130,133,131;,
 3;130,132,133;,
 3;134,135,136;,
 3;136,137,138;,
 3;138,139,140;,
 3;141,142,143;,
 3;141,143,144;,
 3;141,144,142;,
 3;145,146,147;,
 3;147,148,149;,
 3;149,150,151;,
 3;152,153,154;,
 3;152,154,155;,
 3;152,155,153;,
 3;156,157,158;,
 3;157,159,160;,
 3;159,161,162;,
 3;163,164,165;,
 3;163,166,164;,
 3;163,165,166;,
 3;167,168,169;,
 3;169,170,171;,
 3;171,172,173;,
 3;174,175,176;,
 3;174,176,177;,
 3;174,177,175;,
 3;178,179,180;,
 3;180,181,182;,
 3;182,183,184;,
 3;185,186,187;,
 3;185,187,188;,
 3;185,188,186;,
 3;189,190,191;,
 3;190,192,193;,
 3;192,194,195;,
 3;196,197,198;,
 3;196,199,197;,
 3;196,198,199;,
 3;200,201,202;,
 3;202,203,204;,
 3;204,205,206;,
 3;207,208,209;,
 3;207,209,210;,
 3;207,210,208;,
 3;211,212,213;,
 3;213,214,215;,
 3;215,216,217;,
 3;218,219,220;,
 3;218,220,221;,
 3;218,221,219;,
 3;222,223,224;,
 3;223,225,226;,
 3;225,227,228;,
 3;229,230,231;,
 3;229,232,230;,
 3;229,231,232;,
 3;233,234,235;,
 3;235,236,237;,
 3;237,238,239;,
 3;240,241,242;,
 3;240,242,243;,
 3;240,243,241;,
 3;244,245,246;,
 3;245,247,248;,
 3;247,249,250;,
 3;251,252,253;,
 3;251,254,252;,
 3;251,253,254;,
 3;255,256,257;,
 3;258,259,256;,
 3;260,261,259;,
 3;262,263,261;,
 3;264,265,263;,
 3;266,267,265;,
 4;257,256,268,269;,
 4;256,259,270,268;,
 4;259,261,271,270;,
 4;261,263,272,271;,
 4;263,265,273,272;,
 4;265,267,274,273;,
 3;269,268,275;,
 3;268,270,276;,
 3;270,271,277;,
 3;271,272,278;,
 3;272,273,279;,
 3;273,274,280;,
 3;281,282,283;,
 3;284,283,285;,
 3;286,285,287;,
 3;288,287,289;,
 3;290,289,291;,
 3;292,291,293;,
 4;282,294,295,283;,
 4;283,295,296,285;,
 4;285,296,297,287;,
 4;287,297,298,289;,
 4;289,298,299,291;,
 4;291,299,300,293;,
 3;294,301,295;,
 3;295,302,296;,
 3;296,303,297;,
 3;297,304,298;,
 3;298,305,299;,
 3;299,306,300;,
 4;307,308,309,310;,
 4;311,312,313,314;,
 4;315,316,317,318;,
 4;319,320,321,322;,
 4;319,312,323,324;,
 4;325,326,313,322;,
 4;327,328,329,330;,
 4;331,332,333,334;,
 4;335,336,337,338;,
 4;339,340,341,342;,
 4;339,343,344,334;,
 4;345,340,333,346;;
 
 MeshMaterialList {
  4;
  195;
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
  3,
  3,
  3,
  3,
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
  1,
  0,
  0,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
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
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.447000;0.169000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   100.000000;
   1.000000;1.000000;1.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   1.000000;1.000000;1.000000;;
  }
  Material {
   0.545600;0.000000;0.263200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  265;
  0.026729;0.994854;-0.097726;,
  0.034331;0.924680;-0.379195;,
  0.477620;0.844376;-0.242711;,
  0.514318;0.852428;0.094038;,
  -0.501544;0.859795;0.095948;,
  -0.431231;0.866270;-0.252224;,
  0.018588;0.438294;-0.898640;,
  0.816644;0.483477;-0.315186;,
  0.980288;0.189053;0.057399;,
  -0.983279;0.175005;0.050353;,
  -0.813142;0.472532;-0.339873;,
  0.004603;-0.132095;-0.991226;,
  -0.067096;-0.111183;-0.991532;,
  0.988896;-0.129804;0.072361;,
  -0.987504;-0.148758;0.052029;,
  -0.984514;-0.112791;-0.134202;,
  0.001631;-0.251469;-0.967864;,
  -0.172916;-0.211412;-0.961980;,
  0.957826;-0.270660;0.096505;,
  -0.959125;-0.273993;0.070763;,
  -0.971960;-0.221267;-0.079591;,
  0.000211;-0.998443;-0.055774;,
  0.000000;0.791554;0.611099;,
  0.963126;0.136091;0.232095;,
  -0.963126;0.136091;0.232095;,
  0.954801;-0.179459;0.236961;,
  -0.954801;-0.179459;0.236960;,
  0.000000;-0.821891;0.569644;,
  -0.921783;-0.319718;0.219309;,
  0.040209;-0.008495;-0.999155;,
  0.992591;-0.076067;-0.094748;,
  -0.025294;-0.016819;-0.999539;,
  0.076523;-0.152339;-0.985361;,
  0.975874;-0.216517;-0.028111;,
  0.176126;-0.283452;-0.942674;,
  -0.000852;-0.990256;-0.139253;,
  -0.017648;-0.996787;-0.078134;,
  0.018235;-0.999070;0.039069;,
  -0.017316;-0.999064;0.039635;,
  0.018169;-0.997217;-0.072301;,
  -0.929908;0.303552;0.207669;,
  0.929909;0.303551;0.207669;,
  0.000000;0.351349;0.936244;,
  0.000000;-0.195470;0.980710;,
  0.921783;-0.319718;0.219309;,
  0.029369;-0.426375;-0.904069;,
  -0.010587;-0.424001;-0.905600;,
  -0.301665;-0.465502;-0.832049;,
  -0.013517;-0.444445;-0.895704;,
  -0.262414;-0.613699;-0.744656;,
  0.002137;-0.640708;-0.767782;,
  -0.050526;-0.420947;-0.905677;,
  0.962030;0.266014;-0.061120;,
  -0.031415;-0.445377;-0.894792;,
  0.991142;0.037284;-0.127467;,
  -0.064780;-0.643679;-0.762549;,
  0.960809;-0.203053;-0.188722;,
  0.976953;0.203661;-0.063917;,
  -0.006545;0.043062;0.999051;,
  0.993877;0.106074;-0.030932;,
  -0.005311;0.124834;0.992163;,
  0.999970;0.007331;0.002390;,
  -0.004020;0.207060;0.978320;,
  0.030708;0.037963;0.998807;,
  -0.965384;0.243134;-0.094439;,
  -0.075671;0.142355;0.986919;,
  -0.986929;0.044908;-0.154774;,
  -0.180358;0.243565;0.952967;,
  -0.963126;-0.166657;-0.211220;,
  -0.011082;0.997202;0.073927;,
  0.012505;-0.945612;-0.325055;,
  0.943145;0.327271;-0.058071;,
  0.972452;-0.037822;-0.230013;,
  0.842555;-0.396722;-0.364297;,
  -0.043788;0.048100;0.997882;,
  0.064826;0.106718;0.992174;,
  0.172451;0.163707;0.971319;,
  -0.977360;0.168604;-0.127832;,
  -0.993079;0.109782;-0.041737;,
  -0.946832;0.316009;-0.060402;,
  -0.997756;0.049739;0.044822;,
  -0.112104;0.992704;-0.044394;,
  -0.022079;0.998766;-0.044484;,
  0.068937;0.995146;0.070226;,
  0.068126;0.996697;-0.044213;,
  -0.090787;0.992878;0.077145;,
  0.000383;0.980898;0.194524;,
  0.246813;0.951891;0.181620;,
  -0.246070;0.949348;0.195418;,
  0.086436;-0.941055;-0.327024;,
  0.002969;-0.999987;-0.004142;,
  0.007758;-0.999950;-0.006372;,
  -0.061342;-0.944985;-0.321312;,
  -0.001819;-0.999997;-0.001912;,
  0.087441;0.637328;-0.765615;,
  0.789281;0.467240;0.398401;,
  0.992312;-0.116547;0.041630;,
  0.940803;-0.153179;0.302368;,
  0.592341;0.398298;0.700350;,
  -0.838568;-0.543592;-0.036220;,
  0.988673;0.064132;0.135693;,
  0.892239;-0.431440;-0.133303;,
  0.153950;0.645429;-0.748145;,
  -0.777948;0.539773;0.321624;,
  -0.805220;-0.592299;-0.028336;,
  -0.819716;-0.020427;0.572405;,
  -0.624413;0.430106;0.652010;,
  0.730637;-0.678897;0.072589;,
  -0.812173;-0.465905;0.351152;,
  -0.669403;-0.623905;-0.403289;,
  -0.818871;0.571306;-0.055318;,
  0.973798;0.220728;-0.054737;,
  0.973148;0.225692;-0.045239;,
  -0.973388;-0.156349;0.167545;,
  0.882678;0.455498;-0.115762;,
  0.995471;0.094018;-0.014065;,
  0.068222;-0.872459;-0.483903;,
  0.996814;0.079068;-0.010497;,
  -0.988056;0.132605;-0.078491;,
  -0.988047;0.151475;-0.028621;,
  0.978829;-0.047699;0.199044;,
  -0.891102;0.429416;-0.146762;,
  -0.999209;-0.039363;0.005603;,
  -0.049172;-0.875802;-0.480160;,
  -0.994444;-0.102003;0.026005;,
  0.889290;0.342626;-0.302937;,
  -0.005964;-0.322533;0.946540;,
  0.014043;-0.999760;0.016825;,
  -0.900264;0.312298;-0.303306;,
  -0.511792;-0.836848;0.194307;,
  -0.275646;-0.957346;-0.086647;,
  0.298291;-0.950939;-0.082081;,
  0.546458;-0.812298;0.203853;,
  0.936757;0.161852;-0.310308;,
  -0.061173;-0.321446;0.944950;,
  -0.184063;-0.982844;0.011757;,
  -0.823288;0.486422;-0.292560;,
  -0.665610;-0.720265;0.195400;,
  -0.460545;-0.883209;-0.088544;,
  0.103327;-0.990585;-0.089805;,
  0.376609;-0.905774;0.194264;,
  -0.938122;0.126898;-0.322219;,
  0.061095;-0.319170;0.945726;,
  0.220413;-0.975301;0.014325;,
  0.808236;0.516838;-0.282193;,
  0.494237;-0.865405;-0.082479;,
  0.689460;-0.695000;0.204008;,
  -0.065172;-0.993727;-0.090878;,
  -0.345011;-0.919234;0.189677;,
  0.889288;0.342628;-0.302940;,
  -0.005960;-0.322536;0.946539;,
  0.014043;-0.999760;0.016826;,
  -0.900263;0.312299;-0.303307;,
  -0.511792;-0.836847;0.194309;,
  -0.275646;-0.957346;-0.086647;,
  0.298291;-0.950939;-0.082081;,
  0.546459;-0.812297;0.203854;,
  0.930811;0.174861;-0.320959;,
  -0.024713;-0.336828;0.941242;,
  -0.092702;-0.994346;0.051799;,
  -0.823287;0.486423;-0.292560;,
  -0.094117;-0.968895;0.228874;,
  -0.332999;-0.942478;-0.029102;,
  0.155409;-0.987115;-0.038116;,
  -0.926480;0.153655;-0.343548;,
  -0.213710;-0.734157;0.644470;,
  -0.009327;-0.994493;0.104388;,
  0.116350;-0.902382;0.414933;,
  -0.027205;-0.359424;0.932778;,
  0.808235;0.516840;-0.282194;,
  0.001487;-0.974475;0.224492;,
  -0.029233;-0.991711;-0.125121;,
  0.889290;0.342626;-0.302936;,
  -0.005960;-0.322534;0.946539;,
  0.014049;-0.999760;0.016821;,
  -0.900263;0.312300;-0.303308;,
  -0.511799;-0.836843;0.194306;,
  -0.275647;-0.957345;-0.086654;,
  0.298304;-0.950934;-0.082087;,
  0.546473;-0.812288;0.203854;,
  0.936756;0.161852;-0.310311;,
  -0.061170;-0.321447;0.944950;,
  -0.184070;-0.982843;0.011757;,
  -0.823291;0.486420;-0.292554;,
  -0.665630;-0.720245;0.195408;,
  -0.460560;-0.883201;-0.088545;,
  0.103331;-0.990584;-0.089811;,
  0.376620;-0.905770;0.194263;,
  -0.933216;0.138537;-0.331534;,
  0.021207;-0.337768;0.940990;,
  0.119766;-0.991142;0.057386;,
  0.808233;0.516842;-0.282194;,
  0.355066;-0.934661;-0.018326;,
  0.120063;-0.965746;0.230044;,
  -0.123897;-0.991709;-0.034091;,
  0.762893;0.091468;-0.640022;,
  0.500595;-0.303590;0.810702;,
  -0.516017;-0.359210;0.777621;,
  -0.199268;-0.292431;0.935295;,
  0.143316;-0.187737;0.971707;,
  -0.724336;0.419398;-0.547214;,
  0.548327;-0.775882;0.312000;,
  0.181046;-0.983039;0.029268;,
  0.774279;-0.368745;0.514315;,
  -0.712515;0.160152;-0.683136;,
  -0.424716;-0.328907;0.843467;,
  0.302932;-0.739927;0.600616;,
  0.164411;-0.582545;0.795996;,
  -0.117962;-0.178046;0.976926;,
  0.717357;0.401603;-0.569310;,
  0.512539;-0.368503;0.775570;,
  0.028952;-0.954117;0.298032;,
  -0.674274;-0.435475;0.596420;,
  -0.988235;-0.145611;0.046792;,
  -0.990312;-0.135163;-0.031838;,
  -0.997291;-0.071747;0.016217;,
  -0.992105;-0.081757;0.095100;,
  -0.979856;-0.155495;0.125313;,
  -0.972817;-0.218516;0.076665;,
  -0.978086;-0.208197;-0.001599;,
  -0.134315;0.602993;-0.786358;,
  -0.062265;0.990036;0.126301;,
  0.071540;0.396667;0.915171;,
  0.134300;-0.602997;0.786358;,
  0.062286;-0.990034;-0.126307;,
  0.988235;0.145613;-0.046788;,
  -0.071553;-0.396679;-0.915165;,
  0.979856;0.155494;-0.125311;,
  0.972817;0.218517;-0.076662;,
  0.978085;0.208199;0.001606;,
  0.990311;0.135166;0.031845;,
  0.997291;0.071748;-0.016214;,
  0.992105;0.081757;-0.095099;,
  0.990100;-0.093211;0.104949;,
  0.996211;-0.082837;0.026512;,
  0.997034;-0.019033;0.074566;,
  0.987785;-0.029134;0.153073;,
  0.977682;-0.103353;0.182908;,
  0.976813;-0.166766;0.134257;,
  0.986091;-0.156352;0.056370;,
  0.148155;0.607546;-0.780344;,
  0.002747;0.992209;0.124550;,
  -0.145561;0.394299;0.907381;,
  -0.148114;-0.607548;0.780351;,
  -0.002731;-0.992209;-0.124553;,
  -0.990100;0.093210;-0.104949;,
  0.145577;-0.394310;-0.907374;,
  -0.977683;0.103352;-0.182907;,
  -0.976814;0.166765;-0.134256;,
  -0.986092;0.156351;-0.056370;,
  -0.996211;0.082836;-0.026512;,
  -0.997034;0.019033;-0.074566;,
  -0.987786;0.029132;-0.153072;,
  0.000000;-0.414692;-0.909962;,
  1.000000;0.000000;-0.000000;,
  0.000000;0.435896;0.899997;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.950191;-0.311669;,
  0.000000;-0.909962;0.414691;,
  0.000000;-0.414692;-0.909962;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.435896;0.899997;,
  1.000000;0.000000;0.000000;,
  0.000000;0.950191;-0.311669;,
  0.000000;-0.909962;0.414691;;
  195;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,1,5;,
  4;1,2,7,6;,
  4;2,3,8,7;,
  4;4,5,10,9;,
  4;5,1,6,10;,
  4;6,29,12,11;,
  4;7,8,13,30;,
  4;9,10,15,14;,
  4;31,6,11,32;,
  4;11,12,17,16;,
  4;30,13,18,33;,
  4;14,15,20,19;,
  4;32,11,16,34;,
  3;35,36,21;,
  3;36,37,21;,
  3;37,38,21;,
  3;38,39,21;,
  3;39,35,21;,
  4;22,22,3,4;,
  4;24,40,4,9;,
  4;41,23,8,3;,
  4;22,22,42,42;,
  4;26,24,9,14;,
  4;23,25,13,8;,
  4;42,42,43,43;,
  4;28,26,14,19;,
  4;27,27,38,37;,
  4;25,44,18,13;,
  4;43,43,27,27;,
  4;45,46,48,47;,
  4;46,51,53,48;,
  4;47,48,50,49;,
  4;48,53,55,50;,
  4;71,52,54,72;,
  4;52,57,59,54;,
  4;72,54,56,73;,
  4;54,59,61,56;,
  4;74,58,60,75;,
  4;58,63,65,60;,
  4;75,60,62,76;,
  4;60,65,67,62;,
  4;77,64,66,78;,
  4;64,79,79,66;,
  4;78,66,68,80;,
  4;66,47,49,68;,
  4;81,82,69,83;,
  4;82,84,85,69;,
  4;83,69,86,87;,
  4;69,85,88,86;,
  4;89,70,90,91;,
  4;70,92,93,90;,
  4;49,50,70,89;,
  4;50,55,92,70;,
  3;94,94,94;,
  3;97,98,95;,
  3;99,99,99;,
  3;96,100,97;,
  3;96,97,101;,
  3;96,95,100;,
  3;102,102,102;,
  3;105,103,106;,
  3;107,107,107;,
  3;104,105,108;,
  3;104,109,109;,
  3;110,110,103;,
  3;111,114,112;,
  3;113,113,113;,
  3;116,116,116;,
  3;115,111,112;,
  3;115,112,117;,
  3;115,117,111;,
  3;118,119,121;,
  3;120,120,120;,
  3;123,123,123;,
  3;122,119,118;,
  3;122,124,119;,
  3;122,118,124;,
  3;125,125,125;,
  3;126,126,126;,
  3;128,128,128;,
  3;127,129,130;,
  3;127,130,131;,
  3;127,131,132;,
  3;133,133,133;,
  3;134,134,134;,
  3;136,136,136;,
  3;135,137,138;,
  3;135,138,139;,
  3;135,139,140;,
  3;141,141,141;,
  3;142,142,142;,
  3;144,144,144;,
  3;143,145,146;,
  3;143,147,145;,
  3;143,148,147;,
  3;149,149,149;,
  3;150,150,150;,
  3;152,152,152;,
  3;151,153,154;,
  3;151,154,155;,
  3;151,155,156;,
  3;157,157,157;,
  3;158,158,158;,
  3;160,160,160;,
  3;159,161,162;,
  3;159,162,163;,
  3;159,163,161;,
  3;164,164,164;,
  3;167,165,168;,
  3;169,169,169;,
  3;166,167,170;,
  3;166,171,167;,
  3;166,170,165;,
  3;172,172,172;,
  3;173,173,173;,
  3;175,175,175;,
  3;174,176,177;,
  3;174,177,178;,
  3;174,178,179;,
  3;180,180,180;,
  3;181,181,181;,
  3;183,183,183;,
  3;182,184,185;,
  3;182,185,186;,
  3;182,186,187;,
  3;188,188,188;,
  3;189,189,189;,
  3;191,191,191;,
  3;190,192,193;,
  3;190,194,192;,
  3;190,193,194;,
  3;195,195,195;,
  3;198,199,196;,
  3;200,200,200;,
  3;197,197,198;,
  3;201,202,202;,
  3;201,196,203;,
  3;204,204,204;,
  3;207,205,208;,
  3;209,209,209;,
  3;206,207,210;,
  3;206,211,207;,
  3;212,212,205;,
  3;213,215,214;,
  3;213,216,215;,
  3;213,217,216;,
  3;213,218,217;,
  3;213,219,218;,
  3;213,214,219;,
  4;220,220,220,220;,
  4;221,221,221,221;,
  4;222,222,222,222;,
  4;223,223,223,223;,
  4;224,224,224,224;,
  4;226,226,226,226;,
  3;227,228,225;,
  3;228,229,225;,
  3;229,230,225;,
  3;230,231,225;,
  3;231,232,225;,
  3;232,227,225;,
  3;233,234,235;,
  3;233,235,236;,
  3;233,236,237;,
  3;233,237,238;,
  3;233,238,239;,
  3;233,239,234;,
  4;240,240,240,240;,
  4;241,241,241,241;,
  4;242,242,242,242;,
  4;243,243,243,243;,
  4;244,244,244,244;,
  4;246,246,246,246;,
  3;247,245,248;,
  3;248,245,249;,
  3;249,245,250;,
  3;250,245,251;,
  3;251,245,252;,
  3;252,245,247;,
  4;253,253,253,253;,
  4;254,254,254,254;,
  4;255,255,255,255;,
  4;256,256,256,256;,
  4;257,257,257,257;,
  4;258,258,258,258;,
  4;259,259,259,259;,
  4;260,260,260,260;,
  4;261,261,261,261;,
  4;262,262,262,262;,
  4;263,263,263,263;,
  4;264,264,264,264;;
 }
 MeshTextureCoords {
  347;
  0.100000;0.000000;,
  0.200000;0.200000;,
  0.000000;0.200000;,
  0.300000;0.000000;,
  0.400000;0.200000;,
  0.500000;0.000000;,
  0.600000;0.200000;,
  0.700000;0.000000;,
  0.800000;0.200000;,
  0.900000;0.000000;,
  1.000000;0.200000;,
  0.200000;0.400000;,
  0.000000;0.400000;,
  0.400000;0.400000;,
  0.800000;0.400000;,
  0.600000;0.400000;,
  1.000000;0.400000;,
  0.200000;0.600000;,
  0.000000;0.600000;,
  0.400000;0.600000;,
  0.800000;0.600000;,
  0.600000;0.600000;,
  1.000000;0.600000;,
  0.200000;0.800000;,
  0.000000;0.800000;,
  0.400000;0.800000;,
  0.800000;0.800000;,
  0.600000;0.800000;,
  1.000000;0.800000;,
  0.100000;1.000000;,
  0.300000;1.000000;,
  0.500000;1.000000;,
  0.700000;1.000000;,
  0.900000;1.000000;,
  0.600000;0.200000;,
  0.400000;0.200000;,
  0.600000;0.400000;,
  0.400000;0.400000;,
  0.600000;0.600000;,
  0.400000;0.600000;,
  0.600000;0.800000;,
  0.400000;0.800000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.500000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  0.500000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.166670;0.000000;,
  0.666670;1.000000;,
  0.333330;0.000000;,
  1.000000;1.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.166670;0.000000;,
  0.666670;1.000000;,
  0.333330;0.000000;,
  1.000000;1.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.166670;0.000000;,
  0.666670;1.000000;,
  0.333330;0.000000;,
  1.000000;1.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.166670;0.000000;,
  0.666670;1.000000;,
  0.333330;0.000000;,
  1.000000;1.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.166670;0.000000;,
  0.666670;1.000000;,
  0.333330;0.000000;,
  1.000000;1.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.333330;1.000000;,
  0.166670;0.000000;,
  0.666670;1.000000;,
  0.333330;0.000000;,
  1.000000;1.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.083330;0.000000;,
  0.166670;0.333330;,
  0.000000;0.333330;,
  0.250000;0.000000;,
  0.333330;0.333330;,
  0.416670;0.000000;,
  0.500000;0.333330;,
  0.583330;0.000000;,
  0.666670;0.333330;,
  0.750000;0.000000;,
  0.833330;0.333330;,
  0.916670;0.000000;,
  1.000000;0.333330;,
  0.166670;0.666670;,
  0.000000;0.666670;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.666670;0.666670;,
  0.833330;0.666670;,
  1.000000;0.666670;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;,
  0.083330;0.000000;,
  0.000000;0.333330;,
  0.166670;0.333330;,
  0.250000;0.000000;,
  0.333330;0.333330;,
  0.416670;0.000000;,
  0.500000;0.333330;,
  0.583330;0.000000;,
  0.666670;0.333330;,
  0.750000;0.000000;,
  0.833330;0.333330;,
  0.916670;0.000000;,
  1.000000;0.333330;,
  0.000000;0.666670;,
  0.166670;0.666670;,
  0.333330;0.666670;,
  0.500000;0.666670;,
  0.666670;0.666670;,
  0.833330;0.666670;,
  1.000000;0.666670;,
  0.083330;1.000000;,
  0.250000;1.000000;,
  0.416670;1.000000;,
  0.583330;1.000000;,
  0.750000;1.000000;,
  0.916670;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}
