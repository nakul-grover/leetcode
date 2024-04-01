class Solution {
public:
int lengthOfLastWord(string s) {
int i=s.size()-1;
while(s[i]==' ')
i--;
int count=0;
for(;i>=0;i--)
{
if(s[i]!=' ')
count++;
if(i==0||s[i]==' ')
break;
}
return count;
}
};