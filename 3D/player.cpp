//==================================
//�����b 3D(player.cpp)
//	Author:�@��q����
//==================================
#include "player.h"

//�O���[�o���ϐ�
LPD3DXMESH g_pMeshPlayer = NULL;			//���b�V�����ւ̃|�C���^
LPD3DXBUFFER g_pBuffMatPlayer = NULL;	//�}�e���A�����ւ̃|�C���^
DWORD g_nNumMatPlayer = 0;			//�}�e���A�����̐�
Player g_aPlayer;
D3DXMATRIX g_mtxWorldPlayer;			//���[���h�}�g���b�N�X
int g_rotDestPlayer;					//�ړI�̊p�x
int g_nIndxShadow;

//�v���C���[����������
void InitPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�̃|�C���^
									//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//X�t�@�C���ǂݍ���
	D3DXLoadMeshFromX("data/MODEL/pengin.x", D3DXMESH_SYSTEMMEM, pDevice, NULL,
		&g_pBuffMatPlayer, NULL, &g_nNumMatPlayer, &g_pMeshPlayer);
	g_aPlayer.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//�ʒu�̏����ݒ�
	g_aPlayer.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//�����̏����ݒ�
	g_nIndxShadow = SetShadow(D3DXVECTOR3(g_aPlayer.pos.x, 0.1f, g_aPlayer.pos.z), g_aPlayer.rot);
}

//�v���C���[�I������
void UninitPlayer(void)
{
	//���b�V���̔j��
	if (g_pMeshPlayer != NULL)
	{
		g_pMeshPlayer->Release();
		g_pMeshPlayer = NULL;
	}

	//�}�e���A���̔j��
	if (g_pBuffMatPlayer != NULL)
	{
		g_pBuffMatPlayer->Release();
		g_pBuffMatPlayer = NULL;
	}
}

//�v���C���[�X�V����
void UpdatePlayer(void)
{
	Camera *pCamera = GetCamera();

	if (GetKeyboardPress(DIK_UP) == true)
	{
		g_aPlayer.pos.x += sinf(0.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.pos.z += cosf(0.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.rot.y = D3DX_PI + pCamera->rot.y;
	}

	if (GetKeyboardPress(DIK_DOWN) == true)
	{
		g_aPlayer.pos.x -= sinf(0.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.pos.z -= cosf(0.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.rot.y = pCamera->rot.y;
	}

	if (GetKeyboardPress(DIK_RIGHT) == true)
	{
		g_aPlayer.pos.x += sinf(D3DX_PI / 2.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.pos.z += cosf(D3DX_PI / 2.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.rot.y = -D3DX_PI / 2.0f + pCamera->rot.y;
	}

	if (GetKeyboardPress(DIK_LEFT) == true)
	{
		g_aPlayer.pos.x -= sinf(D3DX_PI / 2.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.pos.z -= cosf(D3DX_PI / 2.0f + pCamera->rot.y) * 1.0f;
		g_aPlayer.rot.y = D3DX_PI / 2.0f + pCamera->rot.y;
	}

	//�v���C���[���Z�b�g
	if (GetKeyboardPress(DIK_F5) == true)
	{
		g_aPlayer.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aPlayer.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}
	SetPositionShadow(g_nIndxShadow, D3DXVECTOR3(g_aPlayer.pos.x, 0.1f, g_aPlayer.pos.z));

	//CollisionModel(&g_aPlayer.pos, &g_aPlayer.posold, g_aPlayer.rot, g_aPlayer.pos.z);
}

//�v���C���[�`�揈��
void DrawPlayer(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�̃|�C���^			

									//�f�o�C�X�̎擾
	pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;			//���݂̃}�e���A���ۑ��p
	D3DXMATERIAL * pMat;			//�}�e���A���f�[�^�ւ̃|�C���^

									//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_mtxWorldPlayer);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_aPlayer.rot.y, g_aPlayer.rot.x, g_aPlayer.rot.z);
	D3DXMatrixMultiply(&g_mtxWorldPlayer, &g_mtxWorldPlayer, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, g_aPlayer.pos.x, g_aPlayer.pos.y, g_aPlayer.pos.z);
	D3DXMatrixMultiply(&g_mtxWorldPlayer, &g_mtxWorldPlayer, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldPlayer);

	//���݂̃}�e���A����ۑ�
	pDevice->GetMaterial(&matDef);

	//�}�e���A���f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL *)g_pBuffMatPlayer->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < (int)g_nNumMatPlayer; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//���f���p�[�c�̕`��
		g_pMeshPlayer->DrawSubset(nCntMat);
	}
	//�ێ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);
}

Player * GetPlayer(void)
{
	return &g_aPlayer;
}
