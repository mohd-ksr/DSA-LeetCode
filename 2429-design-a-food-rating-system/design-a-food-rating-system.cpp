

struct FoodComparator {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        if (a.first != b.first) return a.first > b.first; 
        return a.second < b.second; 
    }
};

class FoodRatings {
private:
    unordered_map<string, pair<string,int>>foodInfo;
    unordered_map<string, set<pair<int, string>, FoodComparator>>cuisinesFoods;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodInfo[foods[i]] = {cuisines[i],ratings[i]};
            cuisinesFoods[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
       auto [cuisine, oldRating] = foodInfo[food];
       cuisinesFoods[cuisine].erase({oldRating, food}); 
       cuisinesFoods[cuisine].insert({newRating, food}); 
       foodInfo[food] = {cuisine, newRating};
    }
    
    string highestRated(string cuisine) {
        return cuisinesFoods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */