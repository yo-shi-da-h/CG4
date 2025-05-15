#include "Effect.h"
#include <random>
using namespace KamataEngine;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distributo(0.0f, 10.0f);


void Effect::Initialize(Model* model,Vector3 position) {
	// NULLポインタチェック
	assert(model);
    model_ = model;
    worldTransform_.Initialize();

    

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
	// 行列を更新
    worldTransform_.TransferMatrix();
	worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera& camera) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera);
}