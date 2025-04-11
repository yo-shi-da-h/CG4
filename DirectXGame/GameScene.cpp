#include "GameScene.h"

using namespace KamataEngine;



GameScene::~GameScene()
{
	delete modelParticle_;
	delete particle_;	
}

void GameScene::Initialize()
{
	//3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4,4);

	//カメラの初期化
	camera_.Initialize();

	//パーティクルの生成
	particle_ = new Particle();

	//パーティクルの初期化
	particle_->Initialize(modelParticle_);
}

void GameScene::Update()
{
	//パーティクルの更新
	particle_->Update();
}

void GameScene::Draw()
{
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//描画開始
	Model::PreDraw(dxCommon->GetCommandList());
	//パーティクルの描画
	particle_->Draw(camera_); //カメラを引数に渡す
	//描画終了
	Model::PostDraw();
}

