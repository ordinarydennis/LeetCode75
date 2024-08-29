class Solution {
public:
	bool closeStrings(string word1, string word2) {

		std::set<char> countS1;
		std::unordered_map<char, int> countM1;

		for (char c : word1)
		{
			countM1[c]++;
			countS1.insert(c);
		}

		std::unordered_map<char, int> countM2;
		std::set<char> countS2;
		for (char c : word2)
		{
			countM2[c]++;
			countS2.insert(c);
		}

		std::vector<int> nCountV1;
		std::vector<int> nCountV2;

		for (const auto& [_, cn] : countM1)
			nCountV1.push_back(cn);

		for (const auto& [_, cn] : countM2)
			nCountV2.push_back(cn);

		std::sort(nCountV1.begin(), nCountV1.end());
		std::sort(nCountV2.begin(), nCountV2.end());

		return countS1 == countS2 && nCountV1 == nCountV2;
	}
};

class Solution {
public:
	bool closeStrings(string word1, string word2) {

		if (word1.size() != word2.size())
			return false;

		set<char> cSet1;
		unordered_map<char, int> map1;
		for (int i = 0;i < word1.size(); i++)
		{
			cSet1.insert(word1[i]);
			map1[word1[i]]++;
		}

		vector<int> v1;
		for (auto [_, o] : map1)
		{
			v1.push_back(o);
		}

		sort(v1.begin(), v1.end());

		set<char> cSet2;
		unordered_map<char, int> map2;
		for (int i = 0;i < word2.size(); i++)
		{
			cSet2.insert(word2[i]);
			map2[word2[i]]++;
		}

		vector<int> v2;
		for (auto [_, o] : map2)
		{
			v2.push_back(o);
		}
		sort(v2.begin(), v2.end());


		return cSet1 == cSet2 && v1 == v2;
	}
};

class Solution {
public:
	bool closeStrings(string word1, string word2) {
		if (word1.size() != word2.size())
			return false;

		vector<int> m1('z' - 'a' + 1, 0);
		vector<int> m2('z' - 'a' + 1, 0);

		for (int i = 0; i < word1.size(); i++)
		{
			m1[word1[i] - 'a']++;
			m2[word2[i] - 'a']++;
		}

		for (int i = 0; i < 'z' - 'a' + 1; i++)
		{
			if (m1[i] == 0 && m2[i] > 0 ||
				m2[i] == 0 && m1[i] > 0
				)
			{
				return false;
			}
		}

		sort(m1.begin(), m1.end());
		sort(m2.begin(), m2.end());

		return m1 == m2;
	}
};