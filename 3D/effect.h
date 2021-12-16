//==================================
//�����b 3D(effect.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _EFFECT_H_			//���̃}�N����`������Ȃ�������
#define _EFFECT_H_			//2�d�C���N���[�h�h�~�̃}�N����`

//�C���N���[�h�t�@�C��
#include "main.h"

// �\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	float fWidth;			//��
	float fHeight;			//����
	D3DXMATRIX mtxWorld;
	bool bUse;				//�g�p���Ă��邩�ǂ���
}Effect;

//�}�N����`
#define MAX_EFFECT		(900)				//�G�̍ő吔

//�v���g�^�C�v�錾
void InitEffect(void);
void UninitEffect(void);
void UpdateEffect(void);
void DrawEffect(void);
void SetEffect(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
//Effect * GetEffect(void);
#endif
