#include "jnsGameObject.h"
#include "jnsRenderer.h"
#include "jnsGraphicDevice_Dx11.h"
#include "jnsInput.h"
#include <random>

namespace jns
{
	GameObject::GameObject()
		: mState(eState::Active),
		radius(20.0f)
	{
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
			case(GameObject::Type::Cell):
			{

			}
			break;
		}

		Pos = Vector2(startX + moveX, startY + moveY);
	}

	void GameObject::Move()
	{
		if (Input::GetKey(eKeyCode::W))
		{
			moveY += 1.5f;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			moveX += 1.5f;
		}
		if (Input::GetKey(eKeyCode::A))
		{
			moveX -= 1.5f;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			moveY -= 1.5f;
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
