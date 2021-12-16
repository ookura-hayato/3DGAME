//==================================
//�����b 3D(camera.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _CAMERA_H_			//���̃}�N����`������Ȃ�������
#define _CAMERA_H_			//2�d�C���N���[�h�h�~�̃}�N����`

#include "main.h"

// �\���̂��`
typedef struct
{
	D3DXVECTOR3 posV;				//���݂̎��_
	D3DXVECTOR3 posR;				//���݂̒����_
	D3DXVECTOR3 posVDest;			//�ړI�̎��_
	D3DXVECTOR3 posRDest;			//�ړI�̒����_
	D3DXVECTOR3 vecU;				//������x�N�g��
	D3DXMATRIX mtxProjection;		//�v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX mtxView;				//�r���[�}�g���b�N�X
	D3DXVECTOR3 rot;				//����
	float fDistance;				//���_���璍���_�̋���
	float fDistanceDest;			//�ړI�̎��_����ړI�̒����_�̋���
}Camera;

//�v���g�^�C�v�錾
void InitCamera(void);
void UninitCamera(void);
void UpdateCamera(void);
void SetCamera(void);
Camera * GetCamera(void);
#endif
