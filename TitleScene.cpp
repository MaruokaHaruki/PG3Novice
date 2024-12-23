/*********************************************************************
 * \file   TitleScene.cpp
 * \brief 
 * 
 * \author Harukichimaru
 * \date   December 2024
 * \note   
 *********************************************************************/
#include "TitleScene.h"
#include "Novice.h"

///=============================================================================
///						初期化
void TitleScene::Initialize() {
}

///=============================================================================
///						更新
void TitleScene::Update() {
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);


	//SPACEキーが押された瞬間
	if(keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
		//次のシーンへ
		sceneNo = GAME;
	}
}

///=============================================================================
///						描画
void TitleScene::Draw() {
	//現在のシーン
	Novice::ScreenPrintf(0, 0, "TitleScene");
	//操作方法
	Novice::ScreenPrintf(0, 20, "Press SPACE key to start");
}
