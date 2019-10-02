#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

//abccba  2,3; -1 6; 6 - (-1) -1 
//abcba   2,2  -1 5  5 - (-1) -1
int FindPalindromeStr(char *s,int len,int left,int right)
{
	int l = left;
	int r = right;

	while(l >= 0 && r < len && s[l] == s[r]){
		l--;
		r++;
	}
	return r - l - 1;
}

char * longestPalindrome(char * s){
	int len = 0;
	int len1 = 0;
	int len2 = 0;
	int maxlen = 0;
	int maxtemp = 0;
	int start = 0;
	int i = 0;
	char* pStr = NULL;
	
	len = strlen(s);
	for(i = 0; i< len ; i++){
		//奇数扩展
		len1 = 	FindPalindromeStr(s,len,i,i);
		//偶数扩展
		len2 = 	FindPalindromeStr(s,len,i,i+1);
		//最长字符串
		maxtemp = len1 > len2? len1:len2;
		if(maxlen < maxtemp){
			maxlen = maxtemp;
			start = i - (maxlen - 1)/2;
		}
	}
	pStr = (char*)malloc(maxlen+1);
	if(pStr == NULL){
		return NULL;
	}
	memset(pStr,0,maxlen+1);
	strncpy(pStr,s+start,maxlen);
	return pStr;
}

int main()
{
	char *s = "aaaabccbadddd";
	longestPalindrome(s);
	return 0;
}