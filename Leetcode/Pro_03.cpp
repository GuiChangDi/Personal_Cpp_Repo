#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Example:
"abcabcbb"

the LongestSubstring is "abc", return is 3.
*/

class Solution {
public:
  int lengthOfLongestSubstring(string s){
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
      if (dict[s[i]] > start)
        start = dict[s[i]];
      dict[s[i]] = i;
      maxLen = max(maxLen, i - start);
    }
    return maxLen;
  }
};

/*
用start储存子串起始下标，每当发现重复字符或字符串遍历完成就计算一遍当前子串长度

int lengthOfLongestSubstring(char * s){
    int i, j = 0, count = 0, max = 0, index[128] = {0}, start = 0;
    for(i=0;s[i]!='\0';i++)     
    {
        if(index[s[i]]>start)   //index用来储存出现重复字符时
        {                       //子串起始下标应移动到的地方
            count = i-start;
            if(count>max)
            {
                max = count;
            }
            start = index[s[i]];
        }
        index[s[i]] = i+1;
    }
    count = i-start;
    return count>max?count:max;
}
*/
int main()
{
  class Solution a;
  string s = "abcabcbb";
  int b = a.lengthOfLongestSubstring(s);
  std::cout<<b<<std::endl;
  std::cin.get();
  return 0;
}