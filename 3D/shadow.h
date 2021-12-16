//==================================
//�����b 3D(shadow.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _SHADOW_H_			//���̃}�N����`������Ȃ�������
#define _SHADOW_H_			//2�d�C���N���[�h�h�~�̃}�N����`

//�C���N���[�h�t�@�C��
#include "main.h"

// �\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;	
	D3DXVECTOR3 rot;
	D3DXMATRIX mtxWorld;							
	bool bUse;
}Shadow;

//�}�N����`
#define MAX_SHADOW		(100)				//�G�̍ő吔

//�v���g�^�C�v�錾
void InitShadow(void);
void UninitShadow(void);
void UpdateShadow(void);
void DrawShadow(void);
int SetShadow(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
void SetPositionShadow(int nIndxShadow, D3DXVECTOR3 pos);

#endif