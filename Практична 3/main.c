#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define MAX_P 30
long long countNumbers(int p) {

	long long dp0[MAX_P + 1] = { 0 };
	long long dp1[MAX_P + 1] = { 0 };

	dp0[1] = 2; // "5", "9"
	dp1[1] = 0;
	dp0[2] = 2 * 2; // "55", "59", "95", "99"
	dp1[2] = 2; // "55", "99"

	for (int i = 3; i <= p; i++) {
		dp0[i] = dp0[i - 1] * 2 - dp1[i - 1]; // Можна додати 5 або 9
		dp1[i] = dp0[i - 1]; // Додаємо ще одну цифру (55 або 99)
	}

	return dp0[p];
}
int main() {
	setlocale(LC_ALL, "Ukr");
	int p;
	printf("Введiть кiлькiсть розрядiв p (p менше 30): ");
	scanf("%d", &p);
	if (p <= 0 || p > MAX_P) {
		printf("Невiрний вхiд. Значення p повинно бути в дiапазонi вiд 1 до 30.\n");
		return 1;
	}
	long long result = countNumbers(p);
	printf("Кiлькiсть чисел iз %d розрядiв: %lld\n", p, result);
	return 0;
}