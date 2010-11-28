void publish(const net::MessageT& message_text) {
	Header header;
	header.putSender(self_); // always add the sender
	header.putAlgo(Algo::getPublishPayload());
	header.putDeliver(Deliver::getPublishPayload());
	header.putOrder(Order::getPublishPayload());
	header.putPersistence(Persistence::getPublishPayload());
	header.putValidity(Validity::getPublishPayload());
	header.putFilter(Filter::getPublishPayload(message_text));
	sendMessages(publish_, header, message_text);
}

void sendMessages(int msg_type, const Header& h, const net::MessageT& payload) const {
	MsgType type;
	if (msg_type == subscribe_)		type = SUBSCRIBE;
	else if (msg_type == unsubscribe_)		type = UNSUBSCRIBE;
	else if (msg_type == publish_)		type = PUBLISH;
	else	type = UNKNOWN;

	MessageT sending;
	sending.resize(h.size+payload.size());
	std::string hh = h.get();
	copy(hh.begin(), hh.end(), sending.begin());
	copy(payload.begin(), payload.end(), sending.begin() + h.size);
	const net::MessageT enc = Security::encrypt(sending);

	bool need_filter = false;
	std::string filterinfo = "";
	std::string algoinfo = "";
	if (type == PUBLISH) {
		algoinfo = h.getAlgo();
		need_filter = Algo::needFiltering(algoinfo);
		if (need_filter)	filterinfo = h.getFilter();
	}
	
	BOOST_FOREACH(std::string to, Algo::getTargetNodes(type, algoinfo)) {
		if (need_filter && (Filter::match(to, filterinfo, payload) == false))
			continue;
		controller_.send(msg_type, to, enc);
	}
}   
