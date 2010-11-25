void deliver(int type, net::MessageT message) {
  Header header(Header::split(message));
  /* ... */
  if (type == publish_) {
  	/* ... */
		BOOST_FOREACH(OrderInfoPtr info
			, Order::processPublishPayload(header.getSender()
					, header.getOrder()
					, header.getPersistence()
					, header.getValidity()
					, message))
		{
			bool invalid = Validity::processPublishPayload(info->sender, info->validity);
			if (invalid) continue;
			Persistence::processPublishPayload(info->sender, info->persistence, info->message);
			deliver_f(message);
		}
	}
}
