//字符串匹配算法

//蛮力匹配算法

//版本1

int match1(char* P, char* T) {
	size_t  n = strlen(T), i = 0;
	size_t  m = strlen(P), j = 0;
	while (j < m&&i < n) {
		if (T[i] == P[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	return i - j;
}

//版本2

int match2(char* P, char* T) {
	size_t  n = strlen(T), i = 0;
	size_t  m = strlen(P), j;
	for ( i = 0; i < n - m + 1; i++) {
		for (j = 0; j < m; j++) {
			if (T[i + j] == P[j]) {
				break;
			}
		}
		if (j >= m) {
			break;
		}
	}
	return i;
}

//KMP算法

int match(char* P, char* T) {
	int* next = buildNext(P);
	int n = (int)strlen(T), i = 0;
	int m = (int)strlen(P), j = 0;
	while (i < n&&j < m) {
		if (0 > j || T[i] == P[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	delete[] next;
	return i - j;
}

//构建next表

int* buildNext(char* P) {
	size_t m = strlen(P), j = 0;
	int* N = new int[m];
	int t = N[0] = -1;
	while (j < m - 1) {
		if (0 > t || P[j] == P[t]) {
			j++;
			t++;
			N[j] = (P[j] != P[t]) ? t : N[t];
		}
		else {
			t = N[t];
		}
	}
	return N;
}