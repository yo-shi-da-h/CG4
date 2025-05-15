#include "GameScene.h"
#include "random"
using namespace KamataEngine;
using namespace MathUtility;


GameScene::~GameScene()
{
	delete modelEffect_;
	for (Effect* effect : effects_) {
		delete effect; //エフェクトの解放
	}
	effects_.clear(); //エフェクトのリストをクリア
}

void GameScene::Initialize()
{
	//3Dモデルデータの生成
	modelEffect_ = Model::CreateFromOBJ("hishigata", true);
	//modelEffect_ = Model::CreateSphere(2,2);
	//カメラの初期化
	camera_.Initialize();

	std::random_device seedGenerator;
	std::mt19937 randomEngine(seedGenerator()); // メルセンヌツイスタの初期化
	std::uniform_real_distribution<float> distribution(0.0f, 2.0f); // 0.0から2.0の範囲で乱数を生成
	std::uniform_real_distribution<float> rotate(-3.0f, 3.0f); // -3.0から3.0の範囲で乱数を生成

	for(int i = 0; i < 100; i++) {
		//エフェクトの生成
	    Effect* effect = new Effect();

		Vector3 scale = { 1.0f, distribution(randomEngine) * 10, 1.0f };

	    Vector3 rotation = {0.0f, 0.0f, rotate(randomEngine)};
		//エフェクトの初期化
	    effect->Initialize(modelEffect_, scale,rotation); //3Dモデルデータと位置を指定

		effects_.push_back(new Effect());
	}


	srand((unsigned)time(NULL)); // 乱数の初期化
}

void GameScene::Update()
{
	//エフェクトの更新
	for (Effect* effect : effects_) {
		effect->Update();
	}
}

void GameScene::Draw()
{
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//描画開始
	Model::PreDraw(dxCommon->GetCommandList());
	//エフェクトの描画
	for (Effect* effect : effects_) {
		effect->Draw(camera_); //カメラを引数に渡す
	}
	//描画終了
	Model::PostDraw();
}

