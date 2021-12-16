//==================================
//制作基礎 3D(wall.cpp)
//	Author:　大倉隼翔
//==================================
#include "wall.h"

//グローバル変数
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffWall = NULL;	//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureWall = NULL;			//テクスチャへのポインタ
Wall g_aWall[MAX_WALL];						//壁情報

//壁初期化処理
void InitWall(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスのポインタ

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/wall000.jpg", &g_pTextureWall);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_WALL, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED, &g_pVtxBuffWall, NULL);
	VERTEX_3D*pVtx = NULL;										//頂点情報へのポインタ
	g_pVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);				//頂点バッファをロックし、頂点情報へのポインタを取得

	for (int nCntWall = 0; nCntWall < MAX_WALL; nCntWall++)
	{

		//頂点の法線の設定
		pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		//頂点カラーの設定
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

		//テクスチャ座標の設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;			//頂点データのポインタを4つ分進める
	}
	//頂点バッファをアンロックする
	g_pVtxBuffWall->Unlock();

	SetWall(D3DXVECTOR3(5.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));		
	SetWall(D3DXVECTOR3(10.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, D3DX_PI*0.5f, 0.0f));		
	SetWall(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, -D3DX_PI * 0.5f, 0.0f));
}

//壁終了処理
void UninitWall(void)
{
	//頂点バッファの破棄
	if (g_pVtxBuffWall != NULL)
	{
		g_pVtxBuffWall->Release();
		g_pVtxBuffWall = NULL;
	}

	//テクスチャの破棄
	if (g_pTextureWall != NULL)
	{
		g_pTextureWall->Release();
		g_pTextureWall = NULL;
	}
}

//壁更新処理
void UpdateWall(void)
{

}

//壁描画処理
void DrawWall(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスのポインタ		
	D3DXMATRIX mtxRot, mtxTrans;	//計算用マトリックス

	
	//テクスチャの設定
	pDevice->SetTexture(0, g_pTextureWall);

	for (int nCntWall = 0; nCntWall < MAX_WALL; nCntWall++)
	{
		//ワールドマトリックスの初期化
			D3DXMatrixIdentity(&g_aWall[nCntWall].mtxWorld);

			//向きを反映
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_aWall[nCntWall].rot.y, g_aWall[nCntWall].rot.x, g_aWall[nCntWall].rot.z);
			D3DXMatrixMultiply(&g_aWall[nCntWall].mtxWorld, &g_aWall[nCntWall].mtxWorld, &mtxRot);

			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_aWall[nCntWall].pos.x, g_aWall[nCntWall].pos.y, g_aWall[nCntWall].pos.z);
			D3DXMatrixMultiply(&g_aWall[nCntWall].mtxWorld, &g_aWall[nCntWall].mtxWorld, &mtxTrans);

			//頂点バッファをデバイスのデータストリームに設定
			pDevice->SetStreamSource(0, g_pVtxBuffWall, 0, sizeof(VERTEX_3D));

			//頂点フォーマットの設定
			pDevice->SetFVF(FVF_VERTEX_3D);

			//ワールドマトリックスの設定
			pDevice->SetTransform(D3DTS_WORLD, &g_aWall[nCntWall].mtxWorld);

			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntWall * 4, 2);
		
	}
	
	//テクスチャの設定
	pDevice->SetTexture(0, NULL);

}

//壁の設定
void SetWall(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	VERTEX_3D*pVtx;	//頂点情報のポインタ
	int nCntWall;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffWall->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntWall = 0; nCntWall < MAX_WALL; nCntWall++)
	{
		if (g_aWall[nCntWall].bUse == false)
		{
			g_aWall[nCntWall].pos = pos;
			g_aWall[nCntWall].rot = rot;

			pVtx[0].pos = D3DXVECTOR3(-80.0f, 100.0f, 70.0f);
			pVtx[1].pos = D3DXVECTOR3(80.0f, 100.0f, 70.0f);
			pVtx[2].pos = D3DXVECTOR3(-80.0f, 0.0f, 70.0f);
			pVtx[3].pos = D3DXVECTOR3(80.0f, 0.0f, 70.0f);

			g_aWall[nCntWall].bUse = true;

			break;
		}
		pVtx += 4;	//ポインタを4つ進める
	}

	//頂点バッファをアンロックする
	g_pVtxBuffWall->Unlock();
}

//壁の取得
Wall* GetWall(void)
{
	return &g_aWall[0];
}