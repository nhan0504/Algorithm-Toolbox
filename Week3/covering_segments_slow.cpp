#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};

bool compare(Segment& a, Segment& b) {
    return a.start < b.start;
}

int get_point(vector<Segment>& segments, int maxEndPoint) {
    int i = 0;
    while (i < maxEndPoint) {

        for (int j = 0; j < segments.size(); j++) {
            if (i == segments[j].end) {
                int k = 0;
                while (k < segments.size()) {                   
                    if (i >= segments[k].start && i <= segments[k].end) {
                        segments.erase(segments.begin() + k);
                    }
                    else {
                        k++;
                    }                  
                }
                return i;
            }
        }   

        i++;
    }
}

vector<int> optimal_points(vector<Segment>& segments) {
  vector<int> points;
  sort(segments.begin(), segments.end(), compare);
  int maxEndPoint = 0;
  for (int i = 0; i < segments.size(); i++) {
      if (segments[i].end > maxEndPoint) {
          maxEndPoint = segments[i].end;
      }
  }
  while (!segments.empty()) {
      int point = get_point(segments, maxEndPoint);
      points.push_back(point);
  }
  return points;
}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        cout << points[i] << " ";
    }
}
