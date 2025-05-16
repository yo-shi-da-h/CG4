#include "Effect.h"
#include <random>
#include <algorithm>
using namespace KamataEngine;



void Effect::Initialize(Model* model,Vector3 position) {
	// NULLポインタチェック
	assert(model);
    model_ = model;
    worldTransform_.Initialize();

    objectColor_.Initialize(); //オブジェクトカラーの初期化

    color_ = {1.0f, 1.0f, 1.0f, 1.0f}; //色の初期化

    std::random_device seedGenerator;
    std::mt19937 randomEngine(seedGenerator());
    std::uniform_real_distribution<float> distributo(0.0f, 10.0f);


    // 大きさ（スケール）のY軸を変更（例：3倍）
    worldTransform_.scale_ = {1.0f, distributo(randomEngine), 1.0f};

    // 回転（Z軸）を30度に設定（度→ラジアンに変換）
    worldTransform_.rotation_ = {
       0.0f,                              // X軸
       0.0f,                              // Y軸
        distributo(randomEngine) // Z軸
    };

    worldTransform_.translation_ = position;
}

void Effect::Update() {

    if(isFinished_) {
		return; //終了フラグが立っている場合は何もしない
	}

	counter_ += 1.0f / 60.0f; //カウンターの更新

	if (counter_ >= kDuration) {
		counter_ = kDuration; 
		isFinished_ = true; //カウンターが指定時間を超えたら終了フラグを立てる
	}
	// 行列を更新
    worldTransform_.TransferMatrix();
	worldTransform_.UpdateMatrix();

    objectColor_.SetColor(color_); //オブジェクトカラーの設定

	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f); //色の透明度を設定
}

void Effect::Draw(Camera& camera) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera ,&objectColor_);
}


