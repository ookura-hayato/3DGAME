//==================================
//制作基礎 3D(model.cpp)
//	Author:　大倉隼翔
//==================================
#include "model.h"

//グローバル変数
LPD3DXMESH g_pMeshModel = NULL;			//メッシュ情報へのポインタ
LPD3DXBUFFER g_pBuffMatModel = NULL;	//マテリアル情報へのポインタ
DWORD g_nNumMatModel = 0;			//マテリアル情報の数
Model g_Model[MAX_MODEL];
D3DXMATRIX g_mtxWorldModel;			//ワールドマトリックス
int g_rotDestModel;					//目的の角度
int g_nInndxShadow;
D3DXVECTOR3 g_vtxMiniModel, g_vtxMaxmModel;

//モデル初期化処理
void InitModel(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//デバイスのポインタ
	//デバイスの取得
	pDevice = GetDevice();
	
	//Xファイル読み込み
	D3DXLoadMeshFromX( "data/MODEL/ganngimarin.x",D3DXMESH_SYSTEMMEM,pDevice,NULL,
		&g_pBuffMatModel,NULL,&g_nNumMatModel,&g_pMeshModel);

	int nNumVtx;									//頂点数
	DWORD sizeFVF;									//頂点フォーマットのサイズ
	BYTE * pVtxBuff;								//頂点バッファへのポインタ

	//頂点数の所得
	nNumVtx = g_pMeshModel->GetNumVertices();
	
	//頂点フォーマットのサイズを取得
	sizeFVF = D3DXGetFVFVertexSize(g_pMeshModel->GetFVF());

	//頂点バッファのロック
	g_pMeshModel->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

	for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
	{
		//頂点座標の代入
		D3DXVECTOR3 Vtx = *(D3DXVECTOR3*)pVtxBuff;

		if (Vtx.x < g_vtxMiniModel.x)
		{
			g_vtxMiniModel.x = Vtx.x;
		}
		if (Vtx.y < g_vtxMiniModel.y)
		{
			g_vtxMiniModel.y = Vtx.y;
		}
		if (Vtx.z < g_vtxMiniModel.z)
		{
			g_vtxMiniModel.z = Vtx.z;
		}
		if (Vtx.x > g_vtxMaxmModel.x)
		{
			g_vtxMaxmModel.x = Vtx.x;
		}
		if (Vtx.y > g_vtxMaxmModel.y)
		{
			g_vtxMaxmModel.y = Vtx.y;
		}
		if (Vtx.z > g_vtxMaxmModel.z)
		{
			g_vtxMaxmModel.z = Vtx.z;
		}
		pVtxBuff += sizeFVF;
	}

	//頂点バッファのアンロック
	g_pMeshModel ->UnlockVertexBuffer();

	g_Model[MAX_MODEL].pos = D3DXVECTOR3(50.0f, 0.0f, 0.0f);				//位置の初期設定
	g_Model[MAX_MODEL].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//向きの初期設定
	g_nInndxShadow = SetShadow(D3DXVECTOR3(g_Model[MAX_MODEL].pos.x,0.1f, g_Model[MAX_MODEL].pos.z), g_Model[MAX_MODEL].rot);
}

//モデル終了処理
void UninitModel(void)
{
	//メッシュの破棄
	if (g_pMeshModel != NULL)
	{
		g_pMeshModel->Release();
		g_pMeshModel = NULL;
	}

	//マテリアルの破棄
	if (g_pBuffMatModel != NULL)
	{
		g_pBuffMatModel->Release();
		g_pBuffMatModel = NULL;
	}
}

//モデル更新処理
void UpdateModel(void)
{
	SetPositionShadow(g_nInndxShadow, D3DXVECTOR3(g_Model[MAX_MODEL].pos.x, 0.1f, g_Model[MAX_MODEL].pos.z));
}

//モデル描画処理
void DrawModel(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//デバイスのポインタ			

	//デバイスの取得
	pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;	//計算用マトリックス
	D3DMATERIAL9 matDef;			//現在のマテリアル保存用
	D3DXMATERIAL * pMat;			//マテリアルデータへのポインタ

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&g_mtxWorldModel);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Model[MAX_MODEL].rot.y, g_Model[MAX_MODEL].rot.x, g_Model[MAX_MODEL].rot.z);
	D3DXMatrixMultiply(&g_mtxWorldModel, &g_mtxWorldModel, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, g_Model[MAX_MODEL].pos.x, g_Model[MAX_MODEL].pos.y, g_Model[MAX_MODEL].pos.z);
	D3DXMatrixMultiply(&g_mtxWorldModel, &g_mtxWorldModel, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldModel);

	//現在のマテリアルを保存
	pDevice->GetMaterial(&matDef);
	
	//マテリアルデータへのポインタを取得
	pMat = (D3DXMATERIAL *)g_pBuffMatModel->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < (int)g_nNumMatModel; nCntMat++)
	{
		//マテリアルの設定
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//モデルパーツの描画
		g_pMeshModel->DrawSubset(nCntMat);
	}
	//保持していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);
}

//当たり判定（モデル）
bool CollisionModel(D3DXVECTOR3*pPos,
	D3DXVECTOR3*pPosOld,
	float fWidith,
	float fHeight)
{
	bool bIsLanding = false;
	Player *pPlayer = GetPlayer();
	for (int nCntModel = 0; nCntModel < MAX_MODEL; nCntModel++)
	{
		if (g_Model[MAX_MODEL].bUse == true)
		{
			if (//判定（上）
				(g_Model[nCntModel].pos.z - g_Model[nCntModel].fHeight / 2) >= pPosOld->z
				&& (g_Model[nCntModel].pos.z - g_Model[nCntModel].fHeight / 2) < pPos->z
				&& (g_Model[nCntModel].pos.x + g_Model[nCntModel].fWidth / 2) > (pPos->x - fWidith / 2)
				&& (g_Model[nCntModel].pos.x - g_Model[nCntModel].fWidth / 2) < (pPos->x + fWidith / 2))
			{
			
				pPos->z = g_Model[nCntModel].pos.z - g_Model[nCntModel].fHeight / 2;
				
			}
			if (//判定(下)
				(g_Model[nCntModel].pos.z + g_Model[nCntModel].fHeight / 2) <= pPosOld->z - pPlayer->pos.z
				&& (g_Model[nCntModel].pos.z + g_Model[nCntModel].fHeight / 2) > pPos->z - pPlayer->pos.z
				&& (g_Model[nCntModel].pos.x + g_Model[nCntModel].fWidth / 2) > (pPos->x - fWidith / 2)
				&& (g_Model[nCntModel].pos.x - g_Model[nCntModel].fWidth / 2) < (pPos->x + fWidith / 2))
			{

				pPos->z = g_Model[nCntModel].pos.z + g_Model[nCntModel].fHeight / 2 + pPlayer->pos.z;
	
			}
			if (//判定(左)
				(g_Model[nCntModel].pos.x - g_Model[nCntModel].fWidth / 2) >= pPosOld->x + pPlayer->pos.x / 2
				&& (g_Model[nCntModel].pos.x - g_Model[nCntModel].fWidth / 2) < pPos->x + pPlayer->pos.x / 2
				&& (g_Model[nCntModel].pos.z + g_Model[nCntModel].fHeight / 2) > (pPos->z - fHeight / 2)
				&& (g_Model[nCntModel].pos.z - g_Model[nCntModel].fHeight / 2) < pPos->z)
			{

				pPos->x = g_Model[nCntModel].pos.x - g_Model[nCntModel].fWidth / 2 - pPlayer->pos.x / 2;
			
			}
			if (//判定(右)
				(g_Model[nCntModel].pos.x + g_Model[nCntModel].fWidth / 2) <= pPosOld->x - pPlayer->pos.x / 2
				&& (g_Model[nCntModel].pos.x + g_Model[nCntModel].fWidth / 2) > pPos->x - pPlayer->pos.x / 2
				&& (g_Model[nCntModel].pos.z + g_Model[nCntModel].fHeight / 2) > (pPos->z - fHeight / 2)
				&& (g_Model[nCntModel].pos.z - g_Model[nCntModel].fHeight / 2) < pPos->z)
			{

				pPos->x = g_Model[nCntModel].pos.x + g_Model[nCntModel].fWidth / 2 + pPlayer->pos.x / 2;
			
			}
		}
	}
	return bIsLanding;
}