#include "jnsMonster.h"


namespace jns
{
	Monster::Monster()
		: mMonsterScale(1)
	{
		mMonsterPos.x = disX(gen);
		mMonsterPos.y = disX(gen);
		mRGB.x = rangecolorR(gen);
		mRGB.y = rangecolorG(gen);
		mRGB.z = rangecolorB(gen);
		SetPos(mMonsterPos);
		SetRGB(mRGB);
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