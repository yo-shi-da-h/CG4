#include "Particle.h"

using namespace KamataEngine;
using namespace MathUtility;
Particle::~Particle()
{
}

void Particle::Initialize(Model* model)
{
	assert(model);

	model_ = model; //3Dモデルデータの設定

	worldTransform_.Initialize(); //ワールド変形の初期化

	objectColor_.Initialize(); //オブジェクトカラーの初期化

	color_ = {1.0f, 1.0f, 0.0f, 1.0f}; //色の初期化
}

void Particle::Update()
{
	//移動
	worldTransform_.translation_ += {0.0f, 0.1f, 0.0f}; //移動量の設定
	
	//行列を更新
	worldTransform_.UpdateMatrix(); 

	objectColor_.SetColor(color_); //オブジェクトカラーの設定
}

void Particle::Draw(Camera& camera)
{
	model_->Draw(worldTransform_,camera, &objectColor_); //3Dモデルデータの描画
}
