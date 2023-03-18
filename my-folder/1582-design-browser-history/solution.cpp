class BrowserHistory {
public:
    vector<string > arr;
    int i , curr_end;
    BrowserHistory(string homepage)
    {
        arr.push_back(homepage);
        i = 0;
        curr_end = 0;
    }
    
    void visit(string url)
    {
        curr_end = i + 1;
        if(arr.size() <= curr_end)
        {
            arr.push_back(url);
            i++;
        }
        else
        {
            arr[curr_end] = url;
            i++;
        }
    }
    
    string back(int steps)
    {
        while(steps != 0)
        {
            if(i == 0)
                break;
            i--;
            steps--;
        }
        return arr[i];
    }
    
    string forward(int steps)
    {
        while(steps != 0)
        {
            if(i == curr_end)
                break;
            i++;
            steps--;
        }
        return arr[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
