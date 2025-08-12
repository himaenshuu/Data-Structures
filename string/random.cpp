class Solution
{
public:
	long long minimumActivationTime(string &signal, vector<int> &pulseOrder, long long targetK)
	{
		int n = signal.size();
		long long totalSubs = 1LL * n * (n + 1) / 2;

		auto isActiveAt = [&](int t)
		{
			vector<char> canvas(n, 0);
			for (int i = 0; i < t; ++i)
			{
				canvas[pulseOrder[i]] = 1;
			}
			long long invalid = 0, streak = 0;
			for (int pos = 0; pos < n; ++pos)
			{
				if (!canvas[pos])
				{
					++streak;
				}
				else
				{
					invalid += streak * (streak + 1) / 2;
					streak = 0;
				}
			}
			invalid += streak * (streak + 1) / 2;

			long long valid = totalSubs - invalid;
			return valid >= targetK;
		};
		int lo = 1, hi = n, ans = -1;
		while (lo <= hi)
		{
			int mid = (lo + hi) >> 1;
			if (isActiveAt(mid))
			{
				ans = mid;
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}
		return ans;
	}
};
