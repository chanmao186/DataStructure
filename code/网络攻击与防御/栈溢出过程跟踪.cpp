#include<iostream>

void function(char* buf_src, int i) {
	char buf_dest[54];
	printf("i=%d", i);
	strcpy_s(buf_dest, buf_src);
}

int main() {
	int k;
	char str[128];
	for (int k = 0; k < 126; k++) {
		str[k] = 'b';
	}
	str[127] = '/0';
	function(str, 1);
	return 0;
}