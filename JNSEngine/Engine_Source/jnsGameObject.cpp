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
		// 공 움직임 구현
		x += 0.1f * Time::DeltaTime();
		Vector4 pos(x, 0.0f, 0.0f, 1.0f);
		renderer::constantBuffer->SetData(&pos);
		renderer::constantBuffer->Bind(eShaderStage::VS);


		// 렌더
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render()
	{
		//상수버퍼로 위치정보 크기정보, 색깔, 업데이트 해줘야한다.

		renderer::mesh->BindBuffer();
		renderer::shader->Binds();
		graphics::GetDevice()->DrawIndexed(renderer::mesh->GetIndexCount(), 0, 0);
	}
	
}