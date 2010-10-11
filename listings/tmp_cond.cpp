template <bool isSingleton, class T>
struct factory {
	static T* create() {
		if(isSingleton) {
			return T::getInstance();
		}
		return new T;
	}
};

// Aufruf
struct Foo { int x; };
Foo* bar = Factory<false, Foo>::create();
