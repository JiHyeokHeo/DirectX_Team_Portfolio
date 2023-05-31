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

	extern ID3D11InputLayout* triangleLayout; // �Է� ����� �ܰ� // ���� �����͸� �ùٸ��� �ؼ��ϱ� ����
	extern ID3D11Buffer* triangleBuffer; // ���� �����͸� �����ϱ� ���� ���� ��ü
	extern ID3DBlob* errorBlob;
	extern ID3DBlob* triangleVSBlob;
	extern ID3D11VertexShader* triangleVSShader; //�Էµ� ���� �����͸� ��ȯ�� ����� ������ ���� (���ؽ� ���̴�)
	extern ID3DBlob* trianglePSBlob;
	extern ID3D11PixelShader* trianglePSShader; // ���� �� �� �ȼ� �����͸� ������ ������ �޾Ƶ鿩 �� �ȼ��� ����


	void Initialize();
}
