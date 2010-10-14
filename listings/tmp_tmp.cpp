struct Widget { int dummy; };

template <class OBJ>
struct Creator  {
	static OBJ* create () {
		return new OBJ;
	}
};

// Template
template <class Maker>
struct WidgetFactory {
	static Widget* create() {
		return Maker::create();
	};
};

// Aufruf
WidgetFactory<Creator<Widget> >::create();
