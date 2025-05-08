#include "GameScene.h"
#include "random"
using namespace KamataEngine;



GameScene::~GameScene()
{
	delete modelEffect_;
	delete effect_;
}

void GameScene::Initialize()
{

	std::random_device seedGenerator;
	std::mt19937 randomEngine(seedGenerator()); // メルセンヌツイスタの初期化
	std::uniform_real_distribution<float> distribution(1.0f, 2.0f); // -1.0から1.0の範囲で乱数を生成

	//3Dモデルデータの生成
	modelEffect_ = Model::CreateFromOBJ("hishigata",true);

	//カメラの初期化
	camera_.Initialize();

	//エフェクトの生成
	effect_ = new Effect();

	//エフェクトの初期化
	effect_->Initialize(modelEffect_);
}

void GameScene::Update()
{
	//エフェクトの更新
	effect_->Update();
}

void GameScene::Draw()
{
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//描画開始
	Model::PreDraw(dxCommon->GetCommandList());
	//エフェクトの描画
	effect_->Draw(camera_); //カメラを引数に渡す
	//描画終了
	Model::PostDraw();
}

