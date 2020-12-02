

#include "MatrixGraph.h"
#include <iostream>
using namespace std;
MatrixGraph::MatrixGraph(int n)

{

	graph = new int* [vertexNumber = n];

	for (int i = 0; i < n; i++)

	{

		graph[i] = new int[n];

		for (int j = 0; j < n; j++)

		{

			graph[i][j] = 0;

		}

	}

}

void MatrixGraph::addNode(int n)

{

	int temp_n = n, countVertex;

	temp_n--;

	int** tempgraph;

	if (temp_n <= 0)

	{

		return;

	}

	if (temp_n > 0 && temp_n < vertexNumber)

	{

		if (graph[temp_n][temp_n] == -1)

		{

			deleteNode(temp_n, false);

		}

	}

	else

	{

		countVertex = n - vertexNumber;

		n = countVertex + vertexNumber;

		tempgraph = new int* [n];

		for (int i = 0; i < n; i++)

		{

			tempgraph[i] = new int[n];

			for (int j = 0; j < n; j++)

			{

				tempgraph[i][j] = 0;

			}

		}

		for (int i = 0; i < vertexNumber; i++)

		{

			for (int j = 0; j < vertexNumber; j++)

			{

				tempgraph[i][j] = graph[i][j];

			}

		}

		delete[] graph;

		graph = tempgraph;

		vertexNumber += countVertex;

	}

}

void MatrixGraph::deleteNode(int n, bool flag)

{

	if (n < 0 || n >= vertexNumber)

	{

		return;

	}

	if (flag)

	{

		for (int i = 0; i < vertexNumber; i++)

		{

			for (int j = 0; j < vertexNumber; j++)

			{

				graph[i][n] = -1;

				graph[n][j] = -1;

			}

		}

	}

	else

	{

		for (int i = 0; i < vertexNumber; i++)

		{

			for (int j = 0; j < vertexNumber; j++)

			{

				graph[i][n] = 0;

				graph[n][j] = 0;

			}

		}

	}

}

void MatrixGraph::PrintMatrix()

{

	for (int i = 0; i <= vertexNumber; i++)

	{

		cout.width(3);

		if (i == 0) { cout << " "; i++; }

		cout << "X" << i;

	}

	cout << endl;

	for (int i = 0; i < vertexNumber; i++)

	{

		cout.width(4);

		cout << "X" << i + 1;

		for (int j = 0; j < vertexNumber; j++)

		{

			cout.width(4);

			if (graph[i][j] == -1)

			{

				cout << "#";

			}

			else

			{

				cout << graph[i][j];

			}

		}

		cout << endl << endl;

	}

}

void MatrixGraph::addArc(int from, int to)

{

	if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)

		return;

	graph[from][to] = 1;

}

void MatrixGraph::deleteArc(int from, int to)

{

	if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)

		return;

	graph[from][to] = 0;

}

int MatrixGraph::hasArc(int from, int to)

{

	if (from < 0 || from >= vertexNumber || to < 0 || to >= vertexNumber)

		return false;

	return graph[from][to];

}

void MatrixGraph::ComplementGraph()

{

	for (int i = 0; i < vertexNumber; i++)

	{

		for (int j = 0; j < vertexNumber; j++)

		{

			if (graph[i][j] == 0)

			{

				graph[i][j] = 1;

			}

			else

			{

				if (graph[i][j] == 1)

				{

					graph[i][j] = 0;

				}

			}

		}

	}

	for (int i = 0; i < vertexNumber; i++)

	{

		for (int j = 0; j < vertexNumber; j++)

		{

			if (i == j)

			{

				graph[i][j] = 0;

			}

		}

	}

}

void MatrixGraph::ShowUnion(MatrixGraph a)

{

	int max, min;

	a.Size() > vertexNumber ? max = a.Size() : max = vertexNumber;

	a.Size() < vertexNumber ? min = a.Size() : min = vertexNumber;

	MatrixGraph c(max);

	for (int i = 0; i < max; i++)

	{

		for (int j = 0; j < max; j++)

		{

			if (a.hasArc(i, j) == 1 || hasArc(i, j) == 1)

			{
				c.addArc(i, j);
			}

		}

	}

	c.PrintMatrix();

}

int MatrixGraph::OrientedGraph(MatrixGraph a)
{
	int i = 0, j = 0, pos = 0, end, st;
	cout << "Введите начало графа : "; cin >> st;
	cout << "\nВведите конец графа : "; cin >> end;
	if (st > 7 || st < 1) {
		cout << "Некоректный ввод" << endl;
		return 0;
	}
	cout << endl;
	int graf[7][7] = {
	 {0,1,0,0,0,0,0},
	 {1,0,1,0,0,0,0},
	 {0,1,0,1,1,0,0},
	 {0,0,1,0,0,1,0},
	 {0,0,1,0,0,0,1},
	 {0,0,0,1,0,0,0},
	 {0,0,0,0,1,0,0} };
	for (j = 0; j < 7; j++) {
		if (graf[st - 1][i] == 1) {
			cout << i + 1 << " граф соеденен с  " << j + 1 << endl;
		}

	}
	cout << "Вы начинаете с " << st << " ветки" << endl;

	pos = st;
	while (pos != end)
	{
		for (j = 0; j < 7; j++) {
			if (graf[pos - 1][j] == 1) {
				cout << "\nВы можете пойти к " << j + 1;
			}
		}
		cout << "\nВведите куда пойти "; cin >> i;
		if (i > 7 && i < 1) {
			cout << "\nОшибка";
		}
		else
		{
			pos = i;
		}
		if (pos == 6) {
			// pos+=1;
		}
	}
}