#include "jnsScene.h"
#include "jnsRenderer.h"
#include "jnsTime.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> dis1(-750.f, 750.f);
std::uniform_real_distribution<float> dis2(-420.f, 420.f);
std::uniform_real_distribution<float> dis3(0.f, 1.f);


namespace jns
{
	Scene::Scene()
	{
		playTime = 0.0f;

		cell_num = 0;
	}
	Scene::~Scene()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			delete gameObj;
		}
	}

	float Scene::distance(const Vector2& a, const Vector2& b) {
		float dx = a.x - b.x;
		float dy = a.y - b.y;
		return std::sqrt(dx * dx + dy * dy);
	}

	void Scene::Instantiate_Cell(int n)
	{
		for (int i = 0; i < n; i++)
		{
			float random_X = dis1(gen);
			float random_Y = dis2(gen);

			float color1 = dis3(gen);
			float color2 = dis3(gen);
			float color3 = dis3(gen);

			GameObject* object = new GameObject();
			object->setType(GameObject::Type::Cell);
			object->set_Radius(20.0f);
			object->set_Init_Pos(random_Y, random_X);
			object->set_Color(color1, color2, color3);
			object->Initialize();
			mGameObjects.push_back(object);

			cell_num += 1;
		}
	}
	void Scene::Destroy()
	{
		std::vector<GameObject>::iterator it;
		for (auto it = mGameObjects.begin(); it != mGameObjects.end();)
		{
			if ((*it)->get_Radius() == 0)
			{
				delete* it;
				it = mGameObjects.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
	void Scene::Initialize()
	{
		player = new GameObject();
		player->set_Init_Pos(300.0f, -550.0f);
		player->set_Radius(50.0f);
		player->setType(GameObject::Type::Player);
		player->Initialize();
		
		Instantiate_Cell(80);
	}

	void Scene::Update()
	{
		if (death > 50)
		{
			Destroy();
			death = 0;
		}

		playTime += Time::DeltaTime();

		if (playTime >= 6.0f && cell_num <= 150)
		{
			Instantiate_Cell(20);

			playTime = 0.0f;
		}

		player->Update();
		Vector2 pPos = player->get_Pos();
		float pRadius = player->get_Radius();

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();

			Vector2 oPos = gameObj->get_Pos();
			float oRadius = gameObj->get_Radius();

			if (distance(pPos, oPos) < (pRadius + oRadius))
			{
				if (gameObj->get_Radius() != 0)
				{
					gameObj->set_Radius(0);
					cell_num -= 1;
					death++;
					player->Radius_up(1.5f);
				}
			}
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
