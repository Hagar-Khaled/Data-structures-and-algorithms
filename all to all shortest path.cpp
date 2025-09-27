// ******************** All to all shortest paths *********************************

#include <iostream>
using namespace std;

#define inf 99
#define dim 7

int weight[dim][dim] = { {0,1,inf,inf,inf,2,9},
						 {1,0,8,inf,inf,inf,inf},
						 {inf,8,0,4,inf,3,inf},
						 { inf, inf, 4, 0, 2, inf, inf },
						 { inf, inf, inf, 2, 0, 1, inf },	
						 { 2, inf, 3, inf, 1, 0, 2 },
						 {9,inf,inf,inf,inf,2,0} };

int main() {

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (weight[i][j] == inf)	cout << "#\t";
			else	cout << weight[i][j] << "\t";
		}
		cout << endl;
	}

	bool flag = false;
	do {
		flag = false;
		for (int src = 0; src < dim; src++) {
			for (int dest = 0; dest < dim; dest++) {
				for (int via = 0; via < dim; via++) {
					if (weight[src][dest] > weight[src][via] + weight[via][dest]) {
						weight[src][dest] = weight[src][via] + weight[via][dest];
						flag = true;
					}
				}
			}
		}
	} while (flag);
	cout << "\n\n";
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cout << weight[i][j] << "\t";
		}
		cout << endl;
	}
}
