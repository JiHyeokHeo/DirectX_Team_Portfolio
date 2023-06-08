#include "jnsPlayer.h"
#include "jnsInput.h"
#include "jnsTime.h"

namespace jns
{
	Player::Player()
	{
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
		Vector2 mousePos = Input::GetMousePos();
		mousePos.x -= 800.0f;
		mousePos.y -= 400.0f;
		mousePos.Normalize();

		Vector2 mPos = GetPos();

		mPos.x += 0.5f * mousePos.x * Time::DeltaTime();
		mPos.y -= 0.5f * mousePos.y * Time::DeltaTime();

		SetPos(mPos);

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
}