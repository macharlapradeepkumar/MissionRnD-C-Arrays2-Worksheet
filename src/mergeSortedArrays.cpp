/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int mnum(char *a, int i);
int mvalid(char *dob1, char *dob2);
int young(int a, int b, int c, int d, int e, int f);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL) return NULL;
 struct transaction C[20];
 int i = 0, j = 0, k = 0,p=0;
 while (i < ALen&&j < BLen){
	  p = mvalid(A[i].date, B[j].date);
	 if (p == 1){
		 C[k] = A[i];
		 i++;
		 k++;
	 }
	 else{
		 C[k] = B[j];
		 k++;
		 j++;
	 }
 }
	 while (i < ALen){
		 C[k] = A[i];
		 k++;
		 i++;
	 }
	 while (j < BLen){
		 C[k] = B[j];
		 k++;
		 j++;

	 }
	 return C;
	
}

int mvalid(char *dob1, char *dob2)
{
	int i , oneday = 0, secday = 0, onemon = 0, secmon = 0, oneyar = 0, secyar = 0;
	oneday = mnum(dob1, 0);
	secday = mnum(dob2, 0);
	onemon = mnum(dob1, 3);
	secmon = mnum(dob2, 3);
	oneyar = mnum(dob1, 6);
	secyar = mnum(dob2, 6);
	i = young(oneyar, secyar, onemon, secmon, oneday, secday);
return i;
}
int young(int a, int b, int c, int d, int e, int f)
{
	if (a > b)
		return 2;
	else if (a < b)
		return 1;
	else if (c > d)
		return 2;
	else if (c < d)
		return 1;
	else if (e > f)
		return 2;
	else
		return 1;
}
int mnum(char *a, int i)
{
	int  k = 0;
	while (a[i] != '-' && a[i] != '\0')
	{
		if (a[i] >= 48 || a[i] > 58)

			k = k * 10 + (a[i] - '0');
		i++;
	}
	return k;
}