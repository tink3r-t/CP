#include <cstdio>

using namespace std;

int main (){
	int t , x , y , dx, dy;
	while(scanf("%d" , &t)  && (t != 0)){
	scanf("%d %d" , &dx, &dy);
		while(t--){
			scanf("%d %d" ,&x , &y);
			if (dx == x || dy == y)
				printf("divisa\n");
			else if (dx < x && dy < y)
				printf("NE\n");
			else if (dx < x && dy > y)
				printf("SE\n");
			else if (dx > x && dy <  y)
				printf("NO\n");
			else printf("SO\n");
			}
		}
	return 0;
}

