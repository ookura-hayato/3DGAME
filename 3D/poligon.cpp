//==================================
//制作基礎 3D(poligon.cpp)
//	Author:　大倉隼翔
//==================================
#include "poligon.h"

//グローバル変数
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffPoligon = NULL;	//頂点バッファへのポインタ
D3DXVECTOR3 g_posPoligon;							//位置
D3DXVECTOR3 g_rotPoligon;							//向き
D3DXMATRIX g_mtxWorldPoligon;						//ワールドマトリックス

//ポリゴン初期化処理
void InitPoligon(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//デバイスのポインタ

	//デバイスの取得
	pDevice = GetDevice();
	
	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED, &g_pVtxBuffPoligon,NULL);
	VERTEX_3D*pVtx = NULL;										//頂点情報へのポインタ
	g_pVtxBuffPoligon->Lock(0, 0, (void**)&pVtx, 0);		//頂点バッファをロックし、頂点情報へのポインタを取得

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(-50.0f, 0.0f, 50.0f);
	pVtx[1].pos = D3DXVECTOR3(50.0f, 0.0f, 50.0f);
	pVtx[2].pos = D3DXVECTOR3(-50.0f, 0.0f, -50.0f);
	pVtx[3].pos = D3DXVECTOR3(50.0f, 0.0f, -50.0f);

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

	//頂点バッファをアンロックする
	g_pVtxBuffPoligon->Unlock();
}

//ポリゴン終了処理
void UninitPoligon(void)
{
	//頂点バッファの破棄
	if (g_pVtxBuffPoligon != NULL)
	{
		g_pVtxBuffPoligon->Release();
		g_pVtxBuffPoligon = NULL;
	}
}

//ポリゴン更新処理
void UpdatePoligon(void)
{
	
}

//ポリゴン描画処理
void DrawPoligon(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//デバイスのポインタ			
	//デバイスの取得
	pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;	//計算用マトリックス

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&g_mtxWorldPoligon);
	
	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotPoligon.y, g_rotPoligon.x, g_rotPoligon.z);
	D3DXMatrixMultiply(&g_mtxWorldPoligon, &g_mtxWorldPoligon, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, g_posPoligon.x, g_posPoligon.y, g_posPoligon.z);
	D3DXMatrixMultiply(&g_mtxWorldPoligon, &g_mtxWorldPoligon, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD,&g_mtxWorldPoligon);

	//頂点バッファをデバイスのデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffPoligon, 0, sizeof(VERTEX_3D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}