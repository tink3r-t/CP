#include <cstdio>

using namespace std;

int main (){
	int t , x , y , z , c = 1;
	scanf("%d" , &t);
		while(t--){
			scanf("%d %d %d" ,&x , &y , &z);
			if (  (x > y  &&  x  < z) || (x < y  &&  x >  z)  )
				printf("Case %d: %d\n" , c , x);
			else if (  (y > x  &&  y  < z) || (y < x  &&  y >  z)  )
				printf("Case %d: %d\n" , c , y);
			else printf("Case %d: %d\n" , c , z);
			
			c++;
			}
	return 0;
}


