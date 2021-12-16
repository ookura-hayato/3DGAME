//==================================
//制作基礎 3D(input.h)
//	Author:　大倉隼翔
//==================================
#pragma once
#ifndef _INPUT_H_			//このマクロ定義がされなかったら
#define _INPUT_H_			//2重インクルード防止のマクロ定義
#include"main.h"

//プロトタイプ宣言
HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd);
void UninitKeyboard(void);
void UpdateKeyboard(void);
bool GetKeyboardPress(int nKey);
bool GetKeyboardTrigger(int nKey);
#endif