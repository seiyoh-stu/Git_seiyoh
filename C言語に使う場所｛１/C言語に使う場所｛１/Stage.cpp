#include "Stage.h"
#include"Dxlib.h"
#include"InputControl.h"

/******************
*�}�N����`
******************/
#define HEIGHT             (12) //�u���b�N�z�u�T�C�Y�i�����j
#define WIDTH              (12) //�u���b�N�z�u�T�C�Y�i���j
#define BLOCKSIZE          (48) //�u���b�N�T�C�Y
#define BLOCK_IMAGE_MAX    (10) //�u���b�N�摜��

#define ITEM_MAX           (8)  //�A�C�e���ő吔

#define SELECT_CURSOR      (0)
#define NEXT_CURSOR        (1)
#define TMP_CURSOR         (2)

/*****************
*�^��`
*****************/
typedef struct
{
	int flg;
	int x, y;
	int width, height;
	int image;
	int backup;
}T_Object;

typedef struct
{
	int x;
	int y;
}T_Object;

enum
{
	E_NONE,
	E_ONCE,
	E_SECOND
};

/*****************
*�ϐ��錾
*****************/

T_Object Block[HEIGHT][WIDTH];
T_CURSOR Select[3];
int Item[ITEM_MAX];
int ClickStatus;
int Stage_State;
int Stage_Mission;
int Stage_Score;
int ClearFlag;

int�@BlockImage[BLOCK_IMAGE_MAX]; //�u���b�N�摜
int StageImage;                 //�w�i�摜
int clickSE;
int FadeOutSE;
int MoveBlockSE;

/****************
*�v���g�^�C�v�錾
****************/

int combo_check(int x, int y);
void combo_check_h(int y, int x, int* cnt, int* col);
void combo_check_w(int y, int x, int* cnt, int* col);
void save_block(void);
void restore_block(void);

/****************
*�X�e�[�W����@�\�F����������
* �����F�Q�[�����[�h���
* �߂�l�F�G���[���
****************/

int StageInitialize(void)
{
	int ret = 0;
	int i;

	//�摜�ǂݍ���
	loadDivGraph("images/block,png", BLOCK_IMAGE_MAX, BLOCK_IMAGE_MAX, 1, BLOCKSIZE, BLOCKSIZE, BlockImage);
	StageImage = LoadGraph("Image/stage.png");
	//�����ǂݍ���
	ClipSE = LoadSoundMem("sounds/click_se.mp3");
	FadeOutSE= LoadSoundMem("sounds/fadeout_se.mp3");
	MoveBlockSE= LoadSoundMem("sounds/moveblock_se.mp3");

	//�u���b�N��������
	CreateBlock();

	ClickStatus = E_NONE;
	Stage_State = 0;
	Stage_Score = 0;
	ClearFlag = FALSE;

	for (i = 0; i < 3; i++)
	{
		Select[i].x = 0;
		Select[i].y = 0;
	}

	//�G���[�`�F�b�N
	for(i=0;i<BLOCK_IMAGE_MAX;i++)
	{
		if (BlockImage[i] == -1)
		{
			ret = -1;
			break;
	     }
	}
	if (StageImage == -1)
	{
		ret = -1;
	}
	if (ClickSE == -1)
	{
		ret = -1;
	}
	if (FadeOutSE == -1)
	{
		ret = -1;
	}
	if (MoveBlockSE == -1)
	{
		ret = -1;
	}
	return ret;
}

/****************
*�X�e�[�W����@�\�F�X�e�[�W�̕`��
* �����F�Ȃ�
* �߂�l�F�Ȃ�
****************/
