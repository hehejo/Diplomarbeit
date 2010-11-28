namespace i6m2etis {
namespace pubsub {
typedef Channel</* ... */> SimpleChannelType;
typedef Channel</* ... */> NeighborhoodType;

class PubSubSystemImpl {
	friend class PubSubSystem;
public:
	PubSubSystemImpl() :
			controller_(new wrapper::chimera::ChimeraWrapper)
			, any_all(new SimpleChannelType("any_all", controller_))
			, position_(new NeighborhoodType("position", controller_))
			, chat_(new SimpleChannelType("chat", controller_))
	{	}	
	/* ... */
private:
	PubSubController controller_;
	IChannelOwn* any_all;
	IChannelOwn* position_;
	IChannelOwn* chat_;
	/* ... */
};
}
}
