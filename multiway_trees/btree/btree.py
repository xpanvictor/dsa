
from btree.btreeNode import (K, BTreeNode)

def BTreeSearch(key: K, node: BTreeNode) -> BTreeNode:
    if node == None:
        return None # element not found
    i = 1
    while (i <= node.keyTally and node.keys[i-1] < key):
        i += 1
    if (i > node.keyTally or node.keys[i - 1] > key):
        return BTreeSearch(key, node.children[i - 1])
    else:
        return node # cos this node then carries the output

