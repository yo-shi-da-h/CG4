#pragma once
#include "KamataEngine.h"
#include <iostream>

class Particle
{
public:
	//デストラクタ
	~Particle();

	//初期化
	void Initialize(KamataEngine::Model* model,KamataEngine::Vector3 position, KamataEngine::Vector3 velocity);

	//更新
	void Update();

	//描画
	void Draw(KamataEngine::Camera& camera);

	bool IsFinished() {
		std::cout << "isFinished_:" << isFinished_ << std::endl;
		return isFinished_;
	}
private:
	KamataEngine::WorldTransform worldTransform_; //ワールド変形

	KamataEngine::Model* model_ = nullptr; //3Dモデルデータ

	KamataEngine::ObjectColor objectColor_; //オブジェクトカラー

	KamataEngine::Vector4 color_; //色の数値

	KamataEngine::Vector3 velocity_ ; //速度の初期化

	bool isFinished_ = false; //終了フラグ

	float counter_ = 0.0f; //カウンター

	const float kDuration = 1.0f; //時間の初期化
};

