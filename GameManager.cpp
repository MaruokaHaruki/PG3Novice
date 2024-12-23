/*********************************************************************
 * \file   GameManager.cpp
 * \brief  
 * 
 * \author Harukichimaru
 * \date   December 2024
 * \note   
 *********************************************************************/
#include "GameManager.h"
#include "Novice.h"

///=============================================================================
///						コンストラクタ
GameManager::GameManager() {
	// シーンの生成
	sceneArray_[TITLE] = std::make_unique<TitleScene>();
	sceneArray_[GAME] = std::make_unique<StageScene>();
	sceneArray_[CLEAR] = std::make_unique<ClearScene>();
	// シーンの初期化
	for(int i = 0; i < 3; i++) {
		sceneArray_[i]->Initialize();
	}
	// シーンの初期設定
	currentSceneNo_ = 0;
	prevSceneNo_ = -1;
}

///=============================================================================
///						デストラクタ
GameManager::~GameManager() {
}

///=============================================================================
///						どのシーンを呼び出すか
int GameManager::Run() {
	//========================================
	// ゲームループ
	while(Novice::ProcessMessage() == 0) {
		//---------------------------------------
		// フレームの開始
		Novice::BeginFrame();

		//---------------------------------------
		// シーンのチェック
		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArray_[currentSceneNo_]->GetSceneNo();

		//---------------------------------------
		// シーンの変更チェック
		if(prevSceneNo_ != currentSceneNo_) {
			sceneArray_[currentSceneNo_]->Initialize();
		}

		//---------------------------------------
		// 更新処理
		sceneArray_[currentSceneNo_]->Update();

		//---------------------------------------
		// 描画処理
		sceneArray_[currentSceneNo_]->Draw();

		//---------------------------------------
		// フレームの終了
		Novice::EndFrame();

		//---------------------------------------
		// ESCキーで終了
		if(Novice::CheckHitKey(DIK_ESCAPE)) {
			break;
		}
	}
	//========================================
	// 終了
	return 0;
}
