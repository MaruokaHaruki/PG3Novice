/*********************************************************************
 * \file   StageScene.cpp
 * \brief
 *
 * \author Harukichimaru
 * \date   December 2024
 * \note
 *********************************************************************/
#include "StageScene.h"
#include "Novice.h"

///=============================================================================
///						初期化
void StageScene::Initialize() {
	//========================================
	// 移動制限
	moveLimitUp = 0;
	moveLimitDown = 720;
	moveLimitLeft = 0;
	moveLimitRight = 1280;

	//========================================
	// プレイヤー
	// 位置
	playerPos = { 500, 600 };
	// 移動速度
	playerSpeed = 5.0f;
	// プレイヤーのサイズ
	playerSize = { 50, 50 };
	// プレイヤーの色
	playerColor = BLUE;
	//========================================
	// エネミー
	// 位置
	enemyPos = { 500, 200 };
	// 移動速度
	enemySpeed = 3.0f;
	// エネミーのサイズ
	enemySize = { 100, 100 };
	// エネミーの色
	enemyColor = RED;
	//========================================
	// 弾
	// 位置
	bulletPos = { 0, 0 };
	// 移動速度
	bulletSpeed = 10.0f;
	// 弾のサイズ
	bulletSize = { 10, 10 };
	// 弾の色
	bulletColor = WHITE;
}

///=============================================================================
///						更新
// NOTE:見やすいベタ書きを意識する(そもそもベタ書きは見にくい)
// NOTE:昔のメモを見直せ。ここで役に立つぞ。
void StageScene::Update() {
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	//========================================
	//プレイヤーの移動
	if(keys[DIK_W] != 0) {
		//上
		playerPos.y -= playerSpeed;
	}
	if(keys[DIK_S] != 0) {
		//下
		playerPos.y += playerSpeed;
	}
	if(keys[DIK_A] != 0) {
		//左
		playerPos.x -= playerSpeed;
	}
	if(keys[DIK_D] != 0) {
		//右
		playerPos.x += playerSpeed;
	}

	//========================================
	//エネミーの移動
	//壁に当たるまで移動し、壁に当たったら逆方向に移動する
	if(enemyPos.x < moveLimitLeft || enemyPos.x + enemySize.x > moveLimitRight) {
		enemySpeed *= -1;
	}
	//移動
	enemyPos.x += enemySpeed;

	//========================================
	//弾の移動
	//SPACEキーが押された瞬間
	if(keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0 && isShot == false) {
		//弾を発射
		bulletPos = playerPos;
		isShot = true;
	}
	if(isShot) {
		//弾が画面外に出たら弾を消す
		if(bulletPos.y < moveLimitUp) {
			isShot = false;
		}
		//移動
		bulletPos.y -= bulletSpeed;
	}

	//========================================
	//当たり判定
	//プレイヤーとエネミー
	if(playerPos.x < enemyPos.x + enemySize.x &&
		playerPos.x + playerSize.x > enemyPos.x &&
		playerPos.y < enemyPos.y + enemySize.y &&
		playerPos.y + playerSize.y > enemyPos.y) {
		//当たったらゲームオーバー
		sceneNo = TITLE;
	}
	//エネミーと弾
	if(bulletPos.x < enemyPos.x + enemySize.x &&
		bulletPos.x + bulletSize.x > enemyPos.x &&
		bulletPos.y < enemyPos.y + enemySize.y &&
		bulletPos.y + bulletSize.y > enemyPos.y) {
		//当たったらクリア
		sceneNo = CLEAR;
	}

	//SPACEキーが押された瞬間
	if(keys[DIK_NEXT] != 0 && preKeys[DIK_NEXT] == 0) {
		//次のシーンへ
		sceneNo = CLEAR;
	}
}

///=============================================================================
///						描画
void StageScene::Draw() {
	//現在のシーン
	Novice::ScreenPrintf(0, 0, "StageScene");
	//操作方法
	Novice::ScreenPrintf(0, 20, "W:UP S:DOWN A:LEFT D:RIGHT SPACE:SHOT NEXT:Clear");

	//========================================
	// プレイヤー
	Novice::DrawBox(
		(int)playerPos.x, (int)playerPos.y,
		(int)playerSize.x, (int)playerSize.y,
		0.0f,
		playerColor, kFillModeSolid);

	//========================================
	// エネミー
	Novice::DrawBox(
		(int)enemyPos.x, (int)enemyPos.y,
		(int)enemySize.x, (int)enemySize.y,
		0.0f,
		enemyColor, kFillModeSolid);

	//========================================
	// 弾
	Novice::DrawBox(
		(int)bulletPos.x, (int)bulletPos.y,
		(int)bulletSize.x, (int)bulletSize.y,
		0.0f,
		bulletColor, kFillModeSolid);
}
