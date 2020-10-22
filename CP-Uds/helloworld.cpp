#include <cstdio>

int main (){
	int t;
	scanf("%d" , &t);
	char  name[100];
	while(t--){
		scanf("%s" , &name);
		printf("Hello %s!\n", name);
	}
	return 0;
}
