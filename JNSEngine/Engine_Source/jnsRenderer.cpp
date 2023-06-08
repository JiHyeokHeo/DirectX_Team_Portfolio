#include "jnsRenderer.h"
#include "jnsMath.h"
#include "jnsInput.h"
#include "jnsTime.h"


namespace renderer
{
	inline static void Rotate(float& x, float& y, float degree)
	{
		float radian = (degree / 180.0f) * 3.141592;   // 1������ 57.3����? �������� �� �ڻ��ΰ� ���� ��Ÿ���� ���ϱ� ���ؼ��� ������ ������ ����ؾ��ϰ�
		//Vector2(x,y).Normalize();						// Normalize�� �ᱹ 1, 1�� ����� �ذ��̰�.

		float t = x * cosf(radian) - y * sinf(radian); // �̰��� �ٷ� ���� �������� �ֽ� �ﰢ�Լ��� Ȱ���� ������ ȸ���̴�. x��ǥ�� x�ڻ��μ�Ÿ - y���μ�Ÿ
		float z = x * sinf(radian) + y * cosf(radian); // 
		//atan
		//atan();
		x = t;
		y = z;
	}
	Vertex vertexes[362] = {};
	jns::Mesh* mesh = nullptr;
	jns::Shader* shader = nullptr;
	jns::graphics::ConstantBuffer* transformconstantBuffer;
	jns::graphics::ConstantBuffer* colorConstanttBuffer;

	 void SetupState()
	 {
		 // Input layout ���� ���� ������ �Ѱ�����Ѵ�.
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
		 mesh->CreateVertexBuffer(vertexes, 362);

		 std::vector<UINT> indexes = {};

		 for (int i = 1; i < 361; i++)
		 {
			 indexes.push_back(0);
			 indexes.push_back(i);
			 indexes.push_back(i + 1);
		 }
		 mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		 // Constant Buffer
		 transformconstantBuffer = new jns::graphics::ConstantBuffer(eCBType::Transform);
		 transformconstantBuffer->Create(sizeof(Vector4));

		 colorConstanttBuffer = new jns::graphics::ConstantBuffer(eCBType::Color);
		 colorConstanttBuffer->Create(sizeof(Vector4));

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
		 float start_x = 0.0f;
		 float start_y = 0.5f;
		 float angle = -1.0f;
		 float center_x = 0.0f;
		 float center_y = 0.0f;

		 vertexes[0].pos = Vector3(center_x, center_y, 0.5f);
		 vertexes[0].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		 Vector3 turnPos = Vector3(start_x, start_y, angle);
		 for (int i = 1; i < 362; i++)
		 {
			 vertexes[i].pos = Vector3(turnPos.x, turnPos.y, 0.5f);
			 vertexes[i].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
			 Rotate(turnPos.x, turnPos.y, angle);
		 }

		 LoadBuffer();
		 LoadShader();
		 SetupState();
	 }

	 void Release()
	 {
		 delete mesh;
		 delete shader;
		 delete transformconstantBuffer;
		 delete colorConstanttBuffer;
	 }

	
}

