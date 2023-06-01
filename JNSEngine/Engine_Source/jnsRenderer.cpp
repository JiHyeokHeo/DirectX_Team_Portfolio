#include "jnsRenderer.h"
#include "jnsMath.h"
#include "jnsInput.h"
#include "jnsTime.h"
#define PI 3.141592

namespace jns::renderer
{
	//static void Rotate(float& x, float& y , float degree)
	//{
	//	float radian = (degree / 180.0f) * PI;  
	//	Vector2(x,y).Normalize();						

	//	float t = x * cosf(radian) - y * sinf(radian); 
	//	float z = x * sinf(radian) + y * cosf(radian);
	//	
	//	x = t;
	//	y = z;
	//}

	 Quaternion targetQuaternion;
	 Quaternion resultQuaternion;

	 Vertex vertexes[256] = {};
	 // Input Layout (정점 정보)
	 ID3D11InputLayout* triangleLayout = nullptr;

	 // Vertex Buffer
	 ID3D11Buffer* triangleBuffer = nullptr;
	 ID3D11Buffer* triangleIdxBuffer = nullptr;
	 ID3D11Buffer* triangleConstantBuffer = nullptr;

	 // error blob
	 ID3DBlob* errorBlob = nullptr;
	 
	 // Vertex Shader Code -> Binary Code 
	 ID3DBlob* triangleVSBlob = nullptr;

	 // Vertex Shader
	 ID3D11VertexShader* triangleVSShader = nullptr;
	 
	 // Pixel Shader Code -> Binary Code
	 ID3DBlob* trianglePSBlob = nullptr;

	 // Vertex Shader
	 ID3D11PixelShader* trianglePSShader = nullptr;


	 void SetupState()
	 {

	 }

	 void LoadBuffer()
	 {
		 // Vertex Buffer
		 D3D11_BUFFER_DESC triangleDesc = {};
		triangleDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		 triangleDesc.ByteWidth = sizeof(Vertex) * 256;
		 triangleDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		triangleDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		 D3D11_SUBRESOURCE_DATA triangleData = {};
		 triangleData.pSysMem = vertexes;
		 jns::graphics::GetDevice()->CreateBuffer(&triangleBuffer, &triangleDesc, &triangleData);

		 std::vector<UINT> indexes = {};
		 indexes.push_back(0);
		 indexes.push_back(1);
		 indexes.push_back(2);


		 // Index Buffer
		 D3D11_BUFFER_DESC triangleIdxDesc = {};
		 triangleIdxDesc.ByteWidth = sizeof(UINT) * indexes.size();
		 triangleIdxDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_INDEX_BUFFER;
		 triangleIdxDesc.Usage = D3D11_USAGE_DEFAULT;
		 triangleIdxDesc.CPUAccessFlags = 0;

		 D3D11_SUBRESOURCE_DATA triangleIdxData = {};
		 triangleIdxData.pSysMem = indexes.data();
		 jns::graphics::GetDevice()->CreateBuffer(&triangleIdxBuffer, &triangleIdxDesc, &triangleIdxData);

		 // Constant Buffer
		 D3D11_BUFFER_DESC triangleCSDesc = {};
		 triangleCSDesc.ByteWidth = sizeof(Vector4);
		 triangleCSDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_CONSTANT_BUFFER;
		 triangleCSDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		 triangleCSDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		 jns:graphics::GetDevice()->CreateBuffer(&triangleConstantBuffer, &triangleCSDesc, nullptr);

		 
		 jns::graphics::GetDevice()->SetConstantBuffer(triangleConstantBuffer, &mTrianglePos, sizeof(Vector4));
		 jns::graphics::GetDevice()->BindConstantBuffer(eShaderStage::VS, eCBType::Transform, triangleConstantBuffer);
		 //
	 }

	 void LoadShader()
	 {
		 jns::graphics::GetDevice()->CreateShader();
	 }

	 void Initialize()
	 {
		 mTrianglePos = Vector4(0.0f, 0.0f, 0.0f, 0.0f);
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


		 SetupState();
		 LoadBuffer();
		 LoadShader();
	 }

	 void Update()
	 {
		 
		 if(Input::GetKey(eKeyCode::LEFT))
		 {
			 mTrianglePos.x -= 0.1f * Time::DeltaTime();
		 }
		 else if (Input::GetKey(eKeyCode::RIGHT))
		 {
			 mTrianglePos.x += 0.1f * Time::DeltaTime();
		 }
		 jns::graphics::GetDevice()->SetConstantBuffer(triangleConstantBuffer, &mTrianglePos, sizeof(Vector4));
		 jns::graphics::GetDevice()->BindConstantBuffer(eShaderStage::VS, eCBType::Transform, triangleConstantBuffer);
	 }
}

