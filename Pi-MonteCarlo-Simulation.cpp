#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double calculatePi(int num_points) {
    int count_inside_circle = 0;

    for (int i = 0; i < num_points; i++) {
        double x = (double)rand() / RAND_MAX * 2.0 - 1.0;
        double y = (double)rand() / RAND_MAX * 2.0 - 1.0;

        if (x * x + y * y <= 1) {
            count_inside_circle++;
        }
    }

    return 4.0 * count_inside_circle / num_points;
}

int main() {
    srand(time(0));
    int num_points = 10000000;

    double pi_estimate = calculatePi(num_points);
    cout << " PI : " << pi_estimate << endl;

    return 0;
}
