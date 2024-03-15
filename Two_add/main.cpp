#include <iostream>
#include <list>
#include <vector>
#include <algorithm> 
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //an iterator to  the list of numbers
        auto it=nums.begin();
        for(int i=0;i<nums.size();i++){
            //auto sb =it+1;
            /*Find function is used to search if an element
            equal to the  difference between the target and 
            the current iterator 's value
            */
            auto jt=find(it+1,nums.end(),target-*it);
            /*condition to evaluate if find operation was succesful*/

            if(jt!=nums.end()){
                //if so, the  pair of elements are returned as vector
                return {i,(int) distance(nums.begin(),jt)};
            }
            it++;
        }
        
        return {};
    }
};
int main(int, char **)
{
    Solution s;
    vector<int> input{ 8,7,-2, 11,15};
    vector<int> output = s.twoSum(input, 9);
    if (output.size() > 0)
    {
        cout << "the indexes are: ";
        for (auto i : output)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "the values are: ";
        for (auto i : output)
        {
            cout << input[i] << " ";
        }
        cout << endl;
          
        
    }
    else
    {
        cout << "None index match the solution" << endl;
    }
    input={3,5,2,4};
    output = s.twoSum(input, 6);
    if (output.size() > 0)
    {
        cout << "the indexes are: ";
        for (auto i : output)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "the values are: ";
        for (auto i : output)
        {
            cout << input[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "None index match the solution" << endl;
    }
    input={3,3};
    output = s.twoSum(input, 6);
    if (output.size() > 0)
    {
        cout << "the indexes are: ";
        for (auto i : output)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "the values are: ";
        for (auto i : output)
        {
            cout << input[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "None index match the solution" << endl;
    }
}
