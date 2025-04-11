#include <Windows.h>
#include "KamataEngine.h"
#include "GameScene.h"

using namespace KamataEngine;
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	KamataEngine::Initialize(L"LE3D_17_ヨシダ_ハルト_CG4");

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	GameScene* gameScene = new GameScene();

	gameScene->Initialize();

	while (true)
	{
		if (KamataEngine::Update()) {
			break;
		}
		

		gameScene->Update();

		//描画開始
	    dxCommon->PreDraw();

		gameScene->Draw();
	    
	    //描画終了
	    dxCommon->PostDraw();
	}

	delete gameScene;

	gameScene = nullptr;

	KamataEngine::Finalize();
	return 0;
}
