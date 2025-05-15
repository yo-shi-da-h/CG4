#pragma once
#include "KamataEngine.h"
#include "Effect.h"
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
	//エフェクト3Dモデルデータ
	Model* modelEffect_ = nullptr;

	//カメラ
	Camera camera_ ;

	//エフェクト
	//Effect* effect_ = nullptr;

	std::list<Effect*> effects_; //エフェクトのリスト

};

