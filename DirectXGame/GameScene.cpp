#include "GameScene.h"



using namespace KamataEngine;
using namespace MathUtility;

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

void GameScene::Initialize() {
	// 3Dモデルデータの生成
	//modelEffect_ = Model::CreateSphere(2, 2);
	modelEffect_ = Model::CreateFromOBJ("diamond", true);

	// カメラの初期化
	camera_.Initialize();

	// エフェクトの生成
	for (int i = 0; i < 10; i++) {
		// 生成
		Effect* effect = new Effect();
		// 位置
		Vector3 position = {0.0f,0.0f,0.0f};
		
		// 初期化
		effect->Initialize(modelEffect_,position);
		// リストに追加
		effects_.push_back(effect);
	}

	// 乱数の初期化
	srand((unsigned)time(NULL));
}

void GameScene::Update() { 
	// 確率で発生
	//if (rand() % 20 == 0) {
	//	// 発生位置は乱数
	//	Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};

	//	// パーティクル発生
	//	ParticleBorn(position);
	//}

	// パーティクルの更新
	/*for(Particle* particle : particles_){
		particle->Update();
	}*/

	// 終了フラグの立ったパーティクルを削除
	/*particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()) {
			delete particle;
			return true;
		}
		return false;
	});*/

	// エフェクトの更新
	for(Effect* effect : effects_){
		effect->Update();
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