#pragma once
#include "jnsEntity.h"

namespace jns
{
	using namespace math;
	class GameObject : public Entity
	{
	public:
		struct mGameObjectStatus
		{
			float mScale;
			Vector2 mPos;
		};

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
		

		//------------------------------------------------
		void SetPos(Vector2 pos) { mStatus.mPos = pos; }
		void SetScale(float scale) { mStatus.mScale = scale; }
		void SetRGB(Vector3 rgb) { mRGB = rgb; }
		
		mGameObjectStatus GetStatus () { return mStatus; }
		Vector2 GetPos() { return mStatus.mPos; }

	public:
		void PipeLineRender();

	private:
		eState mState;
		mGameObjectStatus mStatus;
		Vector3 mRGB;

		//std::vector<Component*> mComponents;
	};

}
