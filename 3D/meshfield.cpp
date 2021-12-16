//==================================
//制作基礎 3D(meshfeild.cpp)
//	Author:　大倉隼翔
//==================================
#include "meshfeild.h"

//マクロ定義
#define MESHFIELD_X_BLOCK (3)					//X方向のブロック数
#define MESHFIELD_Z_BLOCK (3)					//Z方向のブロック数

#define MESHFIELD_VERTEX_NUM	((MESHFIELD_X_BLOCK + 1)*(MESHFIELD_Z_BLOCK + 1))										//頂点数
#define MESHFIELD_INDEX_NUM		((MESHFIELD_X_BLOCK + 1) * 2 * MESHFIELD_Z_BLOCK + (MESHFIELD_Z_BLOCK - 1) * 2)			//インデックス数
#define MESHFIELD_PRIMITIVE_NUM	 (MESHFIELD_X_BLOCK * MESHFIELD_Z_BLOCK * 2 + (MESHFIELD_Z_BLOCK -1) * 4)				//ポリゴン数

//グローバル変数
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffMeshfeild = NULL;						//頂点バッファへのポインタ
LPDIRECT3DINDEXBUFFER9	g_pIdxBuffMeshfeild = NULL;						//インデックスバッファへのポインタ
//LPDIRECT3DTEXTURE9 g_pTextureMeshfeild = NULL;							//テクスチャへのポインタ
D3DXVECTOR3 g_posMeshfeild;												//位置
D3DXVECTOR3 g_rotMeshfeild;												//向き
D3DXMATRIX g_mtxWorldMeshfeild;											//ワールドマトリックス 

//メッシュフィールド初期化処理
void InitMeshfeild(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスのポインタ

	////テクスチャの読み込み
	//D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/field002.jpg", &g_pTextureMeshfeild);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * MESHFIELD_VERTEX_NUM, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED, &g_pVtxBuffMeshfeild, NULL);

	VERTEX_3D*pVtx = NULL;										//頂点情報へのポインタ
	g_pVtxBuffMeshfeild->Lock(0, 0, (void**)&pVtx, 0);			//頂点バッファをロックし、頂点情報へのポインタを取得

	//インデックスバッファの生成
	pDevice->CreateIndexBuffer(sizeof(WORD) * 100000000, D3DUSAGE_WRITEONLY,D3DFMT_INDEX16,
		D3DPOOL_MANAGED, &g_pIdxBuffMeshfeild, NULL);

	//頂点の設定
	for(int nCntZ = 0; nCntZ <= MESHFIELD_Z_BLOCK ; nCntZ++)
	{
		for (int nCntX = 0; nCntX <= MESHFIELD_X_BLOCK; nCntX++)
		{
			//頂点の設定
			pVtx[0].pos = D3DXVECTOR3(-70.0f + 50.0f * nCntX, 0.0f, 70.0f -50.0f * nCntZ);

			//法線の設定	 
			pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

			//頂点カラーの設定
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			
			////テクスチャ座標の設定
			//pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			//pVtx[1].tex = D3DXVECTOR2(0.0f, 0.5f);
			//pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
			//pVtx[3].tex = D3DXVECTOR2(0.5f, 0.0f);
			//pVtx[4].tex = D3DXVECTOR2(0.5f, 0.5f);
			//pVtx[5].tex = D3DXVECTOR2(0.5f, 1.0f);
			//pVtx[6].tex = D3DXVECTOR2(1.0f, 0.0f);
			//pVtx[7].tex = D3DXVECTOR2(1.0f, 0.5f);
			//pVtx[8].tex = D3DXVECTOR2(1.0f, 1.0f);
			pVtx++;
		}
	}
	//頂点バッファをアンロックする
	g_pVtxBuffMeshfeild->Unlock();

	WORD * pIdx;											//インデックス情報へのポインタ
	g_pIdxBuffMeshfeild->Lock(0, 0, (void**)&pIdx, 0);		//インデックスバッファをロックし、頂点情報へのポインタを取得

	for (int nCntZ = 0; nCntZ <= MESHFIELD_Z_BLOCK; nCntZ++)
	{
		for (int nCntX = 0; nCntX <= MESHFIELD_X_BLOCK; nCntX++)
		{
			//インデックスの設定
			pIdx[0] = (WORD)(nCntX + (MESHFIELD_X_BLOCK + 1) * (nCntZ + 1));
			pIdx[1] = (WORD)(nCntX + (MESHFIELD_X_BLOCK + 1) * nCntZ);
			pIdx += 2;
		}
		if (nCntZ < MESHFIELD_Z_BLOCK - 1)
		{
			pIdx[0] = pIdx[-1];
			pIdx[1] = (WORD)(MESHFIELD_X_BLOCK + 1) * (nCntZ + 2);
			pIdx += 2;
		}

	}
	
	//インデックスバッファをアンロックする
	g_pIdxBuffMeshfeild->Unlock();
}

//メッシュフィールド終了処理
void UninitMeshfeild(void)
{
	//頂点バッファの破棄
	if (g_pVtxBuffMeshfeild != NULL)
	{
		g_pVtxBuffMeshfeild->Release();
		g_pVtxBuffMeshfeild = NULL;
	}

	//インデックスバッファの破棄
	if (g_pIdxBuffMeshfeild != NULL)
	{	  
		g_pIdxBuffMeshfeild->Release();
		g_pIdxBuffMeshfeild = NULL;
	}

	////テクスチャの破棄
	//if (g_pTextureMeshfeild != NULL)
	//{
	//	g_pTextureMeshfeild->Release();
	//	g_pTextureMeshfeild = NULL;
	//}
}

//メッシュフィールド更新処理
void UpdateMeshfeild(void)
{

}

//メッシュフィールド描画処理
void DrawMeshfeild(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//デバイスのポインタ			
									//デバイスの取得
	pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;	//計算用マトリックス

	////テクスチャの設定
	//pDevice->SetTexture(0, g_pTextureMeshfeild);

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&g_mtxWorldMeshfeild);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotMeshfeild.y, g_rotMeshfeild.x, g_rotMeshfeild.z);
	D3DXMatrixMultiply(&g_mtxWorldMeshfeild, &g_mtxWorldMeshfeild, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, g_posMeshfeild.x, g_posMeshfeild.y, g_posMeshfeild.z);
	D3DXMatrixMultiply(&g_mtxWorldMeshfeild, &g_mtxWorldMeshfeild, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldMeshfeild);

	//頂点バッファをデバイスのデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffMeshfeild, 0, sizeof(VERTEX_3D));

	//インデックスバッファをデバイスのデータストリームに設定
	pDevice->SetIndices(g_pIdxBuffMeshfeild);

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	//ポリゴンの描画
	pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, MESHFIELD_VERTEX_NUM, 0, MESHFIELD_PRIMITIVE_NUM);

	////テクスチャの設定
	//pDevice->SetTexture(0, NULL);
}