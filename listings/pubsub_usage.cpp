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
	PubSubSystem::getInstance().init(700)
	IChannel bcast = PubSubSystem::getInstance().getChannelHandle(BROADCAST);
	
	app_deliver_func f = boost::bind(deliver, "[node 1]", _1);
	PubSubSystem::getInstance().init(7001, "localhost", 7000).subscribe(BROADCAST, f);
	
	app_deliver_func f_2 = boost::bind(deliver, "[node 2]", _1);
	PubSubSystem::getInstance().init(7002, "localhost", 7000).subscribe(BROADCAST, f_2);
	

	while(true) {
			bcast->publish("Nachricht an Alle.");
			boost::this_thread::sleep(boost::posix_time::seconds(5));
	}
	
	return 0;
}
