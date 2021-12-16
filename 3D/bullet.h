#pragma once
#ifndef _BULLET_H_			//このマクロ定義がされなかったら
#define _BULLET_H_			//2重インクルード防止のマクロ定義
#include"main.h"

//マクロ定義
#define MAX_BULLET		(300)					//弾の最大数
#define COLOERBULLET	(D3DXCOLOR(1.0f,1.0f,1.0f,1.0f))

// 弾の構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXMATRIX mtxWorld;
	D3DXVECTOR3 move;		//移動量
	int nLife;				//寿命
	bool bUse;				//使用しているかどうか
}Bullet;

//プロトタイプ宣言
void InitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);
void SetBullet(D3DXVECTOR3 pos,D3DXVECTOR3 move);
#endif
