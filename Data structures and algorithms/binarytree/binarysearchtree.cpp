#include"binarysearchtree.h"

//查找

template<typename T>
TreeNode(T) BST<T>::search(const T& e) {
	return searchIn(_root, e, _hot = NULL);
}

template<typename T>
static TreeNode(T)& searchIn(TreeNode(T)& v,const T& e, TreeNode(T)& hot) {
	if (!v || (e == x->data) {
		return v;
	}
	hot = v;
	return searchIn(((e < v->data) ? v->lc : v->rc), e, hot);
}

//插入

template<T>
TreeNode(T) BST<T>::insert(const T&e) {
	TreeNode(T)& x = search(e);
	if (!x) {
		x = new BinNode(e, _hot);
		_size++;
		updateHeightAbove(x);
		return x;
	}
}

//删除

template<typename T>
bool BST<T>::remove(const T& e) {
	TreeNode(T) &x = search(e);
	if (!x) {
		return false;
	}
	removeAt(x, _hot);
	_size--;
	updateHeightAbove(_hot);
	return true;
}

template<typename T>
static TreeNode(T) removeAt(TreeNode(T)& x, TreeNode(T)& hot) {
	TreeNode(T) w = x;
	TreeNode(T) succ = NULL;
	if (!HasLChild(*x)) {
		succ = x = x->rc;
	}
	else if (!HasRChild(*x)) {
		succ = x = x->lc;
	}
	else {
		w = w->succ();
		swap(x->data, w->data);
		TreeNode(T) u = w->parent;
		((u == x) ? u->rc : u->lc) = succ = w->rc;
	}
	hot = w->parent;
	if (succ) {
		succ->parent = hot;
	}
	release(w->data);
	release(w);
	return succ;
}

//“3+4”重构

template<typename T>
TreeNode(T) BST<T>::connect34(TreeNode(T) a, TreeNode(T) b, TreeNode(T) c,
	TreeNode(T) T0, TreeNode(T) T1, TreeNode(T) T2, TreeNode(T) T3) {
	a->lc = T0; if (T0) T0->parent = a;
	a->rc = T1; if (T1) T1->parent = a;
	updataHeight(a);
	c->lc = T2; if (T2) T2->parent = c;
	c->rc = T3; if (T3) T3->parent = c;
	updataHeight(c);
	b->lc = a; a->parent = b;
	b->rc = c; c->parent = b;
	updataHeight(b);
	return b;
}

//统一重平衡

template<typename T>
TreeNode(T) BST<T>::rotateAt(TreeNode<T> v) {
	TreeNode(T) p = v->parent;
	TreeNode(T) g = p->parent;
	if (IsLChild(*p)) {
		if (IsLChild(*v)) {
			p->parent = g->parent;
			return connect34(v, p, g,
				v->lc, v->rc, p->rc, g->rc);
		}
		else {
			v->parent = g->parent;
			return connect34(p, v, g,
				p->lc, v->lc, v->rc, g->rc);
		}
	}
	else {
		if (IsRChild(*v)) {
			p->parent = g->parent;
			return connect34(g, p, v, 
				g->lc, p->rc, v->lc, v->rc);
		}
		else {
			v->parent = g->parent;
			return connect34(g, v, p, 
				g->lc, v->lc, v->rc, p->rc);
		}
	}
}