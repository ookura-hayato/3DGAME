//==================================
//�����b :3D(camera.cpp)
//	Author:�@��q����
//==================================
#include "camera.h"

//�O���[�o���ϐ�
Camera g_Camera;	//�J�������

//�J�����̏���������
void InitCamera(void)
{
	//���_�E�����_�E�������ݒ肷��
	g_Camera.posV = D3DXVECTOR3(0.0f, 20.0f, -80.0f);
	g_Camera.posR = D3DXVECTOR3(0.0f, 20.0f, 0.0f);
	g_Camera.vecU = D3DXVECTOR3(0.0f,1.0f,0.0f);
	g_Camera.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	g_Camera.fDistance = sqrtf((g_Camera.posR.z - g_Camera.posV.z) * (g_Camera.posR.z - g_Camera.posV.z) + (g_Camera.posR.x - g_Camera.posV.x) * (g_Camera.posR.x - g_Camera.posV.x));
}

//�J�����̏I������
void UninitCamera(void)
{

}

//�J�����̍X�V����
void UpdateCamera(void)
{
	Player *pPlayer = GetPlayer();

	g_Camera.posRDest.x = pPlayer->pos.x + sinf(pPlayer->rot.x)*pPlayer->pos.x;
	g_Camera.posRDest.y = 0.0f;
	g_Camera.posRDest.z = pPlayer->pos.z + cosf(pPlayer->rot.x)*pPlayer->pos.x;
	g_Camera.posVDest.x = pPlayer->pos.x - sinf(pPlayer->rot.z)*g_Camera.fDistance;
	g_Camera.posVDest.y = 0.0f;			 
	g_Camera.posVDest.z = pPlayer->pos.z - cosf(pPlayer->rot.z)*g_Camera.fDistance;
	g_Camera.posR.x += (g_Camera.posRDest.x - g_Camera.posR.x)* 0.1;
	g_Camera.posR.z += (g_Camera.posRDest.z - g_Camera.posR.z)* 0.1;
	g_Camera.posV.x += (g_Camera.posVDest.x - g_Camera.posV.x)* 0.1;
	g_Camera.posV.z += (g_Camera.posVDest.z - g_Camera.posV.z)* 0.1;

	////�����_�̐���
	//if (GetKeyboardPress(DIK_E) == true)
	//{
	//	//��]��
	//	g_Camera.rot.y += 0.1f;
	//	g_Camera.posR.x = g_Camera.posV.x + sinf(g_Camera.rot.y) * g_Camera.fDistance;
	//	g_Camera.posR.z = g_Camera.posV.z + cosf(g_Camera.rot.y) * g_Camera.fDistance;
	//	
	//}

	////�����_�̐���
	//if (GetKeyboardPress(DIK_Q) == true)
	//{
	//	//��]��
	//	g_Camera.rot.y -= 0.1f;
	//	g_Camera.posR.x = g_Camera.posV.x + sinf(g_Camera.rot.y) * g_Camera.fDistance;
	//	g_Camera.posR.z = g_Camera.posV.z + cosf(g_Camera.rot.y) * g_Camera.fDistance;

	//}

	////���_�̐���
	////if (GetKeyboardPress(DIK_C) == true)
	////{
	////	��]��
	////	g_Camera.rot.y += 0.1f;
	////	g_Camera.posV.x = g_Camera.posR.x - sinf(g_Camera.rot.y) * g_Camera.fDistance;
	////	g_Camera.posV.z = g_Camera.posR.z - cosf(g_Camera.rot.y) * g_Camera.fDistance;

	////}

	////���_�̐���
	////if (GetKeyboardPress(DIK_Z) == true)
	////{
	////	��]��
	////	g_Camera.rot.y -= 0.1f;
	////	g_Camera.posV.x = g_Camera.posR.x - sinf(g_Camera.rot.y) * g_Camera.fDistance;
	////	g_Camera.posV.z = g_Camera.posR.z - cosf(g_Camera.rot.y) * g_Camera.fDistance;

	////	
	////}

	//�J�������Z�b�g
	if (GetKeyboardPress(DIK_F4) == true)
	{
		g_Camera.posV = D3DXVECTOR3(0.0f, 20.0f, -80.0f);
		g_Camera.posR = D3DXVECTOR3(0.0f, 20.0f, 0.0f);
		g_Camera.vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		g_Camera.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}

	////�J�����̈ړ�(��)
	//if (GetKeyboardPress(DIK_S) == true)
	//{
	//	g_Camera.posV.x -= sinf(g_Camera.rot.y) * 1.0f;
	//	g_Camera.posV.z -= cosf(g_Camera.rot.y) * 1.0f;
	//	
	//	g_Camera.posR.x = g_Camera.posV.x + sinf(g_Camera.rot.y) * g_Camera.fDistance;
	//	g_Camera.posR.z = g_Camera.posV.z + cosf(g_Camera.rot.y) * g_Camera.fDistance;
	//}
	////�J�����̈ړ�(��)
	//if (GetKeyboardPress(DIK_W) == true)
	//{
	//	g_Camera.posV.x += sinf(g_Camera.rot.y) * 1.0f;
	//	g_Camera.posV.z += cosf(g_Camera.rot.y) * 1.0f;
	//
	//	g_Camera.posR.x = g_Camera.posV.x + sinf(g_Camera.rot.y) * g_Camera.fDistance;
	//	g_Camera.posR.z = g_Camera.posV.z + cosf(g_Camera.rot.y) * g_Camera.fDistance;
	//}
	////�J�����̈ړ�(��)
	//if (GetKeyboardPress(DIK_A) == true)
	//{
	//	g_Camera.posV.x -= sinf(D3DX_PI / 2.0f + g_Camera.rot.y) * 1.0f;
	//	g_Camera.posV.z -= cosf(D3DX_PI / 2.0f + g_Camera.rot.y) * 1.0f;

	//	g_Camera.posR.x = g_Camera.posV.x + sinf(g_Camera.rot.y) * g_Camera.fDistance;
	//	g_Camera.posR.z = g_Camera.posV.z + cosf(g_Camera.rot.y) * g_Camera.fDistance;
	//}
	////�J�����̈ړ�(�E)
	//if (GetKeyboardPress(DIK_D) == true)
	//{
	//	g_Camera.posV.x += sinf(D3DX_PI / 2.0f + g_Camera.rot.y) * 1.0f;
	//	g_Camera.posV.z += cosf(D3DX_PI / 2.0f + g_Camera.rot.y) * 1.0f;

	//	g_Camera.posR.x = g_Camera.posV.x + sinf(g_Camera.rot.y) * g_Camera.fDistance;
	//	g_Camera.posR.z = g_Camera.posV.z + cosf(g_Camera.rot.y) * g_Camera.fDistance;
	//}


	//�p�x�̐��K��
	if (g_Camera.rot.y < D3DX_PI / 2)
	{
		g_Camera.rot.y - D3DX_PI;
	}
	if (g_Camera.rot.y > -D3DX_PI / 2)
	{
		g_Camera.rot.y + D3DX_PI;
	}
}

//�J�����̐ݒ菈��
void SetCamera(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//�f�o�C�X�̃|�C���^		

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_Camera.mtxView);

	//�r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&g_Camera.mtxView,&g_Camera.posV,&g_Camera.posR,&g_Camera.vecU);

	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &g_Camera.mtxView);

	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_Camera.mtxProjection);

	//�v���W�F�N�V�����}�g���b�N�X�̍쐬
	D3DXMatrixPerspectiveFovLH(&g_Camera.mtxProjection,D3DXToRadian(60.0f)
	,(float)SCREEN_WIDTH/(float)SCREEN_HEIGHT,1.0f,1000.0f);

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &g_Camera.mtxProjection);
}

//�J�����̎擾
Camera * GetCamera(void)
{
	Camera *pCamera = &g_Camera;

	//�Ԃ�l
	return pCamera;
}