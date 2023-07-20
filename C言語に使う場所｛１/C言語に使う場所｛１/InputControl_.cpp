#include "DxLib.h"
#include "InputControl.h"

/*****************
*�ϐ��錾
*****************/
int old_button;
int now_button;
int mouse_position_x;
int mouse_position_y;

/****************
*�v���g�^�C�v�錾
****************/

/****************
*���͐���@�\�F����������
* �����F�Ȃ�
* �߂�l�F�Ȃ�
****************/

void Input_Initialize(void)
{
	old_button = NULL;
	now_button = NULL;
	mouse_position_x = NULL;
	mouse_position_y = NULL;
}

/****************
*���͐���@�\�F�X�V����
* �����F�Ȃ�
* �߂�l�F�Ȃ�
****************/

void Input_Updata(void)
{
	int ret = FALSE;
	//ESC�L�[�������ꂽ�烋�[�v�𔲂���
	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ret = TRUE;
	}

	return = ret;
}

/****************
*���͐���@�\�F���͏�񏈗�(�������u��)
* �����F�w�肷��}�E�X�̃{�^��
* �߂�l�FTRUE(���͂��ꂽ),FALSE(�����́j
****************/

int GetOldKey(int key)
{
	int ret = FALSE;

	if ((key & old_button) != FALSE)
	{
		ret = TRUE;
	}
	return ret;
}

/****************
*���͐���@�\�F���͏�񏈗�(�����Ă�)
* �����F�w�肷��}�E�X�̃{�^��
* �߂�l�FTRUE(���͂��ꂽ),FALSE(�����́j
****************/

int GetNowKey(int key)
{
	int ret = FALSE;


	if ((key & now_button) != FALSE)
	{
		ret = TRUE;
	}
	return ret;
}

/****************
*���͐���@�\�F���͏�񏈗�(�������u��)
* �����F�w�肷��}�E�X�̃{�^��
* �߂�l�FTRUE(���͂��ꂽ),FALSE(�����́j
****************/
int GetKeyFlg(int key)
{
	int ret = FALSE;
	intkeyflg = now_botton & ~old_button;

	if ((key & keyflg) != FALSE)
	{
		ret=TRUE
	}
	return ret;
}

/****************
*���͐���@�\�}�E�X�̍��W�擾����
* �����F�Ȃ�
* �߂�l�F�}�E�X�J�[�\����X���W���
****************/

int GetMousePositionX(void)
{
	return mouse_position_x;
}


/****************
*���͐���@�\�}�E�X�̍��W�擾����
* �����F�Ȃ�
* �߂�l�F�}�E�X�J�[�\����Y���W���
****************/

int GetMousePositionY(void)
{
	return mouse_position_y;
}