#include"binarysearchtree.h"
#define Balanced(x) (stature((x).lc)==stature((x).rc))//����ƽ������statureΪ�߶�
#define BalFac(x) (stature((x).lc)-stature((x).rc))//ƽ������
#define AvlBalanced(x) ((-2<BalFac(x))&&(BalFac(x)<2))//AVLƽ������
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