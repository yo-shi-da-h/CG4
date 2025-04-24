#include "Effect.h"

Effect::~Effect()
{
}

void Effect::Initialize(Model* model)
{
	assert(model);

	model_ = model; //3Dモデルデータの設定

	worldTransform_.Initialize(); //ワールド変形の初期化
}

void Effect::Update()
{
	worldTransform_.TransferMatrix(); //ワールド変形の更新
}

void Effect::Draw(Camera& camera)
{
	model_->Draw(worldTransform_,camera); //3Dモデルデータの描画
}
