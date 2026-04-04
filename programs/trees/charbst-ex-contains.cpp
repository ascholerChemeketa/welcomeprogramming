#include <iostream>
#include <string>
using namespace std;

struct BSTNode {
  // Store a value and two child pointers
  char value;
  BSTNode* left;
  BSTNode* right;

  ///-------------------------------------------------------
  ///  Everything else just to provide tracking of nodes
  ///-------------------------------------------------------

  // Constructor - left/right set to null
  BSTNode(char val);

  // Disable copy/assignment - these are declared but not defined
  BSTNode(const BSTNode& val);
  BSTNode& operator=(const BSTNode& val);

  // Destructor - decrement counter
  ~BSTNode();

  // Debugging purposes only - Not a normal feature
  //   Used for tracking memory allocation, updated in constructor/destructor
  static int nodeCount;
};

int BSTNode::nodeCount = 0;

BSTNode::BSTNode(char val) {
  value = val;
  left = nullptr;
  right = nullptr;
  nodeCount++;
}

BSTNode::~BSTNode() {
  nodeCount--;
}

class CharBST {
  // Would normally be private.
  // Made public to allow intrusive unit tests.
public:
  BSTNode* root;

public:
  /// Constructor - root inited to null
  CharBST();
  /// Destructor - deletes any child nodes
  ~CharBST();

  /// return true if no values in tree
  bool isEmpty();

  /// Produce an in order string representation
  std::string toString() const;

  /// check if value is present
  bool containsRecursive(char val) const;
  bool containsIterative(char val) const;

  /// add (a possibly duplicate) value to tree
  void insertRecursive(char val);
  void insertIterative(char val);

  /// remove indicated char from tree
  void remove(char val);
  /// remove the smallest value from the tree
  void removeSmallest();
  
  /// Disable copy/assignment - these are declared but not defined
  CharBST(const CharBST& val);
  CharBST& operator=(const CharBST& val);
};


///----------------------Forward declare helpers---------------------
char smallestValueFrom(BSTNode* curNode);
BSTNode* removeSmallestHelper(BSTNode* startNode);
void deleteSubTree(BSTNode* curNode);
BSTNode* copySubTree(BSTNode* currentNode);


///----------------------CON/DE STRUCTORS----------------------------
CharBST::CharBST() {
  root = nullptr;
}

void deleteSubTree(BSTNode* curNode) {
  if (curNode != nullptr) {
    deleteSubTree(curNode->left);
    deleteSubTree(curNode->right);
    delete curNode;
  }
}

CharBST::~CharBST() {
  deleteSubTree(root);
  root = nullptr;
}

CharBST::CharBST(const CharBST& other) {
  root = copySubTree(other.root);
}

CharBST& CharBST::operator=(const CharBST& other) {
  if (this != &other) {
    // remove any existing nodes
    deleteSubTree(root);
    // copy nodes of other tree
    root = copySubTree(other.root);
  }
  return *this;
}

bool CharBST::isEmpty() {
  return root == nullptr;
}

///----------------------Print----------------------------
/// Nonmember helper function
string toStringHelper(BSTNode* curNode) {
  if (curNode == nullptr)
    return "";

  string result = toStringHelper(curNode->left);
  result += to_string(curNode->value) + " ";
  result += toStringHelper(curNode->right);

  return result;
}

string CharBST::toString() const {
  return toStringHelper(root);
}

///----------------------Search---------------------------

///----------------------RemoveSmallest---------------------------

///----------------------Smallest---------------------------

///----------------------Removal---------------------------
