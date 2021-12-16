//==================================
//�����b 3D(main.cpp)
//	Author:�@��q����
//==================================
#include"main.h"

//�v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//�O���[�o���ϐ�
LPDIRECT3D9			g_pD3D = NULL;
LPDIRECT3DDEVICE9   g_pD3DDevice = NULL;
VERTEX_3D			g_aVertex[4];
LPDIRECT3DTEXTURE9  g_pTexturePolygon = NULL;
//MODE g_mode = MODE_TITLE;

//=================
//���C���֐�
//=================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hInstancePrev, LPSTR lCmdLine, int nCmdShow)
{
	RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WindowProc,
		0,
		0,
		hInstance,
		LoadIcon(NULL,IDI_APPLICATION),
		LoadCursor(NULL,IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		CLASS_NAME,
		LoadIcon(NULL,IDI_APPLICATION)
	};
	HWND hWnd;					//�E�B���h�E�n���h��
	MSG msg;					//���b�Z�[�W���i�[			

	//�E�B���h�E�N���X�̓o�^
	RegisterClassEx(&wcex);

	//�N���C�A���g�̈���w��̃T�C�Y�ɒ���
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	//�E�B���h�E�𐶐�
	hWnd = CreateWindowEx
	(
		0,
		CLASS_NAME,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(rect.right - rect.left),		
		(rect.bottom - rect.top),				
		NULL,
		NULL,
		hInstance,
		NULL);						//�E�B���h�E�쐬�f�[�^

	//����\��ݒ�
	DWORD dwCurrentTime;			//���ݎ���
	DWORD dwExecLastTime;			//�Ō�ɏ�����������

//����������
	if (FAILED(Init(hInstance, hWnd, TRUE)))
	{//�����������s�����ꍇ
		return -1;
	}

//�E�B���h�E�̕\��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	timeBeginPeriod(1);
	dwCurrentTime = 0;			//����������
	dwExecLastTime = timeGetTime();		//���ݎ������擾
	//���b�Z�[�W���[�v
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{//�E�C���h�E�̏���
			if (msg.message == WM_QUIT)
			{//WM_QUIT���b�Z�[�W���󂯎�����烁�b�Z�[�W���[�v�𔲂���
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{//DirectX�̏���
			dwCurrentTime = timeGetTime();		//���ݎ������擾
			if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))
			{//60����1�b�o��
				dwExecLastTime = dwCurrentTime;		//�����J�n�̎���[���ݎ���]��ۑ�
			}

			//�X�V����
				Update();

				//�`�揈��
				Draw();
		}
	}
	//�I������
	Uninit();
	//����\��߂�
	timeEndPeriod(1);

	//�E�C���h�E�N���X�̓o�^������
	UnregisterClass(CLASS_NAME, wcex.hInstance);
	return(int)msg.wParam;
}

//�E�C���h�E�v���V�[�W��
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nID;						//�Ԃ�l���i�[
	
	const RECT rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };	//�E�C���h�E�̗̈�

	switch (uMsg)
	{

	case WM_DESTROY:			
		PostQuitMessage(0);
		break;

	case WM_CLOSE:		//����{�^�������̃��b�Z�[�W
		//nID = MessageBox(hWnd, "�I�����܂����H", "�I�����b�Z�[�W", MB_YESNO|MB_TOPMOST);
		//if (nID == IDYES)
		//{
			//�E�C���h�E��j������
			DestroyWindow(hWnd);
		//}
		//else
		//{
			return 0;	//0��Ԃ��Ȃ��ƏI�����Ă��܂�
		//}
		break;

	case WM_LBUTTONDOWN:		//�}�E�X���N���b�N�̃��b�Z�[�W
								//�E�C���h�E�Ƀt�H�[�J�X�����킹��
		SetFocus(hWnd);
		break;

	case WM_KEYDOWN: //�L�[�����̃��b�Z�[�W
		switch (wParam)
		{
		case VK_ESCAPE:		//ESC�L�[�������ꂽ��
			/*nID = MessageBox(hWnd, "�I�����܂����H", "�I�����b�Z�[�W", MB_YESNO);
			if (nID == IDYES)
			{*/
				//�E�C���h�E��j������(WM_DESTROY���b�Z�[�W�𑗂�)
				DestroyWindow(hWnd);
			/*}*/
			break;
		}
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);		//����̏�����Ԃ�
}

//����������
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	D3DDISPLAYMODE d3ddm;			//�f�B�X�v���C���[�h
	D3DPRESENT_PARAMETERS d3dpp;	//�v���[���e�[�V�����p�����[�^�[

	//Direct3D�I�u�W�F�N�g�̐���
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (g_pD3D == NULL)
	{
		return E_FAIL;
	}

	//���݂̃f�B�X�v���C���[�h���擾
	if (FAILED(g_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return E_FAIL;
	}

	//�f�o�C�X�̃v���[���e�[�V�����p�����[�^�̐ݒ�
	ZeroMemory(&d3dpp, sizeof(d3dpp));								//�p�����[�^�̃[���N���A
	d3dpp.BackBufferWidth = SCREEN_WIDTH;							//�Q�[����ʃT�C�Y(��)
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;							//�Q�[����ʃT�C�Y(����)
	d3dpp.BackBufferFormat = d3ddm.Format;							//�o�b�N�o�b�t�@�̌`��
	d3dpp.BackBufferCount = 1;										//�o�b�N�o�b�t�@�̌`��
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;						//�o�b�N�o�b�t�@�̐�
	d3dpp.EnableAutoDepthStencil = TRUE;							//�f�v�X�o�b�t�@�̐؂�ւ�(�f���M���ɓ���)
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;						//�f�v�X�o�b�t�@�Ƃ���16bit���g��
	d3dpp.Windowed = bWindow;										//�E�C���h�E���[�h
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;		//�t���b�V�����[�g
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;		//�C���^�[�o��

	//Direct3D�f�o�C�X�̐���(�`�揈���ƒ��_�������n�[�h�E�F�A�ōs��)
	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&g_pD3DDevice)))
	{
		//Direct3D�f�o�C�X�̐���(�`�揈���̓n�[�h�E�F�A�A���_������CPU�ōs��)
		if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp,
			&g_pD3DDevice)))
		{
			//Direct3D�f�o�C�X�̐���(�`�揈���ƒ��_������CPU�ōs��)
			if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL,
				hWnd,
				D3DCREATE_SOFTWARE_VERTEXPROCESSING,
				&d3dpp,
				&g_pD3DDevice)))
			{
				return E_FAIL;
			}
		}
	}

	//�����_�X�e�[�g�̐ݒ�
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);


	//�e�N�X�`���X�e�[�W�X�e�[�g�p�����[�^�̐ݒ�
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);

	////���C���[�t���[�����[�h�̐ݒ�
	//g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	////���ɖ߂�
	//g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);

	//�L�[�{�[�h����������
	if (FAILED(InitKeyboard(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	//�J�����̏���������
	InitCamera();

	//�e����������
	InitShadow();

	//�r���{�[�h����������
	InitBillboard();

	//���b�V���t�B�[���h����������
	InitMeshfeild();

	//���C�g�̏���������
	InitLight();

	//�v���C���[����������
	InitPlayer();

	//���f������������
	InitModel();

	//�Ǐ���������
	InitWall();

	//�G�t�F�N�g����������
	InitEffect();

	//�����̏���������
	InitExplosion();

	//�e�̏���������
	InitBullet();

	////�T�E���h����������
	//InitSound(hWnd);

	////���[�h�̐ݒ�
	//SetMode(g_mode);

	//�e��I�u�W�F�N�g�̏���������
	return S_OK;
}

//�I������
void Uninit(void)
{

	//�J�����̏I������
	UninitCamera();

	//�r���{�[�h�I������
	UninitBillboard();

	//�e�I������
	UninitShadow();

	//���b�V���t�B�[���h�I������
	UninitMeshfeild();

	//���C�g�̏I������
	UninitLight();

	//�v���C���[�I������
	UninitPlayer();

	//���f���I������
	UninitModel();

	//�L�[�{�[�h�I������
	UninitKeyboard();

	//�ǏI������
	UninitWall();

	//�ǏI������
	UninitEffect();

	//�����̏I������
	UninitExplosion();

	//�e�̏I������
	UninitBullet();

	////�T�E���h�̏I���ݒ�
	//UninitSound();

	if (g_pD3DDevice != NULL)
	{
		g_pD3DDevice->Release();
		g_pD3DDevice = NULL;
	}

	//Direct3D�I�u�W�F�N�g
	if (g_pD3D != NULL)
	{
		g_pD3D->Release();
		g_pD3D = NULL;
	}

	//����\��߂�
	timeEndPeriod(1);
	
}

//�X�V����
void Update(void)
{

	//�J�����̍X�V����
	UpdateCamera();

	//�e�X�V����
	UpdateShadow();

	//�r���{�[�h�X�V����
	UpdateBillboard();

	//���b�V���t�B�[���h�X�V����
	UpdateMeshfeild();

	//���C�g�̍X�V����
	UpdateLight();

	//�v���C���[�X�V����
	UpdatePlayer();

	//���f���X�V����
	UpdateModel();

	//�L�[�{�[�h�X�V����
	UpdateKeyboard();

	//�ǍX�V����
	UpdateWall();

	//�ǍX�V����
	UpdateEffect();

	//�����̍X�V����
	UpdateExplosion();

	//�e�̍X�V����
	UpdateBullet();

	//switch (g_mode)
	//{
	//case MODE_TITLE:					//�^�C�g�����
	//	UpdateTitle();
	//	break;

	//case MODE_TUTORIAL:				//�`���[�g���A�����
	//	UpdateTutorial();
	//	break;

	//case MODE_GAME:					//�Q�[�����
	//	UpdateGame();
	//	break;

	//case MODE_RESULT:					//���U���g����
	//	UpdateResult();
	//	break;
	//}
}

//�`�揈��
void Draw(void)
{
	

	//��ʃN���A
	g_pD3DDevice->Clear(0, NULL,
		(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);

	//�`��̊J�n
	if (SUCCEEDED(g_pD3DDevice->BeginScene()))
	{//���������Ƃ�

		//�J�����̐ݒ菈��
		SetCamera();

		//�Ǖ`�揈��
		DrawWall();

		//�G�t�F�N�g�`�揈��
		DrawEffect();

		//���b�V���t�B�[���h�`�揈��
		DrawMeshfeild();

		//�e�`�揈��
		DrawShadow();

		//�v���C���[�`�揈��
		DrawPlayer();

		//���f���`�揈��
		DrawModel();

		//�r���{�[�h�`�揈��
		DrawBillboard();

		//switch (g_mode)
		//{
		//case MODE_TITLE:					//�^�C�g�����
		//	DrawTitle();
		//	break;

		//case MODE_TUTORIAL:					//�`���[�g���A�����
		//	DrawTutorial();
		//	break;

		//case MODE_GAME:						//�Q�[�����
		//	DrawGame();
		//	break;

		//case MODE_RESULT:					//���U���g����
		//	DrawResult();
		//	break;
		//}

		//�`��I��
		g_pD3DDevice->EndScene();
	}
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
//�f�o�C�X�̎擾
LPDIRECT3DDEVICE9 GetDevice(void)
{
	return g_pD3DDevice;
}

////���[�h�̐ݒ�
//void SetMode(MODE mode)
//{
//	//���݂̉�ʂ̏I������
//	switch (g_mode)
//	{
//	case MODE_TITLE:				//�^�C�g�����
//		UninitTitle();
//		break;
//
//	case MODE_TUTORIAL:				//�`���[�g���A�����
//		UninitTutorial();
//		break;
//
//	case MODE_GAME:					//�Q�[�����
//		UninitGame();
//		break;
//
//	case MODE_RESULT:				//���U���g����
//		UninitResult();
//		break;
//	}
//
//	//�V������ʂ̏���������
//	switch (mode)
//	{
//	case MODE_TITLE:				//�^�C�g�����
//		InitTitle();
//		break;
//
//	case MODE_TUTORIAL:				//�`���[�g���A�����
//		InitTutorial();
//		break;
//
//	case MODE_GAME:					//�Q�[�����
//		InitGame();
//		break;
//
//	case MODE_RESULT:				//���U���g����
//		InitResult();
//		break;
//	}
//
//	g_mode = mode;	//���݂̉�ʂ�؂�ւ���
//}
//
////���[�h�̎擾
//MODE GetMode(void)
//{
//	return g_mode;
//}