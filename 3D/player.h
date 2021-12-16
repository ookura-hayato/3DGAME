//==================================
//�����b 3D(player.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _PLAYER_H_			//���̃}�N����`������Ȃ�������
#define _PLAYER_H_			//2�d�C���N���[�h�h�~�̃}�N����`

//�C���N���[�h�t�@�C��
#include "main.h"

// �\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;				//�ʒu
	D3DXVECTOR3 posold;				//�O��̈ʒu
	D3DXVECTOR3 rot;				//����
}Player;

//�v���g�^�C�v�錾
void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);                  
Player * GetPlayer(void);
#endif