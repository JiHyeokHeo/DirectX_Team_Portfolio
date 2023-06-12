#include "jnsScene.h"
#include "jnsRenderer.h"
#include "jnsTime.h"
#include <random>

//랜덤 실수 생성
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

	//세포들 간의 거리 측정
	float Scene::distance(const Vector2& a, const Vector2& b) {
		float dx = a.x - b.x;
		float dy = a.y - b.y;
		return std::sqrt(dx * dx + dy * dy);
	}

	//세포 생성
	void Scene::Instantiate_Cell(int n)
	{
		for (int i = 0; i < n; i++)
		{
			float random_X = dis1(gen);
			float random_Y = dis2(gen);

			color1 = dis3(gen);
			color2 = dis3(gen);
			color3 = dis3(gen);

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

	//죽은 세포 배열에서 삭제, 동적 해제
	void Scene::Destroy()
	{
		std::vector<GameObject>::iterator it;
		for (auto it = mGameObjects.begin(); it != mGameObjects.end();)
		{
			if ((*it)->radius == 0)
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
		player->set_Color(1.0, 1.0, 1.0);
		player->setType(GameObject::Type::Player);
		player->Initialize();

		enemy = new GameObject();
		enemy->set_Init_Pos(-300.0f, 550.0f);
		enemy->set_Radius(50.0f);
		enemy->setType(GameObject::Type::Enemy);
		enemy->Initialize();

		Instantiate_Cell(80);
	}

	void Scene::Update()
	{
		//죽은 세포가 50마리 쌓이면 Destroy
		if (dead_cell > 50)
		{
			Destroy();
			dead_cell = 0;
		}

		playTime += Time::DeltaTime();

		//6마다 생성
		if (playTime >= 6.0f && cell_num <= 150)
		{
			Instantiate_Cell(20);

			playTime = 0.0f;
		}

		player->Update();
		enemy->Update();

		Vector2 pPos = player->get_Pos();
		Vector2 ePos = enemy->get_Pos();

		float pRadius = player->radius;
		float eRadius = enemy->radius;

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();

			Vector2 oPos = gameObj->get_Pos();
			float oRadius = gameObj->radius;

			if (distance(pPos, oPos) < (pRadius + oRadius))
			{
				if (gameObj->radius != 0)
				{
					gameObj->set_Radius(0);
					cell_num -= 1;
					dead_cell++;
					player->radius+= 1.5f;
				}
			}
			if (distance(pPos, ePos) < (pRadius + eRadius))
			{
				if (pRadius >= eRadius)
				{
					player->radius += 0.0005f;
					enemy->radius -= 0.0005f;
				}
				else
				{
					player->radius -= 0.0005f;
					enemy->radius += 0.0005f;
				}
			}
			if (distance(ePos, oPos) < (eRadius + oRadius))
			{
				if (gameObj->radius != 0)
				{
					gameObj->set_Radius(0);
					cell_num -= 1;
					dead_cell++;
					enemy->radius += 2.0f;
				}
			}
		}
	}

	void Scene::LateUpdate()
	{
	
	}

	void Scene::Render()
	{
		enemy->Render();
		player->Render();

		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render();
		}
	}
}
