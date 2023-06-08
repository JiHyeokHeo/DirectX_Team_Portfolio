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

		// 렌더
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render()
	{
		////상수버퍼로 위치정보 크기정보, 색깔, 업데이트 해줘야한다.
		Vector4 color(1.0f, 1.0f, 1.0f, 1.0f);
		renderer::colorConstanttBuffer->SetData(&color);
		renderer::colorConstanttBuffer->Bind(eShaderStage::VS);

		Vector4 pos(mPos.x, mPos.y, 0.0f, 1.0f);
		renderer::transformconstantBuffer->SetData(&pos);
		renderer::transformconstantBuffer->Bind(eShaderStage::VS);
		
	}
	
}