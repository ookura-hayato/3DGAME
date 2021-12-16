//==================================
//制作基礎 3D(effect.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _EFFECT_H_			//このマクロ定義がされなかったら
#define _EFFECT_H_			//2重インクルード防止のマクロ定義

//インクルードファイル
#include "main.h"

// 構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	float fWidth;			//幅
	float fHeight;			//高さ
	D3DXMATRIX mtxWorld;
	bool bUse;				//使用しているかどうか
}Effect;

//マクロ定義
#define MAX_EFFECT		(900)				//敵の最大数

//プロトタイプ宣言
void InitEffect(void);
void UninitEffect(void);
void UpdateEffect(void);
void DrawEffect(void);
void SetEffect(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
//Effect * GetEffect(void);
#endif
