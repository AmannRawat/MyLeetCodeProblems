class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq;
        for(auto n:score){
            pq.push(n);
        }
        vector<pair<int,string>> v;
        int i=1;
        while(!pq.empty()){
            if(i==1){
                v.push_back(make_pair(1, "Gold Medal"));
                pq.pop();
                i++;
                continue;
            }
            if(i==2){
                v.push_back("Silver Medal");
                pq.pop();
                i++;
                continue;
            }       
            if(i==3){
                 v.push_back("Bronze Medal"); 
                 pq.pop();
                 i++;
                 continue;
            } 
            string a=to_string(i);
            v.push_back(a);   
            pq.pop();  
            i++;
        }
        return v;
    }
};