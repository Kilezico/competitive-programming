vector<Point> ConvexHull(vector<Point> pnt)
{
    vector<Point> hull;
    sort(pnt.begin(), pnt.end()); // Se já tiver ordenado, não precisas
    for (int i=0; i<2; i++) {
        for (Point p: pnt) {
            while (hull.size() >= 2 && (hull[hull.size()-1] - hull[hull.size()-2]).cross((p - hull[hull.size()-1])) > 0) {
                hull.pop_back();
            }
            hull.push_back(p);
        }
        hull.pop_back();
        if (i == 0) reverse(pnt.begin(), pnt.end());
    }
    return hull;
}