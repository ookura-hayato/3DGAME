//==================================
//�����b 3D(model.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _MODEL_H_			//���̃}�N����`������Ȃ�������
#define _MODEL_H_			//2�d�C���N���[�h�h�~�̃}�N����`

//�C���N���[�h�t�@�C��
#include "main.h"

// �\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	float fWidth;
	float fHeight;
	bool bUse;
}Model;

//�}�N����`
#define MAX_MODEL		(100)				//�G�̍ő吔

//�v���g�^�C�v�錾
void InitModel(void);
void UninitModel(void);
void UpdateModel(void);
void DrawModel(void);
bool CollisionModel(D3DXVECTOR3*pPos,
	D3DXVECTOR3*pPosOld,
	D3DXVECTOR3*pMove,
	float fWidith,
	float fHeight);
#endif