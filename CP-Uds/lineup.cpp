#include <cstdio>
#include <vector>
#include <algorithm>

int main (){
	short pos[11][11] = {0};
	int maxSum = 0;
	int sum;
	for (short i = 0 ; i < 11;  i++){
		for (short j = 0 ; j < 11 ; j ++ ){
			scanf("%hu" , &pos[i][j] );
		}
	}
	
	std::vector<int> v = {0,1,2,3,4,5,6,7,8,9,10};
	
	do{
	sum = pos[v[0]][0] + pos[v[1]][1] + pos[v[2]][2] + pos[v[3]][3] + pos[v[4]][4] + pos[v[5]][5] + pos[v[6]][6] + pos[v[7]][7] + pos[v[8]][8] + pos[v[9]][9] + pos[v[10]][10];
	maxSum = maxSum < sum ? sum : maxSum;
	} while(std::next_permutation(v.begin(),v.end()));

	printf("%d\n", maxSum);

	return 0;

}
