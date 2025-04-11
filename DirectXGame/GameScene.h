#pragma once
#include "KamataEngine.h"
using namespace KamataEngine;
class GameScene
{
public:
	
	//初期化
	void Initialize();

	//更新
	void Update();

	//描画
	void Draw();

private:
	//パーティクル3Dモデルデータ
	Model* modelParticle_ = nullptr;

	//カメラ
	Camera camera_ ;

};

