#pragma once
#include "jnsEntity.h"

namespace jns
{
	using namespace math;
	class GameObject : public Entity
	{
	public:
		enum eState
		{
			Active,
			Paused,
			Dead,
		};

		GameObject();
		virtual ~GameObject();
	
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		
	
	private:
		eState mState;
		//std::vector<Component*> mComponents;
		
	};

}
