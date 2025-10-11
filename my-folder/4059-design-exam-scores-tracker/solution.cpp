class ExamTracker {
public:
    vector<int>times;
    vector<long long>preScores;
    ExamTracker()
    {
    }
    
    void record(int time, int score)
    {
        times.push_back(time);
        if(preScores.size() == 0)
        {
            preScores.push_back(score);
        }
        else
        {
            preScores.push_back((long long)score + preScores[preScores.size() - 1]);
        }
    }
    
    long long totalScore(int startTime, int endTime)
    {
        auto it = lower_bound(times.begin(),times.end(),startTime);
        auto it2 = upper_bound(times.begin(),times.end(),endTime);
        if(it2 == times.begin())
        {
            return 0;
        }
        int idx = it - times.begin();
        it2--;
        int idx2 = it2 - times.begin();
        if(idx2 < idx)
        {
            return 0;
        }
        return preScores[idx2] - (idx > 0 ? preScores[idx - 1] : 0);
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
