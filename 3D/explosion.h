//==================================
//�����b 3D(poligon.cpp)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _EXPLOSION_H_			//���̃}�N����`������Ȃ�������
#define _EXPLOSION_H_			//2�d�C���N���[�h�h�~�̃}�N����`
#include"main.h"
//�}�N����`
#define MAX_EXPLOSION		(128)					//�����̍ő吔

// �����̍\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXMATRIX mtxWorld;
	D3DXVECTOR3 move;		//�ړ���
	int nCounterAnim;		//�A�j���[�V�����J�E���^�[
	int nPatternAnim;		//�A�j���[�V�����p�^�[��No.
	bool bUse;				//�g�p���Ă��邩�ǂ���
}Explosion;

//�v���g�^�C�v�錾
void InitExplosion(void);
void UninitExplosion(void);
void UpdateExplosion(void);
void DrawExplosion(void);
void SetExplosion(D3DXVECTOR3 pos, D3DXCOLOR col,float size);
#endif
