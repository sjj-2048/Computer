#include"stack.h"

//½øÖÆ×ª»»

void convert(Stack<char> &S, _int64 n, int base) {
	static char digit[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	if (0 < n) {
		S.push(digit[n%base]);
	}
	convert(S, n / base, base);
}
