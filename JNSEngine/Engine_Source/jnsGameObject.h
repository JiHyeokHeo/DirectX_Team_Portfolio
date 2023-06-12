#pragma once
#include "jnsEntity.h"
#include "jnsComponent.h"

#include "jnsMesh.h"
#include "jnsShader.h"
#include "jnsConstantBuffer.h"

using namespace jns::math;

namespace jns
{
	class GameObject : public Entity
	{
	public:
		enum eState
		{
			Active,
			Paused,
			Dead,
		};

		enum Type
		{
			Player,
			Enemy,
			Cell,
			None,
		};

		struct Tr_status
		{
			Vector4 Pos;
			Vector4 Size;
		};

		Tr_status object_status;

		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		void Move();
		void Roam();

		Type G_Type;

		void setType(enum Type type)
		{
			G_Type = type;
		}

		Type getType()
		{
			return G_Type;
		}

		void set_Init_Pos(float y, float x)
		{
			startY = y;
			startX = x;
		}
		void set_Radius(float r)
		{
			radius = r;
		}
		Vector2 get_Pos()
		{
			return Pos;
		}

		void set_Color(float a, float b, float c)
		{
			color1 = a;
			color2 = b;
			color3 = c;
		}

		float radius;
	private:
		eState mState;
		//std::vector<Component*> mComponents;

		float moveY = 0.0f;
		float moveX = 0.0f;

		float startY = 0.0f;
		float startX = 0.0f;;

		float color1;
		float color2;
		float color3;

		Vector2 Pos;
		Vector2 prevPos;

		int randDir;
	};
}
