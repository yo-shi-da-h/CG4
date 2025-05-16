#pragma once

#include <KamataEngine.h>
#include <iostream>
using namespace KamataEngine;
class Effect {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="position">位置</param>
	/// <param name="velocity">移動量</param>
	void Initialize(Model* model,Vector3 position);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="camera">カメラ</param>
	void Draw(Camera& camera);

	bool IsFinished() {
		std::cout << "isFinished_:" << isFinished_ << std::endl;
		return isFinished_;
	}

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;

	ObjectColor objectColor_; //オブジェクトカラー

	Vector4 color_; //色の数値

	bool isFinished_ = false; //終了フラグ

	float counter_ = 0.0f; //カウンター

	const float kDuration = 1.0f; //時間の初期化
};