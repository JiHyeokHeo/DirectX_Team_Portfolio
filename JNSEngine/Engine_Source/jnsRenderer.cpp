#include "jnsRenderer.h"

namespace jns::renderer
{
	 Vertex vertexes[6] = {};

	 //�ʱ�ȭ���� ���� ��ü�� ����ϰ� �Ǹ� ������ �߻��ϹǷ� �켱  nullptr ������ ä���д�
	 // Input Layout (���� ����)
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
		 //���۰�ü�� �Ӽ��� �����ϱ� ���� �������̽�
		 D3D11_BUFFER_DESC triangleDesc = {};

		 //������ ������� ����, USAGE_DYNAMIC�� ���۰� ����ϰ� ����� �� ����
		triangleDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;

		//������ ũ�� ����
		triangleDesc.ByteWidth = sizeof(Vertex) * 6;
		
		//���ε� �÷��׸� ���� ���۷� ����
		//���ε� �÷��׶�? ���۰� � �뵵�� ���� �� �����ϴ� ���� (�ε��� ���� or ���� ����)
		triangleDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;

		//CPU�� ���ۿ� ������ �ϴ� ��� ���� -> WRITE �̹Ƿ� CPU�� ���ۿ� ���� ���� �۾� ����
		triangleDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		// �׷��Ƚ� �ڿ��� �ʱ� �����͸� ���� �������̽�
		 D3D11_SUBRESOURCE_DATA triangleData = {};
		 //pSysMem�� �׷��Ƚ� �ʱ� �ڿ��� ������, vertexes�� �ּҸ� �Ҵ��� 
		 triangleData.pSysMem = vertexes;

		 jns::graphics::GetDevice()->CreateBuffer(&triangleBuffer, &triangleDesc, &triangleData);
	 }

	 void LoadShader()
	 {
		 //�׷��� ����̽��� �����͸� ��ȯ�ް� ���̴��� �����Ѵ� // �׷��� ����̽� = �׷��� ī��
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

