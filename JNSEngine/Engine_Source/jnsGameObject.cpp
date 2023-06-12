#include "jnsGameObject.h"
#include "jnsRenderer.h"
#include "jnsGraphicDevice_Dx11.h"
#include "jnsInput.h"
#include "jnsTime.h"

namespace jns
{
	GameObject::GameObject()
		: mState(eState::Active),
		radius(20.0f)
	{
		randDir = 0;
	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Initialize()
	{
		//정점들의 정보를 정해주고 버퍼, 쉐이더, 인풋 레이아웃 생성 
		renderer::Initialize();
	}

	void GameObject::Update()
	{
		switch (G_Type)
		{
			case(GameObject::Type::Player):
			{
				Move();
			}
			break;
			case(GameObject::Type::Enemy):
			{
				Roam();
			}
			break;
		}

		Pos = Vector2(startX + moveX, startY + moveY);
	}

	void GameObject::Roam()
	{
		if (Pos.x < -750 || Pos.x > 750 || Pos.y < - 400 || Pos.y > 400)
		{
			Pos = prevPos;
			randDir = rand() % 8;
		}
		else
		{
			prevPos = Pos;
		}

		switch (randDir)
		{
			case 0:
			{
				moveY -= 75.0f * Time::DeltaTime();
			} break;
			case 1:
			{
				moveY += 50.0f * Time::DeltaTime();
				moveX -= 50.0f * Time::DeltaTime();
			} break;
			case 2:
			{
				moveY += 75.0f * Time::DeltaTime();
			} break;
			case 3:
			{
				moveY -= 50.0f * Time::DeltaTime();
				moveX -= 50.0f * Time::DeltaTime();
			} break;
			case 4:
			{
				moveX += 75.0f * Time::DeltaTime();
			} break;
			case 5:
			{
				moveY += 50.0f * Time::DeltaTime();
				moveX += 50.0f * Time::DeltaTime();
			} break;
			case 6:
			{
				moveX -= 75.0f * Time::DeltaTime();
			} break;
			case 7:
			{
				moveY -= 50.0f * Time::DeltaTime();
				moveX += 50.0f * Time::DeltaTime();
			} break;
		}
	}
	void GameObject::Move()
	{
		if (Input::GetKey(eKeyCode::W))
		{
			moveY += 200.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			moveX += 200.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			moveX -= 200.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			moveY -= 200.0f * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render()
	{
		//상수버퍼로 위치정보 크기정보, 색깔, 업데이트 해줘야한다.

		object_status.Pos = Vector4(startX + moveX, startY + moveY, 0.0f, 0.0f);
		object_status.Size = Vector4(radius, radius, 0.0f, 0.0f);

		Vector4 color(color1,color2,color3, 1.0f);

		renderer::constantBuffers[0]->SetData(&object_status);
		renderer::constantBuffers[0]->Bind(eShaderStage::VS);

		renderer::constantBuffers[1]->SetData(&color);
		renderer::constantBuffers[1]->Bind(eShaderStage::VS);

		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
}
