#pragma once
/******************
*マクロ定義
******************/

/*****************
*型定義
*****************/

/****************
*プロトタイプ宣言
****************/

void Input_Initialize(void);
void input_Update(void);
int Input_Escape(void);

int GetOldkey(int key);
int GetNowKey(int key);
int GetKeyFlg(int key);
int GetMousepositionX(void);
int GetMousepositionY(void);
