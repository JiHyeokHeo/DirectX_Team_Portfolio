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
		// 여기서 초기 게임 맵데이터를 세팅해줘야 한다.
		Player* mPlayer = new Player();
		mGameObjects.push_back(mPlayer);

		for (int i = 0; i < 100; i++)
		{
			Monster* mMonster = new Monster();
			mGameObjects.push_back(mMonster);
		}
		
		FindTarget(mPlayer);

	}
	void Scene::Update()
	{
		CollisionCheck(mTarget);
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

	void Scene::CollisionCheck(GameObject* Target)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj->GetName() == L"Player")
				continue;
			
			InterSect(Target, gameObj);
		}
	}

	void Scene::InterSect(GameObject* Target, GameObject* CheckList)
	{
		Vector2 mTargetDistance = Target->GetPos();
		Vector2 mCheckList = CheckList->GetPos();

		Vector2 monsterDistanceBetween = mTargetDistance - mCheckList;

		//labs();
		
	}

}