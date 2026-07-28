class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int NetGain =0;
        int HighestAlt =0;
        for(int i=0;i<gain.size();i++){
            NetGain += gain[i];
            if(NetGain > HighestAlt) HighestAlt = NetGain;
        }
        return HighestAlt;
    }
};