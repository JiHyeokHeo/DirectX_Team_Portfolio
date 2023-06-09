#include "jnsPlayer.h"
#include "jnsInput.h"
#include "jnsTime.h"
#include "jnsGraphicDevice_Dx11.h"

namespace jns
{
	Player::Player()
		: mousePos(0.0f, 0.0f)
	{
		SetPos(Vector2(0.0f, 0.0f));
		SetName(L"Player");
		SetScale(70.0f);
	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		mouseposition();
		mousemove(0.5f);

		GameObject::Update();
	}
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Player::Render()
	{
		GameObject::Render();
	}

	void Player::mouseposition()
	{
		mousePos = Input::GetMousePos();
		D3D11_VIEWPORT viewPort = graphics::GetDevice()->GetViewPort();
		mousePos.x -= viewPort.Width / 2;
		mousePos.y -= viewPort.Height / 2;
		//mousePos.Normalize();
	}
	void Player::mousemove(float power)
	{
		Vector2 mPos = GetPos();
		mPos.x += power * mousePos.x * Time::DeltaTime();
		mPos.y -= power * mousePos.y * Time::DeltaTime();
		SetPos(mPos);
	}
}