#pragma once
#include "jnsEntity.h"
#include "jnsGameObject.h"

namespace jns
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		float distance(const Vector2& a, const Vector2& b);

		void Instantiate_Cell(int n);

		void Destroy();

	private:
		std::vector<GameObject*> mGameObjects;

		GameObject* player;
		GameObject* enemy;

		int dead_cell = 0; // 죽은 세포 체크
		int cell_num;
		float playTime;

		float color1;
		float color2;
		float color3;
	};
}
