// B1001.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>

int main()
{
	int n;
	int cnt = 0;
	scanf_s("%d", &n);
	while (n != 1) {
		if (n % 2 == 0) n = n / 2;
		else n = (3 * n + 1) / 2;
		cnt++;
	}
	printf("%d", cnt);
    return 0;
}

