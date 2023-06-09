#include "jnsPlayer.h"
#include "jnsInput.h"
#include "jnsTime.h"
#include "jnsGraphicDevice_Dx11.h"

namespace jns
{
	Player::Player()
		: mousePos(0.0f, 0.0f)
		, mData(PlayerData{ 4.0f })
	{
		SetPos(Vector2(0.0f, 0.0f));
		SetName(L"Player");
		
		SetScale(50.0f);
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
	/*	if (GetIsCol() == true)
		{
			mScale += 0.5f;
		}*/

		mouseposition();
		mousemove(0.5f);
		//SetScale(mScale);

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
		mousePos.y = 900.0f - mousePos.y;
		mousePos = mousePos - Vector2{ 800.0f, 450.0f };
	}
	void Player::mousemove(float power)
	{
		float Distance = Vector2::Distance(GetPos(), mousePos);
		math::Vector2 mdirection = mousePos - GetPos();

		mdirection.Normalize();

		math::Vector2 mPos = GetPos() + mdirection * Distance * Time::DeltaTime();
		SetPos(mPos);
	}
}