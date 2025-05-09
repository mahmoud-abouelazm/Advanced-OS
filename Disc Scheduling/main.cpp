#include <bits/stdc++.h> 
using namespace std; 
 
pair<int, vector<int>> fcfs(int n, int q, vector<int>& dataQueue, int head) { 
    int total_movement = 0; 
 
    for (int request : dataQueue) { 
        total_movement += abs(head - request); 
        head = request; 
    } 
    return {total_movement, dataQueue}; 
} 
 
pair<int, vector<int>> scan(int n, int q, vector<int>& dataQueue, int head , int direction) { 
    vector<int> sequence; 
    int total_movement = 0; 
    set<int>items(dataQueue.begin() , dataQueue.end()); 
    if(direction == 1){
        for(int i = head ; i < n ; i++){
            if(items.count(i)){
                total_movement += abs(head - i);
                head = i;
                items.erase(i);
                sequence.push_back(i);
                
            }
        }
        for(int i = n-1 ; i >= 0  ; i--){
            if(items.count(i)){
                total_movement += abs(head - i);
                head = i;
                items.erase(i);
                sequence.push_back(i);
            }
        }
    }else{
        for(int i = head ; i >= 0  ; i--){
            if(items.count(i)){
                total_movement += abs(head - i);
                head = i;
                items.erase(i);
                sequence.push_back(i);
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(items.count(i)){
                total_movement += abs(head - i);
                head = i;
                items.erase(i);
                sequence.push_back(i);
                
            }
        }
        
    }
    return {total_movement, sequence}; 
} 
 
pair<int, vector<int>> cScan(int n, int q, vector<int>& dataQueue, int head , int direction) { 
    vector<int> sequence; 
    int total_movement = 0; 
    set<int>items(dataQueue.begin() , dataQueue.end()); 
    if(direction == 1){
        for(int i = head ; i < n-1 ; i++){
            if(items.count(i)){
                total_movement += abs(head - i);
                head = i;
                items.erase(i);
                sequence.push_back(i);
                
            }
        }
        sequence.push_back(n-1);
        sequence.push_back(0);
        for(int i = 1 ; i < n-1 ; i++){
            if(items.count(i)){
                total_movement += abs(head - i);
                head = i;
                items.erase(i);
                sequence.push_back(i);
                
            }
        }
    }else{
        for(int i = head ; i > 0 ; i--){
            if(items.count(i)){
                total_movement += abs(head - i);
                head = i;
                items.erase(i);
                sequence.push_back(i);
            }
        }
        sequence.push_back(0);
        sequence.push_back(n-1);
        for(int i = n-1 ; i > 0 ; i--){
            if(items.count(i)){
                total_movement += abs(head - i);
                head = i;
                items.erase(i);
                sequence.push_back(i);
            }
        }
        
    }
    return {total_movement, sequence}; 
} 
 
int main() { 
    int q, n, head; 
 
    cout << "Enter size of queue: "; 
    cin >> q; 
 
    vector<int> dataQueue(q); 
    cout << "Enter queue elements:\n"; 
    for (int &i : dataQueue) cin >> i; 
 
    cout << "Enter Head initial location: "; 
    cin >> head; 
 
    cout << "Enter number of cylinders: "; 
    cin >> n; 
 
    while (true) { 
        cout << "\nChoose Scheduling Algorithm:\n"; 
        cout << "1 - FCFS\n"; 
        cout << "2 - SCAN\n"; 
        cout << "3 - C-SCAN\n"; 
        cout << "4 - Exit\n"; 
        cout << "Enter your choice: "; 
 
        int choice; 
        cin >> choice; 
        int dir ;
        pair<int, vector<int>> ans; 
 
        switch (choice) { 
            case 1: 
                ans = fcfs(n, q, dataQueue, head); 
                cout << "FCFS Total Head Movement: " << ans.first << endl; 
                cout << "Seek Sequence: "; 
                for (int i : ans.second) cout << i << " "; 
                cout << endl; 
                break; 
            case 2: 
                cout << "Enter direction\n1- Inner tracks to outer tracks\n2- Outer tracks to inner tracks\n";
                cin >> dir;
                ans = scan(n, q, dataQueue, head , dir); 
                cout << "SCAN Total Head Movement: " << ans.first << endl; 
                cout << "Seek Sequence: "; 
                for (int i : ans.second) cout << i << " "; 
                cout << endl; 
                break; 
            case 3: 
                cout << "Enter direction\n1- Inner tracks to outer tracks\n2- Outer tracks to inner tracks\n";
                cin >> dir;
                ans = cScan(n, q, dataQueue, head , dir); 
                cout << "C-SCAN Total Head Movement: " << ans.first << endl; 
                cout << "Seek Sequence: "; 
                for (int i : ans.second) cout << i << " "; 
                cout << endl; 
                break; 
            case 4: 
                cout << "Exiting...\n"; 
                return 0; 
            default: 
                cout << "Invalid choice. Try again.\n"; 
        } 
    } 
 
    return 0; 
}
