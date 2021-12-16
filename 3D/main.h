//==================================
//�����b 3D(main.h)
//	Author:�@��q����
//==================================
#pragma once
#ifndef _MAIN_H_						//���̃}�N����`������Ȃ�������
#define _MAIN_H_						//��d�C���N���[�h�h�~�̃}�N����`
#include<windows.h>
#include"d3dx9.h"						//�`��ɕK�v
#define	 DIRECTINPUT_VERSION (0x0800)	//�r���h���̌x���΍��p�}�N��
#include "dinput.h"						//���͏����ɕK�v
#include "xaudio2.h"
#include "poligon.h"
#include "camera.h"
#include "light.h"
#include "model.h"
#include "input.h"
#include "shadow.h"
#include "wall.h"
#include "billboard.h"
#include "meshfeild.h"
#include "effect.h"
#include"bullet.h"
#include"explosion.h"
#include "player.h"

//#include"title.h"
//#include "game.h"
//#include "result.h"
//#include "sound.h"
//#include"tutorial.h"


//���C�u�����̃����N
#pragma comment(lib,"d3d9.lib")			//�`��ɕK�v
#pragma comment(lib,"d3dx9.lib")		//d3d9.lib�̊g�����C�u����
#pragma comment(lib,"dxguid.lib")		//DirectX�R���|�[�l���g�Ɏg�p
#pragma comment(lib,"winmm.lib")		//�V�X�e�������擾�ɕK�v
#pragma comment(lib,"dinput8.lib")		//���͏����ɕK�v

//�}�N����`
#define CLASS_NAME		"WindowClass"				//�E�B���h�E�N���X�̖��O
#define WINDOW_NAME		"DirectX�̊�{����"			//�E�B���h�E�̖��O(�L���v�V�����ɕ\��)
#define SCREEN_WIDTH (1280)							//�E�B���h�E�̕�
#define SCREEN_HEIGHT (720)							//�E�B���h�E�̍���
//#define FVF_VERTEX_2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)
#define FVF_VERTEX_3D (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_DIFFUSE|D3DFVF_TEX1)

//// ���_���[2D]�̍\���̂��`
//typedef struct
//{
//	D3DXVECTOR3 pos;		//���_���W
//	float rhw;				//���W�ϊ��p�W���i1.0f�ŌŒ�j
//	D3DCOLOR col;			//���_�J���[
//	D3DXVECTOR2 tex;		//�e�N�X�`�����W
//}VERTEX_2D;

// ���_���[3D]�̍\���̂��`
typedef struct
{
	D3DXVECTOR3 pos;		//���_���W
	D3DXVECTOR3 nor;		//�@���x�N�g��
	D3DCOLOR col;			//���_�J���[
	D3DXVECTOR2 tex;		//�e�N�X�`�����W
}VERTEX_3D;

////��ʁi���[�h�j�̎��
//typedef enum
//{
//	MODE_TITLE = 0,		//�^�C�g�����
//	MODE_TUTORIAL,		//�`���[�g���A�����
//	MODE_GAME,			//�Q�[�����
//	MODE_RESULT,		//���U���g���
//	MODE_MAX
//}MODE;

//�v���g�^�C�v�錾
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
void Uninit(void);
void Update(void);
void Draw(void);
LPDIRECT3DDEVICE9 GetDevice(void);
//void SetMode(MODE mode);
//MODE GetMode(void);
#endif
