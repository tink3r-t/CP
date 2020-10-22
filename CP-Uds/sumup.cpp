// sumup.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>

using namespace std;

int start = 0;

typedef long long ll;

int PARSER_T(char* data) {
	long long value = 0;
	switch (data[start]) {
	case '*':
		value = 1;
		start++;
		start++;
		while (data[start] != ')') {
			if (data[start] != ',')
				value *= PARSER_T(data);
			start++;
		}
		break;
	case '+':
		start++;
		start++;
		while (data[start] != ')') {
			if (data[start] != ',')
				value += PARSER_T(data);
			start++;
		}
		break;
	default:
		if (start == 0)
			return -1;

		int v1,v2;
		//printf("V 4 Token: %c AND index is %d\n", data[start], start);
		//for (int i = 0 ;data[i] != ')' && data[i] != '\0'; i++ )
		if ((data[start] != ')' && data[start] != ',')){ 
			v1 = data[start] - '0';
		start++;
		if ( data[start] != ')' && data[start] != ',' ){
			v2 = data[start] - '0';
			value = v1 *10 + v2;
		}
		else {
			start--;
			value = v1;
		}
		}
	}
	return value;
}

int main()
{
	long long sumUp = 0;
	char line[1000000];
	int cVal = 0;
	while ( cVal != -1 ) {
		cin.getline(line,1000000);
		start = 0;
		cVal = PARSER_T(line);
		if (cVal != -1)
			sumUp += cVal;
	}
	cout<<sumUp<<"\n";
	return 0;
}
