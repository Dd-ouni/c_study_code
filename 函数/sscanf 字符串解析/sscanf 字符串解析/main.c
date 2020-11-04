#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// sscanf ÓÃÀý1
void test01() {
	char* ip = "127.0.0.1:8080";
	int ip1, ip2, ip3, ip4, port;
	sscanf(ip, "%d%*[.]%d%*[.]%d%*[.]%d%*[:]%d", &ip1, &ip2, &ip3, &ip4, &port);
	printf("%d %d %d %d %d", ip1, ip2, ip3, ip4, port);
};

// sscanf ÓÃÀý2
void test02() {
	char* email = "ddouni2457@126.com";
	char buf1[1024] = { 0 };
	char buf2[1024] = { 0 };
	sscanf(email, "%[a-z0-9]%*[@]%[a-z0-9.]", buf1, buf2);
	printf("%s %s\n", buf1, buf2);
}
int main(int argc, char* argv[]) {
	test02();
	system("pause");
	return 0;
}