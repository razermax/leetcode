
#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"



//计算几个V字，行数*2-2，一个周期
//第一行s[rows*2-2] 0,6,12
//0     [6]        12
//1   5 7     11 13
//2 4   8  10    14
//3     9        15


char * convert(char * s, int numRows){
	int row = 0;
	int i = 0;
	int len = 0;
	char *zStr = NULL;
	char *pStr = NULL;

	//字符串长度
	len = strlen(s);
	//参数判断
	if(numRows>=len || numRows<2) {
		return s;
	}
	//申请排列后字符串内存
	zStr = (char*)malloc(len+1);
	if(zStr == NULL){
		return NULL;
	}
	//初始化内存
	memset(zStr,0,len+1);
	pStr = zStr;

	//遍历行
	for(row=0;row<numRows;row++){
		i=row;
		//第一行和最后一行只有1个字符,字符索引相差为,行数*2-2,
		//第一行，0,6,12,18...
		//最后一行，3,9,15
		if(row==0||row==numRows-1){
			while(i<len){
				*pStr=s[i];
				pStr++;
				i+=numRows*2-2;
			}
		}
		else{
			//遍历其他行
			while(i<len){
				*pStr=s[i];
				pStr++;
				i+=(numRows-row-1)*2;
				if(i<len){
					*pStr=s[i];
					pStr++;
					i+=row*2;
				}
			}
		}
	}
	return zStr;     
}



int main()
{
	char *str = "PAYPALISHIRING";
	int row =3;
	char *ret = NULL;
	ret = convert(str,3);
	return 0;
}
