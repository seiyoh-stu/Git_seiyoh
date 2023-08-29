#include "DxLib.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPreInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);


	//Dxライブライの初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//入力待機
	WaitKey();


	//Dxライブライ使用の終了方法
	DxLib_End();


	return 0;

}