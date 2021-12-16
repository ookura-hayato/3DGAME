#pragma once
#ifndef _BULLET_H_			//���̃}�N����`������Ȃ�������
#define _BULLET_H_			//2�d�C���N���[�h�h�~�̃}�N����`
#include"main.h"

//�}�N����`
#define MAX_BULLET		(300)					//�e�̍ő吔
#define COLOERBULLET	(D3DXCOLOR(1.0f,1.0f,1.0f,1.0f))

// �e�̍\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXMATRIX mtxWorld;
	D3DXVECTOR3 move;		//�ړ���
	int nLife;				//����
	bool bUse;				//�g�p���Ă��邩�ǂ���
}Bullet;

//�v���g�^�C�v�錾
void InitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);
void SetBullet(D3DXVECTOR3 pos,D3DXVECTOR3 move);
#endif
