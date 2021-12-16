//==================================
//�����b 3D(wall.cpp)
//	Author:�@��q����
//==================================
#include "billboard.h"

//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffBillboard = NULL;	//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureBillboard = NULL;			//�e�N�X�`���ւ̃|�C���^
Billboard g_aBillboard[MAX_BILLBOARD];						//�Ǐ��
int g_nIdxShadow;

//�r���{�[�h����������
void InitBillboard(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//�f�o�C�X�̃|�C���^

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/koiking.png", &g_pTextureBillboard);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_BILLBOARD, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED, &g_pVtxBuffBillboard, NULL);
	VERTEX_3D*pVtx = NULL;										//���_���ւ̃|�C���^
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);				//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾

	for (int nCntBillboard = 0; nCntBillboard < MAX_BILLBOARD; nCntBillboard++)
	{
		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-20.0f, 50.0f, 50.0f);
		pVtx[1].pos = D3DXVECTOR3(30.0f, 50.0f, 50.0f);
		pVtx[2].pos = D3DXVECTOR3(-20.0f, 20.0f, 50.0f);
		pVtx[3].pos = D3DXVECTOR3(30.0f, 20.0f, 50.0f);

		//���_�̖@���̐ݒ�
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;			//���_�f�[�^�̃|�C���^��4���i�߂�
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffBillboard->Unlock();
	g_nIdxShadow = SetShadow(D3DXVECTOR3(g_aBillboard[MAX_BILLBOARD].pos.x, 0.1f, g_aBillboard[MAX_BILLBOARD].pos.z), g_aBillboard[MAX_BILLBOARD].rot);


}

//�r���{�[�h�I������
void UninitBillboard(void)
{
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffBillboard != NULL)
	{
		g_pVtxBuffBillboard->Release();
		g_pVtxBuffBillboard = NULL;
	}

	//�e�N�X�`���̔j��
	if (g_pTextureBillboard != NULL)
	{
		g_pTextureBillboard->Release();
		g_pTextureBillboard = NULL;
	}
}

//�r���{�[�h�X�V����
void UpdateBillboard(void)
{
	SetPositionShadow(g_nIdxShadow, D3DXVECTOR3(g_aBillboard[MAX_BILLBOARD].pos.x, 0.1f, g_aBillboard[MAX_BILLBOARD].pos.z));
}

//�r���{�[�h�`�揈��
void DrawBillboard(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//�f�o�C�X�̃|�C���^		
	D3DXMATRIX  mtxTrans;	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX  mtxView;
	pDevice->GetTransform(D3DTS_VIEW,&mtxView);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pTextureBillboard);

	//Z�o�b�t�@��Z�e�X�g�̐ݒ�
	pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	for (int nCntBillboard = 0; nCntBillboard < MAX_BILLBOARD; nCntBillboard++)
	{
		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_aBillboard[nCntBillboard].mtxWorld);

		//�J�����̋t�s���ݒ�
		g_aBillboard[nCntBillboard].mtxWorld._11 = mtxView._11;
		g_aBillboard[nCntBillboard].mtxWorld._12 = mtxView._21;
		g_aBillboard[nCntBillboard].mtxWorld._13 = mtxView._31;
		g_aBillboard[nCntBillboard].mtxWorld._21 = mtxView._12;
		g_aBillboard[nCntBillboard].mtxWorld._22 = mtxView._22;
		g_aBillboard[nCntBillboard].mtxWorld._23 = mtxView._32;
		g_aBillboard[nCntBillboard].mtxWorld._31 = mtxView._13;
		g_aBillboard[nCntBillboard].mtxWorld._32 = mtxView._23;
		g_aBillboard[nCntBillboard].mtxWorld._33 = mtxView._33;

		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, g_aBillboard[nCntBillboard].pos.x, g_aBillboard[nCntBillboard].pos.y, g_aBillboard[nCntBillboard].pos.z);
		D3DXMatrixMultiply(&g_aBillboard[nCntBillboard].mtxWorld, &g_aBillboard[nCntBillboard].mtxWorld, &mtxTrans);

		//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
		pDevice->SetStreamSource(0, g_pVtxBuffBillboard, 0, sizeof(VERTEX_3D));

		//���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_3D);
		
		//���C�g�𖳌��ɂ���
		pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &g_aBillboard[nCntBillboard].mtxWorld);

		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntBillboard * 4, 2);
		//���C�g��L���ɂ���
		pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

		pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
		pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
		pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
		pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	}

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, NULL);

}

//�r���{�[�h�̐ݒ�
void SetBillboard(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	VERTEX_3D*pVtx;	//���_���̃|�C���^
	int nCntBillboard;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntBillboard = 0; nCntBillboard < MAX_BILLBOARD; nCntBillboard++)
	{
		if (g_aBillboard[nCntBillboard].bUse == false)
		{
			g_aBillboard[nCntBillboard].pos = pos;
			g_aBillboard[nCntBillboard].rot = rot;

			pVtx[0].pos = D3DXVECTOR3(-50.0f, 50.0f, 50.0f);
			pVtx[1].pos = D3DXVECTOR3(50.0f, 50.0f, 50.0f);
			pVtx[2].pos = D3DXVECTOR3(-50.0f, 0.0f, 50.0f);
			pVtx[3].pos = D3DXVECTOR3(50.0f, 0.0f, 50.0f);

			g_aBillboard[nCntBillboard].bUse = true;

			break;
		}
		pVtx += 4;	//�|�C���^��4�i�߂�
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffBillboard->Unlock();
}