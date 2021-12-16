//==================================
//制作基礎 3D(light.cpp)
//	Author:　大倉隼翔
//==================================
#include "light.h"

//グローバル変数
D3DLIGHT9 g_Light[MAX_LIGHT];									//ライト情報

//ライトの初期化処理
void InitLight(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスのポインタ		
	D3DXVECTOR3 vecDir;								//ライトの方向ベクトル
	
	
	//ライトをクリアする
	ZeroMemory(&g_Light, sizeof(g_Light));

	//ライトの種類を設定
	g_Light[0].Type = D3DLIGHT_DIRECTIONAL;

	//ライトの拡散光を設定
	g_Light[0].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	
	//ライトの方向を設定
	vecDir = D3DXVECTOR3(0.2f, -0.8f, -0.4f);
	

	//正規化する
	D3DXVec3Normalize(&vecDir, &vecDir);
	g_Light[0].Direction = vecDir;

	//ライトを設定する
	pDevice->SetLight(0, &g_Light[0]);

	//ライトを有効にする
	pDevice->LightEnable(0, TRUE);

	//ライトの種類を設定
	g_Light[1].Type = D3DLIGHT_DIRECTIONAL;

	//ライトの拡散光を設定
	g_Light[1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//ライトの方向を設定
	vecDir = D3DXVECTOR3(1.2f, -1.8f, 2.4f);

	//正規化する
	D3DXVec3Normalize(&vecDir, &vecDir);
	g_Light[1].Direction = vecDir;

	//ライトを設定する
	pDevice->SetLight(0, &g_Light[1]);

	//ライトを有効にする
	pDevice->LightEnable(0, TRUE);

	//ライトの種類を設定
	g_Light[2].Type = D3DLIGHT_DIRECTIONAL;

	//ライトの拡散光を設定
	g_Light[2].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//ライトの方向を設定
	vecDir = D3DXVECTOR3(0.0f, -1.0f, 2.0f);

	//正規化する
	D3DXVec3Normalize(&vecDir, &vecDir);
	g_Light[2].Direction = vecDir;

	//ライトを設定する
	pDevice->SetLight(0, &g_Light[2]);

	//ライトを有効にする
	pDevice->LightEnable(0, TRUE);
}

//ライトの終了処理
void UninitLight(void)
{

}

//ライトの更新処理
void UpdateLight(void)
{

}