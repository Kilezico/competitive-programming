struct Point {
    ll x, y;
    Point(ll x=0, ll y=0) : x(x), y(y) {}
    double len() { return hypot(x, y); }
    ll dot(Point& p2) { return (x*p2.x + y*p2.y); }
    ll cross(Point p2) { return (x*p2.y - y*p2.x); } // Retorna a componente Z
    Point operator+(Point& p2) { return Point(x + p2.x, y + p2.y); }
    Point operator-(Point& p2) { return Point(x - p2.x, y - p2.y); }
    bool operator<(Point& p2) { return (x != p2.x) ? (x < p2.x) : (y < p2.y); }
    bool operator==(Point &p2) { return (x == p2.x && y == p2.y); }
};
ostream& operator<<(ostream& os, Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}