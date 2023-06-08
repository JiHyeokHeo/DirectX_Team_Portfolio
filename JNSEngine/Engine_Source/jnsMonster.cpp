#include "jnsMonster.h"


namespace jns
{
	Monster::Monster()
		:mMonsterPos(0.0f, 0.0f)
	{
		mMonsterPos.x = disX(gen);
		mMonsterPos.y = disX(gen);
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
		GameObject::Initialize();
	}
	void Monster::Update()
	{
		GameObject::Update();
	}
	void Monster::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Monster::Render()
	{
		GameObject::Render();
	}
}