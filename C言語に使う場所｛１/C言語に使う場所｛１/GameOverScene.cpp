#include "GameMainScene.h"
#include "DxLib.h"
#include"SceneManager.h"

/*****************
*変数宣言
*****************/

int GameOverImage;
int GameOverSE;
int GameOverFlag;

/****************
*プロトタイプ宣言
****************/


/****************
*ゲームオーバー画面：初期化処理
* 引数：なし
* 戻り値：エラー情報
****************/

int GameOverScene_Initialize(void)
{
	int ret = 0;

	//画像読み込み
	GameOverImage = LoadGraph("images/gameover/png");
	//音源読み込み
	GameOverSE = LoadSoundMem("sounds/gemaover_se.mp3");
	GameOverFlag = FALSE;
	

	//エラーチェック
	if (GameOverImage == -1)
	{
		ret = -1;
	}
	if (GameOverSE == -1)
	{
		ret = -1;
	}

	return ret;

}


/****************
*ゲームメイン画面：更新処理
* 引数：なし
* 戻り値：なし
****************/

void GameOverScene_Updata(void)
{
	//ゲームオーバー効果音再生チェック
	if (CheckSoundMem(GameoverSE) == 0)
	{
		if (GameOverFlag == TRUE) {
			Change_Scene(E_GAME_OVER);
		}
		else
		{
			PlaySoundMem(GameOverSE, DX_PAYTYPE_BACK);
			GameOverFlag = TRUE;
		}
	}
}

/****************
*ゲームメイン画面：描画処理
* 引数：なし
* 戻り値：なし
****************/

void GameOverScene_Draw(void)
{
	//ゲームオーバー画像表示
	DrawGraph(0,0,GameOverImage,FALSE):
}