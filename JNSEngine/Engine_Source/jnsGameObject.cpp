#include "jnsGameObject.h"
#include "jnsRenderer.h"
#include "jnsGraphicDevice_Dx11.h"
#include "jnsInput.h"
#include <random>

namespace jns
{
	GameObject::GameObject()
		: mState(eState::Active)
	{
	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Initialize()
	{
		//�������� ������ �����ְ� ����, ���̴�, ��ǲ ���̾ƿ� ���� 
		renderer::Initialize();
	}

	void GameObject::Update()
	{
		switch (G_Type)
		{
			case(GameObject::Type::Player):
			{
				Move();

				startY = 300.f;
				startX = -700.0f;
				
				sizeX = 50.0f;
				sizeY = 50.0f;
			}
			break;
			case(GameObject::Type::obstacle):
			{
				sizeX = 20.f;
				sizeY = 20.f;
			}
			break;
		}

		radius = sizeX;
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
		//������۷� ��ġ���� ũ������, ����, ������Ʈ ������Ѵ�.

		object_status.Pos = Vector4(startX + moveX, startY + moveY, 0.0f, 0.0f);
		object_status.Size = Vector4(sizeX, sizeY, 0.0f, 0.0f);

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