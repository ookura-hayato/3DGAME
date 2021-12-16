//==================================
//制作基礎 :3D(camera.cpp)
//	Author:　大倉隼翔
//==================================
#include "camera.h"

//グローバル変数
Camera g_Camera;	//カメラ情報

//カメラの初期化処理
void InitCamera(void)
{
	//視点・注視点・上方向を設定する
	g_Camera.posV = D3DXVECTOR3(0.0f, 20.0f, -80.0f);
	g_Camera.posR = D3DXVECTOR3(0.0f, 20.0f, 0.0f);
	g_Camera.vecU = D3DXVECTOR3(0.0f,1.0f,0.0f);
	g_Camera.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_Camera.fDistance = sqrtf((g_Camera.posR.z - g_Camera.posV.z) * (g_Camera.posR.z - g_Camera.posV.z) + (g_Camera.posR.x - g_Camera.posV.x) * (g_Camera.posR.x - g_Camera.posV.x));
}

//カメラの終了処理
void UninitCamera(void)
{

}

//カメラの更新処理
void UpdateCamera(void)
{
	Player *pPlayer = GetPlayer();

	g_Camera.posRDest.x = pPlayer->pos.x + sinf(pPlayer->rot.x)*pPlayer->pos.x;
	g_Camera.posRDest.y = 0.0f;
	g_Camera.posRDest.z = pPlayer->pos.z + cosf(pPlayer->rot.x)*pPlayer->pos.x;
	g_Camera.posVDest.x = pPlayer->pos.x - sinf(pPlayer->rot.z)*g_Camera.fDistance;
	g_Camera.posVDest.y = 0.0f;			 
	g_Camera.posVDest.z = pPlayer->pos.z - cosf(pPlayer->rot.z)*g_Camera.fDistance;
	g_Camera.posR.x += (g_Camera.posRDest.x - g_Camera.posR.x)* 0.1;
	g_Camera.posR.z += (g_Camera.posRDest.z - g_Camera.posR.z)* 0.1;
	g_Camera.posV.x += (g_Camera.posVDest.x - g_Camera.posV.x)* 0.1;
	g_Camera.posV.z += (g_Camera.posVDest.z - g_Camera.posV.z)* 0.1;

	////注視点の旋回
	//if (GetKeyboardPress(DIK_E) == true)
	//{
	//	//回転量
	//	g_Camera.rot.y += 0.1f;
	//	g_Camera.posR.x = g_Camera.posV.x + sinf(g_Camera.rot.y) * g_Camera.fDistance;
	//	g_Camera.posR.z = g_Camera.posV.z + cosf(g_Camera.rot.y) * g_Camera.fDistance;
	//	
	//}

	////注視点の旋回
	//if (GetKeyboardPress(DIK_Q) == true)
	//{
	//	//回転量
	//	g_Camera.rot.y -= 0.1f;
	//	g_Camera.posR.x = g_Camera.posV.x + sinf(g_Camera.rot.y) * g_Camera.fDistance;
	//	g_Camera.posR.z = g_Camera.posV.z + cosf(g_Camera.rot.y) * g_Camera.fDistance;

	//}

	////視点の旋回
	////if (GetKeyboardPress(DIK_C) == true)
	////{
	////	回転量
	////	g_Camera.rot.y += 0.1f;
	////	g_Camera.posV.x = g_Camera.posR.x - sinf(g_Camera.rot.y) * g_Camera.fDistance;
	////	g_Camera.posV.z = g_Camera.posR.z - cosf(g_Camera.rot.y) * g_Camera.fDistance;

	////}

	////視点の旋回
	////if (GetKeyboardPress(DIK_Z) == true)
	////{
	////	回転量
	////	g_Camera.rot.y -= 0.1f;
	////	g_Camera.posV.x = g_Camera.posR.x - sinf(g_Camera.rot.y) * g_Camera.fDistance;
	////	g_Camera.posV.z = g_Camera.posR.z - cosf(g_Camera.rot.y) * g_Camera.fDistance;

	////	
	////}

	//カメラリセット
	if (GetKeyboardPress(DIK_F4) == true)
	{
		g_Camera.posV = D3DXVECTOR3(0.0f, 20.0f, -80.0f);
		g_Camera.posR = D3DXVECTOR3(0.0f, 20.0f, 0.0f);
		g_Camera.vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		g_Camera.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}

	////カメラの移動(下)
	//if (GetKeyboardPress(DIK_S) == true)
	//{
	//	g_Camera.posV.x -= sinf(g_Camera.rot.y) * 1.0f;
	//	g_Camera.posV.z -= cosf(g_Camera.rot.y) * 1.0f;
	//	
	//	g_Camera.posR.x = g_Camera.posV.x + sinf(g_Camera.rot.y) * g_Camera.fDistance;
	//	g_Camera.posR.z = g_Camera.posV.z + cosf(g_Camera.rot.y) * g_Camera.fDistance;
	//}
	////カメラの移動(上)
	//if (GetKeyboardPress(DIK_W) == true)
	//{
	//	g_Camera.posV.x += sinf(g_Camera.rot.y) * 1.0f;
	//	g_Camera.posV.z += cosf(g_Camera.rot.y) * 1.0f;
	//
	//	g_Camera.posR.x = g_Camera.posV.x + sinf(g_Camera.rot.y) * g_Camera.fDistance;
	//	g_Camera.posR.z = g_Camera.posV.z + cosf(g_Camera.rot.y) * g_Camera.fDistance;
	//}
	////カメラの移動(左)
	//if (GetKeyboardPress(DIK_A) == true)
	//{
	//	g_Camera.posV.x -= sinf(D3DX_PI / 2.0f + g_Camera.rot.y) * 1.0f;
	//	g_Camera.posV.z -= cosf(D3DX_PI / 2.0f + g_Camera.rot.y) * 1.0f;

	//	g_Camera.posR.x = g_Camera.posV.x + sinf(g_Camera.rot.y) * g_Camera.fDistance;
	//	g_Camera.posR.z = g_Camera.posV.z + cosf(g_Camera.rot.y) * g_Camera.fDistance;
	//}
	////カメラの移動(右)
	//if (GetKeyboardPress(DIK_D) == true)
	//{
	//	g_Camera.posV.x += sinf(D3DX_PI / 2.0f + g_Camera.rot.y) * 1.0f;
	//	g_Camera.posV.z += cosf(D3DX_PI / 2.0f + g_Camera.rot.y) * 1.0f;

	//	g_Camera.posR.x = g_Camera.posV.x + sinf(g_Camera.rot.y) * g_Camera.fDistance;
	//	g_Camera.posR.z = g_Camera.posV.z + cosf(g_Camera.rot.y) * g_Camera.fDistance;
	//}


	//角度の正規化
	if (g_Camera.rot.y < D3DX_PI / 2)
	{
		g_Camera.rot.y - D3DX_PI;
	}
	if (g_Camera.rot.y > -D3DX_PI / 2)
	{
		g_Camera.rot.y + D3DX_PI;
	}
}

//カメラの設定処理
void SetCamera(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//デバイスのポインタ		

	//ビューマトリックスの初期化
	D3DXMatrixIdentity(&g_Camera.mtxView);

	//ビューマトリックスの作成
	D3DXMatrixLookAtLH(&g_Camera.mtxView,&g_Camera.posV,&g_Camera.posR,&g_Camera.vecU);

	//ビューマトリックスの設定
	pDevice->SetTransform(D3DTS_VIEW, &g_Camera.mtxView);

	//プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&g_Camera.mtxProjection);

	//プロジェクションマトリックスの作成
	D3DXMatrixPerspectiveFovLH(&g_Camera.mtxProjection,D3DXToRadian(60.0f)
	,(float)SCREEN_WIDTH/(float)SCREEN_HEIGHT,1.0f,1000.0f);

	//プロジェクションマトリックスの設定
	pDevice->SetTransform(D3DTS_PROJECTION, &g_Camera.mtxProjection);
}

//カメラの取得
Camera * GetCamera(void)
{
	Camera *pCamera = &g_Camera;

	//返り値
	return pCamera;
}