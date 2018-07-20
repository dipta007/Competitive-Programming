// BST Sequences: A binary search tree was created by traversing through an array from left to right
// and inserting each element. Given a binary search tree with distinct elements, print all possible
// arrays that could have led to this tree.
// EXAMPLE
// Input:   2
//        1   3
// Output: {2, 1, 3}, {2, 3, 1}

#include <deque>
#include <list>
#include <cassert>
#include <limits>
#include <algorithm>
#include <functional>
#include <queue>
#include <iostream>
#include <iomanip>
#include <memory>
#include <cmath>
using namespace std;

template <typename T, bool NodeWithParent,
          template<typename, bool> class Node>
class Tree;

template <typename T, bool WithParent>
class Node;

namespace TestUtils
{
    template <typename T, bool NodeWithParent, template<typename, bool> class Node>
    void printTree(const Tree<T, NodeWithParent, Node> &tree)
    {
        using NodePtr = typename Tree<T, NodeWithParent, Node>::NodePtr;

        T minValue = std::numeric_limits<T>::max(), maxValue = std::numeric_limits<T>::min();

        // Lambda function is used to hide it from externall access
        std::function<size_t (const NodePtr &)> getDepth =
        [&](const NodePtr &node) -> size_t
        {
            if (!node)
                return 0;

            auto depth = std::max(getDepth(node->getLeft()), getDepth(node->getRight())) + 1;
            minValue = std::min(minValue, node->getValue());
            maxValue = std::max(maxValue, node->getValue());
            return depth;
        };

        size_t depth = getDepth(tree.getRoot());

        // bottommost max leaf count
        size_t size = 1;
        for(int i=1 ;i<=depth - 1; i++) {
        	size *= 2;
        }

        // width of node, in digits
        size_t digits = (maxValue != 0 || minValue != 0) ? log10(std::max(maxValue, std::abs(minValue))) + 1  : 1;
        if (minValue < 0)
            ++digits;

        const std::string placeholder(digits, ' ');

        std::queue<NodePtr> queue;
        std::queue<NodePtr> childs;
        queue.push(tree.getRoot());
        std::cout << "Tree:" << std::endl;

        do
        {
            // space between nodes
            std::string space((size - 1) * (placeholder.length() + 1) + 1, ' ');

            // margin
            std::cout << std::string(space.length() / 2, ' ');;
            while (!queue.empty())
            {
                if (!queue.front())
                {
                    std::cout << placeholder << space;
                    childs.emplace();
                    childs.emplace();
                }
                else
                {
                    std::cout << std::setw(digits) << std::right << queue.front()->getValue() << space;
                    childs.push(queue.front()->getLeft());
                    childs.push(queue.front()->getRight());
                }
                queue.pop();
            }
            std::cout << std::endl;
            queue.swap(childs);
            size /= 2;
        } while (size > 0);
    }

    // The function treeFromArray from the task 4.2 helps us to fill test trees.
    template <typename T, bool NodeWithParent = false,
              template<typename, bool> class N = Node>
    auto treeFromArray(const T *array, size_t size)
    {
        using NodePtr = typename Tree<T, NodeWithParent, N>::NodePtr;

        std::function<NodePtr (const T *, const NodePtr &, int, int)> subtreeFromArray =
        [&subtreeFromArray](const T *array, const NodePtr &parent, int start, int end) -> NodePtr
        {
            if (end < start)
                return nullptr;

            int i = (start + end) / 2;
            auto node = std::make_shared<N<T, NodeWithParent>>(array[i], parent);
            node->setLeftChild(subtreeFromArray(array, node, start, i - 1));
            node->setRightChild(subtreeFromArray(array, node, i + 1, end));
            return node;
        };

        Tree<T, NodeWithParent, N> tree;
        tree.setRoot(subtreeFromArray(&array[0], nullptr, 0, size - 1));
        return tree;
    }

    template <typename T, bool NodeWithParent = false,
              template<typename, bool> class N = Node>
    auto treeFromArray(std::initializer_list<T> array)
    {
        return treeFromArray<T, NodeWithParent, N>(array.begin(), array.size());
    }

    template <typename T, bool NodeWithParent = false,
              template<typename, bool> class N = Node>
    auto getSampleTree(size_t nodeCount)
    {
        std::vector<T> v(nodeCount) ;
        iota(std::begin(v), std::end(v), 0); // Fill with 0, 1, ..., nodeCount - 1.
        return treeFromArray<T, NodeWithParent, N>(&v[0], v.size());
    }
}


template <typename Node, bool WithParent>
class NodeBase
{
public:
    NodeBase() = default;

    NodeBase(const std::shared_ptr<Node> &p) : parent(p)
    {
    }

    std::shared_ptr<Node> getParent()
    {
        return parent.lock();
    }
private:
    std::weak_ptr<Node> parent;
};

// Specialization for tree node containing no reference to parent
template <typename Node>
class NodeBase<Node, false>
{
public:
    NodeBase() = default;

    NodeBase(const std::shared_ptr<Node> &)
    {
    }

private:
};

template <typename T, bool WithParent = false>
class Node : public NodeBase<Node<T, WithParent>, WithParent>
{
    using Super = NodeBase<Node, WithParent>;

public:
    using NodePtr = std::shared_ptr<Node>;

    Node(T &&v) : value(std::move(v))
    {
    }

    Node(const T &v) : value(v)
    {
    }

    Node(T &&v, const NodePtr &parent) : Super(parent), value(std::move(v))
    {
    }

    Node(const T &v, const NodePtr &parent) : Super(parent), value(v)
    {
    }

    const T &getValue() const
    {
        return value;
    }

    const NodePtr &getLeft() const
    {
        return childs.first;
    }

    NodePtr &getLeft()
    {
        return childs.first;
    }

    const NodePtr &getRight() const
    {
        return childs.second;
    }

    NodePtr &getRight()
    {
        return childs.second;
    }

    template <typename U>
    void setLeftChild(U &&node)
    {
        childs.first = std::forward<U>(node);
    }

    template <typename U>
    void setRightChild(U &&node)
    {
        childs.second = std::forward<U>(node);
    }

protected:
    T value;
    std::pair<NodePtr, NodePtr> childs;
};


template <typename T, bool WithParent = false,
          template<typename, bool> class N = Node>
class Tree
{
public:
    using NodePtr = typename N<T, WithParent>::NodePtr;

    const NodePtr &getRoot() const
    {
        if (isEmpty())
            throw TreeIsEmptyException();
        return root;
    }

    template <typename U>
    void setRoot(U &&node)
    {
        root = std::forward<U>(node);
    }

    bool isEmpty() const
    {
        return !root;
    }

    class TreeIsEmptyException {};

protected:
    NodePtr root;
};

template <typename T, bool WithParent = false>
using NodePtr = typename Tree<T, WithParent>::NodePtr;


template <typename T>
std::list<std::deque<T>> possibleStableJoins(std::deque<T> &prefix, std::deque<T> &left, std::deque<T> &right);

template <typename T>
std::list<std::deque<T>> possibleArrays(const NodePtr<T> &root)
{
    std::list<std::deque<T>> result;
    if (!root)
    {
        result.emplace_back(); // empty is required to call cycle body at least once
        return result;
    }

    auto leftArrays = possibleArrays<T>(root->getLeft());
    auto rightArrays = possibleArrays<T>(root->getRight());

    std::deque<T> prefix;
    prefix.push_back(root->getValue());
    for (auto &left : leftArrays)
        for (auto &right : rightArrays)
        {
            auto joins = possibleStableJoins<T>(prefix, left, right);
            result.splice(result.end(), std::move(joins));
            assert(prefix.size() == 1 && prefix[0] == root->getValue());
        }
    return result;
}

template <typename T>
std::list<std::deque<T>> possibleStableJoins(std::deque<T> &prefix, std::deque<T> &left, std::deque<T> &right)
{
    std::list<std::deque<T>> result;

    if (left.empty() || right.empty())
    {
        std::deque<T> r(prefix);
        r.insert(r.end(), left.begin(), left.end());
        r.insert(r.end(), right.begin(), right.end());
        result.push_back(std::move(r));
        return result;
    }

    prefix.push_back(left.front());
    left.pop_front();
    result.splice(result.end(), possibleStableJoins(prefix, left, right));
    left.push_front(prefix.back());
    prefix.pop_back();

    prefix.push_back(right.front());
    right.pop_front();
    result.splice(result.end(), possibleStableJoins(prefix, left, right));
    right.push_front(prefix.back());
    prefix.pop_back();

    return result;
}

int main()
{
    auto tree = TestUtils::treeFromArray({5, 10, 15, 20, 25, 50, 60, 65, 70, 80});
    TestUtils::printTree(tree);
    // auto tree = TestUtils::treeFromArray({2, 3, 1});
    auto result = possibleArrays<int>(tree.getRoot());

    for (auto &array : result)
    {
        std::string sep;
        std::cout << "{";
        for (auto &n : array)
        {
            std::cout << sep << n;
            if (sep.empty())
                sep = ", ";
        }
        std::cout << "}" << std::endl;
    }
}
