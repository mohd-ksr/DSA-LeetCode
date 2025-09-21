class MovieRentingSystem {
private:
    // (shop, movie) -> price
    unordered_map<long long, int> priceMap;

    // movie -> available copies (price, shop)
    unordered_map<int, set<pair<int,int>>> available;

    // rented movies (price, shop, movie)
    set<tuple<int,int,int>> rented;

    long long encode(int shop, int movie) {
        return ((long long)shop << 32) | (unsigned int)movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[encode(shop, movie)] = price;
            available[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (!available.count(movie)) return res;
        int cnt = 0;
        for (auto &[price, shop] : available[movie]) {
            if (cnt == 5) break;
            res.push_back(shop);
            cnt++;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = priceMap[encode(shop, movie)];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceMap[encode(shop, movie)];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto &[price, shop, movie] : rented) {
            if (cnt == 5) break;
            res.push_back({shop, movie});
            cnt++;
        }
        return res;
    }
};
