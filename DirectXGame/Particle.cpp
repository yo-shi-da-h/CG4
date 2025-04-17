#include "Particle.h"
#include <algorithm>
using namespace KamataEngine;
using namespace MathUtility;
Particle::~Particle()
{
}

void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity)
{
	assert(model);

	model_ = model; //3Dモデルデータの設定

	worldTransform_.Initialize(); //ワールド変形の初期化

	objectColor_.Initialize(); //オブジェクトカラーの初期化

	color_ = {1.0f, 1.0f, 0.0f, 1.0f}; //色の初期化

	worldTransform_.translation_ = position; //ワールド変形の位置を設定

	velocity_ = velocity; //速度の初期化

	//大きさ
	worldTransform_.scale_ = {0.5f, 0.5f, 0.5f}; 
}

void Particle::Update()
{

	if(isFinished_) {
		return; //終了フラグが立っている場合は何もしない
	}

	counter_ += 1.0f / 60.0f; //カウンターの更新

	if (counter_ >= kDuration) {
		counter_ = kDuration; 
		isFinished_ = true; //カウンターが指定時間を超えたら終了フラグを立てる
	}

	//移動
	worldTransform_.translation_ += velocity_; //移動量の設定
	
	//行列を更新
	worldTransform_.UpdateMatrix(); 

	objectColor_.SetColor(color_); //オブジェクトカラーの設定

	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f); //色の透明度を設定
}

void Particle::Draw(Camera& camera)
{
	model_->Draw(worldTransform_,camera, &objectColor_); //3Dモデルデータの描画
}
