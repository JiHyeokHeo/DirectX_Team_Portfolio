#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
	private:

	};
}
