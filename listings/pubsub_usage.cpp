#include <iostream>
#include "pubsub/PubSubSystem.h"
#include "boost/thread.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace std;
using namespace i6m2etis::pubsub;
using namespace i6m2etis::net;

void deliver(const string& node, const MessageT& message) {       
	cout << node << " " << ptime(second_clock::local_time()) << ": "<< MessageTHelper::to_str(message) << endl;
}

int main() {
	PubSubSystem::getInstance().init(7000);
	IChannel* any = PubSubSystem::getInstance().getChannelHandle(ANY_ALL);
	
	app_deliver_func f = boost::bind(deliver, "[node 1]", _1);
	PubSubSystem::getInstance().init(7001, "localhost", 7000).subscribe(ANY_ALL, f);
	
	app_deliver_func f_2 = boost::bind(deliver, "[node 2]", _1);
	PubSubSystem::getInstance().init(7002, "localhost", 7000).subscribe(ANY_ALL, f_2);
	
	MessageT msg;
	MessageTHelper::transform(msg, "Nachricht an Alle.");
	while(true) {
			any->publish(msg);
			boost::this_thread::sleep(boost::posix_time::seconds(5));
	}
	
	return 0;
}
