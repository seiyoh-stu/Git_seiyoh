#include "GameClearScene.h"
#include"DxLib.h"
#include"SceneManager.h"

/******************
*マクロ定義
******************/

/*****************
*型定義
*****************/

/*****************
*変数宣言
*****************/

int GameClearImage;
int GamaClearSE;
int GameClearFlag;

/****************
*プロトタイプ宣言
****************/

/****************
*ゲームクリア画面：初期化処理
* 引数：なし
* 戻り値：なし
****************/

int GameClearScene_inttialize(void)
{
	int ret = 0;

	//
	GameClearImage = LoadGraph("images/gameclear.png");
	//
	GamaClearSE = LoadSoundMem("sounds/gameclear_se.mp3");

	GamaClearFlag = 0;

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
*ゲームクリア画面：更新処理
* 引数：なし
* 戻り値：なし
****************/

void GameClearScene_Update(void)

{
	//ゲームクリア効果音再生チェック
	if (CheckSoundMem(GameClearSE) == )
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
*ゲームクリア画面：描画処理
* 引数：なし
* 戻り値：なし
****************/

void GameClearScene_Draw(void)
{
Drawgraph(0,0,GameClearImage,FALSE);
}