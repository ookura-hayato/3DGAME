//==================================
//�����b 3D(input.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _INPUT_H_			//���̃}�N����`������Ȃ�������
#define _INPUT_H_			//2�d�C���N���[�h�h�~�̃}�N����`
#include"main.h"

//�v���g�^�C�v�錾
HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd);
void UninitKeyboard(void);
void UpdateKeyboard(void);
bool GetKeyboardPress(int nKey);
bool GetKeyboardTrigger(int nKey);
#endif