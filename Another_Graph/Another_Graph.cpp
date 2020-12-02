

#include<windows.h>

#include<iostream>

#include"MatrixGraph.h"

using namespace std;

void main()

{

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	MatrixGraph a(6), b(6);

	a.addArc(0, 1);

	a.addArc(1, 2);

	a.addArc(1, 4);

	a.addArc(2, 3);

	a.addArc(3, 2);

	a.addArc(4, 0);

	cout << "Матрица А." << endl;

	a.PrintMatrix();

	b.addArc(0, 1);

	b.addArc(1, 4);

	b.addArc(4, 0);

	b.addArc(4, 3);

	cout << "Матрица B." << endl;

	b.PrintMatrix();

	int n, from, to, vertex;

	do

	{

		cout.width(3);

		cout << "///////////////////////////////////////\n";

		cout << "// 1.Добавить дугу в матрицу А. //\n";

		cout << "// 2.Удалить дугу из матрицы А. //\n";

		cout << "// 3.Добавить дугу в матрицу B. //\n";

		cout << "// 4.Удалить дугу из матрицы B. //\n";

		cout << "// 5.Добавить вершину в матрицу А. //\n";

		cout << "// 6.Удалить вершину из матрицы A. //\n";

		cout << "// 7.Вывод объединения А и B. //\n";

		cout << "// 8.Вывод дополнения А. //\n";

		cout << "// 9.Выход... //\n";

		cout << "///////////////////////////////////////\n";

		cin >> n;

		switch (n)

		{

		case 1:cout << "Ведите вершины.\n";

			cin >> from >> to;

			from--; to--;

			a.addArc(from, to);

			a.PrintMatrix(); break;

		case 2:cout << "Ведите вершины.\n";

			cin >> from >> to;

			from--; to--;

			a.deleteArc(from, to);

			a.PrintMatrix(); break;

		case 3:cout << "Ведите вершины.\n";

			cin >> from >> to;

			from--; to--;

			b.addArc(from, to);

			b.PrintMatrix(); break;

		case 4:

			cout << "Ведите вершины.\n";

			cin >> from >> to;

			from--; to--;

			b.deleteArc(from, to);

			b.PrintMatrix(); break;

		case 5:cout << "Ведите вершину.\n";

			cin >> vertex;

			//vertex--;

			a.addNode(vertex);

			a.PrintMatrix(); break;

		case 6:cout << "Ведите вершину.\n";

			cin >> vertex;

			vertex--;

			a.deleteNode(vertex, true);

			a.PrintMatrix(); break;

		case 7:a.ShowUnion(b); break;

		case 8:a.ComplementGraph();

			a.PrintMatrix();

		case 9:cout << "Выход...\n"; break;

		default: cout << "Попробуйте еще\n";

		}

	} while (n != 9);

}

