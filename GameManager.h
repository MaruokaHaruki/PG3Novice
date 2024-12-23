/*********************************************************************
 * \file   GameManager.h
 * \brief  
 * 
 * \author Harukichimaru
 * \date   December 2024
 * \note   
 *********************************************************************/
#pragma once
#include <memory>
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"

///=============================================================================
///						ゲームマネージャー
class GameManager {
	///--------------------------------------------------------------
	///							メンバ関数
public:

	// \brief コンストラクタ
	GameManager();
	// \brief デストラクタ
	~GameManager();

	// ゲームループを呼び出す
	int Run();

	///--------------------------------------------------------------
	///							メンバ変数
private:
	/// @brief シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArray_[3];

	/// @brief 現在のシーン
	int currentSceneNo_;
	/// @brief 前のシーン
	int prevSceneNo_;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
};

