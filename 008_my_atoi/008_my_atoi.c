
#include "string.h"
#include <stdio.h>
#include <stdlib.h>


int myAtoi(char * str){
    char *p = NULL;
    int len = 0;
    int i =0;
    long long num =0;
    int flag =0;
	int numflag = 0;
    if(str == NULL){
        return 0;
    }
    p = str;
    len = strlen(str);
    while(i<len){
        //去掉无效空格
        if(str[i] == ' '){
			if(numflag == 0 && flag == 0){
				i++;
				continue;
			}else{
				break;
			}
        }
        //判断符号
        if(str[i] == '-' || str[i] == '+'){
			if(flag){
				break;
			}
            //还没有数据时，符号是有效字符
            if(numflag == 0){
                if(str[i] == '-'){
                    flag = 1;   
                }else{
                    flag = 2;
                }
                i++;
                continue;
            }else{
                //当已经有数据时，-已经是无效字符了
                break;
            }
        }
        if(str[i]>='0' && str[i]<='9'){
			numflag = 1;
            num = num*10 + (str[i]-48);
			if (num >= 2147483648) {
				if(flag == 1){
					return -2147483648;
				}else{
					return 2147483647;
				}
			}
            i++;
            continue;
        }else{
			//已经解析数据之后出现乱码		
			break;
		}
    }
	if(flag == 1){
		num = 0 - num;
	}
	return num;
}





int _tmain(int argc, _TCHAR* argv[])
{
	char * str1 = "123456";
	char * str2 = "  123456  ";
	char * str3 = "@#!123456!@#";
	char * str4 = "!@#+123456++";
	char * str5 = "-123456";
	char * str6 = "!@#-123456!@#+123";
	char * str7 = "-91283472332";
	char * str8 = "words and 987";
	char * str9 = "+-2";
	char * str10 = "   +0 123";

	int n =0;

	n = myAtoi(str1);
	printf("1:%d\n",n);

	n = myAtoi(str2);
	printf("2:%d\n",n);

	n = myAtoi(str3);
	printf("3:%d\n",n);

	n = myAtoi(str4);
	printf("4:%d\n",n);

	n = myAtoi(str5);
	printf("5:%d\n",n);

	n = myAtoi(str6);
	printf("6:%d\n",n);

	n = myAtoi(str7);
	printf("7:%d\n",n);

	n = myAtoi(str8);
	printf("8:%d\n",n);

	n = myAtoi(str9);
	printf("9:%d\n",n);
	
	n = myAtoi(str10);
	printf("10:%d\n",n);
	return 0;
}