#include <iostream>

using namespace std;
int main() {
    long long k, m, d, week, a1, counter, days, start;
    cin >> k >> m >> d;
    long long prev = 0;
    if (d > 5) {
        start = m;
    } else {
        start = m + (8 - d - 2) * k;
    }
    week = start - (2 + (8 - d - 1)) * (8 - d) / 2;
    if (week < 0) {
        a1 = 1;
        week = m;
        counter = 0;
        for (long long i = d; i <= 7; ++i) {
            if (i>5) {
                week -= a1;
            } else {
                week = week - a1 + k;
            }
            a1++;
            if (week < 0) {
                cout << counter;
                return 0;
            }
            counter += 1;
        }
        cout << counter;
        return 0;
    }
    a1 = 8 - d + 1;
    days = 8 - d;
    long long last_positive_week = week;
    long long last_positive_a1 = a1;
    long long last_positive_days = days;

    while (week > 0) {
        days += 7;
        prev = week;
        week = week + 5 * k - (2 * a1 + 7) * 7 / 2;
        a1 += 7;

        if (week > 0) {
            last_positive_week = week;
            last_positive_a1 = a1;
            last_positive_days = days;
        }
    }
    cout << days << endl;
    cout << a1 << endl;
    cout << week << endl;
    cout << "---" << endl;

    if (week == 0) {
        counter = 1;
        while (week == 0) {
            days += 1;
            if (counter > 5) {
                week = week - a1;
            } else {
                week = week + k - a1;
            }
            a1 += 1;
            counter += 1;
        }
        cout << days - 1;
    } else {
        days -= 7;
        a1 -= 7;
        week = prev;
        long long left = 0;
        long long right = 7;
        long long mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (mid > 5) {
                if (week - (2 * a1 + mid) * mid / 2 > 0) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else {
                if (week + mid * k - (2 * a1 + mid) * mid / 2 > 0) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        cout << days + left;
    }
    return 0;
}