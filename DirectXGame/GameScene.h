#pragma once
#include "KamataEngine.h"
#include "Effect.h"
using namespace KamataEngine;
class GameScene {

public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	~GameScene();

	/// <summary>
	/// パーティクル発生
	/// </summary>
	/// <param name="position">位置</param>
	//void ParticleBorn(Vector3 position);

	// パーティクル3Dモデルデータ
	//Model* modelParticle_ = nullptr;

	// エフェクト3Dモデルデータ
	Model* modelEffect_ = nullptr;

	// パーティクル
	//std::list<Particle*> particles_;

	// エフェクト
	std::list<Effect*> effects_;

	// カメラ
	Camera camera_;

};