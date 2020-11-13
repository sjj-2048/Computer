#include"stack.h"

//½øÖÆ×ª»»

//µÝ¹é°æ
void convert(Stack<char> &S, _int64 n, int base) {
	static char digit[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	if (0 < n) {
		S.push(digit[n%base]);
	}
	convert(S, n / base, base);
}

//µü´ú°æ
void convert1(Stack<char> &S, _int64 n, int base) {
	static char digit[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	while (0 < n) {
		int remainder = (int)(n%base);
		S.push(digit[remainder]);
		n = n / base;
	}
}

//À¨ºÅÆ¥Åä

bool paren(const char exp[], int lo, int hi) {
	Stack<char> S;
	for (int i = 0; i < hi; i++) {
		switch (exp[i]) {
			case '(':case '{':case '[':
				S.push(exp[i]);
				break;
			case ')':
				if (S.empty() || (S.pop() != '(')) {
					return false;
					break;
				}
			case ']':
				if (S.empty() || (S.pop() != '[')) {
					return false;
					break;
				}
			case '}':
				if (S.empty() || (S.pop() != '{')) {
					return false;
					break;
				}
			default:
				break;
		}
	}
	return S.empty();
}