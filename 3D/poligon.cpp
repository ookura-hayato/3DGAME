//==================================
//�����b 3D(poligon.cpp)
//	Author:�@��q����
//==================================
#include "poligon.h"

//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffPoligon = NULL;	//���_�o�b�t�@�ւ̃|�C���^
D3DXVECTOR3 g_posPoligon;							//�ʒu
D3DXVECTOR3 g_rotPoligon;							//����
D3DXMATRIX g_mtxWorldPoligon;						//���[���h�}�g���b�N�X

//�|���S������������
void InitPoligon(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();
	
	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED, &g_pVtxBuffPoligon,NULL);
	VERTEX_3D*pVtx = NULL;										//���_���ւ̃|�C���^
	g_pVtxBuffPoligon->Lock(0, 0, (void**)&pVtx, 0);		//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾

	//���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(-50.0f, 0.0f, 50.0f);
	pVtx[1].pos = D3DXVECTOR3(50.0f, 0.0f, 50.0f);
	pVtx[2].pos = D3DXVECTOR3(-50.0f, 0.0f, -50.0f);
	pVtx[3].pos = D3DXVECTOR3(50.0f, 0.0f, -50.0f);

	//���_�̖@���̐ݒ�
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffPoligon->Unlock();
}

//�|���S���I������
void UninitPoligon(void)
{
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffPoligon != NULL)
	{
		g_pVtxBuffPoligon->Release();
		g_pVtxBuffPoligon = NULL;
	}
}

//�|���S���X�V����
void UpdatePoligon(void)
{
	
}

//�|���S���`�揈��
void DrawPoligon(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�̃|�C���^			
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_mtxWorldPoligon);
	
	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotPoligon.y, g_rotPoligon.x, g_rotPoligon.z);
	D3DXMatrixMultiply(&g_mtxWorldPoligon, &g_mtxWorldPoligon, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, g_posPoligon.x, g_posPoligon.y, g_posPoligon.z);
	D3DXMatrixMultiply(&g_mtxWorldPoligon, &g_mtxWorldPoligon, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD,&g_mtxWorldPoligon);

	//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffPoligon, 0, sizeof(VERTEX_3D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
}