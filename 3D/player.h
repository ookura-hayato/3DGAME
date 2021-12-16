//==================================
//制作基礎 3D(player.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _PLAYER_H_			//このマクロ定義がされなかったら
#define _PLAYER_H_			//2重インクルード防止のマクロ定義

//インクルードファイル
#include "main.h"

// 構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;				//位置
	D3DXVECTOR3 posold;				//前回の位置
	D3DXVECTOR3 rot;				//向き
}Player;

//プロトタイプ宣言
void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);                  
Player * GetPlayer(void);
#endif