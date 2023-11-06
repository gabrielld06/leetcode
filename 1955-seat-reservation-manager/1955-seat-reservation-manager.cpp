class decrease_order {
public:
    decrease_order() {

    }

    bool operator() (const int& lhs, const int&rhs) const {
        return (lhs>rhs);
    }
};

class SeatManager {
public:
    priority_queue<int, vector<int>, decrease_order> seats;
    
    SeatManager(int n) {
        for(int i = 1;i <= n;i++) {
            seats.push(i);
        }
    }
    
    int reserve() {
        int top = seats.top();

        seats.pop();
        
        return top;
    }
    
    void unreserve(int seatNumber) {
        seats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */