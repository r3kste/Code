#include <ios>
int main() {
    int n, f;
    scanf ("%d", &n);

    while (n--) {
        scanf ("%d", &f);
        printf ("%d\n", f * (2024 - f));
    }
}