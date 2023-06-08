#include "jnsScene.h"
#include "jnsPlayer.h"
#include "jnsTime.h"
#include "jnsMonster.h"

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
		// ���⼭ �ʱ� ���� �ʵ����͸� ��������� �Ѵ�.
		Player* mPlayer = new Player();
		mGameObjects.push_back(mPlayer);

		Monster* mMonster = new Monster();
		mGameObjects.push_back(mMonster);
		

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