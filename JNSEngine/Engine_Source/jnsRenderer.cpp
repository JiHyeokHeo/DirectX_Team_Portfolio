#include "jnsRenderer.h"

namespace jns::renderer
{
	 Vertex vertexes[3] = {};

	 // Input Layout (정점 정보)
	 ID3D11InputLayout* triangleLayout = nullptr;
	 ID3D11InputLayout* squareLayout = nullptr;

	 // Vertex Buffer
	 ID3D11Buffer* triangleBuffer = nullptr;
	 ID3D11Buffer* squareBuffer = nullptr;

	 // error blob
	 ID3DBlob* errorBlob = nullptr;
	 
	 // Vertex Shader Code -> Binary Code 
	 ID3DBlob* triangleVSBlob = nullptr;
	 ID3DBlob* squareVSBlob = nullptr;

	 // Vertex Shader
	 ID3D11VertexShader* triangleVSShader = nullptr;
	 ID3D11VertexShader* squareVSShader = nullptr;
	 
	 // Pixel Shader Code -> Binary Code
	 ID3DBlob* trianglePSBlob = nullptr;
	 ID3DBlob* squarePSBlob = nullptr;

	 // Vertex Shader
	 ID3D11PixelShader* trianglePSShader = nullptr;
	 ID3D11PixelShader* squarePSShader = nullptr;


	 void SetupState()
	 {

	 }

	 void LoadBuffer()
	 {
		 D3D11_BUFFER_DESC triangleDesc = {};
		 D3D11_BUFFER_DESC squareDesc = {};
		triangleDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		triangleDesc.ByteWidth = sizeof(Vertex) * 3;
		triangleDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		triangleDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		 D3D11_SUBRESOURCE_DATA triangleData = {};
		 triangleData.pSysMem = vertexes;
		 jns::graphics::GetDevice()->CreateBuffer(&triangleBuffer, &triangleDesc, &triangleData);
	 }

	 void LoadShader()
	 {
		 jns::graphics::GetDevice()->CreateShader();
	 }

	 void Initialize()
	 {
		 vertexes[0].pos = Vector3(-0.5f, 0.8f, 0.5f);
		 vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		 vertexes[1].pos = Vector3(-0.2f, 0.8f, 0.5f);
		 vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		 vertexes[2].pos = Vector3(-0.5f, 0.0f, 0.5f);
		 vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		 SetupState();
		 LoadBuffer();
		 LoadShader();
	 }
}

