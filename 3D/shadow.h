//==================================
//制作基礎 3D(shadow.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _SHADOW_H_			//このマクロ定義がされなかったら
#define _SHADOW_H_			//2重インクルード防止のマクロ定義

//インクルードファイル
#include "main.h"

// 構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;	
	D3DXVECTOR3 rot;
	D3DXMATRIX mtxWorld;							
	bool bUse;
}Shadow;

//マクロ定義
#define MAX_SHADOW		(100)				//敵の最大数

//プロトタイプ宣言
void InitShadow(void);
void UninitShadow(void);
void UpdateShadow(void);
void DrawShadow(void);
int SetShadow(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
void SetPositionShadow(int nIndxShadow, D3DXVECTOR3 pos);

#endif