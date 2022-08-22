long findMaximumSum(vector<int> stockPrices, int k) {
    int low = 0;
    int high = k-1;
    set<int> s;
    map<int, int> m;
    long sum = 0;
    long ans = LONG_MIN;
    
    for(int i=0; i<=high; i++){
        sum += stockPrices[i];
        s.insert(stockPrices[i]);
    }
    
    if(s.size() == k) ans = max(ans, sum);
    
    while(high < stockPrices.size()){
        m[stockPrices[low]]--;
        sum -= stockPrices[low];
        if(m[stockPrices[low]] == 0) s.erase(stockPrices[low]);
        low++;
        high++;
        
        if(high < stockPrices.size()){
            sum += stockPrices[high];
            s.insert(stockPrices[high]);
            m[stockPrices[high]]++;
        }
        //if(sum == 14) cout<<s.size();
        //cout<<sum<<" ";
        if(s.size() == k) ans = max(ans, sum);
    }
    cout<<endl;
    
    return (ans<0)?-1:ans;
}