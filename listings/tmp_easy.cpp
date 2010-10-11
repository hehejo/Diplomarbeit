template <typename T>
T min (T a, T b) {
	if (a < b || a == b)
		return a;
	return b;
}

// Aufruf
int minimal = min<int>(5, 9);
