/*********************************************************************
 * \file   TitleScene.h
 * \brief  
 * 
 * \author Harukichimaru
 * \date   December 2024
 * \note   
 *********************************************************************/
#pragma once
#include "IScene.h"

///=============================================================================
///						タイトルシーン
class TitleScene : public IScene {
	///--------------------------------------------------------------
	///						 メンバ関数
public:
	// \brief 初期化
	void Initialize() override;
	// \brief 更新
	void Update() override;
	// \brief 描画
	void Draw() override;
private:
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
};

