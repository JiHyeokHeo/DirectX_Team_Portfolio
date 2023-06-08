#include "jnsGameObject.h"
#include "jnsRenderer.h"
#include "jnsGraphicDevice_Dx11.h"
#include "jnsTime.h"
#include "jnsInput.h"

namespace jns
{
	GameObject::GameObject()
		:mState(GameObject::Active)
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

	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render()
	{
		Vector4 color(mRGB.x, mRGB.y, mRGB.z, 1.0f);
		renderer::colorConstanttBuffer->SetData(&color);
		renderer::colorConstanttBuffer->Bind(eShaderStage::VS);

		Vector4 pos(mPos.x, mPos.y, 0.0f, 1.0f);
		renderer::transformconstantBuffer->SetData(&pos);
		renderer::transformconstantBuffer->Bind(eShaderStage::VS);
		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
	
}