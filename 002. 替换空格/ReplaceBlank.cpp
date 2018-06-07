#include<iostream>
#include<string.h>
using namespace std;
void ReplaceBlank(char string[], int length);
int main() {
	char string[17] = "We are happy.";
	cout<<string<<endl;	
	ReplaceBlank(string, 17);
	cout<<string<<endl;
	return 0;
} 
//在原数组上将空格替换为%20 
void ReplaceBlank(char string[], int length) {
	int len = 0;
	int i = 0;
	int blank = 0;
	while (string[i] != '\0') {
		if (string[i] == ' ')
			blank++;
		else
			len++;
		i++;
	}
	int replacedLen = blank * 3 + len;
	if (replacedLen > length) {
		cout << "数组越界" << endl;
		return;
	}
	len = len + blank - 1;
	while (len > 0) {
		if (string[len] == ' ') {			
			string[--replacedLen] = '0';
			string[--replacedLen] = '2';
			string[--replacedLen] = '%';
		} else {
			string[--replacedLen] = string[len];
		}
		len--;
	}	
}
