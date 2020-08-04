#include <iostream>
#include<list>
#include<vector>
#include<list>

struct node{
    int val;
    node *left;
    node *right;
};



class BinaryTree{
public:
    BinaryTree():root(NULL),numNode(0){std::cout<<"构造函数已经调用了"<<std::endl;}
    void CreateTree(){
        if(root!=NULL){
           std::cout<<"根节点不为空，说明已经创建过二叉树，如果需要重新创建，请先使用clear()清空该二叉树"<<std::endl;
           return;
        }
        std::cout<<"请输入根节点的数据: "<<std::endl;
        int x;
        std::cin>>x;
        node *newnode = new node;
        newnode->val = x;
        newnode->left=NULL;
        newnode->right = NULL;
        root = newnode;
        numNode++;
        std::cout<<"二叉树根节点已经创建成功，此时结点个数为: "<<numNode<<std::endl;
        while(true){
            std::cout<<"开始创建其他结点，请输入r或l以确定是向根节点左插入还是右插入，如果输入q表示停止输入"<<std::endl;
            char pos;
            std::cin>>pos;
            if(pos=='q'){
                std::cout<<"停止创建结点，该二叉树目前拥有的结点数为: "<<numNode<<std::endl;
                break;
            }
            else if(pos=='l' || pos=='r'){
               
                std::cout<<"请输入你想要创建的结点的值: "<<std::endl;
                int elem;
                std::cin>>elem;
                if(pos=='l'){
                    std::cout<<"该节点将插入根节点的左侧"<<std::endl;
                    CreateTree(root,root->left,elem,pos);
                }
                else{
                    std::cout<<"该节点将插入根节点的右侧"<<std::endl;
                    CreateTree(root,root->right,elem,pos);
                }

            }
        }
        
    }
    void CreateTree(node *curr,node *n,int x,char pos){
        if(n!=NULL){
            char ch;
            std::cout<<"该结点已经非空，请选择是插入该结点的左侧还是右侧: "<<n->val<<" :"<<std::endl;
            std::cin>>ch;
            if(ch=='l') CreateTree(n,n->left,x,ch);
            else if(ch=='r') CreateTree(n,n->right,x,ch);
        }
        else{
            if(pos=='l' || pos == 'r'){
                node *t = new node;
                t->val = x;
                t->left = NULL;
                t->right = NULL;
                if(pos == 'l'){
                    curr->left = t;
                }
                else curr->right = t;
                numNode++;
                std::cout<<"插入结点成功,该二叉树目前拥有的结点个数为: "<<numNode<<std::endl;
            }
        }
    }
    void clear(node *current){
        if(current->left!=NULL) clear(current->left);
        if(current->right!=NULL) clear(current->right);
        delete current;
        numNode--;
        std::cout<<"清除结点成功，此时二叉树结点个数为: "<<numNode<<std::endl;
        return;
    }
    void clearTree(){
        clear(root);
    }
    ~BinaryTree(){
        std::cout<<"析构函数调用了"<<std::endl;
        clearTree();
    }

    void travse(int order=0){
        switch (order)
        {
        case 0:
            std::cout<<"进行先序遍历,其结果为:"<<std::endl;
            _pre(root);
            std::cout<<std::endl;
            break;
        case 1:
            std::cout<<"进行中遍历,其结果为:"<<std::endl;
            _in(root);
            std::cout<<std::endl;
            break;
        case 2:
            std::cout<<"进行后续遍历,其结果为:"<<std::endl;
            _post(root);
            std::cout<<std::endl;
            break;
        case 3:
            std::cout<<"进行层次遍历,其结果为:"<<std::endl;
            BFT();
            std::cout<<std::endl;
            break;

        case 4:
            std::cout<<"进行morris先序遍历,其结果为:"<<std::endl;
            morrisPre();
            std::cout<<std::endl;
            break;
        case 5:
            std::cout<<"进行morris中序遍历,其结果为:"<<std::endl;
            morrisMid();
            std::cout<<std::endl;
            break;
        case 6:
            std::cout<<"进行morris后序遍历,其结果为:"<<std::endl;
            morrisPost();
            std::cout<<std::endl;
            break;
        default:
            break;
        }
    }


    void _pre(node *n){
        if(n!=NULL){
            std::cout<<n->val<<" ";
            _pre(n->left);
            _pre(n->right);
        }
    }

    void _in(node *n){
         if(n!=NULL){
            _in(n->left);
             std::cout<<n->val<<" ";
            _in(n->right);
        }
    }

    void BFT(){
        std::list<node*> queue;
        queue.push_back(root);
        while(!queue.empty()){
            node *temp = queue.front();
            std::cout<<temp->val<<" ";
            queue.pop_front();
            if(temp->left!=NULL) queue.push_back(temp->left);
            if(temp->right!=NULL) queue.push_back(temp->right);
        }
    }

    void _post(node *n){
         if(n!=NULL){
            _post(n->left);
            _post(n->right);
            std::cout<<n->val<<" ";
        }
    }

    void Morris(){
        if(root == NULL)
            return;
        node *cur = root;
        node *mostRight = NULL;
        while(cur != NULL){
            mostRight = cur->left;
            if(mostRight != NULL){
                while(mostRight->right && mostRight!=cur) mostRight = mostRight->right;
                if(mostRight->right == NULL){
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                }
                

            }
        }
    }

    void morrisPre(){
       // std::cout<<"Morris先序遍历结果为："<<std::endl;
        if(root==NULL) return;
        node *cur = root;
        node *mostRight = NULL;
        while(cur != NULL){
            mostRight = cur->left;
            if(mostRight == NULL){
                std::cout<<cur->val<<" ";
                cur = cur->right;
            }
            else{
                while(mostRight->right!=NULL && mostRight->right != cur){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == NULL){
                    std::cout<<cur->val<<" ";
                    mostRight->right = cur;
                    cur = cur->left;
                }
                else{
                    mostRight->right = NULL;
                    cur = cur->right;
                }
            }
        }
      //  std::cout<<"\nMorris先序遍历结束"<<std::endl;
    }

    void morrisMid(){
      //   std::cout<<"Morris中序遍历结果为："<<std::endl;
         if(root == NULL) return;
         node *cur = root;
         node *mostRight = NULL;
         while(cur != NULL){
             mostRight = cur->left;
             if(mostRight == NULL){
                 std::cout<<cur->val<<" ";
                 cur = cur->right;
             }
             else{
                 while(mostRight->right!=NULL && mostRight->right != cur) mostRight = mostRight->right;
                 if(mostRight->right==NULL){
                     mostRight->right = cur;
                     cur = cur->left;
                 }
                 else{
                     std::cout<<cur->val<<" ";
                     mostRight->right = NULL;
                     cur = cur->right;
                 }
             }
         }
     //    std::cout<<"\nMorris中序遍历结束"<<std::endl;
    }
    void sout(node *t){
          std::list<int> l;
          while(t != NULL){
              l.push_front(t->val);
              t = t->right;
          }
          for(auto it = l.cbegin();it != l.cend();) std::cout<<*it++ <<" ";
    }
    void morrisPost(){
      //  std::cout<<"Morris后序遍历结果为："<<std::endl;
        if(root == NULL) return;
        node *cur = root;
        node *mostRight = NULL;
        while(cur != NULL){
            mostRight = cur->left;
            if(mostRight == NULL) cur = cur->right;
            else{
                while(mostRight->right != NULL && mostRight->right != cur) mostRight=mostRight->right;
                if(mostRight->right == cur){
                    mostRight->right = NULL;
                    sout(cur->left);
                    cur = cur->right;
                }
                else{
                    mostRight->right = cur;
                    cur = cur->left;
                }
            }
        }
        sout(root);
        // std::cout<<"\nMorris后序遍历结束"<<std::endl;

    }
private:
    node *root;
    int numNode;
    //禁止拷贝构造和拷贝赋值
    BinaryTree(const BinaryTree&);
    BinaryTree& operator=(const BinaryTree&);
};


int main(){
    BinaryTree bt;
    bt.CreateTree();
    for(int i=0;i<=6;i++){
        bt.travse(i);
    }
    return 0;
}