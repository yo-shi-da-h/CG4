#include "Effect.h"

Effect::~Effect()
{
}

void Effect::Initialize(Model* model, Vector3 position)
{
	assert(model);

	model_ = model; //3Dモデルデータの設定

	worldTransform_.Initialize(); //ワールド変形の初期化

	worldTransform_.translation_ = position; //ワールド変形の位置の特定

	worldTransform_.scale_ = {1.0f, 1.0f, 1.0f}; //大きさ
}

void Effect::Update()
{
	worldTransform_.TransferMatrix(); //ワールド変形の更新
}

void Effect::Draw(Camera& camera)
{
	model_->Draw(worldTransform_,camera); //3Dモデルデータの描画
}
