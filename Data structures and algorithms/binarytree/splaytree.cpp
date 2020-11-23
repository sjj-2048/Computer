#include"splaytree.h"

//作为左孩子
template<typename NodePosi> inline
void attachAsLChild(NodePosi p, NodePosi lc) {
	p->lc = lc;
	if (lc) {
		lc->parent = p;
	}
}
//作为右孩子
template<typename NodePosi> inline
void attachAsRChild(NodePosi p, NodePosi rc) {
	p->rc = rc;
	if (rc) {
		rc->parent = p;
	}
}

//双层伸展

template<typename T>
TreeNode(T) Splay<T>::splay(TreeNode(T) v) {
	
	if (!v) {
		return NULL;
	}
	
	TreeNode(T) p;
	TreeNode(T) g;

	while ((p = v->parent)&&(g = p->parent)) {
		
		TreeNode(T) gg = g->parent;
		if (IsLChild(*p)) {
			if (IsLChild(*v)) {//zig-zig
				attachAsRChild(p, g);
				attachAsLChild(g, p->rc);
				
				attachAsRChild(v, p);
				attachAsLChild(p, v->rc);
			}
			else {//zig-zag
				attachAsRChild(v, p)
				attachAsLChild(p, v->rc);

				attachAsRChild(g, v->lc);
				attachAsLChild(v, g);
			}
		}else if (IsRChild(*p)) {
			   //zag-zag
				attachAsRChild(g, p->lc);
				attachAsLChild(g, v->rc);

				attachAsRChild(v, g);
				attachAsLChild(v, p);
			}else {//zag-zig
				attachAsRChild(p, v->lc)
				attachAsLChild(g, v->rc);

				attachAsRChild(v, g);
				attachAsLChild(v, p);
			}
		if (!gg) {
			v->parent = NULL;
		}
		else {
			(g == gg->lc) ? attachLChild(gg, v) : attachRChild(gg, v);
		}
		updateHeight(g);
		updateHeight(p);
		updateHeight(v);
	}//双层伸展结束

	if (p = v->parent) {//最后一步做一次单旋
		if (IsLChild(*v)) {
			attachAsRChild(v, p);
			attachAsLChild(p, v->rc);
		}
		else {
			attachAsRChild(p, v->lc);
			attachAsLChild(v, p);
		}
		updateHeight(p);
		updateHeight(v);

	}
	v->parent = NULL;
	return v;

}

//搜索
template<typename T>
TreeNode(T)& Splay<T>::search(const T& e) {
	TreeNode(T) p = searchIn(_root, e, _hot = NULL);
	_root = splay(p ? p : _hot);
	return _root;
}

//插入
template<typename T>
TreeNode(T) Splay<T>::insert(const T& e) {
	if (!_root) {
		_size++;
		_root = new BinNode<T>(e);
		return _root;
	}
	if (e == search(e)) {
		return _root;
	}
	size++;
	TreeNode(T) t = _root;
	if (_root->data < e) {
		_root = new BinNode<T>(e, NULL, t, t->rc);
		t->parent = _root;
		if (HasRChild(*t)) {
			t->rc->parent = _root;
			t->rc = NULL;
		}
	}
	else {
		_root = new BinNode<T>(e, NULL, t->lc, t);
		t->parent = _root;
		if (HasLChild(*t)) {
			t->lc->parent = _root;
			t->lc=NULL:
		}
	}
	updateHeightAbove(t);
	return _root;
}


//删除
template<typename T>
bool Splay<T>::remove(const T& e) {
	if (!_root || e != search(e)->data) {
		return false;
	}
	TreeNode(T) w = _root;
	if (!HasLChild(*_root)) {
		_root = _root->rc;
		if (_root) {
			_root->parent = NULL;
		}
	}
	else if (!HasRChild(*_root)) {
		_root = _root->lc;
		if (_root) {
			_root->parent = NULL;
		}
	}
	else {
		TreeNode(T) lTree = _root->lc;
		lTree->parent = NULL;
		_root->lc = NULL;//暂时分离左子树
		_root = _root->rc;
		_root->parent = NULL;
		search(w->data);
		_root->lc = lTree;
		lTree->parent = _root;
	}
	release(w->data);
	release(w);
	_size--;
	if (_root) {
		updateHeight(_root);
		return true;
	}
}