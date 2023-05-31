#pragma once
#include "JNSEngine.h"
#include "jnsGraphicDevice_Dx11.h"

using namespace jns::math;

namespace jns::renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};


	extern Vertex vertexes[];

	extern ID3D11InputLayout* triangleLayout; // 입력 어셈블러 단계 // 정점 데이터를 올바르게 해석하기 위함
	extern ID3D11Buffer* triangleBuffer; // 정점 데이터를 저장하기 위한 버퍼 객체
	extern ID3DBlob* errorBlob;
	extern ID3DBlob* triangleVSBlob;
	extern ID3D11VertexShader* triangleVSShader; //입력된 정점 데이터를 변환해 출력할 정점을 생성 (버텍스 쉐이더)
	extern ID3DBlob* trianglePSBlob;
	extern ID3D11PixelShader* trianglePSShader; // 정점 간 의 픽셀 데이터를 보간된 값으로 받아들여 각 픽셀에 저장


	void Initialize();
}
