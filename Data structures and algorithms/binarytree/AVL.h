#include"binarysearchtree.h"
#define Balanced(x) (stature((x).lc)==stature((x).rc))//理想平衡条件stature为高度
#define BalFac(x) (stature((x).lc)-stature((x).rc))//平衡因子
#define AvlBalanced(x) ((-2<BalFac(x))&&(BalFac(x)<2))//AVL平衡条件
#define tallerChild(x) (\
	stature((x)->lc)>stature((x)->rc)?(x)->lc:(\
	stature((x)->lc)>stature((x)->rc)?(x)->lc:(\
	IsLChild(*(x))?(x)->lc:(x)->rc\
	)\
	)\
)

template<class T>
class AVL :public BST<T> {

public:
	TreeNode(T) insert(const T& e);
	bool remove(const T& e);

};