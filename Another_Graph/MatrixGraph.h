#pragma once

class MatrixGraph

{

	int** graph;

	int vertexNumber;//число вершин

public:

	MatrixGraph(int);

	void ShowUnion(MatrixGraph a);
	
	int  OrientedGraph(MatrixGraph a); // орграф

	void ComplementGraph(); //дополнение

	void addArc(int, int);//добавление дуги

	void deleteArc(int, int);

	void addNode(int);

	void deleteNode(int, bool);

	int hasArc(int, int);// проверка дуги

	int Size() { return vertexNumber; }

	void PrintMatrix();

};