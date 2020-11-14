#include"binarytree.h"
#include"stack.h"
#include"queue.h"
/*******************************************************

                   �������ڵ�����ӿ�

********************************************************/

//�������

template<typename T>
Node(T) BinNode<T>::insertAsLC(const T& e) {
	return lChild = new BinNode(e, this);
}

//����Һ���

template<typename T>
Node(T) BinNode<T>::insertAsRC(const T& e) {
	return rChild = new BinNode(e, this);
}

//����

//������α���
template<typename VST,typename T>
void BinNode<T>::travLevel(VST& visit) {
	Queue<Node(T)> q;
	q.enqueue(this);
	while (!q.empty()) {
		Node(T) x = q.dequeue();
		visit(x->data);
		if (HasLChild(*x)) {
			q.enqueue(x->lc);
		}
		if (HasRChild(*x)) {
			q.enqueue(x->rc);
		}
	}
}

//��������������ݹ���ʽ
template<typename VST>
void BinNode<T>::travPre_R(Node(T) x,VST& visit) {

	if (!x) {//�ݹ��
		return;
	}
	visit(x->data);
	travPre_R(x->lChild, visit);
	travPre_R(x->rChild, visit);//β�ݹ�

}
//������1
template<typename T>
void BinNode<T>::travPre_I1(Node(T) x,VST& visit) {

	Stack<Node(T)> s;
	if (x) {
		s.push(x);
	}
	while (!s.empty()) {

		x = s.pop();
		visit(x->data);
		if (!x->rc) {
			s.push(x->rc);
		}
		if (!x->lc) {
			s.push(x->lc);
		}
	}
}
//������2
template<typename T>
void BinNode<T>::travPre_I2(Node(T) x, VST& visit) {
	Stack<Node(T)> s;
	while (true) {
		while (x) {
			visit(x->data);
			s.push(x->rc);
			x = x->lc;
		}
		if (s.empty()) {
			break;
		}
		x = s.pop();
	}
}

//��������������ݹ���ʽ
template<typename VST>
void BinNode<T>::travIn_R(Node(T) x, VST& visit) {

	if (!x) {//�ݹ��
		return;
	}
	travIn_R(x->lChild, visit);
	visit(x->data);
	travIn_R(x->rChild, visit);//β�ݹ�

}

//������1
template<typename T>
void BinTree<T>::travIn_I1(Node(T) x, VST& visit) {

	Stack<Node(T)> s;
	while (true) {
		while (x) {
			s.push(x);
			x = x->lc;
		}
		if (S.empty()) {
			break;
		}
		x = S.pop();
		visit(x->data);
		x = x->rc;
	}
}

//������2
template<typename T>
void BinTree<T>::travIn_I2(Node(T) x, VST& visit) {

	Stack<Node(T)> s;
	while (true) {
		if (x) {
			s.push(x);
			x = x->lc;
		}
		else if (!s.empty()) {
			x = s.pop();
			visit(x);
			x = x->rc;
		}
		else {
			break;
		}
	}
}
template<typename VST>
void BinNode<T>::travPost(VST&);//�����������

//���ҵ�ǰ�ڵ��ֱ�Ӻ��
template<typename T>
Node(T) BinNode<T>::succ() {
	Node(T) s = this;
	if (rc) {
		s = rc;
		while (HasLChild(*s)) {
			s = s->lc;
		}
	}
	else {
		while (IsRChild(*s)) {
			s = s->parent;
		}
		s = s->parent;
	}
	
	return s;
}
//��ǰ�ڵ�ĺ������������ǰ�����Ĺ�ģ
template<typename T>
int BinNode<T>::size() {
	
	s = 1;//��ǰ�ڵ����
	
	if (lChild) {
		s += lChild.size();
	}
	if (rChild) {
		s += rChild.size();
	}

	return s;
}
/*******************************************************

                  �����������ӿ�

********************************************************/

//���¸߶�

template<typename T>
int BinTree<T>::updateHeight(Node(T) x) {

	return x->height = 1 + max(stature(x->lc), stature(x->rc));

}

//�������ȸ߶�

template<typename T>
void BinTree<T>::updateHeightAbove(Node(T) x) {

	while (x) {
		updateHeight(x);
		x = x->parent;
	}
}

//����ڵ�

template<typename T>
Node(T) BinTree<T>::insertAsRoot(const T& e) {

	_size = 1;
	return _root = new BinNode(e);

}
template<typename T>
Node(T) BinTree<T>::insertAsLC(Node(T) x, T& e) {

	_size++;
	x->insertAsLC(e);
	updateHeightAbove(x);
	return x->lc;

}
template<typename T>
Node(T) BinTree<T>::insertAsRC(Node(T) x, T& e) {

	_size++;
	x->insertAsRC(e);
	updateHeightAbove(x);
	return x->rc;

}

//��ĳһ�������������

template<typename T>
Node(T) BinTree<T>::attachAsLC(Node(T) x, BinTree<T>* &S) {

	x->lc = S->_root;
	x->lc->parent = x;
	_size += S->_size;
	updateHeightAbove(x);
	S->_root = NULL;
	S->_size = 0;
	release(S);
	S = NULL;
	return x;
}
template<typename T>
Node(T) BinTree<T>::attachAsRC(Node(T) x, BinTree<T>* &S) {

	x->rc = S->_root;
	x->rc->parent = x;
	_size += S->_size;
	updateHeightAbove(x);
	S->_root = NULL;
	S->_size = 0;
	release(S);
	S = NULL;
	return x;
}

//����ɾ��
template<typename T>
static int removeAt(Node(T) x) {
	
	if (!x) {
		return 0;
	}
	int n += removeAt(x->lc) + removeAt(x->rc);
	release(x->data);
	release(x);
	return n;
}

template<typename T>
int BinTree<T>::remove(Node(T) x)
{

	FromParentTo(*x) = NULL;
	updateHeightAbove(x);
	int n = removeAt(x);
	_size -= n;
	return n;

}

//��������

template<typename T>
BinTree<T>* BinTree<T>::secede(Node(T) x) {

	FromParentTo(*x) = NULL;
	updateHeightAbove(x);
	_size -= x->size();

	BinTree<T>* S = new BinTree<T>;
	S->_size = x->size();
	S->_root = x;
	x->parent = NULL;
	
	return S;

}