class Solution {
public:
    string simplifyPath(string path) {
        stack<char> stk;
        int dot_num = 0;
        for(int i = 0; i < path.length(); i++) {
        	if (path[i] == '/') {
        		if (stk.size() == 0) {
        			stk.push(path[i]);
				} else {
					if (stk.top() == '/') {} // 解决 // 
					else if (stk.top() == '.') {
	        			if (dot_num == 1)   // 解决 ./ 
	        				stk.pop();
	        			else if (dot_num == 2) {  // 解决 ../ , 如 /abc/../ 
	        				stk.pop();
	        				stk.pop();
	        				if (stk.size() > 1 && stk.top() == '/') {
	        					stk.pop(); // 弹出 / 
	        					while(stk.size() > 1 && stk.top() != '/') // 弹出abc
									stk.pop();
							}
						}
					} else {
						stk.push(path[i]);
					}
	        		dot_num = 0;
				}
        		
			} else if (path[i] == '.') {
				stk.push(path[i]);
				dot_num = dot_num + 1;
			} else {
				stk.push(path[i]);
				dot_num = 0;
			}
			if (i == path.length() - 1) {
				if (dot_num == 1)
					stk.pop();
				if (dot_num == 2) {
					stk.pop();
    				stk.pop();
    				if (stk.size() > 1 && stk.top() == '/') {
    					stk.pop(); // 弹出 / 
    					while(stk.size() > 1 && stk.top() != '/') // 弹出abc
							stk.pop();
					}
				}
				if (stk.size() > 1 && stk.top() == '/')
					stk.pop();
			}
		}

        vector<int> str;
        while(!stk.empty()) {
            str.push_back(stk.top());
            stk.pop();
        }
		
		string result = "";
        for (int i = str.size() - 1; i >= 0; i--) 
            result.push_back(str[i]);
        return result;
    }
};
