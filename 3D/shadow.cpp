//==================================
//制作基礎 3D(shadow.cpp)
//	Author:　大倉隼翔
//==================================
#include "shadow.h"

//グローバル変数
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffShadow = NULL;	//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureShadow = NULL;			//テクスチャへのポインタ
Shadow g_aShadow[MAX_SHADOW];						//影情報

//影初期化処理
void InitShadow(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスのポインタ

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,"data/TEXTURE/shadow000.jpg", &g_pTextureShadow);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_SHADOW, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED, &g_pVtxBuffShadow, NULL);
	VERTEX_3D*pVtx = NULL;										//頂点情報へのポインタ
	g_pVtxBuffShadow->Lock(0, 0, (void**)&pVtx, 0);				//頂点バッファをロックし、頂点情報へのポインタを取得
	
	for (int nCntShadow = 0; nCntShadow < MAX_SHADOW; nCntShadow++)
	{
		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(-15.0f, 0.0f, 15.0f);
		pVtx[1].pos = D3DXVECTOR3(15.0f, 0.0f, 15.0f);
		pVtx[2].pos = D3DXVECTOR3(-15.0f, 0.0f, -15.0f);
		pVtx[3].pos = D3DXVECTOR3(15.0f, 0.0f, -15.0f);

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

	}
	pVtx += 4;			//頂点データのポインタを4つ分進める

	//頂点バッファをアンロックする
	g_pVtxBuffShadow->Unlock();
}

//影終了処理
void UninitShadow(void)
{
	//頂点バッファの破棄
	if (g_pVtxBuffShadow != NULL)
	{
		g_pVtxBuffShadow->Release();
		g_pVtxBuffShadow = NULL;
	}

	//テクスチャの破棄
	if (g_pTextureShadow != NULL)
	{
		g_pTextureShadow->Release();
		g_pTextureShadow = NULL;
	}
}

//影更新処理
void UpdateShadow(void)
{

}

//影描画処理
void DrawShadow(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスのポインタ		
	D3DXMATRIX mtxRot, mtxTrans;	//計算用マトリックス

	//減算合成の設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	//テクスチャの設定
	pDevice->SetTexture(0, g_pTextureShadow);

	for (int nCntShadow = 0; nCntShadow < MAX_SHADOW; nCntShadow++)
	{
		if (g_aShadow[nCntShadow].bUse == true)
		{
			//ワールドマトリックスの初期化
			D3DXMatrixIdentity(&g_aShadow[nCntShadow].mtxWorld);

			//向きを反映
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_aShadow[nCntShadow].rot.y, g_aShadow[nCntShadow].rot.x, g_aShadow[nCntShadow].rot.z);
			D3DXMatrixMultiply(&g_aShadow[nCntShadow].mtxWorld, &g_aShadow[nCntShadow].mtxWorld, &mtxRot);

			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_aShadow[nCntShadow].pos.x, g_aShadow[nCntShadow].pos.y, g_aShadow[nCntShadow].pos.z);
			D3DXMatrixMultiply(&g_aShadow[nCntShadow].mtxWorld, &g_aShadow[nCntShadow].mtxWorld, &mtxTrans);

			//頂点バッファをデバイスのデータストリームに設定
			pDevice->SetStreamSource(0, g_pVtxBuffShadow, 0, sizeof(VERTEX_3D));

			//頂点フォーマットの設定
			pDevice->SetFVF(FVF_VERTEX_3D);

			//ワールドマトリックスの設定
			pDevice->SetTransform(D3DTS_WORLD, &g_aShadow[nCntShadow].mtxWorld);

			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
		}
	}
	//設定を元に戻す
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	//テクスチャの設定
	pDevice->SetTexture(0, NULL);
	
}

//影の設定
int SetShadow(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{

	int nCntShadow;
	
	for (nCntShadow = 0; nCntShadow < MAX_SHADOW; nCntShadow++)
	{
		if (g_aShadow[nCntShadow].bUse == false)
		{
			D3DXVECTOR3 pos = g_aShadow[nCntShadow].pos;
			D3DXVECTOR3 rot = g_aShadow[nCntShadow].rot;
			g_aShadow[nCntShadow].bUse = true;

			break;
		}
	}

	return nCntShadow;
}

//影の位置の更新処理
void SetPositionShadow(int nIndxShadow, D3DXVECTOR3 pos)
{
	g_aShadow[nIndxShadow].pos = pos;
}