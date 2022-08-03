class MyCalendar {
public:
    struct Event {
        int start, end;
        Event *left, *right;
        Event() : start(-1), end(-1), left(nullptr), right(nullptr) {}
        Event(int s, int e) : start(s), end(e), left(nullptr), right(nullptr) {}
    };
    
    Event *root;
    
    MyCalendar() {
        root = nullptr;
    }
    
    bool insert(Event *at, int start, int end) {
        if(end <= at->start) {
            if(at->left == nullptr) {
                at->left = new Event(start, end);
                return true;
            }
            return insert(at->left, start, end);
        }
        
        if(start >= at->end) {
            if(at->right == nullptr) {
                at->right = new Event(start, end);
                return true;
            }
            return insert(at->right, start, end);
        }
        
        return false;        
    }
    
    bool book(int start, int end) {   
        if(root == nullptr) {
            root = new Event(start, end);
            return true;
        }
        
        
        return insert(root, start, end);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */