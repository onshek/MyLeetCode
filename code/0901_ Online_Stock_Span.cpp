class StockSpanner {
private:
    stack<pair<int, int>> infoStack;
    int cnt = 0;
public:
    StockSpanner() {}
    int next(int price) {
        int result;
        while ((!infoStack.empty()) && (infoStack.top().first <= price)) 
            infoStack.pop();

        if (!infoStack.empty()) result = cnt - infoStack.top().second;
        infoStack.push(pair<int, int>(price, cnt++));
        return infoStack.size() == 1 ? cnt : result;
    }
};