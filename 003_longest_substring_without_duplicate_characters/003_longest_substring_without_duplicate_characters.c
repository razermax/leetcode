#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int lengthOfLongestSubstring(char * s){

	int len = 0;
	int sublen = 0;
	int maxlen = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	if(s == NULL){
		return 0;
	}

	//总字符串长度
	len = strlen(s);

	for(i = 0; i<len; i++){
		//遍历子字符串，所有字符都不可以和后续字符重复
		for(j = k; j<i; j++){
			//出现重复
			if(s[j] == s[i]){
				k = j + 1;
				break;
			}
		}
		sublen = i - k + 1;
		if(sublen > maxlen){
			maxlen = sublen;
		}
	}
	return maxlen;
}
