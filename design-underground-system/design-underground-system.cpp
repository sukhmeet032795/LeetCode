class UndergroundSystem {
public:
    
    typedef struct{
        string name;
        int time;
    }inbound;
    
    typedef struct{
        string name;
        int sum;
        int count;
    }station;
    
    map<string, list<station>> stations;
    map<int, inbound> m;
    
    UndergroundSystem() {
        m.clear();
        stations.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        
        inbound inb;
        inb.name = stationName;
        inb.time = t;
        m[id] = inb;
    }
    
    void checkOut(int id, string stationName, int t) {
        
        inbound tmp = m[id];
        m.erase(id);
        
        auto itr = (stations[tmp.name]).begin();
        for(; itr != (stations[tmp.name]).end(); ++itr)
        {
            if(itr->name == stationName)
            {
                station stat;
                stat.count = itr->count + 1;
                stat.name = stationName;
                stat.sum = (t - tmp.time) + itr->sum;
                stations[tmp.name].push_back(stat);
                break;
            }
        }
        
        if(itr != (stations[tmp.name]).end())
        {
            (stations[tmp.name]).erase(itr);
            return;
        }
        
        station stat;
        stat.count = 1;
        stat.name = stationName;
        stat.sum = (t - tmp.time);
        stations[tmp.name].push_back(stat);
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        list<station> stats = stations[startStation];
        for(auto &itr : stats)
        {
            if(itr.name == endStation)
            {
                double c = ((double)itr.count);
                return (itr.sum)/(c);
            }
        }
        
        return 0.0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

