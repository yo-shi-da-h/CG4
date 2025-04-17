#pragma once
#include "KamataEngine.h"
using namespace KamataEngine;
class Particle
{
public:
	//デストラクタ
	~Particle();

	//初期化
	void Initialize(Model* model,Vector3 position, Vector3 velocity);

	//更新
	void Update();

	//描画
	void Draw(Camera& camera);
private:
	WorldTransform worldTransform_; //ワールド変形

	Model* model_ = nullptr; //3Dモデルデータ

	ObjectColor objectColor_; //オブジェクトカラー

	Vector4 color_; //色の数値

	Vector3 velocity_ ; //速度の初期化
};

