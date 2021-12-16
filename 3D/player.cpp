//==================================
//制作基礎 3D(player.cpp)
//	Author:　大倉隼翔
//==================================
#include "player.h"

//グローバル変数
LPD3DXMESH g_pMeshPlayer = NULL;			//メッシュ情報へのポインタ
LPD3DXBUFFER g_pBuffMatPlayer = NULL;	//マテリアル情報へのポインタ
DWORD g_nNumMatPlayer = 0;			//マテリアル情報の数
Player g_aPlayer;
D3DXMATRIX g_mtxWorldPlayer;			//ワールドマトリックス
int g_rotDestPlayer;					//目的の角度
int g_nIndxShadow;

//プレイヤー初期化処理
void InitPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//デバイスのポインタ
									//デバイスの取得
	pDevice = GetDevice();

	//Xファイル読み込み
	D3DXLoadMeshFromX("data/MODEL/pengin.x", D3DXMESH_SYSTEMMEM, pDevice, NULL,
		&g_pBuffMatPlayer, NULL, &g_nNumMatPlayer, &g_pMeshPlayer);
	g_aPlayer.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//位置の初期設定
	g_aPlayer.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//向きの初期設定
	g_nIndxShadow = SetShadow(D3DXVECTOR3(g_aPlayer.pos.x, 0.1f, g_aPlayer.pos.z), g_aPlayer.rot);
}

//プレイヤー終了処理
void UninitPlayer(void)
{
	//メッシュの破棄
	if (g_pMeshPlayer != NULL)
	{
		g_pMeshPlayer->Release();
		g_pMeshPlayer = NULL;
	}

	//マテリアルの破棄
	if (g_pBuffMatPlayer != NULL)
	{
		g_pBuffMatPlayer->Release();
		g_pBuffMatPlayer = NULL;
	}
}

//プレイヤー更新処理
void UpdatePlayer(void)
{
	Camera *pCamera = GetCamera();

	if (GetKeyboardPress(DIK_UP) == true)
	{
		g_aPlayer.pos.x += sinf(0.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.pos.z += cosf(0.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.rot.y = D3DX_PI + pCamera->rot.y;
	}

	if (GetKeyboardPress(DIK_DOWN) == true)
	{
		g_aPlayer.pos.x -= sinf(0.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.pos.z -= cosf(0.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.rot.y = pCamera->rot.y;
	}

	if (GetKeyboardPress(DIK_RIGHT) == true)
	{
		g_aPlayer.pos.x += sinf(D3DX_PI / 2.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.pos.z += cosf(D3DX_PI / 2.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.rot.y = -D3DX_PI / 2.0f + pCamera->rot.y;
	}

	if (GetKeyboardPress(DIK_LEFT) == true)
	{
		g_aPlayer.pos.x -= sinf(D3DX_PI / 2.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.pos.z -= cosf(D3DX_PI / 2.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.rot.y = D3DX_PI / 2.0f + pCamera->rot.y;
	}

	//プレイヤーリセット
	if (GetKeyboardPress(DIK_F5) == true)
	{
		g_aPlayer.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aPlayer.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}
	SetPositionShadow(g_nIndxShadow, D3DXVECTOR3(g_aPlayer.pos.x, 0.1f, g_aPlayer.pos.z));

	//CollisionModel(&g_aPlayer.pos, &g_aPlayer.posold, g_aPlayer.rot, g_aPlayer.pos.z);
}

//プレイヤー描画処理
void DrawPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//デバイスのポインタ			

									//デバイスの取得
	pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;	//計算用マトリックス
	D3DMATERIAL9 matDef;			//現在のマテリアル保存用
	D3DXMATERIAL * pMat;			//マテリアルデータへのポインタ

									//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&g_mtxWorldPlayer);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_aPlayer.rot.y, g_aPlayer.rot.x, g_aPlayer.rot.z);
	D3DXMatrixMultiply(&g_mtxWorldPlayer, &g_mtxWorldPlayer, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, g_aPlayer.pos.x, g_aPlayer.pos.y, g_aPlayer.pos.z);
	D3DXMatrixMultiply(&g_mtxWorldPlayer, &g_mtxWorldPlayer, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldPlayer);

	//現在のマテリアルを保存
	pDevice->GetMaterial(&matDef);

	//マテリアルデータへのポインタを取得
	pMat = (D3DXMATERIAL *)g_pBuffMatPlayer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < (int)g_nNumMatPlayer; nCntMat++)
	{
		//マテリアルの設定
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//モデルパーツの描画
		g_pMeshPlayer->DrawSubset(nCntMat);
	}
	//保持していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);
}

Player * GetPlayer(void)
{
	return &g_aPlayer;
}
