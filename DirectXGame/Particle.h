
#pragma once

#include <KamataEngine.h>
using namespace KamataEngine;
// パーティクル
class Particle {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="position">位置</param>
	/// <param name="velocity">移動量</param>
	void Initialize(Model* model, Vector3 position, Vector3 velocity);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="camera">カメラ</param>
	void Draw(Camera& camera);

	// デスフラグのgetter
	bool IsFinished() { return isFinished_;}

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;

	// 色変更オブジェクト
	ObjectColor objectcolor_;
	// 色の数値
	Vector4 color_;
	
	// 移動量
	Vector3 velocity_;

	// 終了フラグ
	bool isFinished_ = false;
	// 経過時間カウント
	float counter_ = 0.0f;
	// 存続時間(消滅までの時間)<秒>
	const float kDuration = 1.0f;
};
