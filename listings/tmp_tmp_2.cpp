// Template Template
template <template <typename> class Maker>
struct WidgetFactory {
	static Widget* create() {
		return Maker<Widget>::create();
	};
};

// Aufruf
WidgetFactory<Creator>::create();
