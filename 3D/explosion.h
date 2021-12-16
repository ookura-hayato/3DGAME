//==================================
//制作基礎 3D(poligon.cpp)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _EXPLOSION_H_			//このマクロ定義がされなかったら
#define _EXPLOSION_H_			//2重インクルード防止のマクロ定義
#include"main.h"
//マクロ定義
#define MAX_EXPLOSION		(128)					//爆発の最大数

// 爆発の構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXMATRIX mtxWorld;
	D3DXVECTOR3 move;		//移動量
	int nCounterAnim;		//アニメーションカウンター
	int nPatternAnim;		//アニメーションパターンNo.
	bool bUse;				//使用しているかどうか
}Explosion;

//プロトタイプ宣言
void InitExplosion(void);
void UninitExplosion(void);
void UpdateExplosion(void);
void DrawExplosion(void);
void SetExplosion(D3DXVECTOR3 pos, D3DXCOLOR col,float size);
#endif
