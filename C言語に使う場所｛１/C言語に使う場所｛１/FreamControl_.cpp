#include "DxLib.h"
#include "FreamControl.h"

/******************
*マクロ定義
******************/

/*****************
*型定義
*****************/

/*****************
*変数宣言
*****************/

int Freamtime;
int NowTime;
int Wait;
int LastTime;

/****************
*プロトタイプ宣言
****************/

/****************
*フレーム制御機能：初期化処理
* 引数：なし
* 戻り値：なし
****************/

void FreamControl_initialize(void)
{
	Freamtime = ((int)1000.0f / FREA_RATE);
	NowTime = 0;
	Wait = 0;
	LastTime = 0;
}
/****************
*フレーム制御機能：更新処理
* 引数：なし
* 戻り値：なし
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