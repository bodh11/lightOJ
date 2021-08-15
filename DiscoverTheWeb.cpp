#include<iostream>
#include<stack>

using namespace std;


int main() {

    int t;
    cin >> t;
    int ca = 1;
    while(t--) {

        stack<string> st_forward;
        stack<string> st_backward;
        string currentURL = "http://www.lightoj.com/";

        // keep reading till commands are comming
        cout << "Case " << ca++ << ":" << endl;
        while(1) {
            string s;
            cin >> s;
            if(s == "QUIT") {
                break;
            }
            if(s == "VISIT") {
                string newUrl;
                cin >> newUrl;

                // forward stack is emptied
                while(!st_forward.empty())
                 st_forward.pop();
                st_backward.push(currentURL);
                 
                currentURL = newUrl;
                cout << currentURL << endl;
            } else if(s == "BACK") {
                if(!st_backward.empty()) {
                    st_forward.push(currentURL);
                    currentURL = st_backward.top();
                    st_backward.pop();
                    cout << currentURL << endl;
                } else {
                    cout << "Ignored" << endl;
                }
            } else if(s == "FORWARD") {
                if(!st_forward.empty()) {
                    st_backward.push(currentURL);
                    currentURL = st_forward.top();
                    st_forward.pop();
                    cout << currentURL << endl;
                } else {
                    cout << "Ignored" << endl;
                }
            }
        }
    }
    return 0;
}