#include <cstdio> 
#include <cmath>

using namespace std; 

int main () {
	int months;
	float downPayment, amount;
	int depRecords;
	while (scanf("%d %f %f %d", &months, &downPayment, &amount, &depRecords) && (months > 0) ){
		float *depRec = new float[depRecords];
		for (int i =  0; i < depRecords; i++)
		{
		int t1;
		float t2;
		scanf("%d %f", &t1,&t2);
		depRec[i] = t2 + t1;	
		}
		int cmonth = -1; 
		float totalAmount = amount + downPayment;
		float currentAmount = totalAmount;
		float paidAmount = 0;
		float oneLoanPayment  = amount / months;
		while(currentAmount <=  (amount - paidAmount) || cmonth == -1  ){
			cmonth ++;
			if (cmonth != 0)
				paidAmount += oneLoanPayment;
			//find dep this month
			float depValue = 0;			
			for (int i = 0; i < depRecords;  i++)
				if (  floor(depRec[i]) <= cmonth )
					depValue = depRec[i] - floor(depRec[i]);
			//printf("month is %d with dep rate %f\n", cmonth , depValue);
			currentAmount = currentAmount - currentAmount * depValue;
			//printf(" Current Value : %f ,  Left to Repay : %f\n", currentAmount , (amount - paidAmount));
		};
		if (cmonth == 1)
			printf ("1 month\n");
		else 
			printf("%d months\n" , cmonth);
		delete [] depRec;
	}
	return 0;
}
