#include<iostream>
using namespace std;
bool find(int str[][5], int rows, int colums, int x);
int main() {
	int str[5][5] = { {1, 2, 8, 9},
					  {2, 4, 9, 12},
					  {4, 7, 10, 13},
					  {6, 8, 11, 15}
					};
    int x = 17;
    cout << find(str, 4, 4, x) << endl;
    return 0;
}
//从数组左下角开始比较 
bool find(int str[][5], int rows, int colums, int x) {
	int i = rows - 1;
	int j = 0;
	while(i >= 0 && j < colums) {
			if (str[i][j] == x)
				return true;
			else if (str[i][j] > x)
				i--;
			else
				j++;
		}
	return false;
}
