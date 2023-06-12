#include "jnsRenderer.h"

#define ver_Num 30

namespace renderer
{
	using namespace jns;
	using namespace jns::graphics;
	Vertex vertexes[ver_Num] = {};

	std::vector<jns::graphics::ConstantBuffer*> constantBuffers;

	jns::Mesh* mesh = nullptr;
	jns::Shader* shader = nullptr;

	void SetupState()
	{
		// Input layout 정점 구조 정보를 넘겨줘야한다.
		D3D11_INPUT_ELEMENT_DESC arrLayout[2] = {};

		arrLayout[0].AlignedByteOffset = 0;
		arrLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		arrLayout[0].InputSlot = 0;
		arrLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[0].SemanticName = "POSITION";
		arrLayout[0].SemanticIndex = 0;

		arrLayout[1].AlignedByteOffset = 12;
		arrLayout[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		arrLayout[1].InputSlot = 0;
		arrLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		arrLayout[1].SemanticName = "COLOR";
		arrLayout[1].SemanticIndex = 0;

		jns::graphics::GetDevice()->CreateInputLayout(arrLayout, 2
			, renderer::shader->GetVSCode()
			, renderer::shader->GetInputLayoutAddressOf());
	}

	void LoadBuffer()
	{
		// Vertex Buffer
		renderer::mesh = new jns::Mesh();
		renderer::mesh->CreateVertexBuffer(vertexes, ver_Num);

		std::vector<UINT> indexes;
		for (UINT i = 0; i < ver_Num; ++i)
		{
			indexes.push_back(0);      // 중점
			indexes.push_back(i + 1);  // 현재 세그먼트의 정점
			indexes.push_back((i + 1) % ver_Num + 1);  // 다음 세그먼트의 정점
		}
		renderer::mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		// Constant Buffer
		constantBuffers.push_back(new ConstantBuffer(eCBType::Transform));
		constantBuffers[0]->Create(sizeof(Vector4) * 2);
		constantBuffers.push_back(new ConstantBuffer(eCBType::Color));
		constantBuffers[1]->Create(sizeof(Vector4));
	}

	void LoadShader()
	{
		renderer::shader = new jns::Shader();
		renderer::shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		renderer::shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
	}

	void Initialize()
	{
		const float radius = 1.0f;  // 원의 반지름

		// 원의 정점 좌표 계산
		float angleIncrement = (2.0f * 3.14159f) / ver_Num;
		float currentAngle = 2.0f * 3.14159f;  // 시작 각도를 2 * PI로 설정하여 시계 방향으로 그리도록 함

		for (int i = 0; i < ver_Num; ++i)
		{
			float x = radius * cos(currentAngle);
			float y = radius * sin(currentAngle);

			vertexes[i].pos = Vector3(x, y, 0.0f);
			vertexes[i].color = Vector4(0.0f, 0.0f, 0.0f, 0.0f);

			currentAngle -= angleIncrement;  // 각도를 감소시켜 시계 방향으로 그림
		}

		LoadBuffer();
		LoadShader();
		SetupState();
	}

	void Release()
	{

	}
}



