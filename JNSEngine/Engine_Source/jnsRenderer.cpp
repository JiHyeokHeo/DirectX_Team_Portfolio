#include "jnsRenderer.h"
#include "jnsMath.h"
#include "jnsInput.h"
#include "jnsTime.h"


namespace renderer
{
	Vertex vertexes[361] = {};
	jns::Mesh* mesh = nullptr;
	jns::Shader* shader = nullptr;
	jns::graphics::ConstantBuffer* constantBuffer = nullptr;

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
			 , shader->GetVSCode()
			 , shader->GetInputLayoutAddressOf());
	 }

	 void LoadBuffer()
	 {
		 // Vertex Buffer
		 mesh = new jns::Mesh();
		 mesh->CreateVertexBuffer(vertexes, 4);

		 std::vector<UINT> indexes = {};
		 indexes.push_back(0);
		 indexes.push_back(1);
		 indexes.push_back(2);

		 indexes.push_back(0);
		 indexes.push_back(2);
		 indexes.push_back(3);
		 mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		 // Constant Buffer
		 D3D11_BUFFER_DESC triangleCSDesc = {};
		 triangleCSDesc.ByteWidth = sizeof(Vector4);
		 triangleCSDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_CONSTANT_BUFFER;
		 triangleCSDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		 triangleCSDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		 constantBuffer = new jns::graphics::ConstantBuffer(eCBType::Transform);
		 constantBuffer->Create(sizeof(Vector4));

		 //Vector4 pos(0.0f, 0.0f, 0.0f, 1.0f);
		 //constantBuffer->SetData(&pos);
		 //constantBuffer->Bind(eShaderStage::VS);

	 }

	 void LoadShader()
	 {
		 shader = new jns::Shader();
		 shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		 shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
	 }

	 void Initialize()
	 {
		 vertexes[0].pos = Vector3(0.0f, 0.5f, 0.0f);
		 vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		 vertexes[1].pos = Vector3(0.5f, -0.5f, 0.0f);
		 vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		 vertexes[2].pos = Vector3(-0.5f, -0.5f, 0.0f);
		 vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		 //vertexes[3].pos = Vector3(-0.8f, 0.8f, 0.5f);
		 //vertexes[3].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		 //vertexes[4].pos = Vector3(-0.5f, 0.8f, 0.5f);
		 //vertexes[4].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		 //vertexes[5].pos = Vector3(-0.5f, 0.5f, 0.5f);
		 //vertexes[5].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);


		 //vertexes[6].pos = Vector3(0.5f, 0.8f, 0.5f);
		 //vertexes[6].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		 //vertexes[7].pos = Vector3(0.8f, 0.5f, 0.5f);
		 //vertexes[7].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		 //vertexes[8].pos = Vector3(0.2f, 0.5f, 0.5f);
		 //vertexes[8].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		 //vertexes[9].pos = Vector3(0.8f, 0.5f, 0.5f);
		 //vertexes[9].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		 //vertexes[10].pos = Vector3(0.5f, 0.2f, 0.5f);
		 //vertexes[10].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		 //vertexes[11].pos = Vector3(0.2f, 0.5f, 0.5f);
		 //vertexes[11].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		 //float start_x =  0.0f;
		 //float start_y =  0.3f;
		 //float angle =  -5.0f;
		 //float center_x = 0.0f;
		 //float center_y = 0.0f;


		 //Vector2 turnPos = Vector2(start_x, start_y);
		 //for (int i = 12; i < 255;)
		 //{
			// vertexes[i].pos = Vector3(center_x, center_y, 0.5f);
			// vertexes[i].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

			// i++;
			// vertexes[i].pos = Vector3(turnPos.x, turnPos.y, 0.5f);
			// vertexes[i].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

			// Rotate(turnPos.x, turnPos.y, angle);

			// i++;
			// vertexes[i].pos = Vector3(turnPos.x, turnPos.y, 0.5f);
			// vertexes[i].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

			// i++;
		 //}


		 LoadBuffer();
		 LoadShader();
		 SetupState();
	 }

	 void Release()
	 {
		 delete mesh;
		 delete shader;
		 delete constantBuffer;
	 }
}

