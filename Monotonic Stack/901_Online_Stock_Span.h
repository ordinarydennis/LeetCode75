class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {

        list.push_back(price);

        int rbegin = list.size() - 1;

        int ret = 0;

        for (int i = rbegin; 0 <= i; i--)
        {
            if (list[i] <= price)
            {
                ret++;
            }
            else
            {
                break;
            }

        }

        return ret;
    }



private:

    vector<int> list;

};



class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {

        int add = 1;

        while (st.size() && st.top().first <= price)
        {
            auto p = st.top();

            add += p.second;

            st.pop();
        }

        st.push({ price , add });

        return add;
    }


private:
    stack<pair<int, int>> st;

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
