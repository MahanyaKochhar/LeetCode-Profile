class Bank {
public:
    vector<long long> actuals;
    Bank(vector<long long>& balance) {
        actuals.push_back(0);
        for(auto& x : balance)
        {
            actuals.push_back(x);
        }
    }

    bool valid(int account)
    {
        if(account >= 1 && account < actuals.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool transfer(int account1, int account2, long long money)
    {
        if(valid(account1) && valid(account2) && actuals[account1] >= money)
        {
            actuals[account1] -= money;
            actuals[account2] += money;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool deposit(int account, long long money)
    {
        if(valid(account))
        {
            actuals[account] += money;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool withdraw(int account, long long money)
    {
        if(valid(account) && actuals[account] >= money)
        {
            actuals[account] -= money;
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
