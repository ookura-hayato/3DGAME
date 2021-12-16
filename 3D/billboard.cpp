//==================================
//制作基礎 3D(wall.cpp)
//	Author:　大倉隼翔
//==================================
#include "billboard.h"

//グローバル変数
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffBillboard = NULL;	//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureBillboard = NULL;			//テクスチャへのポインタ
Billboard g_aBillboard[MAX_BILLBOARD];						//壁情報
int g_nIdxShadow;

//ビルボード初期化処理
void InitBillboard(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスのポインタ

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/koiking.png", &g_pTextureBillboard);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_BILLBOARD, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED, &g_pVtxBuffBillboard, NULL);
	VERTEX_3D*pVtx = NULL;										//頂点情報へのポインタ
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);				//頂点バッファをロックし、頂点情報へのポインタを取得

	for (int nCntBillboard = 0; nCntBillboard < MAX_BILLBOARD; nCntBillboard++)
	{
		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(-20.0f, 50.0f, 50.0f);
		pVtx[1].pos = D3DXVECTOR3(30.0f, 50.0f, 50.0f);
		pVtx[2].pos = D3DXVECTOR3(-20.0f, 20.0f, 50.0f);
		pVtx[3].pos = D3DXVECTOR3(30.0f, 20.0f, 50.0f);

		//頂点の法線の設定
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

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
	g_pVtxBuffBillboard->Unlock();
	g_nIdxShadow = SetShadow(D3DXVECTOR3(g_aBillboard[MAX_BILLBOARD].pos.x, 0.1f, g_aBillboard[MAX_BILLBOARD].pos.z), g_aBillboard[MAX_BILLBOARD].rot);


}

//ビルボード終了処理
void UninitBillboard(void)
{
	//頂点バッファの破棄
	if (g_pVtxBuffBillboard != NULL)
	{
		g_pVtxBuffBillboard->Release();
		g_pVtxBuffBillboard = NULL;
	}

	//テクスチャの破棄
	if (g_pTextureBillboard != NULL)
	{
		g_pTextureBillboard->Release();
		g_pTextureBillboard = NULL;
	}
}

//ビルボード更新処理
void UpdateBillboard(void)
{
	SetPositionShadow(g_nIdxShadow, D3DXVECTOR3(g_aBillboard[MAX_BILLBOARD].pos.x, 0.1f, g_aBillboard[MAX_BILLBOARD].pos.z));
}

//ビルボード描画処理
void DrawBillboard(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスのポインタ		
	D3DXMATRIX  mtxTrans;	//計算用マトリックス
	D3DXMATRIX  mtxView;
	pDevice->GetTransform(D3DTS_VIEW,&mtxView);

	//テクスチャの設定
	pDevice->SetTexture(0, g_pTextureBillboard);

	//ZバッファとZテストの設定
	pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	for (int nCntBillboard = 0; nCntBillboard < MAX_BILLBOARD; nCntBillboard++)
	{
		//ワールドマトリックスの初期化
		D3DXMatrixIdentity(&g_aBillboard[nCntBillboard].mtxWorld);

		//カメラの逆行列を設定
		g_aBillboard[nCntBillboard].mtxWorld._11 = mtxView._11;
		g_aBillboard[nCntBillboard].mtxWorld._12 = mtxView._21;
		g_aBillboard[nCntBillboard].mtxWorld._13 = mtxView._31;
		g_aBillboard[nCntBillboard].mtxWorld._21 = mtxView._12;
		g_aBillboard[nCntBillboard].mtxWorld._22 = mtxView._22;
		g_aBillboard[nCntBillboard].mtxWorld._23 = mtxView._32;
		g_aBillboard[nCntBillboard].mtxWorld._31 = mtxView._13;
		g_aBillboard[nCntBillboard].mtxWorld._32 = mtxView._23;
		g_aBillboard[nCntBillboard].mtxWorld._33 = mtxView._33;

		//位置を反映
		D3DXMatrixTranslation(&mtxTrans, g_aBillboard[nCntBillboard].pos.x, g_aBillboard[nCntBillboard].pos.y, g_aBillboard[nCntBillboard].pos.z);
		D3DXMatrixMultiply(&g_aBillboard[nCntBillboard].mtxWorld, &g_aBillboard[nCntBillboard].mtxWorld, &mtxTrans);

		//頂点バッファをデバイスのデータストリームに設定
		pDevice->SetStreamSource(0, g_pVtxBuffBillboard, 0, sizeof(VERTEX_3D));

		//頂点フォーマットの設定
		pDevice->SetFVF(FVF_VERTEX_3D);
		
		//ライトを無効にする
		pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

		//ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &g_aBillboard[nCntBillboard].mtxWorld);

		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntBillboard * 4, 2);
		//ライトを有効にする
		pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

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

//ビルボードの設定
void SetBillboard(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	VERTEX_3D*pVtx;	//頂点情報のポインタ
	int nCntBillboard;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBillboard = 0; nCntBillboard < MAX_BILLBOARD; nCntBillboard++)
	{
		if (g_aBillboard[nCntBillboard].bUse == false)
		{
			g_aBillboard[nCntBillboard].pos = pos;
			g_aBillboard[nCntBillboard].rot = rot;

			pVtx[0].pos = D3DXVECTOR3(-50.0f, 50.0f, 50.0f);
			pVtx[1].pos = D3DXVECTOR3(50.0f, 50.0f, 50.0f);
			pVtx[2].pos = D3DXVECTOR3(-50.0f, 0.0f, 50.0f);
			pVtx[3].pos = D3DXVECTOR3(50.0f, 0.0f, 50.0f);

			g_aBillboard[nCntBillboard].bUse = true;

			break;
		}
		pVtx += 4;	//ポインタを4つ進める
	}

	//頂点バッファをアンロックする
	g_pVtxBuffBillboard->Unlock();
}