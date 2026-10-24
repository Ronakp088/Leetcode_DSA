class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string t1(arriveAlice.begin(),arriveAlice.begin()+2);
        string t2(leaveAlice.begin(),leaveAlice.begin()+2);
        string t3(arriveBob.begin(),arriveBob.begin()+2);
        string t4(leaveBob.begin(),leaveBob.begin()+2);
        int Aam = stoi(t1);
        int Abm = stoi(t3);
        int Lam = stoi(t2);
        int Lbm = stoi(t4);
        int daysInMonths[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        string t5(arriveAlice.begin()+3,arriveAlice.end());
        string t6(leaveAlice.begin()+3,leaveAlice.end());
        string t7(arriveBob.begin()+3,arriveBob.end());
        string t8(leaveBob.begin()+3,leaveBob.end());
        int Aad = stoi(t5);
        int Abd = stoi(t7);
        int Lad = stoi(t6);
        int Lbd = stoi(t8);
        int enterDA = 0;
        int enterDB = 0;
        int exitDA = 0;
        int exitDB = 0;
        for(int i =0;i< Aam;i++){
            enterDA += daysInMonths[i];
        }
        for(int i =0;i< Abm;i++){
            enterDB += daysInMonths[i];
        }
        for(int i =0;i< Lam;i++){
            exitDA += daysInMonths[i];
        }
        for(int i =0;i< Lbm;i++){
            exitDB += daysInMonths[i];
        }
        enterDA += Aad;
        enterDB += Abd;
        exitDA += Lad;
        exitDB += Lbd;
        vector<int> arr;
        arr.push_back(enterDA);
        arr.push_back(enterDB);
        arr.push_back(exitDA);
        arr.push_back(exitDB);
        sort(arr.begin(),arr.end());

        if(exitDA < enterDB) return 0;
        else if(exitDB < enterDA) return 0;

        return arr[2]-arr[1] +1;
        

    }
};