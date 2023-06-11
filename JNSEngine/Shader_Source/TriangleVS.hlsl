struct VSIn
{
	float3 Pos : POSITION;
	float4 Color : COLOR;
};

struct VSOut
{
	float4 Pos : SV_Position;
	float4 Color : COLOR;
};

cbuffer Transform : register(b0)
{
    float4 Pos;
    float4 Size;
}

cbuffer Color : register(b1)
{
    float4 color;
}

VSOut main(VSIn In)
{
	VSOut Out = (VSOut)0.0f;

	Out.Pos = float4(In.Pos, 1.0f);
	//Out.Pos.x += 0.4f; //inputPosX; -> 상수버퍼를 통해서 이데이터가 넘와야한다.
	
    Out.Pos.x *= Size.x;
    Out.Pos.y *= Size.y;
	
    Out.Pos.x += Pos.x;
    Out.Pos.y += Pos.y;
	
    Out.Pos.x /= 800.f;
    Out.Pos.y /= 450.f;
	
    Out.Color = color;

	return Out;
}