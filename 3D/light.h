//==================================
//制作基礎 3D(light.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _LIGHT_H_			//このマクロ定義がされなかったら
#define _LIGHT_H_			//2重インクルード防止のマクロ定義

#include "main.h"

//マクロ定義
#define MAX_LIGHT		(3)				//敵の最大数

//プロトタイプ宣言
void InitLight(void);
void UninitLight(void);
void UpdateLight(void);
#endif
