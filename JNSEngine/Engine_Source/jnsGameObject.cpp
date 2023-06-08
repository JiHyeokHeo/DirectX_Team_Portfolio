#include "jnsGameObject.h"
#include "jnsRenderer.h"
#include "jnsGraphicDevice_Dx11.h"
#include "jnsTime.h"

namespace jns
{
	GameObject::GameObject()
		:mState(GameObject::Active)
		,x(0.0f)
		,y(0.0f)
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Initialize()
	{
	}
	void GameObject::Update()
	{
		// �� ������ ����
		x += 0.1f * Time::DeltaTime();
		Vector4 pos(x, 0.0f, 0.0f, 1.0f);
		renderer::constantBuffer->SetData(&pos);
		renderer::constantBuffer->Bind(eShaderStage::VS);


		// ����
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render()
	{
		//������۷� ��ġ���� ũ������, ����, ������Ʈ ������Ѵ�.

		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
	
}