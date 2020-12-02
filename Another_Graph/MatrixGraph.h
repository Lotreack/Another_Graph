#pragma once

class MatrixGraph

{

	int** graph;

	int vertexNumber;//����� ������

public:

	MatrixGraph(int);

	void ShowUnion(MatrixGraph a);
	
	int  OrientedGraph(MatrixGraph a); // ������

	void ComplementGraph(); //����������

	void addArc(int, int);//���������� ����

	void deleteArc(int, int);

	void addNode(int);

	void deleteNode(int, bool);

	int hasArc(int, int);// �������� ����

	int Size() { return vertexNumber; }

	void PrintMatrix();

};