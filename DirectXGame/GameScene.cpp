#include "GameScene.h"
#include "random"


using namespace KamataEngine;
using namespace MathUtility;
std::random_device seedGenerator;
    std::mt19937 randomEngine(seedGenerator());
    std::uniform_real_distribution<float> distributo(-1.0f, 1.0f);
GameScene::~GameScene() {
	// 3Dモデルデータの解放
	//delete modelParticle_;
	delete modelEffect_;

	//// パーティクルの解放
	//for (Particle* particle : particles_) {
	//	delete particle;
	//}
	//particles_.clear();

	// エフェクトの解放
	for(Effect* effect : effects_){
		delete effect;
	}
	effects_.clear();
}

//void GameScene::ParticleBorn(Vector3 position) {
//	// パーティクルの生成
//	for (int i = 0; i < 150; i++) {
//		// 生成
//		Particle* particle = new Particle();
//		// 位置
//		Vector3 position_ = position;
//
//		// 移動量
//		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
//		Normalize(velocity);
//		velocity *= distribution(randomEngine);
//		velocity *= 0.1f;
//
//		// 初期化
//		particle->Initialize(modelParticle_, position_, velocity);
//		// リストに追加
//		particles_.push_back(particle);
//	}
//}

void GameScene::EffectBorn(Vector3 position) {
	// エフェクトの生成
	for (int i = 0; i < 10; i++) {
		// 生成
		Effect* effect = new Effect();
		// 位置
		Vector3 position_ = {0.0f,0.0f,0.0f};

		position_ = position;
		
		// 初期化
		effect->Initialize(modelEffect_,position);
		// リストに追加
		effects_.push_back(effect);
	}
	// 乱数の初期化
	srand((unsigned)time(NULL));
}

void GameScene::Initialize() {
	// 3Dモデルデータの生成
	//modelEffect_ = Model::CreateSphere(2, 2);
	modelEffect_ = Model::CreateFromOBJ("diamond", true);

	// カメラの初期化
	camera_.Initialize();
	
	
}

void GameScene::Update() { 
	

	// エフェクトの更新
	for(Effect* effect : effects_){
		effect->Update();
	}

	effects_.remove_if([](Effect* efffect) {
		if(efffect->IsFinished()) {
			delete efffect; //終了したパーティクルを削除
			return true; //リストから削除する
		}
		return false; //リストに残す
	});

	if (rand() % 10 == 0) {
		Vector3 position = {distributo(randomEngine)* 30.0f, distributo(randomEngine)*2.0f, 0};
	    EffectBorn(position); //パーティクルの発生

	}
	

	
}

void GameScene::Draw() {
	// DirectXCommon インスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// パーティクルの描画
	/*for (Particle* particle : particles_) {
		particle->Draw(camera_);
	}*/

	// エフェクトの描画
	for(Effect* effect : effects_){
		effect->Draw(camera_);
	}

	// 3Dモデル描画後処理
	Model::PostDraw();
}

