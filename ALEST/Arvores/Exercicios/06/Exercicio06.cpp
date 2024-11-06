#include <iostream>
#include "Exercicio06.hpp"

using namespace std;

NodeCharTree::NodeCharTree(char i){
    info = i;
    parent = nullptr;

}
NodeCharTree::~NodeCharTree() {}

char NodeCharTree::getInfo() const { return info; }
void NodeCharTree::setInfo(char i) { info = i; }
NodeCharTree *NodeCharTree::getParent() const { return parent; }

NodeCharTree *NodeCharTree::getChild(int index) const {

return nullptr;

}

bool NodeCharTree::isRoot() const { return parent == nullptr; }
bool NodeCharTree::isInternal() const { return parent != nullptr && childs.size() !=0; }
bool NodeCharTree::isExternal() const { return childs.size() == 0; }
int NodeCharTree::degree() const { return childs.size(); }

int NodeCharTree::depth() const {
    int res = 0;
    NodeCharTree *aux = parent;
    while(aux != nullptr){
        ++res;
        aux = aux->parent;
    }
    return res;
}

int NodeCharTree::height(Node *subtree) const {
    if(subtree)

}
int NodeCharTree::size() const {
    return -1;
}
void NodeCharTree::addSubtree(NodeCharTree *subtree) {
    if(subtree == nullptr) return;
    childs.push_back(subtree);
    subtree->parent = this;

}

bool NodeCharTree::removeSubtree(NodeCharTree *subtree) {

    for(int = 0; i<childs.size();++i){
        if()childs[i]==subtree){
            childs.erease();
        }
    }

}

bool NodeCharTree::contains(char i) const {
    if(this->info == i) return true;
    for(int j = 0; childs.size();++j){
        if(childs[j]->contains(i)) return true;
    }
    return false;

}

NodeCharTree const *NodeCharTree::find(char i) const {

    if(this->info == i) return this;
    for(int j = 0; childs.size();++j){
        NodeCharTree const *aux = childs[j]->find(i);
        if(aux != nullptr) return aux;
    }
    return nullptr;




}

string NodeCharTree:: strGraphViz() const {

    return "";

}