
#include <iostream> 

#include <queue> 

using namespace std; 

 

const int NUM_DESKS = 3; 

const int MAX_QUEUE = 5; 

 

int desk[NUM_DESKS]; 

queue<int> q[NUM_DESKS]; 

 

int add_client(int client_id) { 

    int min_size = MAX_QUEUE + 1; 

    int chosen = -1; 

    for (int i = 0; i < NUM_DESKS; i++) { 

        int sz = (int)q[i].size(); 

        if (sz < MAX_QUEUE && sz < min_size) { 

            min_size = sz; 

            chosen = i; 

        } 

    } 

    if (chosen == -1) return -1; 

    q[chosen].push(client_id); 

    return chosen; 

} 

 

void free_desk(int desk_index) { 

    desk[desk_index] = -1; 

    if (!q[desk_index].empty()) { 

        desk[desk_index] = q[desk_index].front(); 

        q[desk_index].pop(); 

    } 

} 

 

void display_state() { 

    cout << "+----------------------------------+" << endl; 

    for (int i = 0; i < NUM_DESKS; i++) { 

        cout << "| Desk" << i << ": "; 

        if (desk[i] == -1) cout << "[Empty]   "; 

        else                cout << "Client " << desk[i] << " "; 

        cout << "| Queue: ["; 

        queue<int> tmp = q[i]; 

        bool first = true; 

        while (!tmp.empty()) { 

            if (!first) cout << ", "; 

            cout << tmp.front(); tmp.pop(); 

            first = false; 

        } 

        if (q[i].empty()) cout << "empty"; 

        cout << "]" << endl; 

    } 

    cout << "+----------------------------------+" << endl; 

} 

 

int main() { 

    desk[0] = 101; q[0].push(201); q[0].push(202); 

    desk[1] = 102; q[1].push(203); q[1].push(204); q[1].push(205); 

    desk[2] = 103; q[2].push(206); 

 

    cout << "\n===== BANK QUEUE SYSTEM =====" << endl; 

    cout << "\n[Initial State]" << endl; 

    display_state(); 

 

    int result = add_client(1001); 

    if (result == -1) 

        cout << "All queues full!" << endl; 

    else 

        cout << "\nClient 1001 added to Desk" << result << "'s queue." << endl; 

    cout << "\n[After Adding Client 1001]" << endl; 

    display_state(); 

 

    cout << "\nFreeing Desk2 (Client " << desk[2] << " served)." << endl; 

    free_desk(2); 

    cout << "\n[After Freeing Desk2]" << endl; 

    display_state(); 

    return 0; 

} 

