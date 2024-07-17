/*

for equation ax + by = gcd(a, b), Extended Euclidean algorithm can be used to calculate 1 solution of x and y
Let that solution be x0, y0

for equation ax + by = c, for a solution to exist c % gcd(a, b) bust be 0
General solution of x and y in this case :-

x = x0 * k(b / g), where k is any integer and g is gcd(a, b)
y = y0 * k(a / g), where k is any integer and g is gcd(a, b)
this hold only if a != 0 && b != 0
for a == 0 || b == 0 handle this case seperately

Source :- https://cp-algorithms.com/algebra/linear-diophantine-equation.html

*/

//gives value of x0 and y0
int extended_euclidean(int a, int b, int &x0, int &y0) 
{
    if (b == 0) 
    {
        x0 = 1;
        y0 = 0;
        return a;
    }
    int x, y;
    int d = extended_euclidean(b, a % b, x, y);
    x0 = y;
    y0 = x - y * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) 
{
    g = extended_euclidean(abs(a), abs(b), x0, y0);
    if (c % g) return false;
    x0 = x0 * c / g;
    y0 = y0 * c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}