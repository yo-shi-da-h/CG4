#pragma once
#include "KamataEngine.h"
using namespace KamataEngine;
class Particle
{
public:
	//デストラクタ
	~Particle();

	//初期化
	void Initialize(Model* model);

	//更新
	void Update();

	//描画
	void Draw(Camera& camera);
private:
	WorldTransform worldTransform_; //ワールド変形

	Model* model_ = nullptr; //3Dモデルデータ
};

