#include "Particle.h"

using namespace KamataEngine;
Particle::~Particle()
{
}

void Particle::Initialize(Model* model)
{
	assert(model);

	model_ = model; //3Dモデルデータの設定

	worldTransform_.Initialize(); //ワールド変形の初期化

	//objectColor_.Initialize(); //オブジェクトカラーの初期化

	//color_ = {1.0f, 1.0f, 0.0f, 1.0f}; //色の初期化

	
}

void Particle::Update()
{
	worldTransform_.TransferMatrix(); //ワールド変形の更新

	//objectColor_.SetColor(color_); //オブジェクトカラーの設定
}

void Particle::Draw(Camera& camera)
{
	model_->Draw(worldTransform_,camera); //3Dモデルデータの描画
}
