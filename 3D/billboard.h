//==================================
//�����b 3D(billboard.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _BILLBOARD_H_			//���̃}�N����`������Ȃ�������
#define _BILLBOARD_H_			//2�d�C���N���[�h�h�~�̃}�N����`

//�C���N���[�h�t�@�C��
#include "main.h"

// �\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXMATRIX mtxWorld;
	bool bUse;
}Billboard;

//�}�N����`
#define MAX_BILLBOARD		(10)				//�G�̍ő吔

//�v���g�^�C�v�錾
void InitBillboard(void);
void UninitBillboard(void);
void UpdateBillboard(void);
void DrawBillboard(void);
void SetBillboard(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
#endif