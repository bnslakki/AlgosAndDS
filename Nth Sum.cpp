// 2 Sum, 3 Sum, 4 Sum...
class Solution {
public:
    vector<vector<int>>ans;

    void solve(int pos, int t, int k, vector<int>&ret, vector<int>& arr){
        if(arr.size() < k)return ;
        // 2 sum base case
        if(k == 2){
            int l = pos;
            int r = arr.size() - 1;
            while (l < r){
                if(arr[l] + arr[r] == t){
                    ret.push_back(arr[l]);
                    ret.push_back(arr[r]);
                    ans.push_back(ret);
                    ret.pop_back();
                    ret.pop_back();
                    l++;
                    r--;
                    while(l < r and arr[l] == arr[l - 1])l++;
                    while(l < r and arr[r] == arr[r + 1])r--;
                }
                else if(arr[l] + arr[r] < t)l++;
                else r--;
            }
        }
        else{
            for(int i = pos; i < arr.size() - k + 1; i++){
                if(i > pos && arr[i] == arr[i-1]){
                    continue;
                }
                ret.push_back(arr[i]);
                solve(i + 1, t - arr[i], k - 1, ret, arr);
                ret.pop_back();
            }
        }
    }
    vector<vector<int>> NthSum(vector<int>& nums, int target, int N) {
        sort(nums.begin(), nums.end());
        vector<int>tm;
        solve(0, target, N, tm, nums);
        return ans;
    }
};
