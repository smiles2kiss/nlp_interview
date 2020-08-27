class Solution {
public:
    vector<int> pick_max(vector<int> nums, int k) {
        vector<int> stack;
        int drop = nums.size() - k; // 需要丢弃的个数
        for (int i = 0; i < nums.size(); i++) {
            while(drop > 0 && !stack.empty() && stack.back() < nums[i]) {
                stack.pop_back();
                drop = drop - 1;
            }
            stack.push_back(nums[i]);
        }
        if (stack.size() > k) {
            vector<int> result(stack.begin(), stack.begin() + k);
            return result;
        }
        return stack;
    }
    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        vector<int> result;
        int i = 0, j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while (i < n1 && j < n2) {
            if (nums1[i] > nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else if (nums1[i] < nums2[j]){
                result.push_back(nums2[j]);
                j++;
            } else {
                int temp1 = i + 1;
                int temp2 = j + 1;
                while(temp1 < n1 && temp2 < n2) {
                    if (nums1[temp1] == nums2[temp2]) {
                        temp1++;
                        temp2++;
                    } else {
                        break;
                    }
                }

                if (temp1 == n1 && temp2 == n2) {
                    result.push_back(nums1[i]);
                    i++;
                } else if (temp1 == n1 && temp2 != n2) {
                    result.push_back(nums2[j]);
                    j++;
                } else if (temp1 != n1 && temp2 == n2) {
                    result.push_back(nums1[i]);
                    i++;
                } else {
                    if (nums1[temp1] > nums2[temp2]) {
                        result.push_back(nums1[i]);
                        i++;
                    } else if (nums1[temp1] < nums2[temp2]) {
                        result.push_back(nums2[j]);
                        j++;
                    }
                }
            }
        }
        if (i < n1) 
            for (int k = i; k < n1; k++) 
                result.push_back(nums1[k]);
        if (j < n2) 
            for (int k = j; k < n2; k++) 
                result.push_back(nums2[k]);
        return result;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int min_pos = 0;
        int max_pos = len1;
        if (k > len2) min_pos = k - len2;
        if (len1 > k) max_pos = k;

        vector<int> ans;
        for (int i = min_pos; i <= max_pos; i++) {
            int j = k - i;
            vector<int> result1 = pick_max(nums1, i);
            vector<int> result2 = pick_max(nums2, j);
            vector<int> result  = merge(result1, result2);

            if (ans.size() == 0) ans = result;
            else {
                int flag = 0;
                for (int t = 0; t < result.size(); t++)
                    if (result[t] > ans[t]) { flag = 1; break; }
                    else if (result[t] < ans[t]) { flag = -1; break;}
                if (flag == 1) ans = result;
            }
        }
        return ans;
    }
};
