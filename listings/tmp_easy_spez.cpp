template <typename T>
T min (T a, T b) {
	if (a <= b)
		return a;
	return b;
}

struct Pair { int x; int y; };

// Spezialisierung des Funktiontemplates min
template<>
Pair min(Pair a, Pair b) {
	return /* ... */;
};

// Aufruf
extern Pair m, n;
int minimal = min<int>(5, 9);
Pair minimal = min<Pair>(m, n);
