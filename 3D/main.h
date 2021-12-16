//==================================
//制作基礎 3D(main.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _MAIN_H_						//このマクロ定義がされなかったら
#define _MAIN_H_						//二重インクルード防止のマクロ定義
#include<windows.h>
#include"d3dx9.h"						//描画に必要
#define	 DIRECTINPUT_VERSION (0x0800)	//ビルド時の警告対策用マクロ
#include "dinput.h"						//入力処理に必要
#include "xaudio2.h"
#include "poligon.h"
#include "camera.h"
#include "light.h"
#include "model.h"
#include "input.h"
#include "shadow.h"
#include "wall.h"
#include "billboard.h"
#include "meshfeild.h"
#include "effect.h"
#include"bullet.h"
#include"explosion.h"
#include "player.h"

//#include"title.h"
//#include "game.h"
//#include "result.h"
//#include "sound.h"
//#include"tutorial.h"


//ライブラリのリンク
#pragma comment(lib,"d3d9.lib")			//描画に必要
#pragma comment(lib,"d3dx9.lib")		//d3d9.libの拡張ライブラリ
#pragma comment(lib,"dxguid.lib")		//DirectXコンポーネントに使用
#pragma comment(lib,"winmm.lib")		//システム時刻取得に必要
#pragma comment(lib,"dinput8.lib")		//入力処理に必要

//マクロ定義
#define CLASS_NAME		"WindowClass"				//ウィンドウクラスの名前
#define WINDOW_NAME		"DirectXの基本処理"			//ウィンドウの名前(キャプションに表示)
#define SCREEN_WIDTH (1280)							//ウィンドウの幅
#define SCREEN_HEIGHT (720)							//ウィンドウの高さ
//#define FVF_VERTEX_2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)
#define FVF_VERTEX_3D (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_DIFFUSE|D3DFVF_TEX1)

//// 頂点情報[2D]の構造体を定義
//typedef struct
//{
//	D3DXVECTOR3 pos;		//頂点座標
//	float rhw;				//座標変換用係数（1.0fで固定）
//	D3DCOLOR col;			//頂点カラー
//	D3DXVECTOR2 tex;		//テクスチャ座標
//}VERTEX_2D;

// 頂点情報[3D]の構造体を定義
typedef struct
{
	D3DXVECTOR3 pos;		//頂点座標
	D3DXVECTOR3 nor;		//法線ベクトル
	D3DCOLOR col;			//頂点カラー
	D3DXVECTOR2 tex;		//テクスチャ座標
}VERTEX_3D;

////画面（モード）の種類
//typedef enum
//{
//	MODE_TITLE = 0,		//タイトル画面
//	MODE_TUTORIAL,		//チュートリアル画面
//	MODE_GAME,			//ゲーム画面
//	MODE_RESULT,		//リザルト画面
//	MODE_MAX
//}MODE;

//プロトタイプ宣言
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
void Uninit(void);
void Update(void);
void Draw(void);
LPDIRECT3DDEVICE9 GetDevice(void);
//void SetMode(MODE mode);
//MODE GetMode(void);
#endif
