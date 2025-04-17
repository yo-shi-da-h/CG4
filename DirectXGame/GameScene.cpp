#include "GameScene.h"
#include "random"
using namespace KamataEngine;
using namespace MathUtility;


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

	std::random_device seedGenerator;
	std::mt19937 randomEngine(seedGenerator());
	std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

	//パーティクルの生成
	for (int i = 0; i < 150; i++) {
		//生成
		Particle* particle = new Particle();
		//位置
		Vector3 position = {0.0f, 0.0f, 0.0f};
		//移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine),0};
		//初期化
		particle->Initialize(modelParticle_, position,velocity );
		//リストに追加
		particles_.push_back(particle);

		Normalize(velocity); //ベクトルの正規化
		velocity *= distribution(randomEngine); //速度の設定
		velocity *= 0.1f; //速度のスケーリング
	}
	
}

void GameScene::Update()
{
	//パーティクルの更新
	for(Particle* particle : particles_) {
		particle->Update();
	}

	particles_.remove_if([](Particle* particle) {
		if(particle->IsFinished()) {
			delete particle; //終了したパーティクルを削除
			return true; //リストから削除する
		}
		return false; //リストに残す
	});
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

