/*********************************************************************
 * \file   ClearScene.cpp
 * \brief	
 * 
 * \author Harukichimaru
 * \date   December 2024
 * \note   
 *********************************************************************/
#include "ClearScene.h"
#include "Novice.h"

///=============================================================================
///						初期化
void ClearScene::Initialize() {
}

///=============================================================================
///						更新
void ClearScene::Update() {
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	//SPACEキーが押された瞬間
	if(keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
		//次のシーンへ
		sceneNo = TITLE;
	}
}

///=============================================================================
///						描画
void ClearScene::Draw() {
	//現在のシーン
	Novice::ScreenPrintf(0, 0, "ClearScene");
	//操作方法
	Novice::ScreenPrintf(0, 20, "Press SPACE key to title");
}
