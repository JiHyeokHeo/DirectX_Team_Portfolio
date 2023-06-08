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
		
		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }

		void SetRGB(Vector3 rgb) { mRGB = rgb; }
	private:
		eState mState;
		//std::vector<Component*> mComponents;
		Vector2 mPos;
		Vector3 mRGB;
	};

}
