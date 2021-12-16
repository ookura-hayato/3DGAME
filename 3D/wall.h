//==================================
//�����b 3D(wall.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _WALL_H_			//���̃}�N����`������Ȃ�������
#define _WALL_H_			//2�d�C���N���[�h�h�~�̃}�N����`

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
}Wall;

//�}�N����`
#define MAX_WALL		(8)				//�G�̍ő吔

//�v���g�^�C�v�錾
void InitWall(void);
void UninitWall(void);
void UpdateWall(void);
void DrawWall(void);
void SetWall(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
Wall* GetWall(void);
#endif