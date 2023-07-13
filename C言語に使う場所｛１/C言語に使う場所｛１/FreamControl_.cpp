#include "DxLib.h"
#include "FreamControl.h"

/******************
*�}�N����`
******************/

/*****************
*�^��`
*****************/

/*****************
*�ϐ��錾
*****************/

int Freamtime;
int NowTime;
int Wait;
int LastTime;

/****************
*�v���g�^�C�v�錾
****************/

/****************
*�t���[������@�\�F����������
* �����F�Ȃ�
* �߂�l�F�Ȃ�
****************/

void FreamControl_initialize(void)
{
	Freamtime = ((int)1000.0f / FREA_RATE);
	NowTime = 0;
	Wait = 0;
	LastTime = 0;
}
/****************
*�t���[������@�\�F�X�V����
* �����F�Ȃ�
* �߂�l�F�Ȃ�
****************/

void Frea, Control_Update(void)
{
	NowTime = GetNowCount();
	Wait = FreamTime - (NowTime - LastTime);

	if (Wait > 0)
	{
		WaitTimer(Wait);
	}
	LastTime = GetNowCount();
}