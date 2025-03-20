vector<Point> convexHull(vector<Point>& pnt)
{
    vector<Point> hull;
    sort(pnt.begin(), pnt.end());
    for (int i=0; i<2; i++) {
        int start = hull.size();
        for (Point p: pnt) {
            while (hull.size() >= 2 + start && (hull[hull.size()-1] - hull[hull.size()-2]).cross((p - hull[hull.size()-1])) >= 0) {
                hull.pop_back();
            }
            hull.push_back(p);
        }
        hull.pop_back();
        reverse(pnt.begin(), pnt.end());
    }
    return hull;
}