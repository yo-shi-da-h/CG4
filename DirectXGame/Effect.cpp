#include "Effect.h"

Effect::~Effect()
{
}

void Effect::Initialize(Model* model, Vector3 Scale, Vector3 Rotate)
{
	assert(model);

	model_ = model; //3Dモデルデータの設定

	worldTransform_.Initialize(); //ワールド変形の初期化

	worldTransform_.rotation_ = Rotate; //回転

	worldTransform_.scale_ = Scale; //大きさ
}

void Effect::Update()
{
	worldTransform_.UpdateMatrix(); //ワールド変形の更新
}

void Effect::Draw(Camera& camera)
{
	model_->Draw(worldTransform_,camera); //3Dモデルデータの描画
}
