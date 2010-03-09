void route(Key* key, const Message& msg, NodeHandle* hint);
void forward(Key& key, Message& msg, NodeHandle* nextHop);
void deliver(const Key& key, const Message& msg)
// routing
local_lookup(in key:Key, in num:int, in safe:bool):NodeHandle[]
neighborSet(in num:int):NodeHandle[]
replicaSet(in key:Key, in maxRank:int):NodeHandle[]
update(in node:NodeHandle, in joined:bool):void
range(in node:NodeHandle, in rank:Rank, inout lkey:Key, inout rkey:Key):bool
