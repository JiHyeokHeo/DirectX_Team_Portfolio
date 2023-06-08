#include "jnsScene.h"


namespace jns
{
	Scene::Scene()
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
		// 여기서 초기 게임 맵데이터를 세팅해줘야 한다.
		GameObject* mGameObject = new GameObject();
		mGameObject->SetPos(Vector2(-0.1f, -0.1f));
		GameObject* mGameObject2 = new GameObject();
		mGameObjects.push_back(mGameObject);
		mGameObjects.push_back(mGameObject2);
	}
	void Scene::Update()
	{

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}
	}
	void Scene::LateUpdate()
	{
	}
	void Scene::Render()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render();
		}
	}
}