//==================================
//制作基礎 3D(main.cpp)
//	Author:　大倉隼翔
//==================================
#include"main.h"

//プロトタイプ宣言
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//グローバル変数
LPDIRECT3D9			g_pD3D = NULL;
LPDIRECT3DDEVICE9   g_pD3DDevice = NULL;
VERTEX_3D			g_aVertex[4];
LPDIRECT3DTEXTURE9  g_pTexturePolygon = NULL;
//MODE g_mode = MODE_TITLE;

//=================
//メイン関数
//=================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hInstancePrev, LPSTR lCmdLine, int nCmdShow)
{
	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WindowProc,
		0,
		0,
		hInstance,
		LoadIcon(NULL,IDI_APPLICATION),
		LoadCursor(NULL,IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		CLASS_NAME,
		LoadIcon(NULL,IDI_APPLICATION)
	};
	HWND hWnd;					//ウィンドウハンドル
	MSG msg;					//メッセージを格納			

	//ウィンドウクラスの登録
	RegisterClassEx(&wcex);

	//クライアント領域を指定のサイズに調整
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	//ウィンドウを生成
	hWnd = CreateWindowEx
	(
		0,
		CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(rect.right - rect.left),		
		(rect.bottom - rect.top),				
		NULL,
		NULL,
		hInstance,
		NULL);						//ウィンドウ作成データ

	//分解能を設定
	DWORD dwCurrentTime;			//現在時刻
	DWORD dwExecLastTime;			//最後に処理した時刻

//初期化処理
	if (FAILED(Init(hInstance, hWnd, TRUE)))
	{//初期化が失敗した場合
		return -1;
	}

//ウィンドウの表示
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	timeBeginPeriod(1);
	dwCurrentTime = 0;			//初期化する
	dwExecLastTime = timeGetTime();		//現在時刻を取得
	//メッセージループ
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{//ウインドウの処理
			if (msg.message == WM_QUIT)
			{//WM_QUITメッセージを受け取ったらメッセージループを抜ける
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{//DirectXの処理
			dwCurrentTime = timeGetTime();		//現在時刻を取得
			if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))
			{//60分の1秒経過
				dwExecLastTime = dwCurrentTime;		//処理開始の時刻[現在時刻]を保存
			}

			//更新処理
				Update();

				//描画処理
				Draw();
		}
	}
	//終了処理
	Uninit();
	//分解能を戻す
	timeEndPeriod(1);

	//ウインドウクラスの登録を解除
	UnregisterClass(CLASS_NAME, wcex.hInstance);
	return(int)msg.wParam;
}

//ウインドウプロシージャ
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nID;						//返り値を格納
	
	const RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };	//ウインドウの領域

	switch (uMsg)
	{

	case WM_DESTROY:			
		PostQuitMessage(0);
		break;

	case WM_CLOSE:		//閉じるボタン押下のメッセージ
		//nID = MessageBox(hWnd, "終了しますか？", "終了メッセージ", MB_YESNO|MB_TOPMOST);
		//if (nID == IDYES)
		//{
			//ウインドウを破棄する
			DestroyWindow(hWnd);
		//}
		//else
		//{
			return 0;	//0を返さないと終了してしまう
		//}
		break;

	case WM_LBUTTONDOWN:		//マウス左クリックのメッセージ
								//ウインドウにフォーカスを合わせる
		SetFocus(hWnd);
		break;

	case WM_KEYDOWN: //キー押下のメッセージ
		switch (wParam)
		{
		case VK_ESCAPE:		//ESCキーが押された時
			/*nID = MessageBox(hWnd, "終了しますか？", "終了メッセージ", MB_YESNO);
			if (nID == IDYES)
			{*/
				//ウインドウを破棄する(WM_DESTROYメッセージを送る)
				DestroyWindow(hWnd);
			/*}*/
			break;
		}
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);		//既定の処理を返す
}

//初期化処理
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	D3DDISPLAYMODE d3ddm;			//ディスプレイモード
	D3DPRESENT_PARAMETERS d3dpp;	//プレゼンテーションパラメーター

	//Direct3Dオブジェクトの生成
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (g_pD3D == NULL)
	{
		return E_FAIL;
	}

	//現在のディスプレイモードを取得
	if (FAILED(g_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return E_FAIL;
	}

	//デバイスのプレゼンテーションパラメータの設定
	ZeroMemory(&d3dpp, sizeof(d3dpp));								//パラメータのゼロクリア
	d3dpp.BackBufferWidth = SCREEN_WIDTH;							//ゲーム画面サイズ(幅)
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;							//ゲーム画面サイズ(高さ)
	d3dpp.BackBufferFormat = d3ddm.Format;							//バックバッファの形式
	d3dpp.BackBufferCount = 1;										//バックバッファの形式
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;						//バックバッファの数
	d3dpp.EnableAutoDepthStencil = TRUE;							//デプスバッファの切り替え(映像信号に同期)
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;						//デプスバッファとして16bitを使う
	d3dpp.Windowed = bWindow;										//ウインドウモード
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;		//フレッシュレート
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;		//インターバル

	//Direct3Dデバイスの生成(描画処理と頂点処理をハードウェアで行う)
	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&g_pD3DDevice)))
	{
		//Direct3Dデバイスの生成(描画処理はハードウェア、頂点処理はCPUで行う)
		if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp,
			&g_pD3DDevice)))
		{
			//Direct3Dデバイスの生成(描画処理と頂点処理をCPUで行う)
			if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL,
				hWnd,
				D3DCREATE_SOFTWARE_VERTEXPROCESSING,
				&d3dpp,
				&g_pD3DDevice)))
			{
				return E_FAIL;
			}
		}
	}

	//レンダステートの設定
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);


	//テクスチャステージステートパラメータの設定
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);

	////ワイヤーフレームモードの設定
	//g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	////元に戻す
	//g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);

	//キーボード初期化処理
	if (FAILED(InitKeyboard(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	//カメラの初期化処理
	InitCamera();

	//影初期化処理
	InitShadow();

	//ビルボード初期化処理
	InitBillboard();

	//メッシュフィールド初期化処理
	InitMeshfeild();

	//ライトの初期化処理
	InitLight();

	//プレイヤー初期化処理
	InitPlayer();

	//モデル初期化処理
	InitModel();

	//壁初期化処理
	InitWall();

	//エフェクト初期化処理
	InitEffect();

	//爆発の初期化処理
	InitExplosion();

	//弾の初期化処理
	InitBullet();

	////サウンド初期化処理
	//InitSound(hWnd);

	////モードの設定
	//SetMode(g_mode);

	//各種オブジェクトの初期化処理
	return S_OK;
}

//終了処理
void Uninit(void)
{

	//カメラの終了処理
	UninitCamera();

	//ビルボード終了処理
	UninitBillboard();

	//影終了処理
	UninitShadow();

	//メッシュフィールド終了処理
	UninitMeshfeild();

	//ライトの終了処理
	UninitLight();

	//プレイヤー終了処理
	UninitPlayer();

	//モデル終了処理
	UninitModel();

	//キーボード終了処理
	UninitKeyboard();

	//壁終了処理
	UninitWall();

	//壁終了処理
	UninitEffect();

	//爆発の終了処理
	UninitExplosion();

	//弾の終了処理
	UninitBullet();

	////サウンドの終了設定
	//UninitSound();

	if (g_pD3DDevice != NULL)
	{
		g_pD3DDevice->Release();
		g_pD3DDevice = NULL;
	}

	//Direct3Dオブジェクト
	if (g_pD3D != NULL)
	{
		g_pD3D->Release();
		g_pD3D = NULL;
	}

	//分解能を戻す
	timeEndPeriod(1);
	
}

//更新処理
void Update(void)
{

	//カメラの更新処理
	UpdateCamera();

	//影更新処理
	UpdateShadow();

	//ビルボード更新処理
	UpdateBillboard();

	//メッシュフィールド更新処理
	UpdateMeshfeild();

	//ライトの更新処理
	UpdateLight();

	//プレイヤー更新処理
	UpdatePlayer();

	//モデル更新処理
	UpdateModel();

	//キーボード更新処理
	UpdateKeyboard();

	//壁更新処理
	UpdateWall();

	//壁更新処理
	UpdateEffect();

	//爆発の更新処理
	UpdateExplosion();

	//弾の更新処理
	UpdateBullet();

	//switch (g_mode)
	//{
	//case MODE_TITLE:					//タイトル画面
	//	UpdateTitle();
	//	break;

	//case MODE_TUTORIAL:				//チュートリアル画面
	//	UpdateTutorial();
	//	break;

	//case MODE_GAME:					//ゲーム画面
	//	UpdateGame();
	//	break;

	//case MODE_RESULT:					//リザルト処理
	//	UpdateResult();
	//	break;
	//}
}

//描画処理
void Draw(void)
{
	

	//画面クリア
	g_pD3DDevice->Clear(0, NULL,
		(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);

	//描画の開始
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{//成功したとき

		//カメラの設定処理
		SetCamera();

		//壁描画処理
		DrawWall();

		//エフェクト描画処理
		DrawEffect();

		//メッシュフィールド描画処理
		DrawMeshfeild();

		//影描画処理
		DrawShadow();

		//プレイヤー描画処理
		DrawPlayer();

		//モデル描画処理
		DrawModel();

		//ビルボード描画処理
		DrawBillboard();

		//switch (g_mode)
		//{
		//case MODE_TITLE:					//タイトル画面
		//	DrawTitle();
		//	break;

		//case MODE_TUTORIAL:					//チュートリアル画面
		//	DrawTutorial();
		//	break;

		//case MODE_GAME:						//ゲーム画面
		//	DrawGame();
		//	break;

		//case MODE_RESULT:					//リザルト処理
		//	DrawResult();
		//	break;
		//}

		//描画終了
		g_pD3DDevice->EndScene();
	}
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
//デバイスの取得
LPDIRECT3DDEVICE9 GetDevice(void)
{
	return g_pD3DDevice;
}

////モードの設定
//void SetMode(MODE mode)
//{
//	//現在の画面の終了処理
//	switch (g_mode)
//	{
//	case MODE_TITLE:				//タイトル画面
//		UninitTitle();
//		break;
//
//	case MODE_TUTORIAL:				//チュートリアル画面
//		UninitTutorial();
//		break;
//
//	case MODE_GAME:					//ゲーム画面
//		UninitGame();
//		break;
//
//	case MODE_RESULT:				//リザルト処理
//		UninitResult();
//		break;
//	}
//
//	//新しい画面の初期化処理
//	switch (mode)
//	{
//	case MODE_TITLE:				//タイトル画面
//		InitTitle();
//		break;
//
//	case MODE_TUTORIAL:				//チュートリアル画面
//		InitTutorial();
//		break;
//
//	case MODE_GAME:					//ゲーム画面
//		InitGame();
//		break;
//
//	case MODE_RESULT:				//リザルト処理
//		InitResult();
//		break;
//	}
//
//	g_mode = mode;	//現在の画面を切り替える
//}
//
////モードの取得
//MODE GetMode(void)
//{
//	return g_mode;
//}