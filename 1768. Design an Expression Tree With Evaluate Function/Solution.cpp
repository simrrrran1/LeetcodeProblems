/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    string s;
    Node* left;
    Node* right;

    virtual ~Node() {
        if (left) delete left;
        if (right) delete right;
    }

    virtual int evaluate() const {
        if (s != "+" && s != "-" && s != "*" && s != "/")
            return stoi(s);

        int lval = left->evaluate();
        int rval = right->evaluate();

        if (s == "+") return lval + rval;
        if (s == "-") return lval - rval;
        if (s == "*") return lval * rval;
        return lval / rval;
    }

    Node(string s, Node* left = nullptr, Node* right = nullptr)
        : s(s), left(left), right(right) {}
};



/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree representing it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<Node*> s;
        for(int i=0; i<postfix.size(); i++){
            if(postfix[i] != "+" && postfix[i] != "-" && postfix[i] != "*" && postfix[i] != "/"){
                Node* node = new Node(postfix[i]);
                s.push(node);
            }else{
                    Node* right = s.top();
                    s.pop();
                    Node* left = s.top();
                    s.pop();
                    Node* node = new Node(postfix[i], left, right);
                    s.push(node);
                }
        }
        return s.top();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */