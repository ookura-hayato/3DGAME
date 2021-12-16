//==================================
//�����b 3D(light.cpp)
//	Author:�@��q����
//==================================
#include "light.h"

//�O���[�o���ϐ�
D3DLIGHT9 g_Light[MAX_LIGHT];									//���C�g���

//���C�g�̏���������
void InitLight(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//�f�o�C�X�̃|�C���^		
	D3DXVECTOR3 vecDir;								//���C�g�̕����x�N�g��
	
	
	//���C�g���N���A����
	ZeroMemory(&g_Light, sizeof(g_Light));

	//���C�g�̎�ނ�ݒ�
	g_Light[0].Type = D3DLIGHT_DIRECTIONAL;

	//���C�g�̊g�U����ݒ�
	g_Light[0].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	
	//���C�g�̕�����ݒ�
	vecDir = D3DXVECTOR3(0.2f, -0.8f, -0.4f);
	

	//���K������
	D3DXVec3Normalize(&vecDir, &vecDir);
	g_Light[0].Direction = vecDir;

	//���C�g��ݒ肷��
	pDevice->SetLight(0, &g_Light[0]);

	//���C�g��L���ɂ���
	pDevice->LightEnable(0, TRUE);

	//���C�g�̎�ނ�ݒ�
	g_Light[1].Type = D3DLIGHT_DIRECTIONAL;

	//���C�g�̊g�U����ݒ�
	g_Light[1].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//���C�g�̕�����ݒ�
	vecDir = D3DXVECTOR3(1.2f, -1.8f, 2.4f);

	//���K������
	D3DXVec3Normalize(&vecDir, &vecDir);
	g_Light[1].Direction = vecDir;

	//���C�g��ݒ肷��
	pDevice->SetLight(0, &g_Light[1]);

	//���C�g��L���ɂ���
	pDevice->LightEnable(0, TRUE);

	//���C�g�̎�ނ�ݒ�
	g_Light[2].Type = D3DLIGHT_DIRECTIONAL;

	//���C�g�̊g�U����ݒ�
	g_Light[2].Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//���C�g�̕�����ݒ�
	vecDir = D3DXVECTOR3(0.0f, -1.0f, 2.0f);

	//���K������
	D3DXVec3Normalize(&vecDir, &vecDir);
	g_Light[2].Direction = vecDir;

	//���C�g��ݒ肷��
	pDevice->SetLight(0, &g_Light[2]);

	//���C�g��L���ɂ���
	pDevice->LightEnable(0, TRUE);
}

//���C�g�̏I������
void UninitLight(void)
{

}

//���C�g�̍X�V����
void UpdateLight(void)
{

}