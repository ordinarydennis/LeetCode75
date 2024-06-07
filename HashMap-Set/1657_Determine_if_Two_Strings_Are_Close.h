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