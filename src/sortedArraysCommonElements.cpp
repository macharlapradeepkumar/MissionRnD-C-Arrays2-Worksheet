/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int numb(char *a, int i);
int valid(char *dob1, char *dob2);

int numb(char *a, int i)
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

int valid(char *dob1, char *dob2)
{
	int i = 0, l = 0, m = 0, oneday = 0, secday = 0, onemon = 0, secmon = 0, oneyar = 0, secyar = 0;
	oneday = numb(dob1, 0);
	secday = numb(dob2, 0);
	onemon = numb(dob1, 3);
	secmon = numb(dob2, 3);
	oneyar = numb(dob1, 6);
	secyar = numb(dob2, 6);
	if ((oneyar == secyar) && (onemon == secmon) && (oneday == secday))
		return 1;
	else return 0;
}


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int m = 0, j = 0,k=0;
	struct transaction C[10];
	if (A == NULL || B == NULL) return NULL;
	for (int i = 0; i < ALen; i++){
		m = valid(A[i].date, B[i].date);
		if (m == 1){
			C[j] = A[i];
			j++;
			k++;
		}
		
	}
	if (k > 0)
		return C;
	else
		return NULL;
}