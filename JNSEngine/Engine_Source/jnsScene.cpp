#include "jnsScene.h"
#include "jnsRenderer.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> dis1(-700.f, 700.f);
std::uniform_real_distribution<float> dis2(-400.f, 400.f);
std::uniform_real_distribution<float> dis3(0.f, 1.f);

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
		player = new GameObject();
		player->Initialize();
		player->setType(GameObject::Type::Player);

		mGameObjects.push_back(player);
		
		for (int i = 0; i < 50; i++)
		{
			float random_X = dis1(gen);
			float random_Y = dis2(gen);

			float color1 = dis3(gen);
			float color2 = dis3(gen);
			float color3 = dis3(gen);

			GameObject* player = new GameObject();
			player->setType(GameObject::Type::Player);
			player->set_Init_Pos(random_Y, random_X);
			player->set_Color(color1, color2, color3);
			player->Initialize();
			//mGameObjects.push_back(player);

			GameObject* object = new GameObject();
			object->setType(GameObject::Type::obstacle);
			object->set_Init_Pos(random_Y, random_X);
			object->set_Color(color1, color2, color3);
			object->Initialize();
			mGameObjects.push_back(object);
		}
	}

	void Scene::Update()
	{
		player->Update();

		//각 게임오브젝트 별로 위치 정보 입력
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
		player->Render();

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render();
		}
	}
}
