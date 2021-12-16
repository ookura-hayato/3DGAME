//==================================
//制作基礎 3D(camera.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _CAMERA_H_			//このマクロ定義がされなかったら
#define _CAMERA_H_			//2重インクルード防止のマクロ定義

#include "main.h"

// 構造体を定義
typedef struct
{
	D3DXVECTOR3 posV;				//現在の視点
	D3DXVECTOR3 posR;				//現在の注視点
	D3DXVECTOR3 posVDest;			//目的の視点
	D3DXVECTOR3 posRDest;			//目的の注視点
	D3DXVECTOR3 vecU;				//上方向ベクトル
	D3DXMATRIX mtxProjection;		//プロジェクションマトリックス
	D3DXMATRIX mtxView;				//ビューマトリックス
	D3DXVECTOR3 rot;				//向き
	float fDistance;				//視点から注視点の距離
	float fDistanceDest;			//目的の視点から目的の注視点の距離
}Camera;

//プロトタイプ宣言
void InitCamera(void);
void UninitCamera(void);
void UpdateCamera(void);
void SetCamera(void);
Camera * GetCamera(void);
#endif
