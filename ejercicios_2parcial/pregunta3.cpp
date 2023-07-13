#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x;
    int y;
};

double calDistancia( Point& p1,  Point& p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double distanciaMin( vector<Point>& points, int izq, int der, double mascerca) {
    if (der - izq <= 3) {
        double minDistance = mascerca;
        for (int i = izq; i <= der; ++i) {
            for (int j = i + 1; j <= der; ++j) {
                double distance = calDistancia(points[i], points[j]);
                if (distance < minDistance) 
                    minDistance = distance;
            }
        }
        return minDistance;
    }

    int mid = (izq + der) / 2;
    Point midPoint = points[mid];

    double disMinIzq = distanciaMin(points, izq, mid, mascerca);
    double disMinDer = distanciaMin(points, mid + 1, der, mascerca);
    double minDistance = min(disMinIzq, disMinDer);

    vector<Point> strip;
    for (int i = izq; i <= der; ++i) {
        if (abs(points[i].x - midPoint.x) < minDistance) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), []( Point& p1,  Point& p2) {
        return p1.y < p2.y;
    });

    int stripSize = strip.size();
    for (int i = 0; i < stripSize; ++i) {
        for (int j = i + 1; j < stripSize && (strip[j].y - strip[i].y) < minDistance; ++j) {
            double distance = calDistancia(strip[i], strip[j]);
            if (distance < minDistance) 
                minDistance = distance;
        }
    }

    return minDistance;
}

int main() {
    int n;
    while (cin >> n && n > 0) {
        vector<Point> points(n);
        for (int i = 0; i < n; ++i) 
            cin >> points[i].x >> points[i].y;
        

        sort(points.begin(), points.end(), []( Point& p1,  Point& p2) {
            return p1.x < p2.x;
        });

        double mascerca = distanciaMin(points, 0, n - 1, numeric_limits<double>::max());

        if (mascerca < 10000) 
            cout << mascerca << endl;
        else 
            cout << "INFINITY" << endl;
    }

    return 0;
}
