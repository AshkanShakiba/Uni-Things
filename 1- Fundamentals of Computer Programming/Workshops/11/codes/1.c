#include <stdio.h>
int main(){
	FILE *testfile = fopen("test.txt", "wb");
	char *str = "Hello World";
	fwrite(str, sizeof(char), 11, testfile);
	fclose(testfile);
}
