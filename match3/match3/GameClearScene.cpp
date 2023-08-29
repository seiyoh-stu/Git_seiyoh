#include "GameClearScene.h"
#include"DxLib.h"
#include"SceneManager.h"

/******************
*�}�N����`
******************/

/*****************
*�^��`
*****************/

/*****************
*�ϐ��錾
*****************/

int GameClearImage;
int GameClearSE;
int GameClearFlag;

/****************
*�v���g�^�C�v�錾
****************/

/****************
*�Q�[���N���A��ʁF����������
* �����F�Ȃ�
* �߂�l�F�Ȃ�
****************/

int GameClearScene_Initialize(void)
{
	int ret = 0;

	//
	GameClearImage = LoadGraph("images/gameclear.png");
	//
	GameClearSE = LoadSoundMem("sounds/gameclear_se.mp3");

	GameClearFlag = 0;

	//
	if (GameClearImage == -1) {
		ret = -1;
	}
	if (GameClearSE == -1) {
		ret = -1;
	}

	return ret;

}

/****************
*�Q�[���N���A��ʁF�X�V����
* �����F�Ȃ�
* �߂�l�F�Ȃ�
****************/

void GameClearScene_Update(void)

{
	//�Q�[���N���A���ʉ��Đ��`�F�b�N
	if (CheckSoundMem(GameClearSE) == 0)
	{
		if (GameClearFlag == TRUE)
		{
			Change_Scene(E_GAMEMAIN);
		}
		else
		{
			PlaySoundMem(GameClearSE, DX_PLAYTYPE_BACK);
			GameClearFlag = TRUE;
		}
	}
}

/****************
*�Q�[���N���A��ʁF�`�揈��
* �����F�Ȃ�
* �߂�l�F�Ȃ�
****************/

void GameClearScene_Draw(void)
{
DrawGraph(0,0,GameClearImage,FALSE);
}