class Solution
{
public:
    long long min(int a, long long b)
    {
        if (a < b)
        {
            return a;
        }
        return b;
    }
    long long maxi(long long a, long long b)
    {
        if (a > b)
        {
            return a;
        }
        return b;
    }

    long long maximumSumOfHeights(vector<int> &mh)
    {
        cout << endl
             << "hit" << endl;

        long long n = mh.size();
        long long ans = 0, max = -1, ind = -1;
        vector<int> run;

        for (long long i = 0; i < n; i++)
        {
            if (mh[i] > max)
            {
                max = mh[i];
                ind = i;
            }
        }

        vector<int> index;
        for (long long i = 0; i < n; i++)
        {
            if (mh[i] == max)
            {
                index.push_back(i);
            }
        }
        int size = index.size();
        int tempMin = n;
        cout << endl
             << "ind array is ";
        for (int i = 0; i < size; i++)
        {
            cout << index[i] << " ";
        }
        cout << endl;

        if (size > 1)
        {
            for (int i = 0; i < size; i++)
            {
                if (tempMin > (abs(index[i] - (n / 2))))
                {
                    cout << "te " << tempMin << endl;
                    tempMin = index[i];
                }
            }
            for (int i = 0; i < size; i++)
            {
                if (tempMin == (abs(index[i] - (n / 2))))
                {
                    run.push_back(index[i]);
                }
            }

            ind = tempMin;
            cout << tempMin << endl;
        }

        cout << "im ind" << ind << endl;

        cout << endl
             << "run array is ";
        for (int i = 0; i < size; i++)
        {
            cout << index[i] << " ";
        }
        cout << endl;

        if (!run.size())
        {
            for (int i = 0; i < run.size(); i++)
            {
                cout << "veda";
                ind = run[i];
                long long now = 0;
                long long temp = max;
                for (long long i = ind; i < n; i++)
                {
                    temp = min(mh[i], temp);
                    now += temp;
                }

                temp = max;
                if (ind != 0)
                    for (int i = ind - 1; i >= 0; i--)
                    {
                        temp = min(mh[i], temp);
                        now += temp;
                    }

                ans = maxi(ans, now);
                cout << "im ans" << ans << endl;
            }
        }
        else
        {
            long long now = 0;
            cout << "im in else";
            long long temp = max;
            for (long long i = ind; i < n; i++)
            {
                temp = min(mh[i], temp);
                now += temp;
            }

            temp = max;
            if (ind != 0)
                for (int i = ind - 1; i >= 0; i--)
                {
                    temp = min(mh[i], temp);
                    now += temp;
                }

            ans = now;
            cout << "im ans" << ans << endl;
        }
        return ans;
    }
};