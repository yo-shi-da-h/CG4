#pragma once
#include "KamataEngine.h"
#include "Particle.h"
using namespace KamataEngine;
class GameScene
{
public:
	
	//デストラクタ
	~GameScene(); 

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

	//パーティクル
	std::list<Particle*> particles_;

};

