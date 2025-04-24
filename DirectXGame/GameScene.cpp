#include "GameScene.h"

using namespace KamataEngine;



GameScene::~GameScene()
{
	delete modelEffect_;
	delete effect_;
}

void GameScene::Initialize()
{
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

