//==================================
//制作基礎 3D(wall.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _WALL_H_			//このマクロ定義がされなかったら
#define _WALL_H_			//2重インクルード防止のマクロ定義

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
}Wall;

//マクロ定義
#define MAX_WALL		(8)				//敵の最大数

//プロトタイプ宣言
void InitWall(void);
void UninitWall(void);
void UpdateWall(void);
void DrawWall(void);
void SetWall(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
Wall* GetWall(void);
#endif