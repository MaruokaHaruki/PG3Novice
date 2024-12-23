/*********************************************************************
 * \file   StageScene.h
 * \brief  
 * 
 * \author Harukichimaru
 * \date   December 2024
 * \note   
 *********************************************************************/
#pragma once
#include "IScene.h"
#include "Novice.h"

//Vector2構造体
struct Vector2 {
	float x;
	float y;
};

///=============================================================================
///						ステージシーン
class StageScene : public IScene {
	///--------------------------------------------------------------
	///						 メンバ関数
public:
	// \brief 初期化
	void Initialize() override;
	// \brief 更新
	void Update() override;
	// \brief 描画
	void Draw() override;

	///--------------------------------------------------------------
	///						 メンバ変数
private:
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//========================================
	// 移動制限
	float moveLimitUp;
	float moveLimitDown;
	float moveLimitLeft;
	float moveLimitRight;


	//========================================
	// プレイヤー
	// 位置
	Vector2 playerPos;
	// 移動速度
	float playerSpeed;
	// プレイヤーのサイズ
	Vector2 playerSize;
	// プレイヤーの色
	unsigned int playerColor;
	//弾の発射
	bool isShot = false;

	//========================================
	// エネミー
	// 位置
	Vector2 enemyPos;
	// 移動速度
	float enemySpeed;
	// エネミーのサイズ
	Vector2 enemySize;
	// エネミーの色
	unsigned int enemyColor;

	//========================================
	// 弾
	// 位置
	Vector2 bulletPos;
	// 移動速度
	float bulletSpeed;
	// 弾のサイズ
	Vector2 bulletSize;
	// 弾の色
	unsigned int bulletColor;

};


