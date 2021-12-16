//==================================
//�����b 3D(meshfeild.cpp)
//	Author:�@��q����
//==================================
#include "meshfeild.h"

//�}�N����`
#define MESHFIELD_X_BLOCK (3)					//X�����̃u���b�N��
#define MESHFIELD_Z_BLOCK (3)					//Z�����̃u���b�N��

#define MESHFIELD_VERTEX_NUM	((MESHFIELD_X_BLOCK + 1)*(MESHFIELD_Z_BLOCK + 1))										//���_��
#define MESHFIELD_INDEX_NUM		((MESHFIELD_X_BLOCK + 1) * 2 * MESHFIELD_Z_BLOCK + (MESHFIELD_Z_BLOCK - 1) * 2)			//�C���f�b�N�X��
#define MESHFIELD_PRIMITIVE_NUM	 (MESHFIELD_X_BLOCK * MESHFIELD_Z_BLOCK * 2 + (MESHFIELD_Z_BLOCK -1) * 4)				//�|���S����

//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffMeshfeild = NULL;						//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DINDEXBUFFER9	g_pIdxBuffMeshfeild = NULL;						//�C���f�b�N�X�o�b�t�@�ւ̃|�C���^
//LPDIRECT3DTEXTURE9 g_pTextureMeshfeild = NULL;							//�e�N�X�`���ւ̃|�C���^
D3DXVECTOR3 g_posMeshfeild;												//�ʒu
D3DXVECTOR3 g_rotMeshfeild;												//����
D3DXMATRIX g_mtxWorldMeshfeild;											//���[���h�}�g���b�N�X 

//���b�V���t�B�[���h����������
void InitMeshfeild(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//�f�o�C�X�̃|�C���^

	////�e�N�X�`���̓ǂݍ���
	//D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/field002.jpg", &g_pTextureMeshfeild);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * MESHFIELD_VERTEX_NUM, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED, &g_pVtxBuffMeshfeild, NULL);

	VERTEX_3D*pVtx = NULL;										//���_���ւ̃|�C���^
	g_pVtxBuffMeshfeild->Lock(0, 0, (void**)&pVtx, 0);			//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾

	//�C���f�b�N�X�o�b�t�@�̐���
	pDevice->CreateIndexBuffer(sizeof(WORD) * 100000000, D3DUSAGE_WRITEONLY,D3DFMT_INDEX16,
		D3DPOOL_MANAGED, &g_pIdxBuffMeshfeild, NULL);

	//���_�̐ݒ�
	for(int nCntZ = 0; nCntZ <= MESHFIELD_Z_BLOCK ; nCntZ++)
	{
		for (int nCntX = 0; nCntX <= MESHFIELD_X_BLOCK; nCntX++)
		{
			//���_�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(-70.0f + 50.0f * nCntX, 0.0f, 70.0f -50.0f * nCntZ);

			//�@���̐ݒ�	 
			pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

			//���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			
			////�e�N�X�`�����W�̐ݒ�
			//pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			//pVtx[1].tex = D3DXVECTOR2(0.0f, 0.5f);
			//pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
			//pVtx[3].tex = D3DXVECTOR2(0.5f, 0.0f);
			//pVtx[4].tex = D3DXVECTOR2(0.5f, 0.5f);
			//pVtx[5].tex = D3DXVECTOR2(0.5f, 1.0f);
			//pVtx[6].tex = D3DXVECTOR2(1.0f, 0.0f);
			//pVtx[7].tex = D3DXVECTOR2(1.0f, 0.5f);
			//pVtx[8].tex = D3DXVECTOR2(1.0f, 1.0f);
			pVtx++;
		}
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffMeshfeild->Unlock();

	WORD * pIdx;											//�C���f�b�N�X���ւ̃|�C���^
	g_pIdxBuffMeshfeild->Lock(0, 0, (void**)&pIdx, 0);		//�C���f�b�N�X�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾

	for (int nCntZ = 0; nCntZ <= MESHFIELD_Z_BLOCK; nCntZ++)
	{
		for (int nCntX = 0; nCntX <= MESHFIELD_X_BLOCK; nCntX++)
		{
			//�C���f�b�N�X�̐ݒ�
			pIdx[0] = (WORD)(nCntX + (MESHFIELD_X_BLOCK + 1) * (nCntZ + 1));
			pIdx[1] = (WORD)(nCntX + (MESHFIELD_X_BLOCK + 1) * nCntZ);
			pIdx += 2;
		}
		if (nCntZ < MESHFIELD_Z_BLOCK - 1)
		{
			pIdx[0] = pIdx[-1];
			pIdx[1] = (WORD)(MESHFIELD_X_BLOCK + 1) * (nCntZ + 2);
			pIdx += 2;
		}

	}
	
	//�C���f�b�N�X�o�b�t�@���A�����b�N����
	g_pIdxBuffMeshfeild->Unlock();
}

//���b�V���t�B�[���h�I������
void UninitMeshfeild(void)
{
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffMeshfeild != NULL)
	{
		g_pVtxBuffMeshfeild->Release();
		g_pVtxBuffMeshfeild = NULL;
	}

	//�C���f�b�N�X�o�b�t�@�̔j��
	if (g_pIdxBuffMeshfeild != NULL)
	{	  
		g_pIdxBuffMeshfeild->Release();
		g_pIdxBuffMeshfeild = NULL;
	}

	////�e�N�X�`���̔j��
	//if (g_pTextureMeshfeild != NULL)
	//{
	//	g_pTextureMeshfeild->Release();
	//	g_pTextureMeshfeild = NULL;
	//}
}

//���b�V���t�B�[���h�X�V����
void UpdateMeshfeild(void)
{

}

//���b�V���t�B�[���h�`�揈��
void DrawMeshfeild(void)
{
	LPDIRECT3DDEVICE9 pDevice;		//�f�o�C�X�̃|�C���^			
									//�f�o�C�X�̎擾
	pDevice = GetDevice();

	D3DXMATRIX mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X

	////�e�N�X�`���̐ݒ�
	//pDevice->SetTexture(0, g_pTextureMeshfeild);

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_mtxWorldMeshfeild);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rotMeshfeild.y, g_rotMeshfeild.x, g_rotMeshfeild.z);
	D3DXMatrixMultiply(&g_mtxWorldMeshfeild, &g_mtxWorldMeshfeild, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, g_posMeshfeild.x, g_posMeshfeild.y, g_posMeshfeild.z);
	D3DXMatrixMultiply(&g_mtxWorldMeshfeild, &g_mtxWorldMeshfeild, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldMeshfeild);

	//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffMeshfeild, 0, sizeof(VERTEX_3D));

	//�C���f�b�N�X�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
	pDevice->SetIndices(g_pIdxBuffMeshfeild);

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�|���S���̕`��
	pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, MESHFIELD_VERTEX_NUM, 0, MESHFIELD_PRIMITIVE_NUM);

	////�e�N�X�`���̐ݒ�
	//pDevice->SetTexture(0, NULL);
}