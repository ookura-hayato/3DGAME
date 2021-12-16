//==================================
//�����b 3D(model.cpp)
//	Author:�@��q����
//==================================
#include "model.h"

//�O���[�o���ϐ�
LPD3DXMESH g_pMeshModel = NULL;			//���b�V�����ւ̃|�C���^
LPD3DXBUFFER g_pBuffMatModel = NULL;	//�}�e���A�����ւ̃|�C���^
DWORD g_nNumMatModel = 0;			//�}�e���A�����̐�
Model g_Model[MAX_MODEL];
D3DXMATRIX g_mtxWorldModel;			//���[���h�}�g���b�N�X
int g_rotDestModel;					//�ړI�̊p�x
int g_nInndxShadow;
D3DXVECTOR3 g_vtxMiniModel, g_vtxMaxmModel;

//���f������������
void InitModel(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�̃|�C���^
	//�f�o�C�X�̎擾
	pDevice = GetDevice();
	
	//X�t�@�C���ǂݍ���
	D3DXLoadMeshFromX( "data/MODEL/ganngimarin.x",D3DXMESH_SYSTEMMEM,pDevice,NULL,
		&g_pBuffMatModel,NULL,&g_nNumMatModel,&g_pMeshModel);

	int nNumVtx;									//���_��
	DWORD sizeFVF;									//���_�t�H�[�}�b�g�̃T�C�Y
	BYTE * pVtxBuff;								//���_�o�b�t�@�ւ̃|�C���^

	//���_���̏���
	nNumVtx = g_pMeshModel->GetNumVertices();
	
	//���_�t�H�[�}�b�g�̃T�C�Y���擾
	sizeFVF = D3DXGetFVFVertexSize(g_pMeshModel->GetFVF());

	//���_�o�b�t�@�̃��b�N
	g_pMeshModel->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

	for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
	{
		//���_���W�̑��
		D3DXVECTOR3 Vtx = *(D3DXVECTOR3*)pVtxBuff;

		if (Vtx.x < g_vtxMiniModel.x)
		{
			g_vtxMiniModel.x = Vtx.x;
		}
		if (Vtx.y < g_vtxMiniModel.y)
		{
			g_vtxMiniModel.y = Vtx.y;
		}
		if (Vtx.z < g_vtxMiniModel.z)
		{
			g_vtxMiniModel.z = Vtx.z;
		}
		if (Vtx.x > g_vtxMaxmModel.x)
		{
			g_vtxMaxmModel.x = Vtx.x;
		}
		if (Vtx.y > g_vtxMaxmModel.y)
		{
			g_vtxMaxmModel.y = Vtx.y;
		}
		if (Vtx.z > g_vtxMaxmModel.z)
		{
			g_vtxMaxmModel.z = Vtx.z;
		}
		pVtxBuff += sizeFVF;
	}

	//���_�o�b�t�@�̃A�����b�N
	g_pMeshModel ->UnlockVertexBuffer();

	g_Model[MAX_MODEL].pos = D3DXVECTOR3(50.0f, 0.0f, 0.0f);				//�ʒu�̏����ݒ�
	g_Model[MAX_MODEL].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//�����̏����ݒ�
	g_nInndxShadow = SetShadow(D3DXVECTOR3(g_Model[MAX_MODEL].pos.x,0.1f, g_Model[MAX_MODEL].pos.z), g_Model[MAX_MODEL].rot);
}

//���f���I������
void UninitModel(void)
{
	//���b�V���̔j��
	if (g_pMeshModel != NULL)
	{
		g_pMeshModel->Release();
		g_pMeshModel = NULL;
	}

	//�}�e���A���̔j��
	if (g_pBuffMatModel != NULL)
	{
		g_pBuffMatModel->Release();
		g_pBuffMatModel = NULL;
	}
}

//���f���X�V����
void UpdateModel(void)
{
	SetPositionShadow(g_nInndxShadow, D3DXVECTOR3(g_Model[MAX_MODEL].pos.x, 0.1f, g_Model[MAX_MODEL].pos.z));
}

//���f���`�揈��
void DrawModel(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�̃|�C���^			

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;			//���݂̃}�e���A���ۑ��p
	D3DXMATERIAL * pMat;			//�}�e���A���f�[�^�ւ̃|�C���^

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_mtxWorldModel);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Model[MAX_MODEL].rot.y, g_Model[MAX_MODEL].rot.x, g_Model[MAX_MODEL].rot.z);
	D3DXMatrixMultiply(&g_mtxWorldModel, &g_mtxWorldModel, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, g_Model[MAX_MODEL].pos.x, g_Model[MAX_MODEL].pos.y, g_Model[MAX_MODEL].pos.z);
	D3DXMatrixMultiply(&g_mtxWorldModel, &g_mtxWorldModel, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldModel);

	//���݂̃}�e���A����ۑ�
	pDevice->GetMaterial(&matDef);
	
	//�}�e���A���f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL *)g_pBuffMatModel->GetBufferPointer();
	for (int nCntMat = 0; nCntMat < (int)g_nNumMatModel; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//���f���p�[�c�̕`��
		g_pMeshModel->DrawSubset(nCntMat);
	}
	//�ێ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);
}

//�����蔻��i���f���j
bool CollisionModel(D3DXVECTOR3*pPos,
	D3DXVECTOR3*pPosOld,
	float fWidith,
	float fHeight)
{
	bool bIsLanding = false;
	Player *pPlayer = GetPlayer();
	for (int nCntModel = 0; nCntModel < MAX_MODEL; nCntModel++)
	{
		if (g_Model[MAX_MODEL].bUse == true)
		{
			if (//����i��j
				(g_Model[nCntModel].pos.z - g_Model[nCntModel].fHeight / 2) >= pPosOld->z
				&& (g_Model[nCntModel].pos.z - g_Model[nCntModel].fHeight / 2) < pPos->z
				&& (g_Model[nCntModel].pos.x + g_Model[nCntModel].fWidth / 2) > (pPos->x - fWidith / 2)
				&& (g_Model[nCntModel].pos.x - g_Model[nCntModel].fWidth / 2) < (pPos->x + fWidith / 2))
			{
			
				pPos->z = g_Model[nCntModel].pos.z - g_Model[nCntModel].fHeight / 2;
				
			}
			if (//����(��)
				(g_Model[nCntModel].pos.z + g_Model[nCntModel].fHeight / 2) <= pPosOld->z - pPlayer->pos.z
				&& (g_Model[nCntModel].pos.z + g_Model[nCntModel].fHeight / 2) > pPos->z - pPlayer->pos.z
				&& (g_Model[nCntModel].pos.x + g_Model[nCntModel].fWidth / 2) > (pPos->x - fWidith / 2)
				&& (g_Model[nCntModel].pos.x - g_Model[nCntModel].fWidth / 2) < (pPos->x + fWidith / 2))
			{

				pPos->z = g_Model[nCntModel].pos.z + g_Model[nCntModel].fHeight / 2 + pPlayer->pos.z;
	
			}
			if (//����(��)
				(g_Model[nCntModel].pos.x - g_Model[nCntModel].fWidth / 2) >= pPosOld->x + pPlayer->pos.x / 2
				&& (g_Model[nCntModel].pos.x - g_Model[nCntModel].fWidth / 2) < pPos->x + pPlayer->pos.x / 2
				&& (g_Model[nCntModel].pos.z + g_Model[nCntModel].fHeight / 2) > (pPos->z - fHeight / 2)
				&& (g_Model[nCntModel].pos.z - g_Model[nCntModel].fHeight / 2) < pPos->z)
			{

				pPos->x = g_Model[nCntModel].pos.x - g_Model[nCntModel].fWidth / 2 - pPlayer->pos.x / 2;
			
			}
			if (//����(�E)
				(g_Model[nCntModel].pos.x + g_Model[nCntModel].fWidth / 2) <= pPosOld->x - pPlayer->pos.x / 2
				&& (g_Model[nCntModel].pos.x + g_Model[nCntModel].fWidth / 2) > pPos->x - pPlayer->pos.x / 2
				&& (g_Model[nCntModel].pos.z + g_Model[nCntModel].fHeight / 2) > (pPos->z - fHeight / 2)
				&& (g_Model[nCntModel].pos.z - g_Model[nCntModel].fHeight / 2) < pPos->z)
			{

				pPos->x = g_Model[nCntModel].pos.x + g_Model[nCntModel].fWidth / 2 + pPlayer->pos.x / 2;
			
			}
		}
	}
	return bIsLanding;
}