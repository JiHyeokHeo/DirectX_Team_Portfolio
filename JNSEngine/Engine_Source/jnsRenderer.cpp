#include "jnsRenderer.h"

namespace jns::renderer
{
	 Vertex vertexes[6] = {};

	 //초기화되지 않은 객체를 사용하게 되면 오류가 발생하므로 우선  nullptr 값으로 채워둔다
	 // Input Layout (정점 정보)
	 ID3D11InputLayout* triangleLayout = nullptr;

	 // Vertex Buffer
	 ID3D11Buffer* triangleBuffer = nullptr;

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
		 //버퍼객체의 속성을 지정하기 위한 인터페이스
		 D3D11_BUFFER_DESC triangleDesc = {};

		 //버퍼의 사용방법을 지정, USAGE_DYNAMIC은 버퍼가 빈번하게 변경될 때 유용
		triangleDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;

		//버퍼의 크기 지정
		triangleDesc.ByteWidth = sizeof(Vertex) * 6;
		
		//바인드 플래그를 정점 버퍼로 지정
		//바인드 플래그란? 버퍼가 어떤 용도로 사용될 지 지정하는 역할 (인덱스 버퍼 or 정점 버퍼)
		triangleDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;

		//CPU가 버퍼에 엑세스 하는 방법 지정 -> WRITE 이므로 CPU는 버퍼에 대해 쓰기 작업 가능
		triangleDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		// 그래픽스 자원의 초기 데이터를 가진 인터페이스
		 D3D11_SUBRESOURCE_DATA triangleData = {};
		 //pSysMem는 그래픽스 초기 자원의 포인터, vertexes의 주소를 할당함 
		 triangleData.pSysMem = vertexes;

		 jns::graphics::GetDevice()->CreateBuffer(&triangleBuffer, &triangleDesc, &triangleData);
	 }

	 void LoadShader()
	 {
		 //그래픽 디바이스의 포인터를 반환받고 쉐이더를 생성한다 // 그래픽 디바이스 = 그래픽 카드
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
	
		 vertexes[3].pos = Vector3(-0.2f, 0.8f, 0.5f);
		 vertexes[3].color = Vector4(2.0f, 0.5f, 0.5f, 1.0f);

		 vertexes[4].pos = Vector3(-0.2f, 0.0f, 0.5f);
		 vertexes[4].color = Vector4(0.5f, 2.0f, 0.5f, 1.0f);

		 vertexes[5].pos = Vector3(-0.5f, 0.0f, 0.5f);
		 vertexes[5].color = Vector4(0.5f, 0.5f, 2.0f, 1.0f);

		 SetupState();
		 LoadBuffer();
		 LoadShader();
	 }
}

