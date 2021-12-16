//==================================
//制作基礎 3D(effect.cpp)
//	Author:　大倉隼翔
//==================================
#include "effect.h"

//グローバル変数
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffEffect = NULL;	//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureEffect = NULL;			//テクスチャへのポインタ
Effect g_Effect[MAX_EFFECT];						//エフェクト情報

//エフェクト初期化処理
void InitEffect(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスのポインタ

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/effect000.png", &g_pTextureEffect);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_EFFECT, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED, &g_pVtxBuffEffect, NULL);
	VERTEX_3D*pVtx = NULL;										//頂点情報へのポインタ
	g_pVtxBuffEffect->Lock(0, 0, (void**)&pVtx, 0);				//頂点バッファをロックし、頂点情報へのポインタを取得

	for (int nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		////頂点座標の設定
		//pVtx[0].pos = D3DXVECTOR3(-50.0f, 50.0f, 50.0f);
		//pVtx[1].pos = D3DXVECTOR3(50.0f, 50.0f, 50.0f);
		//pVtx[2].pos = D3DXVECTOR3(-50.0f, 0.0f, 50.0f);
		//pVtx[3].pos = D3DXVECTOR3(50.0f, 0.0f, 50.0f);

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
	g_pVtxBuffEffect->Unlock();

}

//エフェクト終了処理
void UninitEffect(void)
{
	//頂点バッファの破棄
	if (g_pVtxBuffEffect != NULL)
	{
		g_pVtxBuffEffect->Release();
		g_pVtxBuffEffect = NULL;
	}

	//テクスチャの破棄
	if (g_pTextureEffect != NULL)
	{
		g_pTextureEffect->Release();
		g_pTextureEffect = NULL;
	}
}

//エフェクト更新処理
void UpdateEffect(void)
{
	for (int nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		if (g_Effect[nCntEffect].bUse == true)
		{
			g_Effect[nCntEffect].pos += g_Effect[nCntEffect].rot;
			g_Effect[nCntEffect].bUse = false;
		}
	}
	if (GetKeyboardPress(DIK_F7) == true)
	{
		SetEffect(D3DXVECTOR3(5.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		SetEffect(D3DXVECTOR3(10.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, D3DX_PI*0.5f, 0.0f));
		SetEffect(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, -D3DX_PI * 0.5f, 0.0f));
	}
}

//エフェクト描画処理
void DrawEffect(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスのポインタ		
	D3DXMATRIX mtxRot, mtxTrans;	//計算用マトリックス

	//テクスチャの設定
	pDevice->SetTexture(0, g_pTextureEffect);

	//ZバッファとZテストの設定
	pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	for (int nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		//ワールドマトリックスの初期化
		D3DXMatrixIdentity(&g_Effect[nCntEffect].mtxWorld);

		//向きを反映
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Effect[nCntEffect].rot.y, g_Effect[nCntEffect].rot.x, g_Effect[nCntEffect].rot.z);
		D3DXMatrixMultiply(&g_Effect[nCntEffect].mtxWorld, &g_Effect[nCntEffect].mtxWorld, &mtxRot);

		//位置を反映
		D3DXMatrixTranslation(&mtxTrans, g_Effect[nCntEffect].pos.x, g_Effect[nCntEffect].pos.y, g_Effect[nCntEffect].pos.z);
		D3DXMatrixMultiply(&g_Effect[nCntEffect].mtxWorld, &g_Effect[nCntEffect].mtxWorld, &mtxTrans);

		//頂点バッファをデバイスのデータストリームに設定
		pDevice->SetStreamSource(0, g_pVtxBuffEffect, 0, sizeof(VERTEX_3D));

		//頂点フォーマットの設定
		pDevice->SetFVF(FVF_VERTEX_3D);

		//ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &g_Effect[nCntEffect].mtxWorld);

		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntEffect * 4, 2);

		pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
		pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
		pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
		pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	}

	//テクスチャの設定
	pDevice->SetTexture(0, NULL);
}

//エフェクトの設定
void SetEffect(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	VERTEX_3D*pVtx;	//頂点情報のポインタ
	int nCntEffect;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffEffect->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		if (g_Effect[nCntEffect].bUse == false)
		{
			g_Effect[nCntEffect].pos = pos;
			g_Effect[nCntEffect].rot = rot;

			pVtx[0].pos = D3DXVECTOR3(-80.0f, 100.0f, 70.0f);
			pVtx[1].pos = D3DXVECTOR3(80.0f, 100.0f, 70.0f);
			pVtx[2].pos = D3DXVECTOR3(-80.0f, 0.0f, 70.0f);
			pVtx[3].pos = D3DXVECTOR3(80.0f, 0.0f, 70.0f);

			g_Effect[nCntEffect].bUse = true;

			break;
		}
		pVtx += 4;	//ポインタを4つ進める
	}

	//頂点バッファをアンロックする
	g_pVtxBuffEffect->Unlock();
}

////壁の取得
//Effect* GetEffect(void)
//{
//	return &g_Effect[0];
//}