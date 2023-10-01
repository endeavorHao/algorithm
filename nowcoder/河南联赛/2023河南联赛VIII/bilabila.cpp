#include <bits/stdc++.h>

using namespace std;

int main() {
	double sin18 = 0.30901699437494742410229341718282;
    double cos18 = 0.95105651629515357211643933337938;
    double sin36 = 0.58778525229247312916870595463907;
    double cos36 = 0.80901699437494742410229341718282;
    int n;
    scanf("%d", &n);
    double len = n * sin18;
    len += n;
    double x = len * sin36 / cos36;
    printf("A: %.2lf %.2lf\n", len, 0.00);
    printf("B: %.2lf %.2lf\n", n * cos36, 0.00 - x - n * sin36);
    printf("C: %.2lf %.2lf\n", 0.00 - n * cos36, 0.00 - x - n * sin36);
    printf("D: %.2lf %.2lf\n", 0.00 - len, 0.00);
    printf("E: %.2lf %.2lf\n", 0.00, n * cos18);
	return 0;
}
