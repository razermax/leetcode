


int reverse(int x){
	long ret = 0;
	int max_value = 2147483647;
	int min_value = -2147483648;

	while(x != 0){
		ret = ret*10+x%10;
		x /= 10;
	}
	if(ret<min_value || ret>max_value){
		return 0;
	}else{
		return ret;
	}
}

