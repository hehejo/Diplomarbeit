struct Header {
private:
  static const size_t start_Key = 0;
  static const size_t start_Algo = KeySize;
  static const size_t start_Filter = start_Algo + Algo::size;
  static const size_t start_Order = start_Filter + Filter::size;
  static const size_t start_Deliver = start_Order + Order::size;
  static const size_t start_Persistence = start_Deliver + Deliver::size;
  static const size_t start_Validity = start_Persistence + Persistence::size;
public:
	static const size_t size = KeySize + Algo::size + Filter::size + Order::size + Deliver::size + Persistence::size + Validity::size;
private:
	char header[size];
public:
	void putSender(const std::string & msg) {
		memcpy(header, msg.c_str(), KeySize);
	}

	std::string getSender() const {
		return std::string(header, KeySize);
	}

#define ACCESSOR(FIELD)\
void put##FIELD(const std::string& msg) { \
memcpy(header+start_##FIELD , msg.c_str(), FIELD::size); \
} \
std::string get##FIELD() const{ \
return std::string(header+start_##FIELD , FIELD::size); \
}

	ACCESSOR(Algo)
	ACCESSOR(Filter)
	ACCESSOR(Order)
	/* ... */
};
