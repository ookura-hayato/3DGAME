//==================================
//�����b 3D(effect.cpp)
//	Author:�@��q����
//==================================
#include "effect.h"

//�O���[�o���ϐ�
LPDIRECT3DVERTEXBUFFER9	g_pVtxBuffEffect = NULL;	//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureEffect = NULL;			//�e�N�X�`���ւ̃|�C���^
Effect g_Effect[MAX_EFFECT];						//�G�t�F�N�g���

//�G�t�F�N�g����������
void InitEffect(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//�f�o�C�X�̃|�C���^

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data/TEXTURE/effect000.png", &g_pTextureEffect);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_EFFECT, D3DUSAGE_WRITEONLY, FVF_VERTEX_3D,
		D3DPOOL_MANAGED, &g_pVtxBuffEffect, NULL);
	VERTEX_3D*pVtx = NULL;										//���_���ւ̃|�C���^
	g_pVtxBuffEffect->Lock(0, 0, (void**)&pVtx, 0);				//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾

	for (int nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		////���_���W�̐ݒ�
		//pVtx[0].pos = D3DXVECTOR3(-50.0f, 50.0f, 50.0f);
		//pVtx[1].pos = D3DXVECTOR3(50.0f, 50.0f, 50.0f);
		//pVtx[2].pos = D3DXVECTOR3(-50.0f, 0.0f, 50.0f);
		//pVtx[3].pos = D3DXVECTOR3(50.0f, 0.0f, 50.0f);

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

		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;			//���_�f�[�^�̃|�C���^��4���i�߂�
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffEffect->Unlock();

}

//�G�t�F�N�g�I������
void UninitEffect(void)
{
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffEffect != NULL)
	{
		g_pVtxBuffEffect->Release();
		g_pVtxBuffEffect = NULL;
	}

	//�e�N�X�`���̔j��
	if (g_pTextureEffect != NULL)
	{
		g_pTextureEffect->Release();
		g_pTextureEffect = NULL;
	}
}

//�G�t�F�N�g�X�V����
void UpdateEffect(void)
{
	for (int nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		if (g_Effect[nCntEffect].bUse == true)
		{
			g_Effect[nCntEffect].pos += g_Effect[nCntEffect].rot;
			g_Effect[nCntEffect].bUse = false;
		}
	}
	if (GetKeyboardPress(DIK_F7) == true)
	{
		SetEffect(D3DXVECTOR3(5.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		SetEffect(D3DXVECTOR3(10.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, D3DX_PI*0.5f, 0.0f));
		SetEffect(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, -D3DX_PI * 0.5f, 0.0f));
	}
}

//�G�t�F�N�g�`�揈��
void DrawEffect(void)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();		//�f�o�C�X�̃|�C���^		
	D3DXMATRIX mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pTextureEffect);

	//Z�o�b�t�@��Z�e�X�g�̐ݒ�
	pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	for (int nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_Effect[nCntEffect].mtxWorld);

		//�����𔽉f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Effect[nCntEffect].rot.y, g_Effect[nCntEffect].rot.x, g_Effect[nCntEffect].rot.z);
		D3DXMatrixMultiply(&g_Effect[nCntEffect].mtxWorld, &g_Effect[nCntEffect].mtxWorld, &mtxRot);

		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, g_Effect[nCntEffect].pos.x, g_Effect[nCntEffect].pos.y, g_Effect[nCntEffect].pos.z);
		D3DXMatrixMultiply(&g_Effect[nCntEffect].mtxWorld, &g_Effect[nCntEffect].mtxWorld, &mtxTrans);

		//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
		pDevice->SetStreamSource(0, g_pVtxBuffEffect, 0, sizeof(VERTEX_3D));

		//���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_3D);

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &g_Effect[nCntEffect].mtxWorld);

		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCntEffect * 4, 2);

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

//�G�t�F�N�g�̐ݒ�
void SetEffect(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	VERTEX_3D*pVtx;	//���_���̃|�C���^
	int nCntEffect;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffEffect->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntEffect = 0; nCntEffect < MAX_EFFECT; nCntEffect++)
	{
		if (g_Effect[nCntEffect].bUse == false)
		{
			g_Effect[nCntEffect].pos = pos;
			g_Effect[nCntEffect].rot = rot;

			pVtx[0].pos = D3DXVECTOR3(-80.0f, 100.0f, 70.0f);
			pVtx[1].pos = D3DXVECTOR3(80.0f, 100.0f, 70.0f);
			pVtx[2].pos = D3DXVECTOR3(-80.0f, 0.0f, 70.0f);
			pVtx[3].pos = D3DXVECTOR3(80.0f, 0.0f, 70.0f);

			g_Effect[nCntEffect].bUse = true;

			break;
		}
		pVtx += 4;	//�|�C���^��4�i�߂�
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffEffect->Unlock();
}

////�ǂ̎擾
//Effect* GetEffect(void)
//{
//	return &g_Effect[0];
//}