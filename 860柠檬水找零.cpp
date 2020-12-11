class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        unordered_map<int, int> myMoney;
        for (auto i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                Process5case(myMoney);
                continue;
            }
            if (bills[i] == 10) {
                if (Process10case(myMoney)) {
                    continue;
                }
                return false;
            }
            if (bills[i] == 20) {
                if (Process20case(myMoney)) {
                    continue;
                }
                return false;
            }
        }
        return true;
    }

private:
    bool Process5case(unordered_map<int, int>& myMoney)
    {
        myMoney[0]++;
        return true;
    }

    bool Process10case(unordered_map<int, int>& myMoney)
    {
        myMoney[1]++;
        myMoney[0]--;
        if (myMoney[0] < 0) {
            return false;
        }
        return true;
    }

    bool Process20case(unordered_map<int, int>& myMoney)
    {
        myMoney[2]++;
        if (myMoney[0] <= 0) {
            return false;
        }
        int ret = 0; 
        if (myMoney[1] > 0) {
            ret += 10;
            myMoney[1]--;
        }
        while (myMoney[0] > 0 && ret != 15) {
            myMoney[0]--;
            ret += 5;
        }
        if (ret != 15) {
            return false;
        }
        return true;
    }
};