#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class Monster : public GameObject
	{
	public:
		Monster();
		~Monster();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		Vector2 mMonsterPos;
		Vector3 mRGB;
		int mMonsterScale;
	};
}
