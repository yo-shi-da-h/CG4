#include "GameScene.h"

using namespace KamataEngine;



GameScene::~GameScene()
{
	delete modelParticle_;
	for(Particle* particle : particles_) {
		delete particle;
	}
}

void GameScene::Initialize()
{
	//3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4,4);

	//カメラの初期化
	camera_.Initialize();

	//パーティクルの生成
	for (int i = 0; i < 150; i++) {
		//生成
		Particle* particle = new Particle();
		//位置
		Vector3 position = {0.5f * i, 0.0f, 0.0f};
		//初期化
		particle->Initialize(modelParticle_, position);
		//リストに追加
		particles_.push_back(particle);
	}

	//Vector3 position = {0.0f, 0.0f, 0.0f}; //パーティクルの位置

	////パーティクルの初期化
	//particle_->Initialize(modelParticle_, {0.0f, 0.0f, 0.0f});
}

void GameScene::Update()
{
	//パーティクルの更新
	for(Particle* particle : particles_) {
		particle->Update();
	}
}

void GameScene::Draw()
{
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//描画開始
	Model::PreDraw(dxCommon->GetCommandList());
	//パーティクルの描画
	for (Particle* particle : particles_) {
		particle->Draw(camera_);
	}
	
	//描画終了
	Model::PostDraw();
}

