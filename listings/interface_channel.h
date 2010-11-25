#include "boost/function.hpp"
#include "net/MessageT.h"

namespace i6m2etis {
namespace pubsub {
typedef boost::function<void(const net::MessageT&)> app_deliver_func;

struct IChannel {
    virtual ~IChannel() {}
    virtual void publish(const net::MessageT& msg) = 0;
    virtual std::string getChannel() const = 0;
};

struct IChannelOwn : public IChannel {
    virtual ~IChannelOwn() {}
    virtual void subscribe(app_deliver_func, const net::MessageT& predicate) = 0;
    virtual void unsubscribe() = 0;
    virtual void init() = 0;
};
}
}
