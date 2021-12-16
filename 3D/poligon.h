//==================================
//制作基礎 3D(poligon.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _POLIGON_H_			//このマクロ定義がされなかったら
#define _POLIGON_H_			//2重インクルード防止のマクロ定義

//インクルードファイル
#include "main.h"

//プロトタイプ宣言
void InitPoligon(void);
void UninitPoligon(void);
void UpdatePoligon(void);
void DrawPoligon(void);
#endif