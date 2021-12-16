//==================================
//制作基礎 3D(meshfeild.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _MESHFEILD_H_			//このマクロ定義がされなかったら
#define _MESHFEILD_H_			//2重インクルード防止のマクロ定義

//インクルードファイル
#include "main.h"

//プロトタイプ宣言
void InitMeshfeild(void);
void UninitMeshfeild(void);
void UpdateMeshfeild(void);
void DrawMeshfeild(void);
#endif
