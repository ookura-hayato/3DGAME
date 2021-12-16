//==================================
//制作基礎 3D(model.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _MODEL_H_			//このマクロ定義がされなかったら
#define _MODEL_H_			//2重インクルード防止のマクロ定義

//インクルードファイル
#include "main.h"

// 構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	float fWidth;
	float fHeight;
	bool bUse;
}Model;

//マクロ定義
#define MAX_MODEL		(100)				//敵の最大数

//プロトタイプ宣言
void InitModel(void);
void UninitModel(void);
void UpdateModel(void);
void DrawModel(void);
bool CollisionModel(D3DXVECTOR3*pPos,
	D3DXVECTOR3*pPosOld,
	D3DXVECTOR3*pMove,
	float fWidith,
	float fHeight);
#endif