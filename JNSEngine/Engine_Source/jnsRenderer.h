#pragma once
#include "JNSEngine.h"
#include "jnsGraphicDevice_Dx11.h"
#include "jnsMesh.h"
#include "jnsShader.h"

using namespace jns::math;

namespace jns::renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};


	extern Vertex vertexes[];
	extern ID3D11InputLayout* triangleLayout;
	extern jns::Mesh* mesh;
	extern ID3D11Buffer* triangleConstantBuffer;
	extern jns::Shader* shader;
	extern ID3D11PixelShader* trianglePSShader;


	void Initialize();
	void Release();
	void Update();

	Vector4 mTrianglePos;
}
