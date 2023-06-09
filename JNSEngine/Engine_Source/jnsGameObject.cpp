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
		// 이것이 행동 트리라고 하는 것이다. (수민님의 조언)
		if (CheckTime())
			return;

		
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render()
	{
		PipeLineRender();
	}


#pragma region PipeLine

	void GameObject::PipeLineRender()
	{
		Vector4 color(mRGB.x, mRGB.y, mRGB.z, 1.0f);
		renderer::colorConstanttBuffer->SetData(&color);
		renderer::colorConstanttBuffer->Bind(eShaderStage::VS);

		
		renderer::transformconstantBuffer->SetData(&mStatus);
		renderer::transformconstantBuffer->Bind(eShaderStage::VS);

		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}


#pragma endregion

	bool GameObject::CheckTime()
	{
		if (mTime >= 3.0f)
			return false;


		if (this->GetState() == GameObject::Paused)
		{
			CheckPauseTime();
			return true;
		}

		return false;
	}
	void GameObject::CheckPauseTime()
	{
		mTime += Time::DeltaTime();

	}
}