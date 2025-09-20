struct Packet {
    int src, dst, time;
};

struct KeyHash {
    size_t operator()(const tuple<int,int,int>& t) const {
        auto [a,b,c] = t;
        return ((size_t)a * 1315423911u) ^ ((size_t)b * 2654435761u) ^ ((size_t)c);
    }
};
class Router {
private:
    int memoryLimit;
    deque<Packet> q;
    unordered_set<tuple<int,int,int>, KeyHash> packetSet;
    unordered_map<int, vector<int>> destMap;
public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int> key = {source, destination, timestamp};
        if (packetSet.count(key)) return false; 

        if ((int)q.size() == memoryLimit) {
            Packet old = q.front(); q.pop_front();
            packetSet.erase({old.src, old.dst, old.time});
            auto &arr = destMap[old.dst];
            auto it = lower_bound(arr.begin(), arr.end(), old.time);
            if (it != arr.end() && *it == old.time) arr.erase(it);
        }
        q.push_back({source, destination, timestamp});
        packetSet.insert(key);
        destMap[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        Packet p = q.front(); q.pop_front();
        packetSet.erase({p.src, p.dst, p.time});
        auto &arr = destMap[p.dst];
        auto it = lower_bound(arr.begin(), arr.end(), p.time);
        if (it != arr.end() && *it == p.time) arr.erase(it);

        return {p.src, p.dst, p.time};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &arr = destMap[destination];
        auto it1 = lower_bound(arr.begin(), arr.end(), startTime);
        auto it2 = upper_bound(arr.begin(), arr.end(), endTime);
        return (int)(it2 - it1);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */