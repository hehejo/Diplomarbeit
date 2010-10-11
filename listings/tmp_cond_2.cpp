template <int v>
struct Int2Type {
	enum { value = v; }
};

template <bool isSingleton, class T>
struct factory {
	static T* create() {
		return create_impl(Int2Type<isSingleton>());
	}
	
	private:
	// generische Implementierung
	static T* create_impl(Int2Type<true>) {
		return T::getInstance();
	}
	
	// Spezialisierung
	static T* create_impl(Int2Type<false>) {
		return new T;
	}
};
