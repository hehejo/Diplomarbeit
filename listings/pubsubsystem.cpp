IChannel* PubSubSystem::getChannelHandle(ChannelList channel) const {
 if (channel == ANY_ALL)	return impl_->any_all;
 if (channel == CHAT)	return impl_->chat_;
 return impl_->position_;
}
