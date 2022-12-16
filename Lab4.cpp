//В экзаменационный период студент сдал n предметов, за которые в сумме получил t баллов.
//Наименьший балл, при котором ставится зачет по каждому предмету, равен p.
//Вам следует подсчитать количество способов, которыми студент мог получить баллы на экзаменах.

#include <iostream>

using namespace std;

int const N = 71;

int main()
{
	int tab[N][N] = {0};
	for (int i = 0; i < N; i++)
	{
		tab[1][i] = 1;
		tab[i][0] = 1;
	}
	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			tab[i][j] = tab[i][j - 1] + tab[i - 1][j];
		}
	}

	int tests, n, t, p;
	cin >> tests;
	for (int i = 0; i < tests; i++)
	{
		cin >> n >> t >> p;
		int k = t - n * p;
		cout << tab[n][k] << endl;
	}
}
