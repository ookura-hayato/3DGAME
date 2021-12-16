//==================================
//制作基礎 3D(poligon.cpp)
//	Author:　大倉隼翔
//==================================
#include"bullet.h"

//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureBullet = NULL;			//テクスチャへのポインタ								//頂点情報の格納
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffBullet = NULL;	//頂点バッファへのポインタ
Bullet g_aBullet[MAX_BULLET];						//弾の情報

//弾の初期化処理
void InitBullet(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntBullet;

	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/bullet000.png", &g_pTextureBullet);

	//弾の情報の初期化
	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		g_aBullet[nCntBullet].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aBullet[nCntBullet].nLife = 50;
		g_aBullet[nCntBullet].bUse = false;
	}

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_BULLET, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED, &g_pVtxBuffBullet, NULL);
	VERTEX_3D*pVtx;										//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);		
	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		 
		//頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//テクスチャ座標の設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;			//頂点データのポインタを4つ分進める
	}
	//頂点バッファをアンロックする
	g_pVtxBuffBullet->Unlock();
}

//弾の終了処理
void UninitBullet(void)
{
	//テクスチャの破棄
	if (g_pTextureBullet != NULL)
	{
		g_pTextureBullet->Release();
		g_pTextureBullet = NULL;
	}

	//頂点バッファの破棄
	if (g_pVtxBuffBullet != NULL)
	{
		g_pVtxBuffBullet->Release();
		g_pVtxBuffBullet = NULL;
	}
}

//弾の更新処理
void UpdateBullet(void)
{
	int nCntBullet;
	VERTEX_3D * pVtx;
	//頂点情報をロックし、頂点情報へのポインタを取得
	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == true)
		{//弾が使用されている
			g_aBullet[nCntBullet].nLife--;
			
			}
			//弾の位置更新
			g_aBullet[nCntBullet].pos.y += g_aBullet[nCntBullet].move.y;
			
			//頂点座標更新
			pVtx[0].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - 15.0f, g_aBullet[nCntBullet].pos.y - 15.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + 15.0f, g_aBullet[nCntBullet].pos.y - 15.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - 15.0f, g_aBullet[nCntBullet].pos.y + 15.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + 15.0f, g_aBullet[nCntBullet].pos.y + 15.0f, 0.0f);
			
			if (g_aBullet[nCntBullet].pos.y < 5)
			{//画面の外に出たら
				g_aBullet[nCntBullet].bUse = false;
			}
		//寿命のカウントダウン
			if (g_aBullet[nCntBullet].nLife <= 0)
			{//寿命が尽きた
				g_aBullet[nCntBullet].bUse = false;
 				SetExplosion(g_aBullet[nCntBullet].pos, COLOERBULLET ,15.0f);
				
			}
		}
		pVtx += 4;			//頂点データのポインタを4つ分進める
	
		//頂点バッファをアンロックする
		g_pVtxBuffBullet->Unlock();
	}
	


//弾の描画処理
void DrawBullet(void)
{

	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスのポインタ		
	D3DXMATRIX  mtxTrans;	//計算用マトリックス
	D3DXMATRIX  mtxView;
	pDevice->GetTransform(D3DTS_VIEW, &mtxView);

	//テクスチャの設定
	pDevice->SetTexture(0, g_pTextureBullet);

	//ZバッファとZテストの設定
	pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	for (int nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		//ワールドマトリックスの初期化
		D3DXMatrixIdentity(&g_aBullet[nCntBullet].mtxWorld);

		//カメラの逆行列を設定
		g_aBullet[nCntBullet].mtxWorld._11 = mtxView._11;
		g_aBullet[nCntBullet].mtxWorld._12 = mtxView._21;
		g_aBullet[nCntBullet].mtxWorld._13 = mtxView._31;
		g_aBullet[nCntBullet].mtxWorld._21 = mtxView._12;
		g_aBullet[nCntBullet].mtxWorld._22 = mtxView._22;
		g_aBullet[nCntBullet].mtxWorld._23 = mtxView._32;
		g_aBullet[nCntBullet].mtxWorld._31 = mtxView._13;
		g_aBullet[nCntBullet].mtxWorld._32 = mtxView._23;
		g_aBullet[nCntBullet].mtxWorld._33 = mtxView._33;

		//位置を反映
		D3DXMatrixTranslation(&mtxTrans, g_aBullet[nCntBullet].pos.x, g_aBullet[nCntBullet].pos.y, g_aBullet[nCntBullet].pos.z);
		D3DXMatrixMultiply(&g_aBullet[nCntBullet].mtxWorld, &g_aBullet[nCntBullet].mtxWorld, &mtxTrans);

		//頂点バッファをデバイスのデータストリームに設定
		pDevice->SetStreamSource(0, g_pVtxBuffBullet, 0, sizeof(VERTEX_3D));

		//頂点フォーマットの設定
		pDevice->SetFVF(FVF_VERTEX_3D);

		//ライトを無効にする
		pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

		//ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &g_aBullet[nCntBullet].mtxWorld);

		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntBullet * 4, 2);

		//ライトを有効にする
		pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

		pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
		pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
		pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
		pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	}

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffBullet, 0, sizeof(VERTEX_3D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

}
//弾の設定処理
void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move)
{
	int nCntBullet;
	VERTEX_3D * pVtx;

	//頂点情報をロックし、頂点情報へのポインタを取得
	g_pVtxBuffBullet->Lock(0,0,(void**)&pVtx,0);

	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
	{
		if (g_aBullet[nCntBullet].bUse == false)
		{//弾が使用されていない場合
			g_aBullet[nCntBullet].pos = pos;

			//頂点座標更新
			pVtx[0].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - 15.0f, g_aBullet[nCntBullet].pos.y - 15.0f, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + 15.0f, g_aBullet[nCntBullet].pos.y - 15.0f, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - 15.0f, g_aBullet[nCntBullet].pos.y + 15.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + 15.0f, g_aBullet[nCntBullet].pos.y + 15.0f, 0.0f);
			g_aBullet[nCntBullet].move = move;
			g_aBullet[nCntBullet].nLife = 50;
			g_aBullet[nCntBullet].bUse = true;
			break;
		}
		//頂点データのポインタを4つ分進める
		pVtx += 4;
	}
	//頂点バッファをアンロックする
	g_pVtxBuffBullet->Unlock();
}