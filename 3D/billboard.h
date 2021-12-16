//==================================
//制作基礎 3D(billboard.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _BILLBOARD_H_			//このマクロ定義がされなかったら
#define _BILLBOARD_H_			//2重インクルード防止のマクロ定義

//インクルードファイル
#include "main.h"

// 構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXMATRIX mtxWorld;
	bool bUse;
}Billboard;

//マクロ定義
#define MAX_BILLBOARD		(10)				//敵の最大数

//プロトタイプ宣言
void InitBillboard(void);
void UninitBillboard(void);
void UpdateBillboard(void);
void DrawBillboard(void);
void SetBillboard(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
#endif