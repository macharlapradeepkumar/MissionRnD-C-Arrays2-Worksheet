/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int num(char *dob1,int i);
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int oneday = 0, onemon = 0, oneyar = 0, secday = 0, secmon = 0, secyar = 0, l=0,m=0;
	oneday = num(date ,0);  
	onemon = num(date, 3);
	oneyar = num(date, 6);
	for (int i = 0; i < len; i++){
		secday = num(Arr[i].date, 0);
		secmon = num(Arr[i].date, 3);
		secyar = num(Arr[i].date, 6);
		if ((oneyar == secyar) && (onemon == secmon) && (oneday == secday))
			l++;
		if (l > 0)
		{
			if ((oneyar != secyar) || (onemon != secmon) || (oneday != secday))
				m++;
		}
	}
	return m;
}
int num(char *a, int i)
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